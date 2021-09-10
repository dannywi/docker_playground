FROM ubuntu

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y python3.8
RUN apt-get install -y build-essential
RUN apt-get install -y nodejs
RUN apt-get install -y vim
RUN apt-get install -y less
RUN apt-get install -y wget

VOLUME /home/widjad
WORKDIR /home/widjad
