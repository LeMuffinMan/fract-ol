# This docker file because my fract-ol project compiles on 42 school computers, but stopped to compile on my personal laptop
# Since it seems a dependence and environment problem, it was an opportunity to practice Docker
FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    clang \
    make \
    libx11-dev \    
    libxext-dev \ 
    libbsd-dev \   
    zlib1g-dev \
    && rm -rf /var/lib/apt/lists/

RUN apt-cache policy xserver-xorg-core libx11-dev

WORKDIR /app
COPY . .

RUN make
