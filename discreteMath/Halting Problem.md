# Halting Problem

**정지 문제**는 "주어진 프로그램이 해결하고자 하는 문제를 해결하는지 말해줄 수 있는 일반화된 알고리즘이 존재하는가?" 라는 질문이다. 이 문제 자체가 이해가 안되는 사람들을 위해 쉽게 설명한 영상을 가져왔다.

https://www.youtube.com/watch?v=92WHN-pAFCs

위의 영상에서 정지문제 자체에 대한 설명과 귀류증명과정을 정말 알기 쉽게 설명했다. 꼭 한번 보는 것을 추천한다.



### 정지 문제란? (쉬운 설명)

산술식을 받아서 결과값을 출력하는 기계 A가 있다고 가정해보자. 이 기계 A는 항상 옳은 답을 출력한다.

<img src="https://github.com/doooooooong/studyBoard/blob/master/discreteMath/images/image-20210812013625833.png?raw=true" alt="image-20210812013625833" style="zoom:50%;" />





또 체스를 두는 기계 C가 있다고 가정해보자. 이 기계는 현재의 체스판 상태를 입력을 받아서 다음 수를 출력한다. 이 기계 C는 체스를 너무 잘해서 항상 이기는 수만 둔다.

<img src="https://github.com/doooooooong/studyBoard/blob/master/discreteMath/images/image-20210812013716714.png?raw=true" alt="image-20210812013716714" style="zoom:50%;" />



점점 인류는 이보다 고도화된 기계를 만들며 그렇다면 결국 컴퓨터는 모든 것을 해낼 수 있지 않을까?

그래서 프로그래머들은 H라는 기계를 고안했다. 기계 H는 다른 기계의 설계도와 입력값을 받아 입력으로 받은 기계가 처리할 수 있을지 예측하는 기계이다.



 위에서 살펴본 **기계 A의 설계도**와 "**3+5**"라는 입력을 받으면 A기계는 정수의 합을 출력할 수 있으므로 기계 H는 잘 작동한다 라는 결과값을 출력한다. 마찬가지로 기계 H도 항상 옳은 답만을 출력한다.

<img src="https://github.com/doooooooong/studyBoard/blob/master/discreteMath/images/image-20210812013845159.png?raw=true" alt="image-20210812013845159" style="zoom:50%;" />





만약 기계 C의 설계도와 "3+5"라는 입력을 기계 H에게 주면, 잘 작동하지 않는다라는 결과를 출력할 것이다.

<img src="https://github.com/doooooooong/studyBoard/blob/master/discreteMath/images/image-20210812013942622.png?raw=true" alt="image-20210812013942622" style="zoom:50%;" />

정지문제는 이런 **기계 H를 만드는 것이 가능한 것인가?** 를 묻는 것이라고 할 수 있다.







### 정지문제의 증명

대락적인 증명법을 보자면, 귀류법을 이용한 증명방법이 있다. 즉, 해결방법이 있다라는 가정에서 모순이 발생한다는 것을 보임으로써 증명한다. 즉 증명하고자 하는 것은 "**정지 문제를 판별하는 알고리즘이 없다**"라는 명제이므로, 귀류법을 위해 "**정지문제를 판별하는 알고리즘이 있다**"고 전제함으로서 시작한다.



기계 H가 존재한다는 가정을 하자. H는 항상 올바른 답을 낸다.

우리는 이제 H가 자가모순에 빠지도록 기계를 설계해볼 것이다.

새로운 기계 P가 있다. 이 기계는 하나의 입력을 받으며 입력을 받은 것을 두 개의 동일한 것으로 출력해준다.

<img src="https://github.com/doooooooong/studyBoard/blob/master/discreteMath/images/image-20210812014218563.png?raw=true" alt="image-20210812014218563" style="zoom:50%;" />



또 새로운 기계 N이 있다. 이 기계는 **잘 작동한다 / 잘 작동하지 않는다** 두가지 상태를 입력으로 받으며, 입력이 **잘 작동한다**로 들어왔을 때, 결과는 잘 작동하지 않게 되며, 입력이 **잘 작동하지 않는다**로 들어왔을 때  잘작동했습니다. 라는 사인의 웃는 얼굴을 출력한다.

![image-20210812014559975](https://github.com/doooooooong/studyBoard/blob/master/discreteMath/images/image-20210812014559975.png?raw=true)





이 기계들을 아래와 같이 설치하고 이를 묶어서 X 기계라고 하자.

![image-20210812015419022](https://github.com/doooooooong/studyBoard/blob/master/discreteMath/images/image-20210812015419022.png?raw=true) 





이 X라는 기계에 X 자신의 설계도를 입력으로 줘보면 어떠한 일이 일어나는지 살펴보자.



두가지 경우가 발생가능하다.

**첫 번째**는 X안의 H기계가 X가 잘 작동한다고 결과를 낸 경우이다.

<img src="https://github.com/doooooooong/studyBoard/blob/master/discreteMath/images/image-20210812015758362.png?raw=true" alt="image-20210812015758362" style="zoom:50%;" />

H는 X가 잘 작동할 것이라고 판별했지만 실제로 X는 오류가 나고 기계가 덜덜덜 떨린다.

 

두번째 경우는 X안의 H기계가 X가 오류를 발생시킬 것이라고 결과를 낸 경우이다.

<img src="https://github.com/doooooooong/studyBoard/blob/master/discreteMath/images/image-20210812015842261.png?raw=true" alt="image-20210812015842261" style="zoom:50%;" />

하지만 기계 X는 잘 작동하여 :) 기호를 내놓았다.

H는 모든 경우에서 항상 올바른 답을 내놓아야핱다는 전제에 위배된다. 따라서 H라는 기계는 이 세상에 존재할 수 없게 되는 것이다.

개어거지인것 같지만 논리상으로 맞으니.. 뭐..





#### 코드로 보는 정지문제의 증명

앞에서 언급한 모든 기계는 유한개의 input을 받아 유한개의 output을 내놓았기 때문에 각각을 함수라고 할 수 있다. 특히 기계 H는 다른 기계의 설계도면과 데이터를 받아 참/거짓을 구별한다. 

즉, H기계를  `exit(P, I)`라는 함수라고 하자.

- P: 사용될 임의의 프로그램
- I: 사용될 임의의 input



이 함수는 프로그램 P가  입력 I에 대해 유한한 단계 후에 정지하고 결과를 반환하면 참을, 그렇지 못하면 거짓을 반환한다. 즉  프로그램 P에 입력 I를 주면 알고리즘이 도중에 종료될 것인가 무한루프 빠질 것인가를 판별하는 함수가 된다. 

P가 함수이고 `P(I)` 가 무한 루프에 빠진다면 (기계가 답을 내지 못하고 덜덜덜 거린다면),  `exit(a, i) == false`가 성립한다.



이제 여기서 exit을 모순시키는 함수 (기계 X)를 정의하면 아래와 같다.

```javascript
function subroutine(s) {
    if exit(s,s) == false
        return true
    else
        infinite loop
}
```

위에 내용을 제대로 이해했다면 위 함수의 어느부분이 기계 N, H, P, X에 대응되는지 눈에 보일 것이다.

- 기계 X: subroutine 함수 자체
- 기계 P: s라는 input 하나를 `exit(s, s)`에 두번 넣어준 부분
- 기계 H: `exit(P, I)` 
- 기계 N:`exit(s, s)`에 결과에 반대로 값을 리턴하는 부분





##### **`exit(s, s)`가 뜻하는 것**

설계도의 입력으로 설계도를 받을 수 있는 것. 즉, 프로그램의 입력으로 프로그램을 받을 수 있다. 

간단한 예로 컴파일러의 경우 소스코드를 입력으로 받아 바이너리 파일을 만드는 프로그램이다. `subroutine`은 프로그램을 받아 그 프로그램의 입력으로 자기 자신을 되먹인다. 예를 들어 s가 컴파일러일 경우, `exit(s, s)`는 **자기 자신을 컴파일하는 중** 무한 루프에 빠지는지 여부를 검사한다.





##### **`exit(subroutine, subroutine)`은 참인가? 거짓인가?** 

위에서 본 X기계의 input을 X기계의 설계도로 준 경우이다.

- 참일 경우: `exit`의 정의에 의해 `subroutine(subroutine)`이 정상적으로 종료해야 한다. 근데 `exit(subroutine, subroutine)`이 참이라고 가정했으므로 subroutine의 조건문에 의해 무한 루프를 한다. 즉 참일 수가 없다.
- 거짓일 경우: `exit`의 정의에 의해 `subroutine(subroutine)`이 무한 루프를 돌아야 한다. 근데 `exit(subroutine, subroutine)`이 거짓이라고 가정했으므로 subroutine의 조건문에 의해 true를 리턴하고 끝난다. 즉 거짓일 수가 없다.



즉 `exit(subroutine, subroutine)`이 참도 거짓도 될 수 없다는 것이므로, 모순이 발생한 것이다. 따라서 **`exit()` 따위는 존재하지 않는다**라는 결론에 이르게 된다. 그렇다면 증명의 시작부로 쭈욱 거슬러 올라가서 `exit`이 존재하게 하는 가정, 즉 **정지 문제를 해결할 알고리즘이 존재한다**는 대전제가 붕괴하면서 증명이 종결된다.

