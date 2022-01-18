FROM	alpine:3.12

#필요항목설치
RUN		apk update
RUN		apk add nginx 
#RUN		apk add openssh
RUN		apk add openssl
RUN		mkdir -p /run/nginx



#ssl 설정
RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Jun/CN=locaglhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN		mv localhost.dev.crt etc/ssl/certs
RUN		mv localhost.dev.key etc/ssl/private
RUN		chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key
#RUN		openssl dhparam -dsaparam -out /etc/ssl/certs/dhparam.pem 2048

#nginx 세팅시작 https://wiki.alpinelinux.org/wiki/Nginx
#RUN		adduser -D -g 'www' www
#RUN		mkdir /www
#RUN		chown -R www:www /var/lib/nginx
#RUN		chown -R www:www /www
#RUN		/etc/nginx/nginx.conf /etc/nginx/nginx.conf.orig
COPY	/srcs/nginx.conf /etc/nginx/
#COPY	/srcs/default.conf /etc/nginx/conf.d

#COPY	/srcs/index.html	/var/www/html/
COPY	/srcs/ssl_params.conf	/etc/nginx/

#ssh키 설정
#RUN adduser -D junhypar
#RUN echo "junhypar:junhypar"|chpasswd

#RUN		sed 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' -i /etc/ssh/sshd_config \
#		&& echo 'root:junhypar' | chpasswd 

#RUN		 ssh-keygen -f /etc/ssh/ssh_host_rsa_key -N '' -t rsa\
#		&& ssh-keygen -f /etc/ssh/ssh_host_dsa_key -N '' -t dsa\
#		&& mkdir -p /var/run/sshd



COPY	./srcs/start.sh		./temp/

EXPOSE	80 443 22


ENTRYPOINT ["sh","./temp/start.sh"]
#CMD ["/usr/sbin/sshd","-D"]
