이번 시간에 다룰 내용은 여러 개의 데이터가 연속적으로 존재할 때 특정한 범위의 데이터의 합을 구하는 방법에 관한 것입니다. 데이터의 합을 가장 빠르고 간단하게 구할 수 있는 자료구조로 세그먼트 트리가 있습니다. **세그먼트 트리(Segment Tree)**는 트리 영역에서 상당히 중요한 개념입니다.

> 배열에서 특정 구간의 합을 가장 빠르게 구하는 방법은 무엇일까?
> 예시 데이터: 5 8 7 3 2 5 1 8 9 8 7 3

위와 같이 12개의 데이터가 있다고 가정해봅시다. 이 때 특정 구간의 합을 구해봅시다.

###### 방법 1. 단순 배열을 이용해 선형적으로 구하기

단순히 선형적으로 구하는 방법을 생각해봅시다.

| 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   | 11   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 5    | 8    | 7    | 3    | 2    | 5    | 1    | 8    | 9    | 8    | 7    | 3    |

위와 같이 배열로 표현해봅시다. 이 때 데이터의 개수가 12개이므로 인덱스는 0부터 11까지 차례대로 들어갑니다. 만약 인덱스 1부터 10까지 데이터를 더하려면 어떻게 할 수 있을까요?

| 0    | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   | 11   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 5    | 8    | 7    | 3    | 2    | 5    | 1    | 8    | 9    | 8    | 7    | 3    |

위 범위를 하나씩 다 더하면 됩니다. 결과로는 58이 나옵니다. 이러한 방식을 고려했을 때 앞에서 하나씩 더해가므로 데이터의 개수가 N이면 시간 복잡도는 **O(N)**이 나옵니다. 따라서 이러한 방식을 이용했을 때 구간의 합을 구하는 속도가 너무 느리기 때문에 더 좋은 알고리즘이 필요합니다.

###### 방법 2. 트리 구조를 이용해 구하기

하지만 **세그먼트 트리**가 나온다면 어떨까요? 트리 구조의 특성상 합을 구할 때 시간 복잡도 **O(logN)**이면 됩니다. 위에서 언급한 단순히 더하는 방법보다 빠르게 구하기 위한 것으로 우리가 이번 시간에 배우게 될 내용입니다. 일단 기존의 배열을 다음과 같이 트리 구조라고 고려해보도록 합시다.

![img](https://postfiles.pstatic.net/MjAxODA1MjNfMjU0/MDAxNTI3MDQzNjk1OTUy.f9HkIyu_MJ7UxK-w9YDGc0irdFhb17Fr6iyk1pLiVrcg.ARKp3Nb8ebiOx4iU0MoaOIXunbudnMvAwB5rmLGkru8g.PNG.ndb796/image.png?type=w773)

**① 구간 합 트리 생성하기**

인덱스는 아까와 동일하게 0부터 11까지입니다. 이제 빠르게 합을 구하기 위해서 '**구간 합 트리**'를 새롭게 생성해주어야 합니다. 차근차근 봅시다. 먼저 최상단 노드에는 전체 원소를 더한 값이 들어갑니다.

![img](https://postfiles.pstatic.net/MjAxODA1MjNfODkg/MDAxNTI3MDQ1NzA1Mjgy.M3JVFOW3XJ1D703LXxBrmPT8_XPTGwVWcMgaqdPe8Jcg.O2_oLTncsUcWgdVyk7n8t15fQf7pSNasL7WgV3kPSmAg.PNG.ndb796/image.png?type=w773)

이후에 두 번째 노드와 세 번째 노드를 구합니다. 두 번째 노드는 인덱스 0부터 인덱스 5까지의 원소를 더한 값을 가지고, 세 번째 노드는 인덱스 6부터 인덱스 11까지의 원소를 더한 값을 가집니다. 말 그대로 원래 데이터의 범위를 반씩 **분할**하며 그 구간의 합들을 저장하도록 초기 설정을 하는 것입니다. 이러한 과정을 반복하면 구간 합 트리의 전체 노드를 구할 수 있습니다.

![img](https://postfiles.pstatic.net/MjAxODA1MjNfMTkx/MDAxNTI3MDQ1NjE1MTA2.027g35DrzBQE0MeuOW3ws1gE3izOAVCq5bnfON6yH_cg.YBYH9kUzWqHMNC8B_POyHsAk0xNH3hVPzqdW-7csGkUg.PNG.ndb796/image.png?type=w773)

 이와 같은 방식으로 구간 합 트리를 구하게 되면 결과적으로 다음과 같습니다. 재미있는 점은 구간 합 트리에 한해서는 인덱스 번호가 1부터 시작한다는 것입니다. 그 이유는 데이터의 인덱스는 0부터이지만 구간 합 트리는 1부터 시작하면 **2를 곱했을 때 왼쪽 자식 노드를 가리키므로 효과적**이기 때문입니다.

![img](https://postfiles.pstatic.net/MjAxODA1MjNfNDQg/MDAxNTI3MDQ2Mzg2MzAy.c5AMlXYpl0MI0vYEKk83Qf5ANciycA3cPqHEznPocyQg.p_pQrg2--R_vv-tUiv5Vgwwmujjay1CjomipG6FSBFsg.PNG.ndb796/image.png?type=w773)

구간 합 트리는 반복적으로 구현하는 것보다 재귀적으로 구현하는게 더 간단합니다. 

// start: 시작 인덱스, end: 끝 인덱스  int init(int start, int end, int node) { if(start == end) return tree[node] = a[start]; int mid = (start + end) / 2; // 재귀적으로 두 부분으로 나눈 뒤에 그 합을 자기 자신으로 합니다.  return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1); }

추가적으로 말씀드리자면 구간 합 트리는 다음과 같이 매 노드가 이미 구간의 합을 가지고 있는 형태가 된다고 할 수 있습니다. 노드의 인덱스와 구간의 합은 별개의 값이므로 헷갈리지 않도록 합니다.

![img](https://postfiles.pstatic.net/MjAxODA1MjNfMTQ0/MDAxNTI3MDQ2OTc5OTEz.KrynWZWNDO9iw9SInFhGiJyPsBzwrXXGXCV5ZVwmnjEg.kSGQcKd4iIeFhhm43-BFdcqYAkijKSjMjYv088Hh5hgg.PNG.ndb796/image.png?type=w773)

또한 구간 합 트리의 원소 개수는 위 그림만 보면 알 수 있듯이 **32개**라는 것을 알 수 있습니다. 쉽게 말해 데이터의 개수가 N개일 때 N보다 큰 가장 가까운 N의 제곱수를 구한 뒤에 그것의 2배까지 미리 배열의 크기를 미리 만들어놓아야 한다는 것입니다.

위 경우에서는 데이터의 개수가 12개이므로 16 * 2 = 32개의 크기가 필요했던 것입니다. 그래서 실제로는 데이터의 개수 N에 4를 곱한 크기만큼 미리 구간 합 트리의 공간을 할당합니다. 이제 구간 합 트리 설정을 마쳤으므로 실제로 합을 구하는 함수를 작성해보도록 합시다.

**② 구간 합을 구하는 함수 만들기**

이제 구간 합을 구하는 함수를 만들어봅시다. 트리 구조를 가지고 있기 때문에 데이터를 탐색함에 있어서 들이는 비용은 O(logN)입니다. 따라서 구간 합을 항상 O(logN)의 시간에 구할 수 있습니다. 예를 들어 4~8의 범위에 대한 합을 구하려고 해봅시다. 그러면 다음과 같이 세 노드의 합만 구해주면 됩니다.

![img](https://postfiles.pstatic.net/MjAxODA1MjNfMjEz/MDAxNTI3MDQ3MTE3ODcy.FfFnmtjoP66zGPBpKz7R3uLG4csUC_tIk1-pMZArNqkg.fSK7G7WEHrcHQi-AKU3IsVg61rdHvEeH97nirp-8ZpUg.PNG.ndb796/image.png?type=w773)

아까 구간 합 트리에서 인덱스 6 원소 값은 24, 인덱스 11의 원소 값은 5, 인덱스 21의 원소 값은 4였습니다. 따라서 이 경우에서 구하고자 하는 답은 24 + 5 + 4 = **33**이 되는 것입니다. 구간의 합을 구하는 함수 또한 재귀적으로 작성하면 매우 짧게 작성할 수 있습니다. 구간의 합은 '**범위 안에 있는 경우**'에 한해서만 더해주면 됩니다. 그 밖의 경우는 고려하지 않는다는 특징이 있습니다.

// start: 시작 인덱스, end: 끝 인덱스 // left, right: 구간 합을 구하고자 하는 범위  int sum(int start, int end, int node, int left, int right) { // 범위 밖에 있는 경우 if(left > end || right < start) return 0; // 범위 안에 있는 경우 if(left <= start && end <= right) return tree[node]; // 그렇지 않다면 두 부분으로 나누어 합을 구하기 int mid = (start + end) / 2; return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right); }

**③ 특정 원소의 값을 수정하는 함수 만들기**

특정 원소의 값을 수정할 때는 해당 원소를 포함하고 있는 모든 구간 합 노드들을 갱신해주면 됩니다. 예를 들어 인덱스 7의 노드를 수정한다고 하면 다음과 같이 5개의 구간 합 노드를 모두 수정하면 됩니다.

![img](https://postfiles.pstatic.net/MjAxODA1MjNfOCAg/MDAxNTI3MDQ3NjY1NjU5.rTBaHNZYzpBIUAToQPY4N0RHpT0k7z2GrFzuY8XCCKEg.jsIxaoDyS_F237U60LoDYktZG1QLlu08DX0V4uitagEg.PNG.ndb796/image.png?type=w773)

이 함수 또한 재귀적으로 구현하면 어렵지 않게 작성할 수 있습니다. 마찬가지로 수정할 노드로는 '**범위 안에 있는 경우**'에 한해서만 수정해주시면 됩니다.

// start: 시작 인덱스, end: 끝 인덱스 // index: 구간 합을 수정하고자 하는 노드 // dif: 수정할 값  void update(int start, int end, int node, int index, int dif) { // 범위 밖에 있는 경우  if(index < start || index > end) return; // 범위 안에 있으면 내려가며 다른 원소도 갱신  tree[node] += dif; if (start == end) return; int mid = (start + end) / 2; update(start, mid, node * 2, index, dif); update(mid + 1, end, node * 2 + 1, index, dif); }

위와 같이 재귀적으로 소스코드를 구성할 수 있었습니다. 다시 말해 세그먼트 트리를 이용하면 구간 합을 계산할 때 기존의 방법보다 획기적으로 속도가 빨라지는 것입니다.

> 세그먼트 트리를 이용하면 구간 합을 구하거나 수정할 때
> O(logN)으로 시간으로 처리할 수 있습니다.

위 내용을 전부 종합하여 소스코드를 작성하면 다음과 같습니다.

\#include <iostream> #include <vector> #define NUMBER 12 using namespace std; int a[] = {1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5}; int tree[4 * NUMBER]; // 4를 곱하면 모든 범위를 커버할 수 있음. 갯수에 대해서 2의 제곱 형태의 길이를 가지기 때문임.  // start: 시작 인덱스, end: 끝 인덱스  int init(int start, int end, int node) { if(start == end) return tree[node] = a[start]; int mid = (start + end) / 2; // 재귀적으로 두 부분으로 나눈 뒤에 그 합을 자기 자신으로 합니다.  return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1); } // start: 시작 인덱스, end: 끝 인덱스 // left, right: 구간 합을 구하고자 하는 범위  int sum(int start, int end, int node, int left, int right) { // 범위 밖에 있는 경우 if(left > end || right < start) return 0; // 범위 안에 있는 경우 if(left <= start && end <= right) return tree[node]; // 그렇지 않다면 두 부분으로 나누어 합을 구하기 int mid = (start + end) / 2; return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right); } // start: 시작 인덱스, end: 끝 인덱스 // index: 구간 합을 수정하고자 하는 노드 // dif: 수정할 값  void update(int start, int end, int node, int index, int dif) { // 범위 밖에 있는 경우  if(index < start || index > end) return; // 범위 안에 있으면 내려가며 다른 원소도 갱신  tree[node] += dif; if (start == end) return; int mid = (start + end) / 2; update(start, mid, node * 2, index, dif); update(mid + 1, end, node * 2 + 1, index, dif); } int main(void) { // 구간 합 트리의 인덱스를 제외하고는 모두 인덱스 0부터 시작합니다. // 구간 합 트리 생성하기  init(0, NUMBER - 1, 1); // 구간 합 구하기  cout << "0부터 12까지의 구간 합: " << sum(0, NUMBER - 1, 1, 0, 12) << '\n'; // 구간 합 구하기  cout << "3부터 8까지의 구간 합: " << sum(0, NUMBER - 1, 1, 0, 12) << '\n'; // 구간 합 갱신하기 cout << "인덱스 5의 원소를 -5만큼 수정" << '\n'; update(0, NUMBER - 1, 1, 5, -5);  // 구간 합 다시 구하기  cout << "3부터 8까지의 구간 합: " << sum(0, NUMBER - 1, 1, 0, 12) << '\n'; }