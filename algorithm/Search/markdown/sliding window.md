## 슬라이딩 윈도우

배열이나 리스트의 요소의 일정 범위의 값을 비교할때 사용하면 유용한 알고리즘이다.



예를들어 정수로 이루어진 배열 [4, 25, 64, 1, 23, 2, -10, 3, 2] 에서 길이가 3인 서브배열의 합계가 가장 큰 서브배열은 무엇인가? 같은 문제에서 사용될 수 있다.

![image-20210730214715835](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Search/images/image-20210730214715835.png?raw=true)



#### 설계

하나씩 다 더해보면 아래와 같다.

**서브 배열 합계 체크 (브루트 포스)** 

```c++
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector <int> v;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }
  
    int sum, max = -1;

    for (int i = 0; i < n-k; i++) {
        sum = 0;

        for (int j = 0; j < k; j++) {
            sum += v[i+j];
        }
    
        if (max < sum) max = sum;
    }
  
    cout << "max: " << max << endl;
    return 0;
  
}
```





**중복된 요소 재사용**

서브 배열의 요소를 순회하다 보면 중복되는 요소들이 존재한다.

![image-20210730220146173](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Search/images/image-20210730220146173.png?raw=true)

범위가 3인 서브배열을 탐색하는 경우 0~2 범위의 서브배열과 1~3 범위의 서브배열은 공통적으로 1~2 범위가 중복된다. 중복되는 요소(공통 요소)들을 재사용하는 방법이 슬라이딩 윈도우 알고리즘의 핵심이다.

각 루프마다 어떤식으로 진행되는지 이미지를 보면서 이해해보자.

![image-20210730221351274](https://github.com/doooooooong/studyBoard/blob/master/algorithm/Search/images/image-20210730221351274.png?raw=true)





우선 슬라이딩 윈도우를 관리하기 위한 변수들로 window_start, window_end, window_sum 등을 사용한다.

- window_start: 슬라이딩 윈도우 시작 인덱스
- window_end: 슬라이딩 윈도우 끝 인덱스
- window_sum: 슬라이딩 윈도우 합계



슬라이딩 윈도우는 하위 윈도우의 범위 `k` 와 동일하게 유지하며 범위내의 요소는 모두 합산하고 범위 밖으로 벗어난 요소들은 빼준다.

다만 슬라이딩 윈도우의 범위가 `k` 보다 커질때까지 ( `window_end >= k - 1` ) 는 요소들을 합산하기만 하고 이후부터 범위밖의 요소들을 차감.

이렇게하면 기존처럼 매번 서브배열의 합계를 구할 필요없이 모든 요소를 1번만 순회하면서 최대값을 구하게 되므로 빠르고 효율적으로 처리된다.





#### 구현 (C++)

```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector <int> arr;
  
  int N, k;
  cin >> N >> k;
  for (int i = 0; i < N; i++) {
    int input;
    cin >> input;
    arr.push_back(input);
  }
  
    int window_sum = 0;
    int max_sum = 0;
    int window_start = 0;
  
  
  for (int window_end = 0; window_end < arr.size(); window_end++) {
    window_sum += arr[window_end];
    
    if (window_end >= k-1) {
      max_sum = max(max_sum, window_sum);
      window_sum -= arr[window_start];
      window_start += 1;
    }
  }
  
  cout << "max: " << max_sum << endl;
  return 0;
  
}
```
