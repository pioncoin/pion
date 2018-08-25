#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/..

DOCKER_IMAGE=${DOCKER_IMAGE:-pioncoin/piond-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/piond docker/bin/
cp $BUILD_DIR/src/pion-cli docker/bin/
cp $BUILD_DIR/src/pion-tx docker/bin/
strip docker/bin/piond
strip docker/bin/pion-cli
strip docker/bin/pion-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
