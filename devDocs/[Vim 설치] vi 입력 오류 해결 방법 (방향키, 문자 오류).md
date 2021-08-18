**[Vim 설치] vi 입력 오류 해결 방법 (방향키, 문자 오류)**



![img](https://t1.daumcdn.net/cfile/tistory/277AC63F558CDAA434)



Ubuntu에서 VI로 문서를 편집하다보면 방향키를 눌렀을때 

의도치 않은 문자가 입력되는 상황이 발생할 때가 있다.



VI에서 해결하기 보다 VI의 차기버전인 VIM을 설치해 문제를 간접적으로 해결해보자.



**VIM 설치 방법**

\- 터미널을 띄운다.(Ctrl + Alt + T)

\- $ sudo apt-get update 엔터

\- $ sudo apt-get install vim 엔터

\- vim ~/.vimrc (vim 설정 파일. 하이라이팅, 인덱스, 공백 칸 수등 설정을 할 수 있다.)

\- 아래 설정 내용을 입력하고 저장한다.





set number      " 줄 번호 표시set tabstop=4     " tab을 4칸으로set ignorecase   " 검색시 대소문자 구별하지 않음set hlsearch     " 검색시 하이라이트set fileencodings=utf-8,euc-kr   " 파일인코딩 형식set bs=indent,eol,start   " backspace 키 사용set ruler        " 상태표시줄 커서 위치 표시set title        " 제목 표시set showmatch   " 매칭되는 괄호 표시set nowrap     " 자동 줄바꿈 해제set wmnu      " tab 자동완성시 가능한 목록 표시 syntax on    " 문법 하이라이트



설정을 완료하고 vim으로 파일을 실행하면 아래와 같이 한결 보기 좋게 표시된다.

물론 VI에서 발생했던 입력문제도 말끔하게 해결된다.



![img](https://t1.daumcdn.net/cfile/tistory/2201784E558CE1C41C)





끝~!!