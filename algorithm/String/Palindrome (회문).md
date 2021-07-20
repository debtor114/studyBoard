# palindrome (회문)

**회문** 또는 **팰린드롬**(palindrome)은 거꾸로 읽어도 제대로 읽는 것과 같은 문장이나 낱말, 숫자, 문자열(sequence of characters) 등이다. 보통 낱말 사이에 있는 띄어쓰기나 문장 부호는 무시한다.

Ex) TENET, 기러기, 수박이박수



가장 직관적인 방법은 가장 첫글자와 마지막글자, 두번째 글자와 마지막에서 두번째 글자를 서로 다 비교해 보는 것이다.

```c++
string s;

bool palindrome (string s) {
  int N = s.length()-1;

  for (int i = 0; i <= N/2; i++) {
    if (s[i] == s[N-i]) continue;
    else return false;
  }
  
  return false;
}

```

길이가 N인 문자열이 펠린드롬인지 아닌지를 구별하는데는 $ O(N) $의 시간복잡도가 필요하다.





## Manacher's Algorithm

위의 방법을 사용해서 부분 문자열에 대한 펠린드롬을 모두 구한다면 어떨까? 그때 시간복잡도는  $ O(N^2) $이 될 것이다. 

너무 느리고, $ N^2 $ 이면 대부분의 PS에서 시간 초과가 날 것 같은 불길한 예감이 든다. 



Manacher's Algorithm은 $ O(N) $ 의 시간복잡도로 부분문자열에 대한 펠린드롬을 구할 수 있게 해준다.



### **설계**

다이나믹 프로그래밍을 기반으로 한다. 현재 인덱스를 기점으로 좌우의 문자를 비교하여 현재 인덱스에서의 팰린드롬 길이를 구한다고 생각해보자.

- s[i] : 문자열의 i번째 문자
- d[i]: i번째 문자를 기준으로 한 팰린드롬의 크기





banana 라는 단어를 보자.

| s[i] | b    | a    | n    | a    | n    | a    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| d[i] | 0    | 0    | 3    | 5    | 3    | 0    |

- d[0]: b(s[0])을 기준으로 팰린드롬이 없다.								**b**anana

- d[1]: a(s[1])을 기준으로 팰린드롬이 없다.									b**a**nana

- d[2]: n(s[2])을 기준으로 ana이라는 팰린드롬이 있다.				b<span style="color:white; background:red">a**n**a</span>na

- d[3]: a(s[3])을 기준으로 anana이라는 팰린드롬이 있다.			b<span style="color:white; background:red">an**a**na</span>

- d[4]: n(s[4])을 기준으로 ana이라는 팰린드롬이 있다.				ban<span style="color:white; background:red">a**n**a</span>

- d[5]: a(s[5])을 기준으로 팰린드롬이 없다.									banan**a**





여기서 알 수 있는 사실은 d[i]는 항상 홀수이며 $ \frac(d[i]-1}{2} $ 만큼 앞뒤로 펠린드롬이라는 것이 보장된다는 사실이다.

그렇다면 d[3] (ban**a**na) 의 값을 가지고d[4] (bana**n**a)의 값을 유추할 수 있는가?



d[3] = 5 였으므로 (5-1)/2 = 2만큼 전후로 펠린드롬이라는 것이 보장된다.

b<span style="color:white; background:red">an**a**na</span>

**a**를 기점으로 앞 뒤로 2만큼 펠린드롬이라는 것을 안다. 

따라서 센터는 3 (a의 인덱스), 반경은 2라고 할 수 있다. 



bana**n**a는 d[3]의 반경에 포함되고 (b<span style="color:white; background:red">an**a**na</span>) ban**a**na를 기점으로 bana**n**a(s[4])와 대칭인 ba**n**ana(s[2])의 펠린드롬이 3이므로 최소 3의 길이를 갖는 펠린드롬임이 보장된다. 

 즉, 4번째 문자(n)가 3번째 문자(a)의 팰린드롬 반경에 속해있고 4번째 문자(n)와 대칭인 2번째 자리 문자(n)의 팰린드롬의 길이가 최소라는 것을 보장하기 때문에 우리는 p[3] = 3 을 p[5]에 최소값으로 세팅해 놓은 뒤  

ban<span style="background:red; color:white">ana</span>xxx 에서 ban와 xxx 만 비교한다.  

(xxx는 단순히 자릿수를 맞춰주기 위한 가상의 문자열이다. 위 상황에서는 비교할 문자열이 원래는 없으므로 비교를 종료하면 된다.)

----



#### **왜 그런지 이해가 잘 안되요..**

**x** (center), 반경 = 9

<span style="background:yellow">a b c d e f g h i **x** i h g f e d c b a </span> 이러한 펠린드롬을 구했다고 가정하자. 

a b c d e <span style="background:red; color:white">f</span> e d i **x** i d e <span style="background:blue; color:white">f</span> e d c b a  반경안의 새로운 <span style="background:red; color:white">f</span>에 대해 d[<span style="background:red; color:white">f</span>]를 구하려고 할때

x를 중심으로 왼쪽 <span style="background:red; color:white">f</span>와 대칭인 오른쪽 <span style="background:blue; color:white">f</span>를 보자.



<span style="background:red; color:white">f</span>의 반경(d[<span style="background:red; color:white">f</span>] 값)이 2일때 **x**를 기준으로 반경 9짜리 펠린드롬이 되기 위해서는 위와 같이 되어야 할 것이다.

a b c <span style="background:red; color:white">d e f e d</span> i **x** i <span style="background:blue; color:white">d e f e d</span> c b a



따라서 x를 기준으로 f에서 반경 2에 속해있는 defed의 각각의 mirror position의 값은 같을 수 밖에 없다.

a b c <span style="background:purple; color:white">d</span> <span style="background:black; color:white">e</span> f <span style="background:green; color:white">e</span> <span style="background:gray; color:white">d</span> i **x** i <span style="background:gray; color:white">d</span> <span style="background:green; color:white">e</span> f <span style="background:black; color:white">e</span> <span style="background:purple; color:white">d</span> c b a





즉, 구하고자 하는 위치의 반경 2가 유지되므로 d[<span style="background:blue; color:white">f</span>] = 2 의 팰린드롬을 보장한다. 





#### **그럼 스트링 길이가 짝수일땐 어떻게 하나요?**

그리고 여기서 문제가 되는 것은 좌우만을 비교하기 때문에 abdccd라는 것에서 짝수길이의 cc와 dccd를 추출해 내지 못하므로

`abdccd` => `#a#b#d#c#c#d#`



각 자리 사이사이에 같은 문자(#)를 넣어 홀수개의 스트링 길이로 만들어주면 된다.





### **구현**

```c++
#include <cstdio>
#include <string>
#include <algorithm>
 
#define MAXN 100001
 
using namespace std;
 
int d[10000]; // 팰린드롬의 반경
string s; // 문자열

int main() {
	int n; // 문자열의 길이
	int r, center; // 맨 끝의 위치, 중간의 위치
	r = center = -1;
	scanf("%s", s);
	n = s.length();
 
	// even palindrome
	for (int i = n - 1; i >= 0; i--) {
		s[(i << 1)+1] = s[i];
		s[i << 1] = '#';
	}
  
	n <<= 1;
	s[n++] = '#';
 
	for (int i = 0; i < n; i++) {
		if (r >= i) d[i] = min(r - i, d[center*2 - i]); // 작은 쪽을 넣어준다.
		else d[i] = 0;
 
		while (i+d[i]+1 < n && i-d[i]-1 >= 0 && s[i+d[i]+1] == s[i-d[i]-1]) 
      p[i]++; // 같으면 증가
		
    if (i + d[i] > r) { // 끝지점을 넘어서면 그때마다 갱신
			r = i + d[i];
			center = i;
		}
	}
 
	for(int i = 0; i < n; i++)
    printf("%d ",d[i]);
	
  return 0;
}s
```

