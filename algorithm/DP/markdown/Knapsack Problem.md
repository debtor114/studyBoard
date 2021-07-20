

# Knapsack Problem

 도둑이 박물관에 침입했습니다. 멋진 그림, 조각품, 보석이 사방에 있습니다. 도둑은 이러한 물건의 가치를 잘 알고 있으며, 각각 이 진귀한 물건들이 시장에서 수백 또는 수천 달러에 거래 되는 것도 잘 알고 있습니다. 그러나 도둑은 현장에 배낭 하나만 가져 왔고, 가방의 수용량 만큼만 가지고 나갈 수 있습니다. 도둑은 가치를 극대화하기 위해 어떤 품목을 가져 가야합니까?



문제에는 두가지 버전이 있습니다.

### 1. Fraction knapsack problem

### 2. 0-1 knapsack problem

차이점은 보물을 가루로 만들어 일부만 취할 수 있는지 없는지 여부입니다. 

1번의 경우에는 그리디 알고리즘으로 간단하게 해결이 가능합니다.  각 항목에 대해 파운드당 가치를 계산합니다. 그리디 알고리즘에 따라 도둑은 파운드당 가치가 가장 큰 물건을 최대한 많이 가져 가기 시작합니다. 그 아이템의 공급이 소진되고 그가 더 많이 운반 할 수 있다면 그는 파운드당 다음으로 큰 가치를 가진 품목을 최대한 많이 가져가며 더 이상 휴대 할 수 없을 때까지 계속합니다.

해결하기 어려운 것은 2번 경우이므로 우리는 2번 (0-1 knapsack problem)에 대해 다룰 것입니다.



$ W: 가방의\ 최대\ 수용\ 무게 \\\\
w_i: i번째\ 보물의\ 무게 \\\\
b_i: i번째\ 보물의\ 가치 \\\\ $

예시)

| $ W = 20 $ | $ i $ | $ w_i $ | $ b_i $ |
| ---------- | ----- | ------- | ------- |
|            | 1     | 2       | 3       |
|            | 2     | 3       | 4       |
|            | 3     | 4       | 5       |
|            | 4     | 5       | 8       |
|            | 5     | 9       | 10      |



#### 첫번째 방법: Brute force approach

먼저 간단한 알고리즘으로이 문제를 해결해 보겠습니다. 

- $ n $ 개의 항목이 있으므로 $ 2^n $ 개의 항목 조합이 가능합니다. 
- 모든 조합을 살펴보고 총 가치가 가장 많고 총 중량이 $ W $ 이하인 조합을 찾습니다. 
- 실행 시간은 $ O(2^n) $입니다.



#### 두번째 방법: Greedy approach

동작하지 않습니다.



#### 세번째 방법: Dynamic Programming

item에 $ 1..n $ 레이블이 지정되어있는 경우 하위 문제는 $ S_k = {items labeled 1, 2, .. k} $ 에 대한 최적의 솔루션을 찾는 것입니다.


하위 문제 ($S_k$)를 사용하여  최종 솔루션 ($S_n$)을 정의할 수 있는가?

그렇게 할 수 없습니다.


$S_i$를 1번째 부터 $i$번째의 아이템을 모두 담았을 때 총 무게와 가치라고 정의한다면, 

$S_4 = (14, 20)$

$S_5 = (20, 26)$ 이다. 

$S_4$ 솔루션은 $S_5$ 솔루션의 일부가 아닙니다.

따라서 하위 문제에 대한 이 정의는 뭔가 잘못됬으므로 다른 시각의 문제 정의가 필요하다.



가지고 나올 수 있는 최대무게를 나타내는 변수 $w$를 추가해 보겠습니다.



그러면 하위 문제는 B [k, w]를 계산하는 것입니다.

B[k, W]는 최대 수용 무게가 W이고, k번째 아이템을 포함하려고 할 때 최대 가치를 의미한다.

$ B[k, W] = \begin{Bmatrix}
 &if,\ w_k > W \ \ \ \ \ \  B[k-1,\ W]  \\\\ 
 &otherwise \ \ \ \ \ \ max\{B[k-1,\ W], \ B[k-1,\ W-w_k]+b_k\} 
\end{Bmatrix} $


- 첫 번째 경우 : $w_k> W$:  item k는 최종 해의 일부가 될 수 없습니다. 총 중량이 W보다 커지기 때문입니다.
- 두 번째 경우 : $w_k <= W$: item k가 최종 해에 포함될 수 있으며 더 큰 값을 가진 케이스를 선택합니다.



두 번째 경우는 총 가중치 W를 갖는 Sk의 부분 집합이 다음 두 가지 중 하나임을 의미합니다.

1) 총 가중치 $ W $를 갖는 $ S_k - 1 $의 부분 집합, 또는

2) 총 중량 $ W-w_k $에 항목 k를 더한 $ S_k - 1 $의 부분 집합



**의사코드**

```c
// 아무것도 선택하지 않는 경우의 가치는 0이다.
for w[] = 0 to W 
  B[0,w] = 0
  
// W = 0이라 아무것도 담을 수 없는 경우의 가치도 0이다.
for i = 1 to n 
  B[i,0] = 0
	for w[i] = 1 to W
		if w[i] <= w // item i can be part of the solution
			if b[i] + B[i-1,w-w[i]] > B[i-1,w] 
        B[i,w] = b[i] + B[i-1,w-w[i]]

      else B[i,w] = B[i-1,w] 
        
    else B[i,w] = B[i-1,w] // wi > w
```





Example)

$ n = 4 \\\\ W = 5\\\\ items = [ (2, 3), (3, 4), (4, 5), (5, 6) ] $


##### 1. 초기화

```C
for w = 0 to W
	B[0, W] = 0;
	
for i = 1 to n
	B[i, 0] = 0;
```



| w/i  | 0    | 1    | 2    | 3    | 4    |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 0    | 0    | 0    | 0    | 0    | 0    |
| 1    | 0    |      |      |      |      |
| 2    | 0    |      |      |      |      |
| 3    | 0    |      |      |      |      |
| 4    | 0    |      |      |      |      |
| 5    | 0    |      |      |      |      |





##### 2. B[1, 1]: W = 1일 때, 1번 아이템 (2,3)을 포함하려고 할 때 최대가치 

$ i = 1, \ b_1 = 3, \ w_1 = 2, \ W = 1 $

```c++
if w[i] <= W // item i can be part of the solution
			if b[i] + B[i-1,W-w[i]] > B[i-1,W] 
        B[i,W] = b[i] + B[i-1, W- w[i]]

      else B[i,W] = B[i-1,W] 
        
else B[i,W] = B[i-1,W] // wi > W 
```

$ w_1 > W $ 이므로 마지막 줄 else에 걸리게 된다.

가방의 최대 수용 무게가 1일 때, 무게가 2인 1번 아이템을 담을 수 없다.

B[1, 1] = B[0, 1] = 0

| w/i  | 0    | 1                                 | 2    | 3    | 4    |
| ---- | ---- | --------------------------------- | ---- | ---- | ---- |
| 0    | 0    | 0                                 | 0    | 0    | 0    |
| 1    | 0    | <span style= "color:red">0</span> |      |      |      |
| 2    | 0    |                                   |      |      |      |
| 3    | 0    |                                   |      |      |      |
| 4    | 0    |                                   |      |      |      |
| 5    | 0    |                                   |      |      |      |



##### 3. B[1, 2]: W = 2일 때, 1번 아이템 (2,3)을 포함하려고 할 때 최대가치

$ i = 1, \ b_1 = 3, \ w_1 = 2, \ W = 2 $



```c++
if wi <= W // item i can be part of the solution
			if bi + B[i-1,W-wi] > B[i-1,W] 
        B[i,W] = bi + B[i-1,W- wi]

      else B[i,W] = B[i-1,W] 
        
else B[i,W] = B[i-1,W] // wi > W 
```

$ w_1 <= W $ 이므로 처음 if에 걸리고, 

$ if (b_1(3) + B[0, 0](0) > B[0, 2](0)) 이므로, \ B[1,2] = 2 + B[0, 0](0) $


가방의 최대 수용 무게가 2일 때, 무게가 2인 1번 아이템을 담을 수 있다.

B[1, 2] = 3 + B[0, 0] = 3

| w/i  | 0    | 1                                 | 2    | 3    | 4    |
| ---- | ---- | --------------------------------- | ---- | ---- | ---- |
| 0    | 0    | 0                                 | 0    | 0    | 0    |
| 1    | 0    | 0                                 |      |      |      |
| 2    | 0    | <span style= "color:red">3</span> |      |      |      |
| 3    | 0    |                                   |      |      |      |
| 4    | 0    |                                   |      |      |      |
| 5    | 0    |                                   |      |      |      |

이런 식으로 표를 작성해서 B[n, W]를 구하면 해결할 수 있다.



![selection_tree](https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/images/selection_tree.png?raw=true)







#### 네번째 방법: Branch and Bound

하지만, 모든 노드를 방문하는 비용을 줄이고자 각 노드 혹은 그 노드를 루트로 갖는 트리 전체를 방문할 가치가 있는지 여부만 확인하고 탐색한다면 더 빠르지 않을까?



 각 노드에서 3 개의 로컬 값을 계산합니다.

- benefit :이 노드까지 value 값의 합계
- weight :이 노드까지의 무게의 합계
- bound :이 노드를 넘어 확장하여 얻을 수 있는 benefit의 상한





**Bound 계산**

- tot_weight

레벨 $ i $에서  tot_weight = i번째 아이템까지의 weight를 더하고  tot_weight가 $W$를 초과하지 않을 때 까지 $ w\_{i + 1}, w\_{i + 2}, ... w_{k-1} $ 을 tot_weight에 더한다.

즉, tot_weight는 W을 넘지 않을 때까지 넣을 수 있는 최대 무게이다.

=> tot_weight = weight + $ \sum_{j=i+1}^{k-1}w_j $



![bound_explaination](https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/images/bound_explaination.png?raw=true)



즉, bound란 보물을 나눌 수 있다고 가정하고 W에 tot_weight만큼 채우고 남은 무게를 보물을 쪼개서 넣는다고 생각하면 된다.



Bound와 tot_weight가 잘 이해되지 않을 수 있다. 아래의 예시를 보자.

$ n = 4, \ W= 16 $

| i    | $ b_i $ | $ w_i $ | $ \frac{b_i}{w_i} $ |
| ---- | ------- | ------- | ------------------- |
| 1    | $40     | 2       | $20                 |
| 2    | $30     | 5       | $6                  |
| 3    | $50     | 10      | $5                  |
| 4    | $10     | 5       | $2                  |

이 있을 때, 1번 보물을 넣는다고 가정하면 

weight는 1번을 선택했으니 무게를 2를 썻다.

- tot_weight는 W(16) 이하로 보물들을 채워넣는 것이다. 지금 1번 보물이 들어있으니 2를 일단 썻기 때문에 14를 넘지 않게 2번 보물 (5)를 담고 3번 보물(10)을 담으려고 했더니 15가 되어 W를 초과해버린다. 따라서 tot_weight는 2번 보물까지 담은 2+5 = 7이 되는 것이다. (실제로 담긴 보물은 1번 보물만 있다.) 

- k = 3

  

- bound는 현재까지 취한 이득 (=1번 보물, 40) + 쪼개지 않고 온전하게 가져갈 수 있는 보물들의 이득 (2번 보물까지, 30) + 남은 무게(16 - 5 - 2 = 8)에 3번 보물을 최대한 쪼개가져갔을 때의 이득 (5*8 = 40) = 110이되는 것이다.





- 글로벌 변수 max_benefit: 지금까지 찾은 최고의 경우에서 얻을 수있는 benefit입니다. 주식으로 치면 실현손익이다.

  

  처음에는 max_benefit = 0입니다. 

  이후 각 노드에서 weight < W이면 max_benefit = max (max_benefit, benefit)



**Branching (or pruning)**

모든 노드는 promising or non-promising으로 평가된다.

- promising : 이 노드를 넘어 더 탐색할 것이다.

  - bound > max_benefit && weight ≤ W

  

- non-promising: 이 노드 이하로는 탐색하지 않을 것이다.

  - bound ≤ max_benefit

  : bound ≤ max_benefit 인 경우 노드를 확장하더라도 max_benefit보다 더 많은 benefit을 얻을 수 없다.

  - weight > W 

  : 이 노드에서 계산된 benefit은 불가능한 경우이다. 따라서 max_benefit은 업데이트되지 않으며이 노드를 넘어 탐색하지 않는다.



Example)

$ n = 4, \ W= 16 $

| i    | $ b_i $ | $ w_i $ | $ \frac{b_i}{w_i} $ |
| ---- | ------- | ------- | ------------------- |
| 1    | $40     | 2       | $20                 |
| 2    | $30     | 5       | $6                  |
| 3    | $50     | 10      | $5                  |
| 4    | $10     | 5       | $2                  |

내림차순으로 $ \frac{b_i}{w_i} $ 을 정렬한다.

$ tot\_weight = weight + \sum\_{j=i+1}^{k-1}w_j \\\\
bound = benefit + \sum_{j=i+1}^{k-1}b_j + (W-tot\_weight)*\frac{b_k}{w_k} \\\\
max\_benefit = max \ (max\_benefit, \  benefit) $


##### 1. i = 0

(0, 0): 아무것도 선택하지 않은 상태

|       | benefit | weight | max_benefit | tot_weight    | bound                               |
| ----- | ------- | ------ | ----------- | ------------- | ----------------------------------- |
| (0,0) | 0       | 0      | 0           | 7 (0 + (2+5)) | $110 (0 + (40+30) + (16-7)*50 / 10) |

$ weight \leq W \\\\
tot\_weight \leq W \\\\
bound > max\_benefit \\\\ $



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/images/bound1.png?raw=true" alt="bound1" style="zoom:50%;" />



##### 2. i = 1

1번 아이템 (40, 2)



(1,1): 1번 아이템 선택O

|       | benefit | weight | max_benefit      | tot_weight | bound                          |
| ----- | ------- | ------ | ---------------- | ---------- | ------------------------------ |
| (1,1) | 40      | 2      | 40 (max (40, 0)) | 7  (2 + 5) | $110 (40 +30 + (16-7)*50 / 10) |

$ weight \leq W \\\\
tot\_weight \leq W \\\\
bound > max\_benefit \\\\ $



(1, 2): 1번 아이템 선택X

|       | benefit | weight | max_benefit | tot_weight      | bound                                |
| ----- | ------- | ------ | ----------- | --------------- | ------------------------------------ |
| (0,0) | 0       | 0      | 0           | 15 (0 + (5+10)) | $82 (0 + (30 + 50) + (16-15)*10 / 5) |

$ weight \leq W \\\\
tot\_weight \leq W \\\\
bound > max\_benefit \\\\ $



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/images/bound2.png?raw=true" alt="bound2" style="zoom:50%;" />



두 노드 모두 promising하지만 (1,1)의 bound가 더 크므로 (1,1)을 선택한다.







##### 3. i = 2

2번 아이템 (30, 5)



(2,1): 1번 아이템 선택O, 2번 아이템 선택O

|       | benefit | weight | max_benefit | tot_weight | bound                          |
| ----- | ------- | ------ | ----------- | ---------- | ------------------------------ |
| (2,1) | 70      | 7      | 70          | 7          | $110 (40 + 30 + (16-7)*10 / 5) |

$ weight \leq W \\\\
tot\_weight \leq W \\\\
bound > max\_benefit \\\\ $



(2,2): 1번 아이템 선택O, 2번 아이템 선택X

|       | benefit | weight | max_benefit | tot_weight  | bound                           |
| ----- | ------- | ------ | ----------- | ----------- | ------------------------------- |
| (2,2) | 40      | 2      | 40          | 12 (2 + 10) | $98 (40 + 50 + (16-12)*10 / 5 ) |

$ weight \leq W \\\\
tot\_weight \leq W \\\\
bound > max\_benefit \\\\ $

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/images/bound3.png?raw=true" alt="bound3" style="zoom:50%;" />

(1,2) (2,1) (2,2) 중에  bound가 가장 높은 (2, 1)을 선택한다.







##### 4. i = 3

3번 아이템 (50, 10)



(3,1): 1번 아이템 선택O, 2번 아이템 선택O, 3번 아이템 선택O

|       | benefit | weight | max_benefit | tot_weight | bound |
| ----- | ------- | ------ | ----------- | ---------- | ----- |
| (3,1) | 120     | 17     | 70          | 17         | $0    |

$ weight \geq W \\\\
tot\_weight \geq W \\\\
bound > max\_benefit \\\\ $

**weight > W 이므로 이 노드는 non-promsing하다.**





(3,2): 1번 아이템 선택O, 2번 아이템 선택O, 3번 아이템 선택X

|       | benefit | weight | max_benefit | tot_weight | bound                         |
| ----- | ------- | ------ | ----------- | ---------- | ----------------------------- |
| (3,2) | 70      | 7      | 70          | 7          | $80 (40 + 30 + (16-7)*10 / 5) |

$ weight \leq W \\\\
tot\_weight \leq W \\\\
bound > max\_benefit \\\\ $



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/images/bound4.png?raw=true" alt="bound4" style="zoom:50%;" />



(3, 1)은 non-promising하고 (2, 2), (3, 2)에서  bound가 높은 (2, 2)를 선택한다.





(3, 3): 1번 아이템 선택O, 2번 아이템 선택X, 3번 아이템 선택O

|       | benefit | weight | max_benefit | tot_weight | bound                      |
| ----- | ------- | ------ | ----------- | ---------- | -------------------------- |
| (3,3) | 90      | 12     | 90          | 12         | $98 (90 + (16-12)*10 / 5 ) |

$ weight \leq W \\\\
tot\_weight \leq W \\\\
bound > max\_benefit \\\\ $



(3, 4): 1번 아이템 선택O, 2번 아이템 선택X, 3번 아이템 선택X

|       | benefit | weight | max_benefit | tot_weight  | bound                      |
| ----- | ------- | ------ | ----------- | ----------- | -------------------------- |
| (3,4) | 40      | 2      | 90          | 12 (2 + 10) | $50 (40 + (16-12)*10 / 5 ) |

$ weight \leq W \\\\
tot\_weight \leq W \\\\
bound \geq max\_benefit \\\\ $



**bound <= max_benefit 이므로 이 노드는 non-promising 하다.**



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/images/bound5.png?raw=true" alt="bound5" style="zoom:50%;" />







##### 5. i = 4

4번 아이템 (10, 5)



(4,3): 1번 아이템 선택O, 2번 아이템 선택X, 3번 아이템 선택O, 4번 아이템 선택O

|       | benefit | weight | max_benefit | tot_weight | bound |
| ----- | ------- | ------ | ----------- | ---------- | ----- |
| (4,3) | 100     | 17     | 90          | 17         | $0    |

$ weight \geq W \\\\
tot\_weight \geq W \\\\
bound > max\_benefit \\\\ $



**weight > W 이므로 이 노드는 non-promsing하다.**



(4,4): 1번 아이템 선택O, 2번 아이템 선택X, 3번 아이템 선택O, 4번 아이템 선택X

|       | benefit | weight | max_benefit | tot_weight  | bound                      |
| ----- | ------- | ------ | ----------- | ----------- | -------------------------- |
| (4,4) | 90      | 2      | 90          | 12 (2 + 10) | $50 (40 + (16-12)*10 / 5 ) |

$ weight \leq W \\\\
tot\_weight \leq W \\\\
bound \leq max\_benefit \\\\ $



**bound <= max_benefit 이므로 이 노드는 non-promising 하다.**



<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/images/bound6.png?raw=true" alt="bound6" style="zoom:50%;" />







따라서 정점 (3,3)의 max_benefit은 $90입니다. 즉, O1, O3 선택

