## String Matching



#### Notation & Terminology

-  T [1 .. n]: n개의 문자의 텍스트
- P [1 .. m]: m개의 문자의 패턴
- 1≤ j ≤m에 대해 T[s+j] = p[j]인 경우 T에서 시프트 s와 함께 P가 발생합니다.
- P가 T의 시프트 s와 함께 발생하면 s를 유효한 시프트라고 합니다. 그렇지 않으면 잘못된 시프트입니다.

![image-20210726163541372](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210726163541372.png?raw=true)







### Navie algorithm

패턴을 한칸을 옮기며 텍스트가 끝날 때 까지 비교해 보는 방식



![image-20210726163734960](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210726163734960.png?raw=true)



![image-20210726163831730](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210726163831730.png?raw=true)





![image-20210726163859011](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210726163859011.png?raw=true)

![image-20210726163541372](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210726163541372.png?raw=true)



![image-20210726163938318](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210726163938318.png?raw=true)



#### 의사코드

```pseudocode
Navie-String-Matching (T, P)
  n <- |T|
  m <- |P|
  for s<-0 to n-m
    do if P[1..m] = T[s+1..s+m]
      then print "P occurs with shift" s
```



#### 시간복잡도

$ (O (n-m+1)*m) $


shift가 발생했을 때의 정보가 다음번 shift에 전혀 사용되지 않으므로 비효율적입니다.




#### C++ code

```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
  string T, P;
  cin >> T >> P;

  int n = T.length();
  int m = P.length();

  for (int s = 0; s < n-m; s++) {
    int count = 0;
    for (int i = 0; i < m; i++) {
      if (T[s+i] != P[i]) continue;
      else count++; 
    }

    if (count == m) printf("P found in T at [%d..%d]\n", s, s+m-1);
  }
  
 return 0; 
}
```





### Rabin-Karp algorithm

길이가 m인 문자열을 m자리 숫자로 취급하는 것

- P[1..m]: m자리 수 정수 p로 치환
- 부분문자열 T[s+1 .. s+m]: m자리 수 정수 $t_s$로 치환

문자열 매칭 문제를 숫자비교 문제로 치환하는데 의의가 있다.



Ex) $ \sum = \\{ 0, 1, 2, ..., 9 \\} $, P[1 .. m] = 31425 일 때, p = 31, 425

![image-20210726171438453](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210726171438453.png?raw=true)



#### **String to Number**

- $ t_0 $: Horner's rule

$ p = P[m] +10(P[m-1] + 10(P[m-2] + .... + 10(P[2] + 10P[1]) ... ) ) $



Ex) P[1..m] = 31425,  p= 5+10(2+10(4+10( 1+10(3) ) ) ) = 31,425



- $ t_1 - t_{n-m} $ : $t_s$를 빨리 계산하는 방법

$ t_{s+1} = 10\*(t_s - 10^{m-1}*T[s+1]) +T[s+m+1] $



ex) s = 7,  $t_7$=31415일 때, 

$t_{7+1}$ = 10*(31415 - 10000\*3) + 2 = 14152 ($ \because T[s+5+1] = 2 $)





##### 시간복잡도

- p, $t_0$를 계산하는 비용: $ \theta(m) $

- $t_1, ... , t{n-m}$을 계산하는 비용: $\theta(n-m) \ or \ \theta(n) $



m이 매우 작다면 p와 $t_s$를 구하는데 상수의 시간이 걸리겠지만 큰 경우에는 시간이 꽤 걸린다. 따라서 나머지연산의 성질까지 이용해주면 아주 좋다.



#### modulo operation

두 수를 비교할 때, 직접 두수를 비교하지 않고 나머지연산을 통해 비교할 수 있다.

하지만 $ t_s \equiv p (mod \ q) $가 $t_s = p$를 항상 보장하지는 않는다.

- valid: $ t_s \equiv p (mod q) $ and $t_s = p$
- spurious hit: $ t_s \equiv p (mod q) $가 $t_s \not= p$

=> $ t_s \not= p (mod q) $이면 절대로 $t_s = p$는 될 수 없다.

여기서 q는 **적당한 소수**를 선택한다.



따라서 $t_s$ 를 구성할 때 modulo operation을 거친 값으로 구성한다.

![image-20210726173848283](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210726173848283.png?raw=true)



- s = 7 일때: T[7 .. 11] = P (valid match)
- s = 13 일때: T[13 .. 17] $ \not= $ P (invalid, spurious hit)





#### 시간복잡도

$ \theta (m) $ : 전처리과정 (p와 $t_0$ 계산)

$ \theta((n-m+1)*m) $: worst case

- $ \theta(n-m+1) $: p = $t_s$를 찾는데 걸리는 시간
- $ \theta(m) $: 유효한 s를 검증하는 시간





#### C++ 코드

```c++
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

int t[100], moduloT[100];

int main() {
    string T, P;
    cin >> T >> P;

    int n = T.length();
    int m = P.length();
    int p = 13;


    // t_0 구하기
    for (int i = 0; i < m; i++)
        t[0] += (T[i]-48)*(pow(10, m-i-1));

    // t_s (1~n-m)구하기
    for (int i = 1; i <= n-m; i++) {
        t[i] = 10*(t[i-1] - pow(10, m-1)*(T[i-1]-48)) + (T[i+m-1]-48);
    }

    // modulo
    for (int i = 0; i <= n-m; i++) {
        moduloT[i] = t[i]%p;
    }

    // 패턴 숫자로 바꿔주고 나머지연산
    int intP = stoi(P);
    int moduleP = intP % p;

    // 나머지 비교
    for (int i = 0; i <= n-m; i++)
        if (moduleP == moduloT[i]) {
            if (intP == t[i]) printf("hit at [%d ... %d]\n", i+1, i+m);
            else printf("spurious hit at [%d ... %d]\n", i+1, i+m);     
        }

    return 0;

}
```


