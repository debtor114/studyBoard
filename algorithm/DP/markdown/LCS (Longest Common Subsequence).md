# LCS (Longest Common Subsequence)

### Substring vs Subsequence

- substring: 연속되고 진행 순서도 맞는 부분 문자열 

- subsequence: 연속적이지는 않지만 진행 순서는 맞는 부분 문자열

  ex) Iamhungry

   substring: "mhun"

  subsequence: "mugy"



### LCS의 길이 구하기

예시로 설명하는게 편하기 때문에 예시를 하나 들어보겠다. 

문자열 `ACAYKP`와 `CAPCAK`가 있다고 가정해보자.

 `ACAYKP` 를 기준 string으로, `CAPCAK`를  비교 String으로 두자. 

그렇다면, 아래의 표와 같은 모양이 생성된다. 

첫 번째로 할일은 문자열 맨 앞에 0을 추가해 첫번째 행과 열을 모두  0으로 만드는 것이다.

이유는 나중에 LCS를 찾을 때 0이 되면 반복문을 종료하기 위해서이다.

| 여기가 (0,0) | 0    | A       | C    | A    | Y    | K    | P    |
| ------------ | ---- | ------- | ---- | ---- | ---- | ---- | ---- |
| 0            | 0    | 0       | 0    | 0    | 0    | 0    | 0    |
| C            | 0    | `(2,2)` |      |      |      |      |      |
| A            | 0    |         |      |      |      |      |      |
| P            | 0    |         |      |      |      |      |      |
| C            | 0    |         |      |      |      |      |      |
| A            | 0    |         |      |      |      |      |      |
| K            | 0    |         |      |      |      |      |      |



그렇다면 기준 문자열(`ACAYKP`)의 `A`와 비교문자열(`CAPCAK`)의 `C`가 만나는 지점 (2,2)이 의미하는 바가 무엇일까? 

`ACAYKP`에서 첫 번째 `A `까지 `CAPCAK`에서 첫 번째 `C`까지 비교했을 때 LCS의 갯수를 뜻한다. 여기선 공통 문자열이 없으니 0이다.

반복적으로 기준 문자열(`ACAYKP`)의 `C`와 비교문자열(`CAPCAK`)의 `C`가 만나는 지점(2,3)은 `AC`와 `C`의 LCS를 뜻하니 1개가 된다.

| (0,0) | 0    | A    | C    | A    | Y    | K    | P    |
| ----- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 0     | 0    | 0    | 0    | 0    | 0    | 0    | 0    |
| C     | 0    | 0    | 1    | 1    | 1    | 1    | 1    |
| A     | 0    |      |      |      |      |      |      |
| P     | 0    |      |      |      |      |      |      |
| C     | 0    |      |      |      |      |      |      |
| A     | 0    |      |      |      |      |      |      |
| K     | 0    |      |      |      |      |      |      |



같은 방식으로 표를 좀 더 채워보자

| (0,0) | 0    | A    | C    | A             | Y    | K    | P    |
| ----- | ---- | ---- | ---- | ------------- | ---- | ---- | ---- |
| 0     | 0    | 0    | 0    | 0             | 0    | 0    | 0    |
| C     | 0    | 0    | 1    | 1             | 1    | 1    | 1    |
| A     | 0    | 1    | 1    | **2** `(3,4)` | 2    | 2    | 2    |
| P     | 0    | 1    | 1    | **2** `(4,4)` | 2    | 2    | 3    |
| C     | 0    |      |      |               |      |      |      |
| A     | 0    |      |      |               |      |      |      |
| K     | 0    |      |      |               |      |      |      |

몇 번의 반복과정 끝에 우리는 규칙을 찾았다. 

**가로줄은 이전 행의 값을 기반으로 해서 계산된다.** 

규칙은 이러하다.

1. **같은 문자가 나오는 경우**

 이전까지의 LCS의 길이(왼쪽 위 대각선) +1 

Why? 두 문자열에서 해당 두 문자를 비교하기 전의 LCS의 길이에 +1을 하기 위해서 이다. 

EX) **2**`(3,4)`: `ACAYKP`의 `ACA`와 `CAPCAK` 의`CA`의 LCS 

`ACAYKP`의 부분 문자열인` AC` 다음에 오는 `A`와 

`CAPCAK` 의 부분 문자열인  `C`다음에 오는 `A`를 봤을 때, 

비로소 LCS가 2이 된 것이 정확한 의미이기에 대각선(왼쪽 위) 방향인 값에서 1을 더해야 한다.



2. **다른 문자가 나오는 경우**

표에서 **위쪽**과 **왼쪽** 값중 큰 값을 사용한다. 

Why?

Ex) **2**`(4, 4)`:  `ACAYKP`의 `ACA`와 `CAPCAK` 의`CAP`의 LCS

`ACA`의 `A`와 `CAP`의 `P`는 다르기 때문에,

`ACA`와 `CA`의 LCS의 길이(2)와 `AC`와 `CAP`의 LCS의 길이(1) 중 큰 값이 오게된다. 



위의 두 규칙을 사용해서 나머지 표를 완성해보자

| (0,0) | 0    | A    | C    | A    | Y    | K    | P    |
| ----- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 0     | 0    | 0    | 0    | 0    | 0    | 0    | 0    |
| C     | 0    | 0    | 1    | 1    | 1    | 1    | 1    |
| A     | 0    | 1    | 1    | 2    | 2    | 2    | 2    |
| P     | 0    | 1    | 1    | 2    | 2    | 2    | 3    |
| C     | 0    | 1    | 2    | 2    | 2    | 2    | 3    |
| A     | 0    | 1    | 2    | 3    | 3    | 3    | 3    |
| K     | 0    | 1    | 2    | 3    | 3    | 4    | 4    |

표를 모두 완성하면 마지막 배열 (7, 7)의 값을 구할 수 있고 두 스트링의 LCS length는 4 라는 것을 알 수 있다.





### LCS 찾기

완성된 테이블로 찾아 갈 수 있다. 

각 구간에서 LCS의 증가 조건은 기준 문자열(`ACAYKP`)의 n번째 문자와 비교 문자열(`CAPCAK`)의 m번째 문자가 같을 때라고 하였다. (n, m은 임의의 수)

즉, 위쪽과 왼쪽 숫자가 자신보다 모두 작은 경우, 왼쪽 대각선 값+1을 해서 증가되었다는 사실을 알 수 있다. 

그 숫자가 0이 되기 전까지 반복적으로 찾아나가고 그런 경우를 모두 찾아서 조합하면

![graph.png](https://github.com/doooooooong/studyBoard/blob/master/algorithm/DP/images/LCS_string.png?raw=true)

K (7, 6), A (6, 4), C (5, 3), A (3, 2)

테이블 특성상 거꾸로 되므로 ACAK가 LCS가 되겠다.



### 구현 (C++) (바로 읽지 말고 직접 위의 논리대로 구현해볼것)

```c++
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;

    int memo[1001][1001];

    cin >> s1 >> s2;

    // LCS Algorithm
    s1 = "0" + s1;
    s2 = "0" + s2;
    for (int i = 0; i < s1.length(); i++) {
        for (int j = 0; j < s2.length(); j++) {
            if (i == 0 || j == 0) {
                memo[i][j] = 0;
                continue;
            }

            if (s1[i] == s2[j])  memo[i][j] = memo[i-1][j-1] + 1;
            else  memo[i][j] = max(memo[i-1][j], memo[i][j-1]);

        }
    }

    // Print LCS table
    printf("  ");
    for (int i = 0; i < s1.length(); i++) {
        if (i == 0) {
            for (int k = 0; k < s1.length(); k++)
                printf("%c ", s1[k]);

            printf("\n");
        }
        
        for (int j = 0; j < s2.length(); j++) {
            if (j == 0) printf("%c ", s2[i]);
            printf("%d ", memo[i][j]);
        }
        printf("\n");
    }

    // Find LCS string
    string LCS;
    int x = s1.length()-1;
    int y = s2.length()-1;
    int LCS_length = memo[x][y];

    while (LCS_length != 0) {
        if (memo[x-1][y] == LCS_length) x--;
        else if (memo[x][y-1] == LCS_length)  y--;
        else {
            LCS.push_back(s1[x] == s2[x] ? s1[x] : s2[y]);
            x--, y--;
            LCS_length--;
        }
    }

    // Print LCS string
    for (int i = LCS.length() - 1; i >= 0; i--)
        printf("%c", LCS[i]);

    printf("\n");
    return 0;

}
```



