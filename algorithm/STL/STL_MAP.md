# STL map 



map은 key, value 페어로 이루어진 자료 구조입니다. 

- Key에 대한 중복이 없습니다.

- **레드블랙 트리(Red-Black Tree 이하 RB Tree)** 기반으로 되어있기 때문에 모든 데이터는 정렬되어 저장됩니다.

  - 빠른 검색 속도를 가집니다. ( $ O(\log(N)) $ )

    

- 인덱스가 따로 존재하지 않기 때문에 iterator를 사용합니다.



#### 기본형태

- `map <key, value>`: key와 value를 pair 형태로 선언합니다.





#### Method

- `begin()`: beginning iterator를 반환
- `end()`: end iterator를 반환

- `insert(make_pair(key,value)`: 맵에 원소를 `pair` 형태로 추가
- `erase(key)`: 맵에서 key(키값)에 해당하는 원소 삭제
- `clear()`: 맵의 원소들 모두 삭제

- `find(key)`: key(키값)에 해당하는 iterator를 반환, 못찾으면 `end()` iterator를 반환
- `count(key)`: key(키값)에 해당하는 원소들(value들)의 개수를 반환

 

#### 기타

- `empty()`: 맵이 비어있으면 true 아니면 false를 반환
- `size()`: 맵 원소들의 수를 반환





## 구현 코드

```c++
#include <iostream>
#include <map>
#include <string>

using namespace std;


int main(){

	map <string, int > m;


	// insert(key,value)
	m.insert(make_pair("a", 1));
  m.insert(make_pair("dest", 1));
	m["f"] = 6;


	// erase(key)
	m.erase("a");


	// empty(), size()
	if(!m.empty()) cout << "m size: " << m.size() << '\n';


	// find(key)
	if (m.find("src") == m.end()) cout << "Not found" << endl;


	// count(key)
	cout << "a count: " << m.count("a") << '\n';


	map <string, int>::iterator it;

	for(it = m.begin(); it != m.end(); it++){
		cout << "m[" << it->first << "]: " << it->second << '\n';
	}

	return 0;

}
```