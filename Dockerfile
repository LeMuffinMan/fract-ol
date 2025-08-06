FROM ubuntu:22.04

# i choosed to build a dockerfile from my 42 session configuration : i need a specific version of clang
# override the default cc version with the one i need
# force to use clang-12 using the command cc
RUN apt-get update && apt-get install -y clang-12 \
    && update-alternatives --install /usr/bin/cc cc /usr/bin/clang-12 100 \
    && update-alternatives --set cc /usr/bin/clang-12
