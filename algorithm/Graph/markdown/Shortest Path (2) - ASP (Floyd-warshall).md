## 2. All Pairs Shortest Path

모든 정점에 대해 최단경로를 찾으려면 앞서 살펴본 다익스트라, 벨만포드 알고리즘을 정점의 갯수만큼 반복하면 될 것이다. 그렇다면 시간복잡도는 아래와 같다.

- Dijkstra: $ O (V \log V + E) \to O (V^2 \log V + VE) \because V \to V^2 \\
  on \ dense \ graph, \ O(V^3) \because E = V^2 $

  

- Bellman-Ford: $ O (V*E) \to O (V^2 *E) \because V \to V^2 \\
  on \ dense \ graph, \ O(V^4) \because E = V^2 $



너무 느린것 같다. 그래서 플로이드와 와샬이란 사람이 새로운 알고리즘을 제시했다.



### Floyd-Warshall Algorithm



#### 개요

- 음의 가중치 간선 허용
- 음의 가중치 사이클은 없다고 가정한다.
- 다이나믹 프로그래밍 패러다임





#### 설계

다이나믹 프로그래밍 패러다임

 i에서 j까지 갈 때 **다이렉트로 가는게 더 비용이 적은가** 아니면 **i와 j사이에 있는 어떤 정점 k를 들렀다 가는 것이 더 비용이 적은가** 비교하며 값을 저장하는 과정이다. 그리고 그 와중에 어떻게 다이나믹 프로그래밍을 접목시키는지 논리적으로 전개하는 과정이다.

출발점은 i, 도착점은 j라고 약속한다.



##### Intermediate vertex

경로 p ($ <v_1, ..., v_L> $)에서 $ v_1, v_L $을 제외한 모든 정점 ( $ \\{ v_2, ... v_{L-1} \\} $ )







1에서 N까지 번호가 매겨진 V를 정점 집합으로 갖는 그래프 G가 있다고 가정하자.

**shortestPath(i, j, k)**: i에서 j로 집합 {1, 2, ..., k} 의 꼭짓점들 만을 경유지로 거쳐 가는 최단 경로를 반환하는 함수



함수가 주어졌을 때, 목표는 {1, 2, ..., N} 에 있는 꼭짓점만을 이용해서 모든 꼭지점 i에서 모든 꼭짓점 j로 가는 최단 경로를 찾는 것이다.



각각 (i, j, k) 쌍에 대하여 **shortestPath(i, j, k)**는 다음 중 한개이다.

- Case1: k를 중간 정점으로 갖지 않는 경로 ( 집합 {1, ...., k-1}에 있는 꼭짓점만 거쳐간다.)

- Case2: k를 중간 정점으로 갖는 경로 i에서 k까지와, k에서 j까지 가는 경로 모두 {1, 2, ...., k-1}에 있는 꼭짓점만을 거쳐간다.



i에서 j까지 1에서 k-1의 꼭짓점 만을 거쳐가는 경로 중 최선의 경로는 shortestPath(i, j, k-1)에 의해 정의되고 만약 i에서 k를 거쳐 j로 가는 더 나은 경로가 있다면, 그 경로는 i에서 k까지 ({1, ..., k-1}만 거쳐서) 가는 경로와 k에서 j까지 ({1, ..., k-1}만 거쳐서) 가는 경로를 합친 것이라는 것은 자명하다.



![image-20210726154217746](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210726154217746.png?raw=true)





##### Recursive Solution

shortestPath(i, j, k)를 $ d_{ij}^{(k)} $로 정의하자.

w(i, j)를 i와 j간의 변의 가중치라면 shortestPath(i, j, k)를 다음의 재귀적 공식으로 정의할 수 있다.

- 기본적인 경우는 $ d_{ij}^{(0)}  = w(i, j) $

- 재귀적인 경우는 $ d_{ij}^{(k)} $ = min(shorestPath(i, j, k-1), shortestPath(i, k, k-1) + shortestPath(k, j, k-1))

$ d\_{ij}^{(k)} = \left\\{\begin{matrix} w\_{ij}& (k =0) \\\  min(d\_{ij}^{(k-1)}, d\_{ik}^{(k-1)}+d_{kj}^{(k-1)})& (k \geq 1) \\\  \end{matrix}\right. $





이 공식은 플로이드-워셜 알고리즘의 핵심이다. 이 알고리즘은 처음에 모든 (i, j) 쌍에 대해서 k = 1일 때 shortestPath(i, j, k)를 계산하고 다음으로 k=2일 때를 계산하는 식으로 k=N이 될 때까지 계속하면, 모든 (i, j) 쌍에 대해서 최단 경로를 찾게 된다.



##### pred[i, j] (predecessor pointers): **i에서 j로 가는 경로의 중간 정점**



모든 pred[i, j]는 초기엔 nil 값으로 설정된다.

중간 정점 k를 지나는 i에서 j까지의 최단 경로가 발견될 때마다 pred[i,j] = k로 설정합니다.

- pred[i, j] = nil: 최단 경로가 존재하지 않는다.
- pred[i,j] = i: 최단 경로가 존재하고 최단 경로에 중간 정점이 없는경우, 즉 최단거리는 간선 (i, j)이다.

- pred[i,j] = k: 최단 경로가 존재하고 k는 i에서 j까지의 중간 정점



- pred[i,j] = i: 최단거리는 간선 (i, j)이다.

- pred[i, j] = i가 아닌 경우: (i, pred[i, j]) 와 (pred[i, j], j)를 재귀적으로 계산한다.

```pseudocode
Floyd-Warshall (w, n) {

	let dist be a |n| × |n| array of minimum distances initialized to ∞ (infinity)
	
	// initialize
	for i = 1 to n 
		for j = 1 to n
			do D(0)[i,j] = w[i,j];
			if (i == j) pred[i, j] = i;
			else pred[i,j] = NIL;
	
			

	for k = 1 to n
		for i = 1 to n
			for j = 1 to n
				if (d(k-1)[i,k] + d(k-1)[k,j] < d(k-1)[i,j]) {	// case 2
					d(k)[i,j] = d(k-1)[i,k] + d(k-1)[k, j];
          pred[i, j] = k;
				}
				
				else d(k)[i,j] = d(k-1)[i, j];									// case 1
				
				
	return d(n)[1...n, 1...n];
}
```





#### 동작

![image-20210730144122604](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730144122604.png?raw=true)





![image-20210730144324607](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730144324607.png?raw=true)



![image-20210730144431816](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730144431816.png?raw=true)



![image-20210730144510949](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730144510949.png?raw=true)

1번 정점에서 0번 정점을 중간정점으로 3번 정점으로 가니까 더 가중치가 낮은 간선이 되었으므로 업데이트 한다.



![image-20210730144732576](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730144732576.png?raw=true)



![image-20210730144805992](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730144805992.png?raw=true)

3번에서 0번으로 가는 간선이 없으므로 아무일도 일어나지 않았다.



![image-20210730144857788](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730144857788.png?raw=true)

0번에서 1번으로 가는 간선이 없으므로 아무일도 일어나지 않았다.



![image-20210730144936753](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730144936753.png?raw=true)



![image-20210730145255980](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730145255980.png?raw=true)



2번에서 1번으로 가는 간선이 없으므로 아무일도 일어나지 않았다.



![image-20210730145412318](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730145412318.png?raw=true)



![image-20210730145515182](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730145515182.png?raw=true)



![image-20210730145809133](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730145809133.png?raw=true)

아무일도 없었고요



![image-20210730145844593](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730145844593.png?raw=true)



![image-20210730150103426](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730150103426.png?raw=true)



![image-20210730150332746](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730150332746.png?raw=true)

![image-20210730150357665](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730150357665.png?raw=true)

3번에서 2번으로 가는 간선이 없으므로 아무일도 일어나지 않았다.



![image-20210730150530803](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730150530803.png?raw=true)

![image-20210730150643803](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Graph/images/image-20210730150643803.png?raw=true)



귀찮아서 못했는데 경로 가중치가 업데이트 될때마다 `pred[i][j] = k` 로 업데이트 하면 경로복원도 가능하다.



#### Negative cycle

**i번 노드에 대해 dist\[i][i] = 0으로 초기화**했었다.

자기 자신에서 출발해 자기 자신에게 돌아오는 경로의 가중치는 절대 0보다 작아질 수 없기 때문이다.

하지만 그래프에 음의 사이클이 존재한다면, 그 사이클에 포함된 노드를 k라 했을 때 dist\[k][k]가 음수 값을 가지게 된다.

따라서, 플로이드 알고리즘을 적용한 후,

**모든 노드의 번호 i에 대해 dist\[i][i]가 0인지 확인해줌으로써 음의 사이클 존재 여부를 판단**할 수 있다.





#### C++ 코드

```c++
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
 
#define INF 99999999
 
using namespace std;

int d[1000][1000];
int V, E;
 

void floyd() {    
    // k = 중간정점
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                //if (i == k || j == k) continue;
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}

 
int main() {

    //init 

    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            d[i][j] = INF;
        }
    }
 
    for (int i = 1; i <= V; i++) 
        d[i][i] = 0;


    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        d[u][v] = w;
    }


    floyd();

    // print distance
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (d[i][j] == INF) printf("- ");
            else printf("%d ", d[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}


```





#### 시간복잡도: $ \theta (|V|^3) $





#### cf> Transitive closure (공사중)

원하는 정점이 서로 직접 혹은 간접적으로 연결되어 있냐를 확인하는 그래프



```
• 주어진 방향 그래프 G = (V, E)
• 계산 G* = (V, E* )
• E* = {(i,j) : G에 i에서 j까지의 경로가 있음}
• 각 가장자리에 1의 가중치를 할당한 다음 FLOYD-WARSHALL을 실행할 수 있습니다.
• dij < n이면 i에서 j까지의 경로가 있습니다.
• 그렇지 않으면 dij = INF이고 경로가 없습니다.


논리 연산 (OR), (AND) 사용
• 각 모서리에 가중치 1을 할당한 다음 이 가중치로 FLOYD-WARSHALL을 실행합니다.


```



$ D^{(k)} $ 대신 $ T^{(k)} = (t_{ij}^{(k)}) $ 를 사용한다.

$ t_{ij}^{(0)} = \left\\{\begin{matrix} 0 & i\not= j \ and \ (i, j) \notin E \\\ 1 & i=j\ or \ (i, j) \in E \end {matrix}\right. \\\ t\_{ij}^{(k)} = \left\\{\begin{matrix} 1 \ \ \ (if \ there \ is \ a \ path \ from \ i \ to \ j \ with \ all \ intermediate \ vertices \ in \ \{1, 2,3, ..., k\}) \\\ = (t\_{ij}^{k-1} = 1) \ or (t\_{ik}^{(k-1)} = 1 \ and \ t\_{kj}^{k-1}=1) \\\ 0 \ (otherwise) \end {matrix}\right. $






```pseudocode
TRANSITIVE-CLOSURE(E, n) 

for i = 1 to n
	for j = 1 to n
		if (i=j or (i, j) in E) then tij(0) = 1 
		else tij(0) = 0

for k = 1 to n
	for i = 1 to n
		for j = 1 to n
			tij(k) = tij(k-1) or (tik(k-1) and tkj(k-1))

return T(n)
```



