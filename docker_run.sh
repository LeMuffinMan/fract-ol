#!/bin/bash

# run this script with the set you want to display as argument 
# ./docker_run.sh mandelbrot 

if ! docker image inspect fract-ol &>/dev/null; then
  echo "➜ Building image..."
  docker build -t fract-ol .
fi

echo "➜ Running fract-ol..."
xhost +local:root
docker run -it --rm \
  --net=host --ipc=host \
  -e DISPLAY=$DISPLAY \
  -e QT_X11_NO_MITSHM=1 \
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  -v ~/.Xauthority:/root/.Xauthority:ro \
  -v $(pwd):/app \
  --privileged \
  fract-ol
xhost -local:root
