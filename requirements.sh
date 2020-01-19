#!/bin/bash

sudo apt-get upgrade

echo "#####################"
echo Install c++17
echo "#####################"
sudo apt-get install gcc-7 g++-7
gcc-7 --version

echo "#####################"
echo Install boost
echo "#####################"
sudo apt-get install libboost-all-dev

echo "#####################"
echo Install swig
echo "#####################"
sudo apt-get install swig

echo "#####################"
echo Install python dev
echo "#####################"
sudo apt-get install python3-dev

