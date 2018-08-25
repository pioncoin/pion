FROM debian:stretch
LABEL maintainer="Pion Developers <dev@pioncoin.org>"
LABEL description="Dockerised PionCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/
