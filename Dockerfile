# This docker file because my fract-ol project compiles on 42 school computers, but stopped to compile on my personal laptop
# Since it seems a dependence and environment problem, it was an opportunity to practice Docker
FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    clang \
    make \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    zlib1g-dev \
    xauth \          
    mesa-utils \     
    libgl1-mesa-glx \ 
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .
RUN make bonus

#docker build -t fract-ol .
#docker run -it --rm fract-ol bash

# sudo apt install xorg-xhost
# xhost +local:docker 
