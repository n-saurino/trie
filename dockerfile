# Use an Ubuntu base image
FROM ubuntu:20.04

# Set the working directory
WORKDIR /workspace

# Set environment variables to make the build non-interactive
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=America/Chicago  

# Install required dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    ninja-build \
    gdb \
    git \
    vim \
    wget \
    libssl-dev \
    libstdc++-9-dev \
    ccache \
    clang \
    valgrind \
    libcurl4-openssl-dev \
    libpq-dev \
    libxml2-dev \
    libjsoncpp-dev \
    libgtest-dev \
    clang-tidy \
    clang-format \
    doxygen \
    autoconf \
    automake \
    libtool \
    zlib1g-dev \
    libbz2-dev \
    liblzma-dev \
    neovim \
    && rm -rf /var/lib/apt/lists/*

# Install Autoconf 2.71
RUN wget https://ftp.gnu.org/gnu/autoconf/autoconf-2.71.tar.gz && \
    tar -xf autoconf-2.71.tar.gz && \
    cd autoconf-2.71 && \
    ./configure && \
    make && \
    make install && \
    cd .. && \
    rm -rf autoconf-2.71 autoconf-2.71.tar.gz

# Install Google Test
RUN cd /usr/src/gtest && \
    cmake . && \
    make && \
    cp lib/*.a /usr/lib && \
    cd / && \
    rm -rf /usr/src/gtest

# Download and install Boost 1.85.0
RUN wget https://archives.boost.io/release/1.85.0/source/boost_1_85_0.tar.gz && \
    tar xfz boost_1_85_0.tar.gz && \
    cd boost_1_85_0 && \
    ./bootstrap.sh --prefix=/usr/local && \
    ./b2 install --with=all --without-stacktrace && \
    cd .. && \
    rm -rf boost_1_85_0 boost_1_85_0.tar.gz

# Copy project files into the container
COPY . /workspace

# Configure and build the project
RUN cmake -S . -B build && \
    cmake --build build

# Default command to keep the container running
CMD ["/bin/bash"]
