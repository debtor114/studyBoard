# 리눅스 서버 개발환경 세팅

## 접속 및 초기설정

- 접속

```bash
ssh ubuntu@x.x.x.x -i <key>`
```



- apt-get 업데이트

```bash
sudo apt-get update
```



## Zsh

- 설치

```bash
sudo apt-get install zsh

sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
```



- 기본 쉘 변경 (to zsh)

```bash
sudo chsh ubuntu -s $(which zsh);

하고 로그아웃하고 로그인
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





## Node

- 설치

```bash
curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.33.11/install.sh | zsh

source ~/.zshrc

nvm install 14.8.0 (버전은 원하는 버전)
node -v // v14.8.0
npm -v // 6.14.7

sudo apt-get install node-gyp
```



## Mysql

- 설치

```bash
sudo apt-get install mysql-server
```

> npm install시 오류 해결
>
> ```bash
> $ npm config set unsafe-perm=true
> ```





- 설정

```bash
// 보안관련
mysql_secure_installation 

// 외부 접속 계정
sudo mysql -u root -p
Enter password: (비밀번호 입력. 입력한 값은 표시되지 않음.)
 
INSERT INTO mysql.user (host,user,authentication_string,ssl_cipher, x509_issuer, x509_subject) VALUES ('%','root',password('root'),'','','');

GRANT ALL PRIVILEGES ON *.* TO 'root'@'%';

FLUSH PRIVILEGES;

exit

sudo vi /etc/mysql/mysql.conf.d/mysqld.cnf

# bind-address            = 127.0.0.1   # Before
bind-address            = 0.0.0.0       # After

sudo service mysql restart
```





nginx

오류시

```bash
● nginx.service - A high performance web server and a reverse proxy server
   Loaded: loaded (/lib/systemd/system/nginx.service; enabled; vendor preset: enabled)
   Active: active (running) since Thu 2020-10-15 15:24:50 UTC; 7s ago                                                                                      defaults 
  Process: 2786 ExecStop=/sbin/start-stop-daemon --quiet --stop --retry QUIT/5 --pidfile /run/nginx.pid (code=exited, status=0/SUCCESS)
  Process: 2794 ExecStart=/usr/sbin/nginx -g daemon on; master_process on; (code=exited, status=0/SUCCESS)
  Process: 2791 ExecStartPre=/usr/sbin/nginx -t -q -g daemon on; master_process on; (code=exited, status=0/SUCCESS)
 Main PID: 2797 (nginx)
    Tasks: 2
   Memory: 1.7M
      CPU: 14ms
   CGroup: /system.slice/nginx.service
           ├─2797 nginx: master process /usr/sbin/nginx -g daemon on; master_process on
           └─2799 nginx: worker process

Oct 15 15:24:50 ip-172-31-46-65 systemd[1]: Stopped A high performance web server and a reverse proxy server.
Oct 15 15:24:50 ip-172-31-46-65 systemd[1]: Starting A high performance web server and a reverse proxy server...
Oct 15 15:24:50 ip-172-31-46-65 systemd[1]: nginx.service: Failed to parse PID from file /run/nginx.pid: Invalid argument
Oct 15 15:24:50 ip-172-31-46-65 systemd[1]: Started A high performance web server and a reverse proxy server.
```



```bash
[Workaround]

sudo mkdir /etc/systemd/system/nginx.service.d
printf "[Service]\nExecStartPost=/bin/sleep 0.1\n" | \
  > sudo tee /etc/systemd/system/nginx.service.d/override.conf
sudo systemctl daemon-reload
sudo systemctl restart nginx
```



nginx 폴더구조 내려받기



방화벽 올리다가 튕기거나 실수로 나갔을 때 대처방법

1- Stop your instance

2- Go to `Instance Settings -> View/Change user Data

3- Paste this

```bash
Content-Type: multipart/mixed; boundary="//"
MIME-Version: 1.0
--//
Content-Type: text/cloud-config; charset="us-ascii"
MIME-Version: 1.0
Content-Transfer-Encoding: 7bit
Content-Disposition: attachment; filename="cloud-config.txt"
#cloud-config
cloud_final_modules:
- [scripts-user, always]
--//
Content-Type: text/x-shellscript; charset="us-ascii"
MIME-Version: 1.0
Content-Transfer-Encoding: 7bit
Content-Disposition: attachment; filename="userdata.txt"
#!/bin/bash
ufw disable
iptables -L
iptables -F
--//

```

4- Start your instance

Hope it works for you









### 인증서 SSL 서버에 설치하기

#### 시스템 확인

- Ubuntu 16.04
- 현재 도메인으로 (아이피가 아닌) http로 접속이 되어야하는 상태여야함



#### Nginx 설치

```bash
$ sudo apt-get install nginx

$ nginx -v  // 1.10.3 (Ubuntu)
```



#### Nginx 설정

SSL 인증서를 발급 받고자 하는 도메인을 Nginx에 등록해야한다. `/etc/nginx/nginx.conf` 에 다음과 같이 추가

```null
events {}

http {
	server {
    	listen 80;
        server_name url; // (Domain name required)
        
        location / {
        	return 200 "Hello, SSL!\n";
        }
    }
}
```



nginx 잘돌아가는지 확인

```bash
$ sudo service nginx reload

$ curl http://url
> Hello, SSL!
```



#### Let's Encrypt

CertBot이라는 녀석을 사용

1. 리눅스 서버 접속

2. Certbot PPA 추가

```bash
$ sudo apt update
$ sudo apt install software-properties-common
$ sudo add-apt-repository universe
$ sudo add-apt-repository ppa:certbot/certbot
$ sudo apt update
```



3. Certbot 설치

```bash
$ sudo apt install certbot python3-certbot-nginx
```



4. Certbot 실행

```bash
$ sudo certbot --nginx
```



5. 인증 확인

```bash
$ curl https://url 
 >  Hello, SSL!
```



#### 자동갱신 등록하기

```bash
$ sudo crontab -e

Select an editor.  To change later, run 'select-editor'.
  1. /bin/ed
  2. /bin/nano        <---- easiest
  3. /usr/bin/vim.basic
  4. /usr/bin/vim.tiny
```



에디터를 열어 아래를 붙여넣기하면 매월 1일 3시에 갱신

```bash
0 18 1 \* \* sudo certbot renew --renew-hook="sudo service restart nginx"
```



#### 등록 확인

```bash
$ sudo certbot certificates (--debug)

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Found the following certs:
  Certificate Name: example.com
    Domains: example.com
    Expiry Date: 2021-01-13 19:45:57+00:00 (VALID: 89 days)
    Certificate Path: /etc/letsencrypt/live/example.com/fullchain.pem        
    Private Key Path: /etc/letsencrypt/live/example.com/privkey.pem
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
```

출처: https://velog.io/@prayme/ubuntu%EC%97%90-nginx-%EC%84%A4%EC%B9%98%ED%95%98%EA%B3%A0-ssl-%EC%A0%81%EC%9A%A9%ED%95%98%EA%B8%B0





### Angluar.js

