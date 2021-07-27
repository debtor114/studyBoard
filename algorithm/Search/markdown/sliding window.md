## 슬라이딩 윈도우

배열이나 리스트의 요소의 일정 범위의 값을 비교할때 사용하면 유용한 알고리즘이다.

실제로는 네트워크



예를들어 정수로 이루어진 배열 [2, 4, 7, 10, 8, 4, 5, 6, 7, 1] 에서 길이가 3인 서브배열의 합계가 가장 큰 서브배열은 무엇인가? 같은 문제에서 사용될 수 있다.

![서브 배열 합계 체크](https://blog.fakecoding.com/content/images/wordpress/2020/07/xScreen-Shot-2020-07-21-at-17.49.12-1024x527.png.pagespeed.ic._wWQLg-4tl.webp)

서브 배열 합계 체크

```c++
#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin >> n >> k;
  
  vector <int> v;
  for (int i = 0; i < n; i++) {
		int input
    cin >> input;
  	v.push_back(input);
  }
  
  int sum, max = -1;
  for (int i = 0; i < n-k; i++) {
    sum = 0;
    for (int j = 0; j < k; j++) {
      sum += v[i+j];
    }
    
    if (max < sum) sum = max
  }
  
  cout << "max: " << max << endl;
  return 0;
  
}


```







우선 기존 단순한 방식에서 서브 배열의 요소를 순회하다 보면 중복되는 요소들이 존재한다.

![서브배열의 공통된 요소 예시](https://blog.fakecoding.com/content/images/wordpress/2020/07/xScreen-Shot-2020-07-21-at-18.47.22.png.pagespeed.ic.l6N19VxvDW.webp)서브배열의 공통된 요소 예시

예시 이미지처럼 범위가 5인 서브배열을 탐색하는 경우 0~4 범위의 서브배열과 1~5 범위의 서브배열은 공통적으로 1~4 범위가 중복된다.

중복되는 요소(공통 요소)들을 재사용하는 방법이 있다면?

바로 이 공통 요소를 재사용 하는 방법이 슬라이딩 윈도우 알고리즘의 핵심이다.

코드를 먼저 살펴보자.

```c++
def max_sub_array(arr, k):
    int window_sum = 0
    int max_sum = 0
    int window_start = 0

    for window_end in range(len(arr)):
        window_sum += arr[window_end]  # 슬라이딩 인덱스 범위 요소 합산
        
        # 슬라이딩 윈도우의 범위가 k 보다 커진 경우
        if window_end >= (k - 1):
            max_sum = max(max_sum, window_sum)
            window_sum -= arr[window_start]  # 슬라이드 윈도우 범위를 벗어난 요소를 합계에서 제거
            window_start += 1  # 슬라이드 윈도우 시작 인덱스 증가

    return max_sum


if __name__ == '__main__':
    print(max_sub_array([2, 4, 7, 10, 8, 4], 3))

# 결과: 25 (7 + 10 + 8)
```

우선 이해를 돕기 위해 기존 배열보다 길이가 짧은 배열로 변경하였다.

각 루프마다 어떤식으로 진행되는지 이미지를 보면서 이해해보자.

![슬라이딩 알고리즘 ( 1 )](https://blog.fakecoding.com/content/images/wordpress/2020/07/xScreen-Shot-2020-07-21-at-19.51.43-1024x529.png.pagespeed.ic.nSxiGyI0Qm.webp)슬라이딩 알고리즘 ( 1 )

![슬라이딩 알고리즘  ( 2 )](https://blog.fakecoding.com/content/images/wordpress/2020/07/xScreen-Shot-2020-07-21-at-19.52.00-1024x580.png.pagespeed.ic.kluzR2-LnE.webp)슬라이딩 알고리즘 ( 2 )

우선 슬라이딩 윈도우를 관리하기 위한 변수들로 window_start, window_end, window_sum 등을 사용한다.

- window_start: 슬라이딩 윈도우 시작 인덱스
- window_end: 슬라이딩 윈도우 끝 인덱스
- widdow_sum: 슬라이딩 윈도우 합계

슬라이딩 윈도우는 하위 윈도우의 범위 `k` 와 동일하게 유지하며 범위내의 요소는 모두 합산하고 범위 밖으로 벗어난 요소들은 빼준다.

다만 슬라이딩 윈도우의 범위가 `k` 보다 커질때까지 ( `window_end >= k - 1` ) 는 요소들을 합산하기만 하고 이후부터 범위밖의 요소들을 차감.

이렇게하면 기존처럼 매번 서브배열의 합계를 구할 필요없이 모든 요소를 1번만 순회하면서 최대값을 구하게 되므로 빠르고 효율적으로 처리된다.





슬라이딩 알고리즘은 핵심은 단순합니다.

매번 처리되는 중복된 요소를 버리지 않고 재사용함으로써 낭비되는 계산을 하지 않음으로써 효율적으로 처리하는 방법입니다.

이런 문제들은 알고리즘 문제로도 출제되니 알아두셔서 문제를 쉽게 해결하는데 도움이 되셨으면 좋겠습니다.

감사합니다.





