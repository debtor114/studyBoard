## **해시(Hash)/해시 함수(Hash Function)/해싱(Hashing)?**

**해시(Hash)** 란 데이터를 다루는 기법 중 하나이며,**해시 함수(Hash Function)** 는 데이터를 효율적으로 관리하기 위해서 임의의 길이의 데이터를 고정된 길이의 데이터로 매핑하는 함수이다.
매핑전 원래 데이터의 값을 **키(key)**, 매핑 후 데이터의 값을 **해시값(Hash Value) 또는 해시코드** 라고 하며, 키(key)와 값(value)으로 매핑되는 과정 자체를 **해싱(Hashing)** 이라고 한다.

 

## **해시 테이블(Hash Table)?**

**해시 테이블(Hash Table)** 은 키(key)와 값(value)이 하나의 쌍을 이루는 데이터 구조이다. 즉, 키(key)와 배열의 인덱스(index)를 이용하여 키를 저장하는 자료구조이다. 해시 테이블은 해시 맵, 맵, 딕셔너리, 연관 배열 이라는 이름으로 알려져있다. (출처: 그림으로 개념을 이해하는 알고리즘 104p)
해시 테이블은 키를 **해시 함수(hash function)** 로 계산하여 그 값을 배열의 인덱스로 사용한다. 이때, 해시 함수에 의해 반환된 데이터의 고유 숫자 값을 **해시값 또는 해시코드** 라고 한다. 즉, key 값을 해시 함수를 통해서 배열의 인덱스로 바꿔주고, 그 자리에 데이터를 저장한다. 정리하면 다음과 같다.


**원래 데이터의 값(Key) -> Hash Function -> \**Hash Function의 결과 =\** Hash Code**

**-> \**Hash Code를 배열의\** Index 로 사용 -> 해당하는 Index에 data 넣기**

 

다음은 해시 테이블의 개념을 예를 들어 설명한 것이다.
이름을 키(key)로 하여 번호를 저장하는 해시 테이블은 다음과 같이 만들 수 있다. 전체 데이터 양을 10이라고 하면 John의 데이터를 저장할 때, 배열의 인덱스는 hashFunction("John") % 10을 통해 인덱스 값을 계산한다. 여기서는 인덱스 값은 2이다.



![img](https://blog.kakaocdn.net/dn/ceKgGz/btqAUvLYrPN/DMVl0lwN8tA2hobFxqHcf0/img.png)출처 :https://en.wikipedia.org/wiki/Hash_table 



이런식으로 데이터를 저장하다 보면 계산된 인덱스 값이 중복될 수가 있다. 예를 들어 저장하고자 하는 키가 정수이고 hash_function이key%10이다. 전체 사이즈가10일때, key 1,11,21은 같은 인덱스 값을 가지게 된다. **충돌 (collision)** 이라고한다.



![img](https://blog.kakaocdn.net/dn/ojpfo/btqAXP9PLGI/kXwsIKhwS9ykPC1WG8Qne0/img.png)출처 :https://en.wikipedia.org/wiki/Hash_table 



## **충돌(Collision)**

**충돌(Collision)** 은 서로 다른 문자열이 Hash function을 통해 Hash 한 결과가 같은 경우 (중복되는 경우)이다.
충돌을 줄여주는 좋은 해시 함수를 사용하는 것이 좋다. 왜냐하면 충돌이 많아질 수록 탐색의 시간 복잡도가 O(1)에서 O(n)에 가까워지기 때문이다. 해결 방법은 다음과 같다.

- Separating Chaining - Linked List, Tree(Red-Black Tree)
- Open addressing - Linear Probing, Quadratic Probing, Double hashing

## **Separating Chaining**

이 방법은 JDK내부에서도 사용하고 있는 충돌 처리 방식인데, Linked List를 이용하는 방식이다. Linked List뿐만이 아니라 Tree(Red-Black Tree)를 사용하기도 한다. 두 개를 사용하는 기준은 data가 6개 이하이면 linked list를 사용하고 8개 이상이면 tree를 사용한다.
(왜 7개가 아니냐 의문이 들 수 있다. 만약 7개일 때, 데이터를 삭제하게 되면 linked list로 바꿔야 하고 만약 추가되면 tree로 바꿔야한다. 이때 바꾸는데 오버헤드가 있기 때문에 기준이 6, 8이다.)



![img](https://blog.kakaocdn.net/dn/dzUUKL/btqAU5TNqPb/57l6XNBJBLFlL1xcXCePq1/img.png)Separating Chaining - Linked list



다음은 Linked list를 사용한 것이다. 인덱스가 충돌이 날 때, 인덱스가 가리키고 있는 linked list에 노드를 추가하여 값을 삽입한다.

데이터를 탐색할 때는 키에 대한 인덱스가 가리키고 있는 Linked list를 선형 검색하여, 해당 키에 대한 데이터를 반환한다.

삭제하는 것도 비슷하게, 키에 대한 인덱스가 가리키고 있는 Linked list에서, 그 노드를 삭제한다.
Separate changing 방식은 Linked List 구조를 사용하고 있기 때문에, 추가할 수 있는 데이타 수의 제약이 작다.
[(코드)](https://hee96-story.tistory.com/49)

## **Open addressing**

이 방법은 인덱스에 대한 충돌 처리에 대해서 Linked List와 같은 추가적인 메모리 공간을 사용하지 않고, hash table array의 빈공간을 사용하는 방법이다. 추가적인 메모리 공간을 사용하지 않기 때문에 Separate chaining방식에 비해서 메모리를 덜 사용한다. Linear Probing, Quadratic Probing, Double hashing 등이 있다. 그 중 Linear Probing은 다음과 같다.



![img](https://blog.kakaocdn.net/dn/ALk2h/btqAWxowTOl/oWIIt6DZ7jdYBd3jngUqWk/img.png)Open addressing - Linear Probing



Linear Probing방식은 인덱스가 중복되는 충돌이 발생할 때 인덱스 뒤에 있는 버킷중에 빈 버킷을 찾아서 데이터를 넣는다. 그림에서 Sandra(key)의 인덱스는 152이다. 하지만 키 John과 충돌이 나기 때문에 그 다음 인덱스인 153에 데이터를 넣는다.

Linear Probing방식에서의 탐색은 Sandra(key)에 대해서 검색을 하면, index가 152이기 때문에, key가 일치하지 않기 때문에 뒤의 index를 검색해서 같은 키가 나오거나 또는 Key가 없을때 까지 검색을 진행한다.

삭제는 더미 노드를 넣어서 검색할 때 다음 인덱스까지 검색을 연결해주는 역할을 해줘야한다. (즉, 삭제가 어렵다.)
[(코드)](https://hee96-story.tistory.com/49)

## **리사이징(Resizing)**

Separate changing에 경우, 버킷이 일정 수준으로 차 버리면 각 버킷에 연결되어 있는 List의 길이가 늘어나기 때문에, 검색 성능이 떨어지기 때문에 버킷의 개수를 늘려줘야 한다. 또한 Open addressing의 경우, 고정 크기 배열을 사용하기 때문에 데이터를 더 넣기 위해서는 배열을 확장해야 한다. 이를 **리사이징(Resizing)이라고** 한다.

 

보통 두 배로 확장하는데, 확장하는 임계점은 현재 데이터 개수가 해시 버킷의 개수의 75%가 될 때이다. 0.75라는 숫자는 load factor 라고 불린다. 리사이징은 더 큰 버킷을 가지는 array를 새로 만든 다음에, 다시 새로운 array에 hash를 다시 계산해서 복사해줘야 한다.

## **해시 테이블의 장점**

1. 적은 리소스로 많은 데이터를 효율적으로 관리할 수 있다.
   - 예) HDD, Cloud에 존재하는 많은 데이터들을 유한한 개의 해시(Hash)값으로 매핑하여 작은 크기의 캐쉬 메모리로 프로세스 관리가 가능하다.
2. 배열의 인덱스(index)를 사용해서 검색, 삽입, 삭제가 빠르다. (평균 시간복잡도 : O(1))
   - 인덱스를 사용해서 배열의 검색이 빠르다는 것은 당연한 소리이다. 하지만 삽입, 삭제는 왜 O(1)인가?
   - 여기서의 인덱스는 데이터만의 고유한 위치이기 때문에 만약 삽입이나 삭제를 한다고 해도 다른 데이터로 채울 필요가 없다. 즉, 삽입이나 삭제할 때 데이터를 이동할 필요가 없기 때문이다.
3. 키(key)와 해시값(Hash)이 연관성이 없어 보안에도 많이 사용된다.
4. 데이터 캐싱(Data Caching)에 많이 사용된다.
   - get(key), put(key)에 캐시 로직을 추가하면 자주 hit하는 데이터를 바로 찾을 수 있다.
5. 중복을 제거하는데 유용하다.

## **해시 테이블의 단점**

1. 충돌
2. 공간 복잡도가 커진다.
3. 순서가 있는 배열에는 어울리지 않는다.
4. 해시 함수 의존도가 높아진다.

## **해시 테이블(Hash Table) VS 해시 맵(Hash Map)**

Java에서 HashTable과 HashMap의 차이는 동기화 지원 여부이다. 키(Key)에 대한 해시(Hash)값을 사용하여 값을 저장, 조회 하는 것은 동일하다.

- **해시 테이블(Hash Table)**
  - 병렬 처리를 할 때 (동기화를 고려해야하는 상황) 
  - Null 값을 허용하지 않는다. 
- 해시 맵(Hash Map)
  - 병렬 처리를 하지 않을 때 (동기화를 고려하지 않는 상황)
  - Null 값을 허용한다.

## **해시 테이블의 성능**

키값이 배열의 인덱스로 변환되기 때문에 탐색,저장,삭제가 빠르다. 평균 시간 복잡도가 O(1)이다.

\- 평균 시작 복잡도인 이유는 collision 때문이다.

|          | **평균적인 경우** | **최악의 경우** |
| -------- | ----------------- | --------------- |
| **탐색** | **O(1)**          | **O(N)**        |
| **삽입** | **O(1)**          | **O(N)**        |
| **삭제** | **O(1)**          | **O(N)**        |





예제코드

