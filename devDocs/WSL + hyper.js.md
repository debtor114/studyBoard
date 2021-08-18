# WSL설치 및 설정



### WSL 설치

1. 제어판 - 프로그램 - windows 기능 켜기/끄기 - Linux용 Windows 하위 시스템 체크 후 재부팅

<img src="C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20201018175641972.png" alt="image-20201018175641972" style="zoom:50%;" /> 

<img src="C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20201018175756720.png" alt="image-20201018175756720" style="zoom:50%;" /> 

<img src="C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20201018175850770.png" alt="image-20201018175850770" style="zoom:67%;" /> 



2. Microsoft Store 앱을 켠후 Ubuntu 다운로드

<img src="C:\Users\KDI\AppData\Roaming\Typora\typora-user-images\image-20201018180014536.png" alt="image-20201018180014536" style="zoom:50%;" /> 

실행 후 root username과 password를 설정





### Hyper.js 

#### 설치

[Hyper](https://hyper.is/)에 접속 후 다운로드



#### 설정

Hyper 터미널을 열고 `Ctrl + ,`를 눌러 preference를 열고 아래의 내용을 붙여넣는다

```json
// Future versions of Hyper may add additional config options,
// which will not automatically be merged into this file.
// See https://hyper.is#cfg for all currently supported options.

module.exports = {
  config: {
    // choose either `'stable'` for receiving highly polished,
    // or `'canary'` for less polished but more frequent updates
    updateChannel: 'canary',

    // default font size in pixels for all tabs
    fontSize: 12,

    // font family with optional fallbacks
    fontFamily: 'Menlo, "DejaVu Sans Mono", Consolas, "Lucida Console", monospace',

    // default font weight: 'normal' or 'bold'
    fontWeight: 'normal',

    // font weight for bold characters: 'normal' or 'bold'
    fontWeightBold: 'bold',

    // line height as a relative unit
    lineHeight: 1,

    // letter spacing as a relative unit
    letterSpacing: 0,

    // terminal cursor background color and opacity (hex, rgb, hsl, hsv, hwb or cmyk)
    cursorColor: 'rgba(248,28,229,0.8)',

    // terminal text color under BLOCK cursor
    cursorAccentColor: '#000',

    // `'BEAM'` for |, `'UNDERLINE'` for _, `'BLOCK'` for █
    cursorShape: 'BLOCK',

    // set to `true` (without backticks and without quotes) for blinking cursor
    cursorBlink: false,

    // color of the text
    foregroundColor: '#fff',

    // terminal background color
    // opacity is only supported on macOS
    backgroundColor: '#000',

    // terminal selection color
    selectionColor: 'rgba(248,28,229,0.3)',

    // border color (window, tabs)
    borderColor: '#333',

    // custom CSS to embed in the main window
    css: '',

    // custom CSS to embed in the terminal window
    termCSS: '',

    // if you're using a Linux setup which show native menus, set to false
    // default: `true` on Linux, `true` on Windows, ignored on macOS
    showHamburgerMenu: '',

    // set to `false` (without backticks and without quotes) if you want to hide the minimize, maximize and close buttons
    // additionally, set to `'left'` if you want them on the left, like in Ubuntu
    // default: `true` (without backticks and without quotes) on Windows and Linux, ignored on macOS
    showWindowControls: '',

    // custom padding (CSS format, i.e.: `top right bottom left`)
    padding: '12px 14px',

    // the full list. if you're going to provide the full color palette,
    // including the 6 x 6 color cubes and the grayscale map, just provide
    // an array here instead of a color map object
    colors: {
      black: '#000000',
      red: '#C51E14',
      green: '#1DC121',
      yellow: '#C7C329',
      blue: '#0A2FC4',
      magenta: '#C839C5',
      cyan: '#20C5C6',
      white: '#C7C7C7',
      lightBlack: '#686868',
      lightRed: '#FD6F6B',
      lightGreen: '#67F86F',
      lightYellow: '#FFFA72',
      lightBlue: '#6A76FB',
      lightMagenta: '#FD7CFC',
      lightCyan: '#68FDFE',
      lightWhite: '#FFFFFF',
    },

    // the shell to run when spawning a new session (i.e. /usr/local/bin/fish)
    // if left empty, your system's login shell will be used by default
    //
    // Windows
    // - Make sure to use a full path if the binary name doesn't work
    // - Remove `--login` in shellArgs
    //
    // Bash on Windows
    // - Example: `C:\\Windows\\System32\\bash.exe`
    //
    // PowerShell on Windows
    // - Example: `C:\\WINDOWS\\System32\\WindowsPowerShell\\v1.0\\powershell.exe`
    shell: 'C:\\WINDOWS\\System32\\wsl.exe',

    // for setting shell arguments (i.e. for using interactive shellArgs: `['-i']`)
    // by default `['--login']` will be used
    shellArgs: [],

    // for environment variables
    env: {},

    // set to `false` for no bell
    bell: 'SOUND',

    // if `true` (without backticks and without quotes), selected text will automatically be copied to the clipboard
    copyOnSelect: false,

    // if `true` (without backticks and without quotes), hyper will be set as the default protocol client for SSH
    defaultSSHApp: true,

    // if `true` (without backticks and without quotes), on right click selected text will be copied or pasted if no
    // selection is present (`true` by default on Windows and disables the context menu feature)
    quickEdit: false,

    // choose either `'vertical'`, if you want the column mode when Option key is hold during selection (Default)
    // or `'force'`, if you want to force selection regardless of whether the terminal is in mouse events mode
    // (inside tmux or vim with mouse mode enabled for example).
    macOptionSelectionMode: 'vertical',

    // URL to custom bell
    // bellSoundURL: 'http://example.com/bell.mp3',

    // Whether to use the WebGL renderer. Set it to false to use canvas-based
    // rendering (slower, but supports transparent backgrounds)
    webGLRenderer: true,

    // for advanced config flags please refer to https://hyper.is/#cfg
  },

  // a list of plugins to fetch and install from npm
  // format: [@org/]project[#version]
  // examples:
  //   `hyperpower`
  //   `@company/project`
  //   `project#1.0.1`
  plugins: [
    "hyper-highlight-active-pane",
    "hyper-fading-scrollbar",
    "hyper-active-tab",
    "hyper-single-instance",
    "hyper-opacity",
    "hyper-aura-theme"
  ],

  // in development, you can create a directory under
  // `~/.hyper_plugins/local/` and include it here
  // to load it and avoid it being `npm install`ed
  localPlugins: [],

  keymaps: {
    // Example
    // 'window:devtools': 'cmd+alt+o',
  },
};

```

공식 홈페이지에 가면 더 많은 플러그인과 테마를 만나볼 수 있다. 



### ZSH 설치

```bash
sudo apt-get update
```



- zsh 설치

```bash
sudo apt-get install zsh

sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
```

터미널을 종료 후 zsh이 기본쉘로 적용이 되지 않았다면 아래의 명령어를 실행한다.

```bash
sudo chsh <root_username> -s $(which zsh)
```



- zsh  플러그인 설치

```bash
git clone https://github.com/zsh-users/zsh-autosuggestions $ZSH_CUSTOM/plugins/zsh-autosuggestions
```



- 터미널 깔끔하게 하기 및 플러그인 적용

```bash
vi ~/.zshrc

맨 아랫줄에

prompt_context() {
        if [[ "$USER" != "$DEFAULT_USER" || -n "$SSH_CLIENT" ]]; then
                prompt_segment black default "%(!.%{%F{yellow}%}.)$USER"
        fi
}

입력

plugins=( git ) => plugins=( git zsh-autosuggestions )

저장하고 나오기 

source ~/.zshrc
```





### Node

- 설치

```bash
curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.33.11/install.sh | zsh

source ~/.zshrc

nvm install 14.8.0 (버전은 원하는 버전)
node -v // v14.8.0
npm -v // 6.14.7

sudo apt-get install node-gyp
```



### Python

```bash
sudo apt-get install python
```



### GCC, G++

```bash
sudo apt-get install gcc
sudo apt-get install g++
```

좀 오래걸린다 참자.





VScode git 계정 세팅

```bash
git config --global user.name "doooooooong" 
git config --global user.email "21500002@handong.edu" 
```



```bash
...
...
git push -u origin master
```

후에 인증을 하면

`~/.vscode-server/bin/<autorized_key_value>` 디렉토리가 생기면서 앞으로는 깃 계정과 비밀번호를 묻지 않는다.





### Angular.js

- 설치

```bash
npm install -g typescript
npm install -g @angular/cli
```



- 확장프로그램

![img](https://blog.kakaocdn.net/dn/d3SqXB/btqv0eIJWhD/srHeZ1lTOFfkIx0CUl3qV1/img.png)아랫부분을 클릭후에 korean이라 입력하면 한글 확장팩을 설치 할 수 있다.



![img](https://blog.kakaocdn.net/dn/ceFxdz/btqv4skYnPc/2UBLvXmXU6IXX6rbfitbgK/img.png)





### Mysql

- 설치

```bash
sudo apt-get install mysql-server
```



- 실행

```bash
sudo service mysql start
```



- 에러

```bash
ERROR 2002 (HY000): Can't connect to local MySQL server through socket  '/var/run/mysqld/mysqld.sock' (2)
```

이미 윈도우에 mysql 워크벤치를 설치해서 사용중이라 포트 충돌이 나는 것

```bash
vi /etc/mysql/mysql.conf.d/mysqld.cnf
```



```mysql
[mysqld]#
# * Basic Settings#
user            = mysql
# pid-file      = /var/run/mysqld/mysqld.pid
# socket        = /var/run/mysqld/mysqld.sock
port            = 3307
# datadir       = /var/lib/mysql
```

포트 번호를 바꿔준다.





### 방법 1

```bash
mysql_secure_installation

Securing the MySQL server deployment.
Enter password for user root:  
```

떳을 때 그냥 enter를 눌러서 접속이 안된다면 2번으로



### 방법 2

```
$ sudo mysql -u root -p
```

엔터를 누르면 들어가진다.



비밀번호 인증 모드로 변경

```mysql
> ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'PWD';
```



적용하기

```
> FLUSH PRIVILEGES;
```



