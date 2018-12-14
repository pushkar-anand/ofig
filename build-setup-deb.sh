#!/usr/bin/env bash

#install build tools
sudo apt update
sudo apt sudo apt-get install build-essential gcc g++ make manpages-dev

#install gtk dev
sudo apt install libgtk-3-dev

#install gnome-devel
sudo apt-get install gnome-devel

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
tar -xzvf cmake-${version}.${build}.tar.gz

#install cmake
cd cmake-${version}.${build}/
./bootstrap
make -j4
sudo make install