# !/bin/bash

export MINIKUBE_HOME=~/goinfre

eval $(minikube docker-env)
MINIKUBE_IP=$(minikube ip)

docker images
