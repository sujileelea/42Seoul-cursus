FROM alpine:3.12

RUN sed -i "s/dl-cdn.alpinelinux.org/mirrors.ustc.edu.cn/g" /etc/apk/repositories

RUN apk update \
		&& apk --update --no-cache add \
                influxdb

EXPOSE 8086
#기본세팅으로 시작.
CMD /usr/sbin/influxd -config /etc/influxdb.conf
