FROM alpine:3.12.0

#RUN sed -i "s/dl-cdn.alpinelinux.org/mirrors.ustc.edu.cn/g" /etc/apk/repositories
RUN apk update \
		&& apk --update --no-cache add nginx \
				php7 php7-fpm php7-mbstring php7-session \
				php7-common php7-iconv php7-json php7-gd php7-curl php7-xml \
				php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql \
				php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap \
				php7-ctype php7-dom mysql-client

####### php-fpm health check #######
# 참조 : https://github.com/renatomefi/php-fpm-healthcheck
RUN wget -O /usr/local/bin/php-fpm-healthcheck \
			https://raw.githubusercontent.com/renatomefi/php-fpm-healthcheck/master/php-fpm-healthcheck

RUN chmod +x /usr/local/bin/php-fpm-healthcheck
RUN echo "pm.status_path = /status" >> /etc/php7/php-fpm.d/www.conf
####################################

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvf latest.tar.gz
RUN	rm -f latest.tar.gz
RUN	mv wordpress/ /var/www/
RUN mkdir -p /run/nginx
COPY wp-config.php /var/www/wordpress/
COPY default.conf /etc/nginx/conf.d/
COPY wordpress.sql /wordpress.sql
COPY wordpress_setup.sh /wordpress_setup.sh
RUN chmod +x /wordpress_setup.sh

EXPOSE 5050

#CMD php-fpm7 && nginx -g "daemon off;"

CMD /bin/sh "/wordpress_setup.sh" && php-fpm7 && nginx -g "daemon off;"
