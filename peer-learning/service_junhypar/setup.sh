#!/bin/env bash -e

RED="\033[31m"
BLUE="\033[34m"
B_BLUE="\033[34;1m"
B_GREEN="\033[31;1m"
BOLD="\033[01m"
WHITE="\033[0m"

echo $B_BLUE
echo "
███████╗████████╗     ███████╗███████╗██████╗ ██╗   ██╗██╗ ██████╗███████╗
██╔════╝╚══██╔══╝     ██╔════╝██╔════╝██╔══██╗██║   ██║██║██╔════╝██╔════╝
█████╗     ██║        ███████╗█████╗  ██████╔╝██║   ██║██║██║     █████╗
██╔══╝     ██║        ╚════██║██╔══╝  ██╔══██╗╚██╗ ██╔╝██║██║     ██╔══╝
██║        ██║███████╗███████║███████╗██║  ██║ ╚████╔╝ ██║╚██████╗███████╗
╚═╝        ╚═╝╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚═╝ ╚═════╝╚══════╝
"
echo $RED
echo $BOLD
echo  "Start Build Minikube(Virtualbox)"
echo $WHITE

export MINIKUBE_HOME=~/goinfre

#docker pull k8s.gcr.io/kubernetes-dashboard-amd64:v1.10.1

minikube delete
minikube start --driver=virtualbox

eval $(minikube docker-env)
MINIKUBE_IP=$(minikube ip)

echo $RED
echo $BOLD
echo "Doing Symlinks"

rm -rf ~/.minikube
ln -sf ~/goinfre/.minikube ~/.minikube



echo "Active Addons"

minikube addons enable metallb
echo $WHITE

echo $RED
echo $BOLD
echo "Install Alpine"
echo $WHITE

docker pull alpine:3.12

echo $RED
echo $BOLD
echo "Docker Build"
echo $WHITE


sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/nginx/srcs/nginx_data.conf > ./srcs/nginx/srcs/nginx.conf

sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/wordpress/wordpress_data.sql > ./srcs/wordpress/wordpress.sql

docker build -t nginx srcs/nginx #> /dev/null 2>&1 ;;> /dev/null은 이과정의 메시지를 화면에표시하지않게해주는 명령어 2>&1 은 이과정중 나오는 에러메시지까지 다 가려주는 커멘드(안쓸꺼임)
docker build -t ftps srcs/ftps
docker build -t mysql srcs/mysql
docker build -t phpmyadmin srcs/phpmyadmin
docker build -t wordpress srcs/wordpress
docker build -t influxdb srcs/influxdb
docker build -t telegraf srcs/telegraf
docker build -t grafana srcs/grafana


echo $RED
echo $BOLD
echo "Apply Yaml"
echo $WHITE

#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml

#kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml

#kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" #스피커간의 통신을 암호화한다는 말

 sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/yaml_format/metalLB-format.yaml > ./srcs/yaml_active/metalLB.yaml
 sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/yaml_format/ftps-format.yaml > ./srcs/yaml_active/ftps.yaml
 sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/yaml_format/nginx-format.yaml > ./srcs/yaml_active/nginx.yaml
cp ./srcs/yaml_format/mysql-format.yaml ./srcs/yaml_active/mysql.yaml
 sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/yaml_format/wordpress-format.yaml > ./srcs/yaml_active/wordpress.yaml
 sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/yaml_format/phpmyadmin-format.yaml > ./srcs/yaml_active/phpmyadmin.yaml
cp ./srcs/yaml_format/influxdb-format.yaml ./srcs/yaml_active/influxdb.yaml
cp ./srcs/yaml_format/telegraf-format.yaml ./srcs/yaml_active/telegraf.yaml
sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" ./srcs/yaml_format/grafana-format.yaml > ./srcs/yaml_active/grafana.yaml



kubectl apply -f ./srcs/yaml_active/metalLB.yaml
kubectl apply -f ./srcs/yaml_active/nginx.yaml
kubectl apply -f ./srcs/yaml_active/ftps.yaml
kubectl apply -f ./srcs/yaml_active/mysql.yaml
kubectl apply -f ./srcs/yaml_active/phpmyadmin.yaml
kubectl apply -f ./srcs/yaml_active/wordpress.yaml
kubectl apply -f ./srcs/yaml_active/influxdb.yaml
kubectl apply -f ./srcs/yaml_active/telegraf.yaml
kubectl apply -f ./srcs/yaml_active/grafana.yaml

sh wordpress_setup.sh

echo $RED
echo $BOLD
echo  "Done"
echo $WHITE

minikube dashboard
