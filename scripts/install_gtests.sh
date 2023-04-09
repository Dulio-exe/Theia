#!/bin/bash
# Opencv installation script for linux
# Made by: @MilkFlavor with ❤️ on GitHub
# Check out: https://github.com/MilkFlavor

# Clone the Google Test repository
git clone https://github.com/google/googletest.git

# Build and install Google Test
cd googletest || exit 1

# Create a build directory
mkdir build

# Build Google Test
cd build || exit 1

# Configure and build Google Test
cmake ..

# Build Google Test
make

# Install Google Test
sudo make install
