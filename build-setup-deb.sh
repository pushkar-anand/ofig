#!/usr/bin/env bash

#install build tools
sudo apt update
sudo apt install build-essential gcc g++ make

#install gtk dev & gnome-devel
sudo apt install libgtk-3-dev gnome-devel

if [[ -z ${TRAVIS} ]];
then
     #remove existing cmake
    sudo apt remove cmake
    sudo apt purge --auto-remove cmake

    #cmake version
    version=3.13
    build=2
    mkdir ~/tmp
    cd ~/tmp

    #get the cmake package
    wget https://github.com/Kitware/CMake/releases/download/v${version}.${build}/cmake-${version}.${build}.tar.gz
    tar -xzf cmake-${version}.${build}.tar.gz

    #install cmake
    cd cmake-${version}.${build}/
    ./bootstrap
    make -j4
    sudo make install

    #verify installations
    gcc -v
    g++ -v
    cmake --version
else
   echo "TRAVIS CI is running the build.\n No need to install latest cmake\n";
   sudo apt remove cmake
   sudo apt purge --auto-remove cmake

    #cmake version
    version=3.13
    build=2
    mkdir ~/tmp
    cd ~/tmp

    #get the cmake package
    wget https://github.com/Kitware/CMake/releases/download/v${version}.${build}/cmake-${version}.${build}.tar.gz
    tar -xzf cmake-${version}.${build}.tar.gz

    #install cmake
    cd cmake-${version}.${build}/
    ./bootstrap
    make -j4
    sudo make install

    #verify installations
    gcc -v
    g++ -v
    /usr/local/bin/cmake --version
fi
