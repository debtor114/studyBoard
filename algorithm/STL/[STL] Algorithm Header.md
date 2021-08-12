## STL - algorithm

PS에 자주 쓰이는 `#include <algorithm>`  헤더파일에서 메소드들을 정리해보았습니다.





### 1. prev_permutation, next_permutation

벡터, 어레이, 리스트 등으로 이루어진 수열을 순열로 취급하여 이전 순열 혹은 다음 순열을 보여준다. 

- 사용법: `next_permutation(Iterator first, Iterator last)`
- 시간복잡도: $ O(N) $

- return type: `boolean`, 다음 순열이 없으면 false, 있으면 true를 반환한다.



#### 예제 코드

```c++
#include <iostream>    
#include <algorithm>  
#include <vector>

using namespace std;

int main () {
  int myInts[] = { 1, 2, 3 };
  vector <int> myInt (myInts, myInts+3);


  
  do {
    for (int i = 0; i < myInt.size(); i++) {
      cout << myInt[i] << " ";''
    }
    cout << '\n';
    
  } while ( next_permutation(myInts.begin(), myInt.end()));


  return 0;
}

// 결과
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1
```





### 2. sort

Quick sort로 구현이 되있으며, comp함수를 정의해서 기준을 만들고 일반 정수 뿐만 아니라 다양한 자료구조를 sort할 수 있다.

- 사용법: `sort (Iterator first, Iterator last, Compare comp)`
- 시간복잡도: $ O(N * \log N) $

- return type: none



#### 예제 코드

```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool comp (const pair <int, int> &p1, const pair <int, int> &p2) {
  if (p1.first == p2.first) return p1.second > p2.second;
  else if (p1.first > p2.first) return p1 > p2;
  return p1 < p2;
}

int main () {
  int myInts[] = { 32, 71, 12, 45, 26, 80, 53, 33 };
  vector <int> v (myInts, myInts+8);
  
  sort(v.begin(), v.end());
  
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";

  // 결과: 12 26 32 33 45 53 71 80
  
  
  
  vector < pair <int, int> > p;
  p.push_back(make_pair(1, 2));
  p.push_back(make_pair(3, 2));
  p.push_back(make_pair(2, 3));
  p.push_back(make_pair(0, 2));
  p.push_back(make_pair(1, 3));
  p.push_back(make_pair(2, 2));
  
  
  
  // p: { (1, 2), (3, 2), (2, 3), (0, 3), (0, 2), (1, 3), (2, 2) }
  
  sort (p.begin(), p.end(), comp);
  
  for (int i = 0; i < p.size(); i++) {
    cout << p[i].first << " " << p[i].second << "\n";
  }
  
  return 0;
  
}
```







### 3. unique

제 기능을 하기 위해서는 정렬된 자료구조안에서 사용해야하며, 자료구조 안의 중복된 원소들을 가장 마지막 원소로 보낸다.

- 사용법 `unique(Iterator first, Iterator last)`
- 시간복잡도: $ O(N) $
- return type: `Iterator  `, 

중복된 원소가 시작하는 시점의 Iterator를 반환한다. 말로는 어려우니 예시를 들어보면 아래와 같다.





```c++
vector <int> v = {1, 1, 3, 4, 5, 5, 6, 7};

unique(v.begin(), v.end())
  
// 결과: v = { 1, 3, 4, 5, 6, 7, 1, 5}
//  											   		v
// 											이 부분의 Iterator를 반환한다.
```





#### 예제 코드

```c++
// unique 단독으로 사용되기는 힘드니 sort, erase와 같이 사용하여 중복된 원소를 지워보겠습니다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  	vector <int> v = {3, 1, 7, 13, 3, 4, 5, 5, 6, 7, 6};
  	sort(v.begin(), v.end());
  
  	v.erase(unique(v.begin(), v.end()), v.end());
  
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  
  // 결과: 1 3 4 5 6 7 13
  
  cout < "\n";
  
  return 0;
  
}
```





### 4. swap

두 변수의 값을 바꿔주는 함수이다. 간단하게 구현할 수도 있지만 정의되어있는 함수를 쓰는것이 더 빠르고 안전하다.

- 사용법: `swap(T& a, T& b)`
- 시간복잡도: $ O(N) $
- return type: none



#### 예제코드

```c++
#include <iostream>     // std::cout
#include <utility>      // std::swap

using namespace std;

int main () {

  int x = 10, y = 20;                 // x:10 y:20
  swap(x,y);                  				// x:20 y:10

  int foo[4];                      		// foo: ?  ?  ?  ?
  int bar[] = {10,20,30,40};      		// foo: ?  ?  ?  ?    bar: 10 20 30 40
  swap(foo,bar);              				// foo: 10 20 30 40   bar: ?  ?  ?  ?

  cout << "foo contains:";
  for (int i: foo) cout << ' ' << i;
  cout << '\n';

  return 0;
}
```





### 5. reverse

배열 혹은 스트링 등의 자료구조 안에 요소들의 순서를 뒤집어 주는 함수

- 사용법: `reverse(Iterator begin, Iterator end)`
- 시간복잡도: $ O(N) $
- return type: none





#### 예제코드

```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector <int> v = { 1, 3, 4, 6, 11, 3, 2 };
  reverse(vector.begin(), vector.end());
  
  for (int i : v) cout << v[i] << " ";
  
  // v: 2 3 11 6 4 3 1
  
  cout << endl;
  
  return 0;
}
```





### 6. lower_bound, upper_bound

기준 값보다 낮거나 같은 (혹은 높거나 같은) 요소들을 가려주는 함수 (정렬이 되어 있어야함)

- 사용법: `lower_bound(Iterator begin, Iterator end, T& value)`
- 시간복잡도: $ O(\log N) $
- return type: `Iterator`

기준보다 낮거나 같은 (혹은 높거나 같은) 배열의 Iterator를 반환한다.



#### 예제코드

```c++
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main () {
  int myInts[] = { 32, 71, 12, 45, 26, 80, 53, 33 };
  vector <int> v (myInts, myInts+8);
  
  sort(v.begin(), v.end());										
  vector<int> :: iterator low, up;
  																						// 12 26 32 33 45 53 71 80
  low = lower_bound (v.begin(), v.end(), 20);	//	^
  up = upper_bound (v.begin(), v.end(), 30);	//				^
  
  
  return 0;
  
}
```





### 7. binary_search

기준 값보다 낮거나 같은 (혹은 높거나 같은) 요소들을 가려주는 함수 (정렬이 되어 있어야함)

- 사용법: `binary_search (Iterator begin, Iterator end, T& value)`
- 시간복잡도: $ O(\log N) $
- return type: `boolean`

찾으려는 요소 있으면 true, 없으면 false를 반환한다.



#### 예제코드

```c++
#include <iostream>
#include <algorithm>
#include <vector>

int main () {
  int myints[] = {1,2,3,4,5,4,3,2,1};
  vector<int> v(myints,myints+9);                         

  // using default comparison:
  sort (v.begin(), v.end());

  
  cout << "looking for a 3... ";
  
  if (binary_search (v.begin(), v.end(), 3)) cout << "found!\n"; 
  else cout << "not found.\n";
  
  return 0;
}
```







### 8. set_difference, set_intersection, set_union

꼭 set 자료구조만이 아니더라도 

set_difference: $ (A-B) \cup (B-A) $

set_intersection: $ A \cap B $

set_union: $ A \cup B $

을 구해주는 함수이다.





- 사용법: `set_difference (Iterator input1_begin, Iterator input1_end, Iterator input2_begin , Iterator input2_end, Iterator output)`
- 시간복잡도: $ O(N) $
- return type: `Iterator`



#### 예제코드

```c++
// set_difference example
#include <iostream>     // std::cout
#include <algorithm>    // std::set_difference, std::sort
#include <vector>       // std::vector

int main () {
  int first[] = {5,10,15,20,25};
  int second[] = {50,40,30,20,10};
  std::vector<int> v(10);                      // 0  0  0  0  0  0  0  0  0  0
  std::vector<int>::iterator it;

  std::sort (first,first+5);     //  5 10 15 20 25
  std::sort (second,second+5);   // 10 20 30 40 50

  it=std::set_difference (first, first+5, second, second+5, v.begin());
                                               //  5 15 25  0  0  0  0  0  0  0
  v.resize(it-v.begin());                      //  5 15 25

  std::cout << "The difference has " << (v.size()) << " elements:\n";
  for (it=v.begin(); it!=v.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  
  
  // set_union

  it=std::set_union (first, first+5, second, second+5, v.begin());
                                               // 5 10 15 20 25 30 40 50  0  0
  v.resize(it-v.begin());                      // 5 10 15 20 25 30 40 50

  std::cout << "The union has " << (v.size()) << " elements:\n";
  for (it=v.begin(); it!=v.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  
  // set_intersection
    it=std::set_intersection (first, first+5, second, second+5, v.begin());
                                               // 10 20 0  0  0  0  0  0  0  0
  v.resize(it-v.begin());                      // 10 20

  std::cout << "The intersection has " << (v.size()) << " elements:\n";
  for (it=v.begin(); it!=v.end(); ++it)
    std::cout << ' ' << 
  
 
  
  
  return 0;
}


```







### 9. max_element, min_element

배열, 리스트 같은 자료구조 내에서 가장 큰 (혹은 작은) 요소를 구해주는 함수

- 사용법: `max_element(Iterator first, Iterator last)`
- 시간복잡도: $ O(N) $
- return type: `Iterator `

Iterator를 반환하기 때문에 최대, 최소값을 쓰기 위해서는 ***(dereference character)를 붙여줘야한다.**





#### 예제코드

```c++
// min_element/max_element example
#include <iostream>     // std::cout
#include <algorithm>    // std::min_element, std::max_element

using namespace std;

int main () {
  int myints[] = {3,7,2,5,6,4,9};

  cout << "The smallest element is " << *min_element(myints,myints+7) << '\n';
  cout << "The largest element is "  << *max_element(myints,myints+7) << '\n';

  return 0;
}
```







### 10. max, min

두 수를 비교해서 더 큰 값 (혹은 더 작은 값)을 구해주는 함수

- 사용법: `max(T& a, T& b)`
- 시간복잡도: $ O(1) $
- return type: `T& `

### 

#### 예제코드

```c++
// max example
#include <iostream>     // std::cout
#include <algorithm>    // std::max

int main () {
  
  // max
  std::cout << "max(1,2)==" << std::max(1,2) << '\n';
  std::cout << "max(2,1)==" << std::max(2,1) << '\n';
  std::cout << "max('a','z')==" << std::max('a','z') << '\n';
  std::cout << "max(3.14,2.73)==" << std::max(3.14,2.73) << '\n';
  
  // min
   std::cout << "min(1,2)==" << std::min(1,2) << '\n';
  std::cout << "min(2,1)==" << std::min(2,1) << '\n';
  std::cout << "min('a','z')==" << std::min('a','z') << '\n';
  std::cout << "min(3.14,2.72)==" << std::min(3.14,2.72) << '\n';
  return 0;
}
```





