FROM debian:buster
LABEL maintainer="sujilee@student.42seoul.kr"

RUN apt-get update && apt-get install -y \
    openssl \ 
    wget \
    nginx \ 
    vim \
    php7.3-fpm \
    mariadb-server \
    php-mysql \
    php-mbstring

RUN	wget https://wordpress.org/latest.tar.gz
RUN	wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz

COPY    ./srcs/default ./
COPY    ./srcs/docker_run.sh ./
COPY    ./srcs/DB.sql ./
COPY    ./srcs/wp-config.php ./
COPY    ./srcs/config.inc.php ./

EXPOSE 80 433

CMD bash docker_run.sh

