## ZSH

 agnoster테마와 sanzzy테마를 사용하고 있다.



sanzzy는 위의 이미지와 같이 iterm에 색을 입히는 역할을 하고,

agonster는 아래의 이미지와 같이 git branch를 확인하기 쉬운 레이아웃을 제공해준다.

 

 

#### **iTerm2 다운방법 (1) : 직접 다운로드하기**

[https://www.iterm2.com](https://www.iterm2.com/)

[ iTerm2 - macOS Terminal ReplacementiTerm2 by George Nachman. Website by Matthew Freeman, George Nachman, and James A. Rosen. Website updated and optimized by HexBrainwww.iterm2.com](https://www.iterm2.com/)

  

**zsh install (shell의 확장판)**

| 1    | brew install zsh | [cs](http://colorscripter.com/info#e) |
| ---- | ---------------- | ------------------------------------- |
|      |                  |                                       |

 

**Oh my ZSH설치 (zsh의 플러그인)**

| 1    | sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)" | [cs](http://colorscripter.com/info#e) |
| ---- | ------------------------------------------------------------ | ------------------------------------- |
|      |                                                              |                                       |

 

 

## snazzy color theme 적용하기

sanzzy 테마를 다운로드하도록 한다.
link : [snazzy](https://raw.githubusercontent.com/sindresorhus/iterm2-snazzy/master/Snazzy.itermcolors)

이외에 다른 테마는 https://iterm2colorschemes.com/에서 받을 수 있다.

 

이후 iterm preferences를 열어서 profiles -> colors를 들어간다.

![img](https://blog.kakaocdn.net/dn/bLpPPW/btqyYPrJRKf/0Om21wTBJfEJEkFIOFa9JK/img.png)



그리고 우측 하단에 color presets를 누른 후 import를 선택하여서 방금 전에 받은 snazzy 테마를 받아준다.



![img](https://blog.kakaocdn.net/dn/y5gl0/btqy0FuE2qU/7KWGUAIYHBHeUt6NY4G4sk/img.png)



그럼 iterm의 색이 snazzy로 바뀐 것을 알 수 있을 것이다.

 

## agnoster theme로 변경하기

터미널에서 **code ~/.zshrc** 를 입력한다. 필자는 VSCode를 이용하기 때문에 code를 입력한 것이고 본인이 사용하는 에디터가 atom이라면 atom ~/.zshrc등으로 본인이 사용하는 에디터로 열어주면 된다.



![img](https://blog.kakaocdn.net/dn/dpfVVd/btqyYQxqPWZ/VIZpJP9eiAZGfMUWYBsBk0/img.png)



 

에디터에 들어가면 ZSH_THEME라는 코드를 볼 수 있는데 해당 코드를 아래 이미지와 같이 바꾸어 agnoster로 바꾸어 준다.



![img](https://blog.kakaocdn.net/dn/myAbz/btqy0Gf3LAL/SaEbO0DlEAwB6uGq8DpLv0/img.png)



 

 

## Font 변경하기

이후로 폰트를 바꾸어줘야 한다. 필자는 Naver D2 font를 선호한다. 아래의 링크에서 다운로드하여주자.

https://github.com/naver/d2codingfont

[ naver/d2codingfontD2 Coding 글꼴. Contribute to naver/d2codingfont development by creating an account on GitHub.github.com](https://github.com/naver/d2codingfont)

 

그리고 iTerm preference에서 이번엔 Text 탭으로 들어가서 font를 방금 다운로드한 D2 font로 변경해준다.



![img](https://blog.kakaocdn.net/dn/bRf1xm/btqyZsixsaM/FkcYTV9VSuOmlMuNZNmpNK/img.png)



 

## 터미널에 사용자 이름 삭제하기



![img](https://blog.kakaocdn.net/dn/oYXHy/btqzK0rqLdi/tYExMG7R1D5oWOavhaIXK1/img.png)



터미널에 사용자 이름을 사용하는 나타내는 영역이 매우 길기 때문에 이 부분을 아래와 같이 사용자이름을 제외한 다른 영역을 지워주도록 하겠다.



![img](https://blog.kakaocdn.net/dn/bQdGKX/btqzJFuM2wL/qfOTMYt9wm6IiATgpyZXVk/img.png)



code ~/.zshrc를 한 이후에 아래 코드를 추가해준다.

```
prompt_context() {
  if [[ "$USER" != "$DEFAULT_USER" || -n "$SSH_CLIENT" ]]; then
    prompt_segment black default "%(!.%{%F{yellow}%}.)$USER"
  fi
}
```

 

 

 

 

## New Line 적용하기 (option)

터미널의 명령어가 길어지다 보면 화면을 벗어나는 경우가 있다. 이러한 경우 터미널 입력 어를 new line으로 입력함으로 불편을 해소할 수 있다.



![img](https://blog.kakaocdn.net/dn/bHrl1z/btqyYPkYjtX/ALGobKgQhkucznhqeCzz4k/img.png)



agnoster 테마를 설치한 기준으로 쉘에 아래의 명령어를 입력해준다.

**code ~/.oh-my-zsh/themes/agnoster.zsh-theme**

 

그 후 아래를 내려가다가 build_prompt()를 찾아준다. 그리고 **prompt_newline**을 prompt_hg와 promt_end사이에 넣어준다.

| 123456789101112 | build_prompt() { RETVAL=$? prompt_status prompt_virtualenv prompt_context prompt_dir prompt_git prompt_bzr prompt_hg prompt_newline //이부분을 추가 꼭 순서 지켜서 prompt_end}[Colored by Color Scripter](http://colorscripter.com/info#e) | [cs](http://colorscripter.com/info#e) |
| --------------- | ------------------------------------------------------------ | ------------------------------------- |
|                 |                                                              |                                       |

 

그리고 코드의 제일 하단에 내려가서 다음 코드를 입력해준다.

(prompt_newline() 에 대한 기능정의)

| 1234567891011 | prompt_newline() { if [[ -n $CURRENT_BG ]]; then  echo -n "%{%k%F{$CURRENT_BG}%}$SEGMENT_SEPARATOR%{%k%F{blue}%}$SEGMENT_SEPARATOR" else  echo -n "%{%k%}" fi  echo -n "%{%f%}" CURRENT_BG=''}[Colored by Color Scripter](http://colorscripter.com/info#e) | [cs](http://colorscripter.com/info#e) |
| ------------- | ------------------------------------------------------------ | ------------------------------------- |
|               |                                                              |                                       |

 



 

## 쉘에 이모티콘 적용하기 (option)



![img](https://blog.kakaocdn.net/dn/vADoJ/btqy0pFF1dc/LhycIKRstk6iTobQ3g2ujk/img.png)



 

위의 이미지를 보면 쉘에 사용자 이름 옆에 이모티콘이 나타나는 것을 볼 수 있다. 해당 기능을 사용하는 방법을 알아보겠다.

 

역시나 **code ~/.zshrc** 명령어로 에디터를 열어준다.

 

그리고

| 1234567 | prompt_context() {  # Custom (Random emoji)  emojis=("⚡️" "🔥" "🇰" "👑" "😎" "🐸" "🐵" "🦄" "🌈" "🍻" "🚀" "💡" "🎉" "🔑" "🚦" "🌙") RAND_EMOJI_N=$(( $RANDOM % ${#emojis[@]} + 1))  prompt_segment black default "{하고싶은이름} ${emojis[$RAND_EMOJI_N]} " } [Colored by Color Scripter](http://colorscripter.com/info#e) | [cs](http://colorscripter.com/info#e) |
| ------- | ------------------------------------------------------------ | ------------------------------------- |
|         |                                                              |                                       |

코드를 입력해준다.

( **{하고싶은이름}** 이부분을 원하는 텍스트로 바꾸면 된다 ) 









```
[oh-my-zsh] Insecure completion-dependent directories detected:
lrwxr-xr-x  1 rafael  admin  88 Apr 28 15:51 /usr/local/share/zsh/site-functions/_brew_services -> ../../../Homebrew/Library/Taps/homebrew/homebrew-services/completions/zsh/_brew_services
[oh-my-zsh] For safety, completions will be disabled until you manually fix all
[oh-my-zsh] insecure directory permissions and ownership and restart oh-my-zsh.
[oh-my-zsh] See the above list for directories with group or other writability.
```

```
chmod 755 /usr/local/share/zsh
chmod 755 /usr/local/share/zsh/site-functions
```





1. [zsh-autosuggestion](https://github.com/zsh-users/zsh-autosuggestions) 설치

   ```
   brew install zsh-autosuggestions
   source /usr/local/share/zsh-autosuggestions/zsh-autosuggestions.zsh
   ```

2. [zsh-syntax-highlighting](https://github.com/zsh-users/zsh-syntax-highlighting) 설치

   ```
   brew install zsh-syntax-highlighting 
   source /usr/local/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
   ```



4. Fasd

가장 많이 사용하게 되는 플러그인입니다. 평소 자주 액세스 하게 되는 리소스를 기준으로 자동완성을 제공합니다. 별도의옵션을 주지 않으면 가장 많이 매칭 되는 곳 기준으로 보여주고 -i 옵션을 준다면 직접 선택할 수 있습니다. 이외에 최신순 이동도 가능합니다.

## 사용예시

![Image for post](https://miro.medium.com/freeze/max/60/1*t0KAoCrpDhsPaMwxKvJtWg.gif?q=20)

![Image for post](https://miro.medium.com/max/1092/1*t0KAoCrpDhsPaMwxKvJtWg.gif)

f -e vim zsh 만 입력해도 zsh가 매칭 되는 파일을 찾아 vim으로 실행하게 됩니다. 기본값은 가장 많은 액세스이지만 -t 옵션으로 최신순 이동도 가능합니다.

![Image for post](https://miro.medium.com/freeze/max/60/1*AIQMVmv241sRAhadYX4T8w.gif?q=20)

![Image for post](https://miro.medium.com/max/1092/1*AIQMVmv241sRAhadYX4T8w.gif)

fasd_cd 명령어는 cd명령어와 함께 사용하는 fasd입니다. z(=jump) 명령어는 매칭 되는 텍스트만 입력하면 가장 많이 접근한 디렉터리로 이동합니다. 이처럼 기본으로 제공하는 alias는 아래와 같습니다.

```
alias a='fasd -a'        # any 이동
alias s='fasd -si'       # interactive + select
alias d='fasd -d'        # 디렉터리찾기
alias f='fasd -f'        # 파일찾기
alias sd='fasd -sid'     # 디렉터리 선택
alias z='fasd_cd -d'     # 디렉터리 이동
alias zz='fasd_cd -d -i' # 디렉터리 선택 후 이동
```

## 설치법

```
## 설치
brew install fasd 
plugins=(
  ...
  fasd
)
```



5. Ripgrep

plugins=(... ripgrep)

디렉터리 안의 파일내용들을 정규식으로 찾아주는 무지막지(?)한 플러그인입니다. 정말 많은 옵션을 제공해서 정규식 검색뿐 아니라 특정 인코딩, 파일명 정규식 일치, 압축파일 검색 등등 다양한 옵션을 제공합니다.



6. Bat

brew install bat

cat대신 사용하기 좋은 플러그인입니다. 역시 최고의 장점은 미리 설정된 syntax highlighting과 git diff 연동입니다.



7. Fd

brew install fd

```
fd -e jpg # 확장자 jpg만 검색
fd -e kt math # kt확장자중 math검색
fd -e kt math-E util# util이 포함된 검색결과는 제외#숨김파일포함 Downloads 폴더에서 DS_Store파일을 찾기 
fd -H '^\.DS_Store$' ~/Downlaods 
```