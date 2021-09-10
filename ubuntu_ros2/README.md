# Docker Image for ROS2 Developments
This image gives you a working GUI in the browser.

Useful commands
```bash
# BUILD IMAGE (ubuntu 20.04 base)
docker build . -t ubuntu_ros2

# RUN CONTAINER
docker run --rm -itp 6080:80 --name ub_ros2 ubuntu_ros2

# GET PROMPT
docker exec -it -w /root ub_ros2 /bin/bash

# SETUP ROS ENV (in container)
. /opt/ros/galactic/setup.bash

# GET GUI IN BROWSER
open http://127.0.0.1:6080
```
