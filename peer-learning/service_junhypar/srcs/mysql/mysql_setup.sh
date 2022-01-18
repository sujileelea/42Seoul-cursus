#!bin/bash

sleep 5
#mysql_server 에 초기 세팅을 해주기 위해서 mysql_install_db 를 root 로 해준다.
mysql_install_db --user=root

#bootstrap 옵션을 사용하는 이유는 mysql 서버가 시작 되기전에 먼저 db테이블이 만들어져야 하기 때문.
mysqld -u root --bootstrap < mysql_init.sql
#진짜 서버 시작.
mysqld -u root
