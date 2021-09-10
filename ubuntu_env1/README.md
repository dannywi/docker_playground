# Generic Ubuntu Environment
# NOTES
```
# BUILD IMAGE 
docker build . -t ubuntu_env1

# RUN WITH VOLUME MAPPED
docker run --rm -itp 8001:8001 -v $(pwd):$(pwd) ubuntu_env1
```
