FROM alpine:3.12
RUN sed -i "s/dl-cdn.alpinelinux.org/mirrors.ustc.edu.cn/g" /etc/apk/repositories

RUN apk update \
	&& apk --update --no-cache add \
	grafana \
	--repository=https://mirrors.ustc.edu.cn/alpine/latest-stable/community/
#repository 는 Alpine linux ERROR: unsatisfiable constraints: docker (missing): required by: world[docker] 오류해결을 위해.
#출처: https://neet.tistory.com/entry/Alpine-linux-ERROR-unsatisfiable-constraints-docker-missing-required-by-worlddocker-오류-해결방법 [자택경비대]

#influxdb 에서 데이터를 가져오겠다고 명시해준다. 아이디와 패스워드까지.
COPY influxdb.yaml /usr/share/grafana/conf/provisioning/datasources/
#대쉬보드 json 의 위치를 세팅
COPY dashboards.yaml /usr/share/grafana/conf/provisioning/dashboards/
#각각의 대쉬보드
COPY dashboards/* /var/lib/grafana/dashboards/

EXPOSE 3000
#기본세팅으로 시작.
CMD /usr/sbin/grafana-server --homepath=/usr/share/grafana
