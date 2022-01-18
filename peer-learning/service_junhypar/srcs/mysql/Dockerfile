# lastest 버젼으로 하면 당겨올때 문제가 생김.
FROM alpine:3.12

RUN sed -i "s/dl-cdn.alpinelinux.org/mirrors.ustc.edu.cn/g" /etc/apk/repositories
RUN apk add mysql mysql-client

# 빈 폴더를 그냥 만들어주는 것인데 이게 없으면 에러남 ㅋㅋ 이유는 모름
RUN	mkdir -p /run/mysqld

COPY ./my.cnf /etc/.
COPY ./mysql_init.sql /mysql_init.sql 
COPY ./mysql_setup.sh /mysql_setup.sh

RUN chmod +x /mysql_setup.sh

EXPOSE 3306

ENTRYPOINT ["sh","/mysql_setup.sh"]
