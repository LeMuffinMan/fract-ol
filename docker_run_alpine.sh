xhost +local:root

docker run -it --rm \
    --ipc=host \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v ~/.Xauthority:/root/.Xauthority:ro \
    -v $(pwd):/app \
    fract-ol-alpine ./fractol_bonus mandelbrot
