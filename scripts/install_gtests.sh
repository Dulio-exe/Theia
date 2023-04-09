#!/bin/bash
# Opencv installation script for linux
# Made by: @MilkFlavor with ❤️ on GitHub

# Clone the Google Test repository
git clone https://github.com/google/googletest.git

# Build and install Google Test
cd googletest || exit 1
mkdir build
cd build || exit 1
cmake ..
make

# Install Google Test
sudo make install
