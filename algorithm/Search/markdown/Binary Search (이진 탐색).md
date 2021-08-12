## Binary Search (이진 탐색)



#### 설계

이진 탐색이란 데이터가 정렬돼 있는 배열에서 특정한 값을 찾아내는 알고리즘이다. 배열의 중간에 있는 임의의 값을 선택하여 찾고자 하는 값 X와 비교한다. X가 중간 값보다 작으면 중간 값을 기준으로 좌측의 데이터들을 대상으로, X가 중간값보다 크면 배열의 우측을 대상으로 다시 탐색한다. 동일한 방법으로 다시 중간의 값을 임의로 선택하고 비교한다. 해당 값을 찾을 때까지 이 과정을 반복한다.





#### 동작

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Search/images/image-20210812180440751.png?raw=true" alt="image-20210812180440751" style="zoom:50%;" />

 **정렬된 배열**에서 이진 탐색(Binary Search) 알고리즘을 사용해 보자

13을 찾는다고 경우를 보자





i. 데이터 집합의 중앙값를 선택한다.

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Search/images/image-20210812180510985.png?raw=true" alt="image-20210812180510985" style="zoom:50%;" />



ii. 중앙 요소의 값과 찾으려는 값을 서로 비교한다.

- 찾으려는 값(13) < 중앙값(9) 이면, 중앙값(9)의 왼편에서 중앙값를 다시 선택하고, 
- 찾으려는 값(13) = 중앙값(9) 이면, 찾았으므로 함수를 종료하고,

- 찾으려는 값(13) > 중앙값(9) 이면, 중앙값(9)의 오른편에서 중앙값를 다시 선택한다.

  

이 경우는 찾으려는 값(13) > 중앙값(9) 이므로 오른편에서 중앙값을 다시 선택한다.

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Search/images/image-20210812180859090.png?raw=true" alt="image-20210812180859090" style="zoom: 43%;" />

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Search/images/image-20210812180755666.png?raw=true" alt="image-20210812180755666" style="zoom:50%;" />



그리고 다시 이진 탐색(2번 과정)을 반복한다. 위의 경우에는 찾으려는 값(13) < 중앙값(14)이므로 중앙값의 왼편에서 중앙값을 다시 선택한다.

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Search/images/image-20210812180941974.png?raw=true" alt="image-20210812180941974" style="zoom:50%;" />



iii. 찾으려는 값(13) = 중앙값(13) 이므로 탐색을 끝낸다.





##### 탐색 실패 케이스

배열의 좌측 혹은 우측을 탐색해야 하는데 더 이상 남은 배열이 존재하지 않을 경우

만약 12를 탐색하려고 했다고 가정하자

<img src="https://github.com/doooooooong/studyBoard/blob/master/algorithm/Search/images/image-20210812181941224.png?raw=true" alt="image-20210812181941224" style="zoom:50%;" />

남은 배열이 13 하나 인데 찾으려는 값(12) $\not=$ 중앙값(13)인 경우이다.

이렇게 탐색할 수 있는 배열이 더 이상 존재하지 않고, 찾으려는 값이 마지막 배열까지 없었다면,

찾으려는 값은 애초에 배열에 존재하지 않는다는 것으로 판단할 수 있고 탐색을 종료한다.





#### 구현

**반복문을 통한 구현**

```c++
int BinarySearch(int *arr, int length, int target) {
    int start = 0;
    int end = length - 1;
    int mid;
    
    while (end - start >= 0) {
        mid = (start + end) / 2;
        
        // target 값을 찾았을 때
        if (arr[mid] == key) return mid;
        
        // target 값이 mid의 값보다 작을 때 (mid 기준으로 왼쪽 배열 탐색)
        else if (arr[mid] > key) end = mid - 1;
        
        // // target 값이 mid의 값보다 클 때 (mid 기준으로 오른쪽 배열 탐색)
        else start = mid + 1;
    }
    
    // target 검색 실패
    return -1;
}
```



**재귀를 사용한 구현**

```c++
bool BinarySearch(int *arr, int start, int end, int, target) {
    if (start > end) return false;
    
    int mid = (start + end) / 2;
    
    if (arr[mid] == target) return true;
    else if (arr[mid] > target) return BinarySearch(arr, start, mid-1, target);
    else return BinarySearch(arr, mid + 1, end, target);
}
```



**C++ STL 사용**

```c++
template <class ForwardIterator, class T>
	bool binary_search(FowardIterator fist, ForwardIterator last, const T& value);
```

```c++
#include <algorithm>
#include <iosteram>
#include <vector>

// example
int	main() {
    vector <int> arr;
    
    for (int i = 0; i < 100; i++) {
        arr.push_back(i);
    }
    
    cout << "exist: " << binary_search(arr.begin(), arr.end(), 70) << "\n";
    return 0;
    
}
```





#### 시간 복잡도: log<sub>2</sub>(N)

 한번 비교가 이루어질때마다, 범위는 1/2로 줄어든다. 즉 데이터 집합의 크기를 n으로 두고, 반복 횟수를 k로 둔다면 아래와 같은 수식이 만들어진다.

$ n*(\frac{1}{2})^k = 1 \\\ n\*\frac{1}{2^k} = 1 \\\ n = 2^k \\\ k = \log_2 n $







#### 추가 예제 - N의 제곱근 구하기

양의 정수 N 이 주어졌을 때 N의 제곱근  $ \sqrt(N) $ 을 구하는 소스코드를 작성해보자. 단, 제곱근 값이 정수 일 경우에만 출력한다.

예를 들어, 

N = 100 -> 10

N = 25 -> 5

N = 10 -> -1

N = 1 -> 1 와 같이 출력한다.



단순히 생각해서 0부터 n-1 까지 자연수를 하나씩 증가시켜 가면서 확인해보면 구할 수 있을 것이다.

```c++
int squareRootLoop(int n) {
    for (int i = 0; i < n; i++)
        if (i * i == n) return i;
    return -1;
}
```

결과 값이 자연수라면 $ \sqrt(N) $ 시간 안에 금방 찾을 수 있지만 자연수가 아닌 경우는 N만큼 확인해봐야 하므로 빅오 표기법으로 O(N) 시간이 된다.

제곱근의 값은 N/2 보다 작거나 같다는 특징을 이용하여 반복문의 조건을
`for (int i=0; i<=n/2; i++)` 로 바꾸면 성능이 개선되겠지만 시간복잡도는 여전히 O(N)이다.



문제 접근을 조금 다르게 해보면 우리는 지금 0부터 N까지의 자연수 중에 N의 제곱근이 있는지 없는지를 찾아보고 있다. 즉, 0부터 N까지의 정렬된 자연수에서 특정 값을 찾고 있는 것이다. 이진 탐색을 이용하여 코드를 다시 작성한다면 시간 복잡도를 O(logN)까지 줄일 수 있을 것이다.

```c++
int squareRootBSearch(int n) {
    int min = 0;
    int max = n;
    int guess;

    while (min <= max) {
        guess = (min + max) / 2;
        if (guess * guess == n)
            return guess;
        else if (guess * guess > n)
            max = guess - 1;
        else
            min = guess + 1;
    }
    return -1;
}
```

