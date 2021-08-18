### 이 강좌를 보면 알게 되는 것들

- Nginx에 https를 적용하는 방법
- Certbot을 사용하여 https를 적용하는 방법
- Nginx Routing

### 준비물

- 어떤 오류가 나도 "나는 괜찮아!" 라고 스스로를 다독일 수 있는 마음가짐
- 파이썬과 Nginx가 설치된 우분투 (AWS 권장)

## 1. Nginx Routing 코드 작성하기

더 자세한 설명은 [TIL - nginx 라우팅에 대하여 알아보자](https://velog.io/@pinot/nginx-포트포워딩에-대하여-알아보자) 에 있습니다!

아래 명령어를 입력해서 nginx의 sites-available 폴더로 이동해보도록 합시다.

```null
$ cd /etc/nginx/sites-available/
```

`touch` 명령어를 사용하여 https를 적용할 사이트를 추가해보도록 합시다. 저는 `kimwol.me`로 정했습니다.

```null
$ sudo touch kimwol.me
```

관리자 권한으로 자신이 선호하는 에디터를 열어, 방금 만들었던 kimwol.me 파일을 수정해보도록 하겠습니다.

```null
$ sudo vi kimwol.me
```

다음 내용을 에디터에 옮겨 적어주세요.
이 코드는 `kimwol.me` 로 들어오는 모든 요청을 `/var/www/html/static` 폴더로 이동시킨다는 내용입니다.

```null
server {
	server_name kimwol.me;
    
    location / {
      root /var/www/html/static/;
      index index.html;
      try_files $uri $uri/ =404;
    }
}
```

저장하고, 다음 명령어를 관리자 권한으로 실행해서 서버에 연결시켜 주세요.

```null
$ sudo ln -s /etc/nginx/sites-available/kimwol.me /etc/nginx/sites-enabled/kimwol.me
```

만약 자신의 코드가 잘 적용 되었나 확인하려면, 다음 명령어를 실행해보세요. 내용이 주석처럼 나타나지 않고, 오류가 나타난다면 코드를 다시 한번 확인해보세요.

```null
$ sudo nginx -t
// nginx: the configuration file /etc/nginx/nginx.conf syntax is ok
// nginx: configuration file /etc/nginx/nginx.conf test is successful
```

위와 같이 설정 검사를 통과한다면, `sudo service nginx restart` 커맨드를 실행하여 서버에 적용시켜 주세요.

## 2. CertBot 다운로드 하기

`apt` 에 있는 CertBot 패키지도 있지만, 업데이트가 뜸한 편입니다.
우리는 레포지토리를 등록하여 패키지를 다운로드 받아 보겠습니다.

```null
$ sudo add-apt-repository ppa:certbot/certbot
```

`enter`를 눌러 확인한 다음, Certbot 패키지를 설치해주세요.

```null
$ sudo apt-get install python-certbot-nginx
```

설치가 완료 되었다면, 다음 단계로 넘어가셔도 좋습니다.

## 3. SSL 설치하기

이제 모든 준비가 끝났습니다!
콘솔에 다음 명령어를 입력하여 인증서를 설치해보도록 합시다.
*`-d` 인자 뒤에 지정할 도메인을 입력해주세요*

```null
$ sudo certbot --nginx -d kimwol.me
```

이메일 등록과, 약관에 동의하시면 기존 http 연결을 어떻게 설정할 것인가에 대한 질문이 나타나게 됩니다. 아래 목록을 확인하시고 원하시는 설정을 입력해주세요.

- **1**을 입력한다면 http 연결을 https로 리다이렉트 하지 않습니다.
- **2**를 입력한다면 https 연결을 https 로 리다이렉트 시킵니다.

1 또는 2를 입력하시고 엔터를 누르시면, 구성이 업데이트 되고 Nginx 서버가 재시작됩니다.

콘솔에 다음과 같은 메시지가 나타나게 된다면, 성공한겁니다!

```null
IMPORTANT NOTES:
 - Congratulations! Your certificate and chain have been saved at:
   /etc/letsencrypt/live/example.com/fullchain.pem
   // 공개 키가 저장된 장소
   Your key file has been saved at:
   /etc/letsencrypt/live/example.com/privkey.pem
   // 비밀 키가 저장 된 장소
   Your cert will expire on 2018-07-23. To obtain a new or tweaked
   version of this certificate in the future, simply run certbot again
   with the "certonly" option. To non-interactively renew *all* of
   your certificates, run "certbot renew"
   // 인증서는 설치가 완료된 이후 90일 까지만 유효합니다, 90일 전에 
"certbot new" 명령어를 실행해 인증서를 갱신하세요.
 - Your account credentials have been saved in your Certbot
   configuration directory at /etc/letsencrypt. You should make a
   secure backup of this folder now. This configuration directory will
   also contain certificates and private keys obtained by Certbot so
   making regular backups of this folder is ideal.
   // 인증서가 /etc/letsencrypt 폴더에 저장되어 있습니다. 당신은 이 개인 키와 공개 키를 안전한 장소에 보관하는것을 추천합니다
 - If you like Certbot, please consider supporting our work by:
     // 만약 Certbot에 만족하셨다면, 커피 한잔 사주세요 :)

   Donating to ISRG / Let's Encrypt:   https://letsencrypt.org/donate
   Donating to EFF:                    https://eff.org/donate-le
```



## 부록 : 자동 갱신 테스트 해보기

CertBot으로 만들어진 인증서는, 90일마다 갱신해주어야 합니다.
설치를 하는 과정에서, `/etc/cron.d`에 자동으로 갱신 시켜주는 커맨드가 추가되어 있습니다.
만약 테스트를 해보고 싶으시다면, 아래 명령어를 입력하시면 됩니다 :)

```null
$ sudo certbot renew --dry-run
```



## 인증서 만료일 확인하기

Certbot으로 부터 발급받은 인증서들에 대한 정보를 표시합니다.

```
$ certbot certificates
```

------



## 자동 갱신하기

그런데 이걸 3개월 알람을 맞춰두고 매 번 사람이 하는 것 까먹을 수도 있고 여간 불편한게 아닙니다. 걱정하지 마세요. 우리에겐 크론탭(Crontab)이 있습니다. Crontab은 정해진 일시에 반복적으로 특정 작업을 할 수 있는 프로그램이고 우분투에 기본적으로 설치되어 있습니다.

간단한 Crontab 명령과 규칙을 살펴보겠습니다.

**자주쓰는 명령 2개**

```
# Crontab 보기
$ sudo crontab -l

# Crontab 편집
$ sudo crontab -e

# Crontab 실행 로그
$ view /var/log/syslog
```

crontab 명령어 앞에 sudo를 써준 것은 root 권한의 크론탭을 수정하고 보겠다는 의미입니다. 각자 웹서버와 인증서를 관리하는 사용자 계정의 크론탭을 이용하면 됩니다. certbot을 그냥 설치했을 때 /etc/letsencrypt에 인증서를 쓸 권한이 필요하므로 여기서는 sudo 를 붙여주었습니다.

**규칙**![http://www.ostechnix.com/wp-content/uploads/2018/05/cron-job-format-1.png](https://www.ostechnix.com/wp-content/uploads/2018/05/cron-job-format-1.png)

위 그림처럼 분, 시, 일, 월, 요일, 명령 순서로 기재하면 됩니다.
예를 들어, /home/user/run.sh를 실행하고 싶다면

```
# 매 시 10분에 
$ 10 * * * * /home/user/run.sh

# 10분 마다 주기적으로 
$ */10 * * * * /home/user/run.sh

# 토요일 새벽 3시에
$ 0 3 * * 6 /home/user/run.sh
```

이렇게 하면 됩니다.

------

## 인증서 갱신하기

만약 매월 1일 03시에 인증서를 갱신하고 싶다면 아래와 같이 설정하면 됩니다.

```
$ 0 18 1 * * /usr/bin/certbot renew --renew-hook="sudo service nginx reload"
```

위에 새벽 3시인데 크론탭에는 18시라고 쓴 것은 서버 시간에 맞췄기 때문입니다. `date` 명령으로 자신의 서버 시간을 확인하고 시간을 설정하세요. [이 페이지](https://www.worldtimebuddy.com/kst-to-utc-converter)에서 시간을 쉽게 변환해볼 수 있습니다.

뒤에 나오는 [–renew-hook](https://certbot.eff.org/docs/using.html#pre-and-post-validation-hooks)은 인증서 갱신을 성공적으로 마치면 아파치를 재시작하기 위해 넣어주었습니다. 인증서 갱신 전에 실행되는 `--pre-hook`도 있습니다.