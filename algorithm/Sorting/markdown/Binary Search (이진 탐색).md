# Binary Search (이진 탐색)

### 설계 디자인

![img](https://t1.daumcdn.net/cfile/tistory/2352D44B51A1D9A725)

 **정렬된 배열**에서 이진 탐색(Binary Search) 알고리즘을 사용해 보자

8을 찾는다고 가정하면,



1. 데이터 집합의 중앙 요소를 선택한다.

![img](https://t1.daumcdn.net/cfile/tistory/01022A4D51A1D9DB15)



2.  중앙 요소의 값과 찾으려는 값을 서로 비교하게 되는데, 

   만약 찾으려는 값이 중앙 요소의 값보다 작다면 중앙 요소의 왼편에서 중앙 요소를 다시 선택하고, 

   반대로 찾으려는 값이 중앙 요소의 값보다 크다면 오른편에서 중앙 요소를 다시 선택한다. 

   그리고 다시 이진 탐색(Binary Search)를 반복한다. 위의 경우에는 찾으려는 값인 8이 중앙값 7보다 크므로 7기준 오른편에서 중앙값을 다시 선택한다.

![img](https://t1.daumcdn.net/cfile/tistory/027A584951A1DAE72F)

이제는 중앙값이 9이고,  찾으려는 값 8은 중앙값 9보다 작으므로 중앙값 왼편을 검색한다.



![img](https://t1.daumcdn.net/cfile/tistory/0178F44951A1DB5A31)

남은 데이터 8이 중앙값으로 선택되고 찾으려는 데이터와 값과 일치하므로 탐색을 끝낸다.



### 탐색 실패 케이스

채워보세요 ^^ 어떤 경우에 실패를 할까요?





### 시간 복잡도: log<sub>2</sub>(N)

 한번 비교가 이루어질때마다, 범위는 1/2로 줄어든다. 즉 데이터 집합의 크기를 n으로 두고, 반복 횟수를 k로 둔다면 아래와 같은 수식이 만들어진다.

![img](https://t1.daumcdn.net/cfile/tistory/23546A4851A1DE8B11)

![img](https://t1.daumcdn.net/cfile/tistory/22232C4951A1E02811)



### 구현

1. 반복문을 통한 구현

```c++
bool BinarySearch(int *arr, int length, int target) {
    int start = 0;
    int end = length - 1;
    int mid;
    
    while (end - start >= 0) {
        mid = (start + end) / 2;
        
        // target 값을 찾았을 때
        if (arr[mid] == key) return true;
        
        // target 값이 mid의 값보다 작을 때 (mid 기준으로 왼쪽 배열 탐색)
        else if (arr[mid] > key) end = mid - 1;
        
        // // target 값이 mid의 값보다 클 때 (mid 기준으로 오른쪽 배열 탐색)
        else start = mid + 1;
    }
    
    // target 검색 실패
    return false;
}
```



2. 재귀를 사용한 구현

```c++
bool BinarySearch(int *arr, int start, int end, int, target) {
    if (start > end) return false;
    
    int mid = (start + end) / 2;
    
    if (arr[mid] == target) return true;
    else if (arr[mid] > target) return BinarySearch(arr, start, mid-1, target);
    else return BinarySearch(arr, mid + 1, end, target);
}
```



3. C++ STL 사용

```c++
template <class ForwardIterator, class T>
	bool binary_search(FowardIterator fist, ForwardIterator last, const T& value);
```



```c++
#include <algorithm>
#include <iosteram>

// example
int	main() {
    int arr[100];
    
    for (int i = 0; i < 100; i++) {
        arr[i] = i;
    }
    
    cout << "exist: " << binary_search(arr, arr+100, 70) << "\n";
    return 0;
    
}
```



