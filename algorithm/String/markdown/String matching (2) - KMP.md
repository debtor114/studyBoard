### KMP algorithm



![image-20210726222229053](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210726222229053.png?raw=true)

navie string matcher를 다시 생각해보면, 위의 사진 같이 앞에 **5개의 문자는 일치하지만** 마지막 6번째 문자가 달라서 같지 않다고 나오는 경우, 앞에 5개의 **문자는 일치한다는 정보**를 버리고 한칸을 shift하고 처음부터 다시 비교하게 된다.

KMP알고리즘은 앞에 **5개는 일치한다라는 정보**를 저장하여 더욱 효율적으로 검색한다는 메인 아이디어로 시작한다.





#### 설계

패턴 자체를 비교하여 필요한 정보를 미리 계산할 수 있습니다. 

전체 문자열은 같지 않지만 부분문자열은 같은 경우, 얼마만큼 비교를 skip할 수 있을지 정보를 제공해주는 함수입니다. 

위 예시의 경우 ababa까지 일치하였고 앞뒤로 <span style="color:white; background:black">aba</span>ba /  ab<span style="color:white; background:black">aba</span> 3개의 문자가 일치하고 2개의 문자가 일치하지 않으므로 2칸을 건너뛰어서 다음 비교를 실행하면 됩니다.

![image-20210726222346579](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210726222346579.png?raw=true)

좀 더 체계적인 용어를 사용하여 정리해보겠습니다.



##### 접두사(prefix)와 접미사(suffix)

- 접두사: 문자열의 첫 문자부터 차례대로 나열한 부분 문자열

Ex) banana의 접두사: b, ba, ban, bana, banan, banana



- 접미사: 문자열의 마지막 문자부터 차례대로 나열한 부분문자열

Ex) banana의 접미사: a, na, ana, nana, anana, banana





##### prefix (failure) function

문자 매칭에 실패했을 때, 얼만큼 건너뛰어야 하는가에 대한 정보.

 즉, 문자 매칭에 실패하기 직전 상황에서, 접두사 / 접미사가 일치한 최대 길이





**2개의 인덱스 (i, j)** 를 활용해서 실패함수를 구할 것입니다.

- 인덱스를 증가시켜나가며 **두 문자가 일치하면 두 인덱스를 증가**시키고,

- 일치하지 않으면 **이전까지의 상황의 실패함수를 참고**해나가며, 참고할 값이 없으면 0 이 됩니다.





![image-20210727212007195](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727212007195.png?raw=true)

실패함수의 첫번째 항목은 0 입니다. 첫번째는 항상 0으로 생각하시면 됩니다.



![image-20210727212240200](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727212240200.png?raw=true)

현재 **i 와 j 인덱스에서 문자가 불일치**하므로, **이전까지의 실패함수를 참고**를 시도합니다.

하지만 이전 상태에서의 실패함수의 값은 0 입니다.

그러므로, i 번째 Fail 함수의 값도 다음과 같이 0 으로 갱신되고, i 가 증가합니다.

 



![image-20210727214119272](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727214119272.png?raw=true)

i 와 j 에서 문자열이 일치하므로, 다음과 같이 j + 1의 값이 i번째 실패함수의 값으로 입력되며,

i와 j의 값이 모두 증가합니다.

 

![image-20210727214203600](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727214203600.png?raw=true)

여기에서도 역시, 'b' 와 'b' 로 일치하기 때문에

i 번째 실패함수의 값은 j + 1인 2로 변경됩니다. i와 j의 값이 모두 증가합니다.

 

![image-20210727214252182](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727214252182.png?raw=true)

여기에서도 역시, 'a' 와 'a' 로 일치하기 때문에

i 번째 실패함수의 값은 j + 1인 3로 변경됩니다. i와 j의 값이 모두 증가합니다.





![image-20210727214541998](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727214541998.png?raw=true)

'b'와 'c'로 불일치하기 때문에, 이전까지의 실패함수를 참고합니다.

다시 말해 이전 인덱스의 실패함수의 값으로 j를 옮겨서, 다시 문자를 비교합니다.

지속해서 불일치한다면 j가 0이 될 때까지 반복합니다.

![image-20210727214609149](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727214609149.png?raw=true)

![image-20210727214619484](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727214619484.png?raw=true)

![image-20210727214640957](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727214640957.png?raw=true)

모든 인덱스와 불일치 했으므로, i번째 Fail 함수의 값이  0으로 갱신되고, i가 증가합니다.



![image-20210727214721442](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727214721442.png?raw=true)

'a' 와 'a' 로 일치하기 때문에 i번째 실패함수의 값은 j + 1인 1로 변경됩니다.

최종적으로 위와 같은 실패함수가 만들어졌습니다. 이 실패함수로 알수 있는 사실은 다음과 같습니다.

 

**- 'a'** 까지 일치하는 접두사/접미사 최대 길이 : **0 (없음)** 

**-** **'ab'** 까지 일치하는 접두사/접미사 최대 길이 : **0** (**없음)**

**- 'aba'** 까지 일치하는 접두사/접미사 최대 길이 : **1 ('a')**

**- 'abab'** 까지 일치하는 접두사/접미사 최대 길이 : **2** **('ab')**

**- 'ababa'** 까지 일치하는 접두사/접미사 최대 길이 : **3 (aba)**

**- 'ababac'** 까지 일치하는 접두사/접미사 최대 길이 : **0 (없음)**

**- 'ababaca'** 까지 일치하는 접두사/접미사 최대 길이 : **1 ('a')**







#### 동작

전체 문자열은 **'babaabaababaca'** 이고,

찾는 문자열은 **'ababaca'** 입니다.



 그리고 정확한 이해를 위해 변수 `begin`을 T의 시작 인덱스로, 일치하는 개수를 `m`이라고 하면 아래와 같은 방식으로 동작한다.

- T[begin+m]==P[m]: 일치할 경우, m++
- T[begin+m]!=P[m]: 불일치할 경우, begin이 스킵하는 만큼 증가하고 m이 실패 함수값이 된다.





![image-20210727215316843](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727215316843.png?raw=true)

- begin: 0
- m = 0

m=0, 0번째 항목에서 **불일치가** 발생했습니다. 하나도 일치하지 않은 경우이므로 바로 한칸만 건너뜁니다.

 ![image-20210727214721442](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727214721442.png?raw=true)







![image-20210727215719739](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727215719739.png?raw=true)

- begin: 1
- m = 3

3번째 index에서 불일치가 발생했습니다. (0부터 시작하므로 0,1,2,3 3번째 Index) 

이 경우엔 m−1의 실패 함수 값 (`fail(m-1`)을 확인하는데 m개가 일치했다는 것은 인덱스 m−1까지 일치했다는 말과 동일하기 때문이다. 위에서 구했던 것처럼 `fail(2)` = 1이기 때문에 다시 T의 1번째 인덱스부터 비교하면 된다.

왜냐하면 `fail(2)`=1이란 의미가 이전에 일치한 문자열 중에 접두사와 접미사가 일치하는 부분이 1개라는 뜻이기 때문에 0번째 인덱스가 일치한다는 것이 보장되기 때문이다. 

 또한 begin 값을 옮겨주어야 하는데 begin에 `m − fail(m−1)`만큼 더해주면 된다. 일치하는 만큼(m) 옮긴다음 반복되는 문자열의 길이 만큼( `fail(m−1)` ) 빼주는 개념이다. 

begin = begin + m - fail(m-1) = 3이므로 3번째 index부터 다시 비교하면 된다.





![image-20210727220658972](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727220658972.png?raw=true)

- begin: 3
- m = 1

이번에는 1번째 index에서 불일치가 일어났습니다. 

마찬가지로 m = 1 이므로 fail(0) 값을 확인하고 begin = begin + m - fail(m-1) = 4이므로 4번째 index부터 다시 비교합니다.





![image-20210727220935071](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727220935071.png?raw=true)

- begin: 4
- m = 3

3번째 index에서 불일치가 발생했습니다. 마찬가지로 m = 3 이므로 fail(2) 값을 확인하고 begin = begin + m - fail(m-1) = 6이므로 6번째 index부터 다시 비교합니다.



 

![image-20210727221042453](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727221042453.png?raw=true)

- begin: 6
- m = 1

1번째 index에서 불일치가 발생했습니다. 마찬가지로 m = 1 이므로 fail(0) 값을 확인하고 begin = begin + m - fail(m-1) = 7이므로 7번째 index부터 다시 비교합니다.









![image-20210727221224580](https://github.com/doooooooong/studyBoard/blob/master/algorithm/String/images/image-20210727221224580.png?raw=true) 

- begin: 7
- m = 7

드디어 T를 찾았는데 이 경우에는 단순히 완전히 건너뛰면 되는 것일까?

 **완전히 일치하는 경우에도 접두사와 접미사가 일치하는 부분이 존재한다.** 즉, 현재 m = 7, fail(6) = 0이므로 begin = begin + m -fail(m-1) = 14이므로 14번째 index부터 다시 비교하면 된다. 

하지만 14번째 인덱스부터 남은 문자의 갯수(0)가 패턴의 길이(7)보다 작으므로 함수를 종료하면된다.







#### 의사코드

```pseudocode
KMP-MATCHER(T, P)
	n = T.length, m = P.length
	pi = COMPUTE-PREFIX-FUCNTION(P)
	q = 0
	
	for i = 1 to n
		while (q > 0 && P[q+1] != T[i])
			q = pi[q]
			
		if (P[q+1] == T[i]) q++;
		if (q == m) {
			print "Pattern occurs with shift" i-m
			q = pi[q]
		}
```



#### **구현 (C++)**

```c++
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int fail[1000];

vector <int> result;


void getFailFunc(string P) {
	int M = 0;
	while (P[M]) M++;

	for (int i = 1, j = 0; i < M; i++) {
		while (j > 0 && P[i] != P[j]) 
            j = fail[j - 1];

		if (P[i] == P[j]) {
			fail[i] = ++j;
		} else {
			fail[i] = 0;
		}
	}
}

void KMP(string text, string pattern) {
    int t_len = text.length();
    int p_len = pattern.length();


    int begin = 0, m = 0;
    while(begin <= t_len - p_len) {
        // 일치개수(m)가 P의 길이보다 작고
        // T[begin+m]과의 문자가 일치하는 경우
        if(m < t_len && text[begin+m] == pattern[m]){
            m++;
            // P를 찾은 경우에 begin값을 저장한다.
            if(m == p_len) result.push_back(begin);
        }
        // 불일치하거나 P를 찾은 경우
        else {
            // 일치한적이 한번도 없고 불일치했다면 단순히 begin 옮기면 된다.
            if(m == 0)
                begin++;
            // 그게 아니라면 begin과 m을 위에서 말한 것처럼 초기화!
            else {
                begin += (m - fail[m-1]);
                m = fail[m-1];
            }
        }
    }
}



int main(void) {
    string T, P;
	cin >> T >> P;

    getFailFunc(P);

    KMP(T, P);
    if (result.empty()) cout << P << " 는 없는 단어입니다.\n";
    else {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << "인덱스부터 일치합니다.\n";
        }
    }
	

	return 0;
}
```





#### 시간복잡도

- 실패함수 계산 : Θ(*m*)
- KMP-MATCHER : Θ(*n*)

