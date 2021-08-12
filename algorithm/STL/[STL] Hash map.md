## [STL] Hash map, Unordered_map



#### hash_map의 자료구조

hash_map의 자료구조는 해시 테이블입니다. 해시 테이블에 자료를 저장할 떄는 key 값을 해시 함수에 대입하여 버킷번호가 나오면 그 버킷의 빈 슬롯에 자료를 저장합니다. 많은 자료를 저장해도 삽입, 삭제, 검색 속도가 거의 일정합니다.

하지만 이 헤더파일은 STL 표준이 아니므로 사용이 불가한 환경이 있다. 내 맥북에선 컴파일이 안된다.. 

대안은 비슷한 unordered_map을 써주면 된다.





#### hash_map을 사용하는 경우

- 많은 자료를 저장하고, 검색 속도가 빨라야 한다.
- 빈번하게 자료를 삽입, 삭제 하지 않는다.





#### Unordered_map 사용방법

```c++
#include <unordered_map>

using namespace std;

unordered_map <int, int> hm;
```





#### hash_map 사용방법

```c++
// hash_map은 STL 표준이 아니다!

#include <hash_map>

using namespace stdext;

hash_map <int, int> hm;
```









#### 메소드 

| **멤버**    | **설명**                                                   |
| ----------- | ---------------------------------------------------------- |
| begin       | 첫 번째 원소의 랜덤 접근 반복자를 반환                     |
| clear       | 저장한 모든 원소를 삭제                                    |
| empty       | 저장한 요소가 없으면 true 반환                             |
| end         | 마지막 원소 다음의(미 사용 영역) 반복자를 반환             |
| erase       | 특정 위치의 원소나 지정 범위의 원소들을 삭제               |
| find        | Key와 연관된 원소의 반복자 반환                            |
| insert      | 원소 추가                                                  |
| lower_bound | 지정한 Key의 요소가 있다면 해당 위치의 반복자를 반환       |
| rbegin      | 역방향으로 첫 번째 원소의 반복자를 반환                    |
| rend        | 역방향으로 마지막 원소 다음의 반복자를 반환                |
| size        | 원소의 개수를 반환                                         |
| upper_bound | 지정한 Key 요소가 있다면 해당 위치 다음 위치의 반복자 반환 |







#### 예제코드

```c++
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

unordered_map <string, int> hm;

int main() {
  hm.insert(make_pair("james", 1));
  hm.insert(make_pair("sujan", 11));
  hm.insert(make_pair("ace", 111));
  hm.insert(make_pair("homa", 1111));
  
  
  for (auto iter : hm) 
    cout << "name: " << iter.first << ", counts: " << iter.second << "\n";
  
  return 0;
  
}
```


