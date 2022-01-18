# !/bin/bash

export MINIKUBE_HOME=~/goinfre

eval $(minikube docker-env)
MINIKUBE_IP=$(minikube ip)

echo "docker ps\n"
docker ps

echo "\ndocker ps -a\n"

docker ps -a
