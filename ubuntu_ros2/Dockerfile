FROM dorowu/ubuntu-desktop-lxde-vnc

ENV DEBIAN_FRONTEND noninteractive

# Basic things
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y python3.8
RUN apt-get install -y build-essential
RUN apt-get install -y nodejs
RUN apt-get install -y vim less wget
RUN apt-get install -y git

# ROS Prerequisites
RUN apt-get install -y locales
RUN locale-gen en_US en_US.UTF-8
RUN update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
RUN export LANG=en_US.UTF-8

RUN apt install -y curl gnupg lsb-release
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key  -o /usr/share/keyrings/ros-archive-keyring.gpg
RUN echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | tee /etc/apt/sources.list.d/ros2.list > /dev/null
RUN apt update

RUN apt install -y ros-galactic-desktop python3-rosdep
RUN rosdep init
RUN rosdep update
RUN apt install -y python3-colcon-common-extensions

RUN echo ". /opt/ros/galactic/setup.bash" >> /root/.bashrc

# Workspace
USER root
WORKDIR /root
