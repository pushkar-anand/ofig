#!/usr/bin/env bash

#install build tools
sudo apt update
sudo apt install build-essential gcc g++ make

#install gtk dev & gnome-devel
sudo apt install libgtk-3-dev gnome-devel

#Get and install catch testing library
git clone https://github.com/catchorg/Catch2.git
cd Catch2
cmake -Bbuild -H. -DBUILD_TESTING=OFF
sudo cmake --build build/ --target install
rm -rf Catch2

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

if [[ -z ${TRAVIS} ]];
then
    #verify installations
    gcc -v
    g++ -v
    cmake --version
else
    #verify installations
    gcc -v
    g++ -v
    /usr/local/bin/cmake --version
fi
