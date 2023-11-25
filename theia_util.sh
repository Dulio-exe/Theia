#!/bin/bash
# Theia build script
# Made by: @MilkFlavor with ❤️ on GitHub
# Date: 2023-01-01

# This script is used to build the Theia

############################################
############# Global variables #############
############################################

# Set debug mode
if [ "$1" == "--debug" ]; then
    DEBUG=true
else
    DEBUG=false
fi

# Set root directory
ROOT_DIR=$(pwd)

############################################
############# Get arguments ################
############################################

# Check if debug is requested
if [ "$DEBUG" == true ]; then
    echo "Debug mode enabled 🤖"
fi

if [ "$1" == "--clean" ]; then
    echo "Cleaning build directory 🧹"
    rm Theia
    echo "Build directory cleaned ✅"
    exit 0
fi

# Check if help is requested
if [ "$1" == "--help" ]; then
    echo "Theia build script"
    echo "Usage: ./build.sh [options]"
    echo "Options:"
    echo "  --debug: Enable debug mode"
    echo "  --help: Show this help message"
    echo "  --version: Show version"
    exit 0
fi

# Check if version is requested
if [ "$1" == "--version" ]; then
    echo "Theia build script"
    echo "Version: 1.0.0"
    echo "Date: 08/04/2023"
    exit 0
fi

############################################
############# Check environment ############
############################################

# Check os
if [ "$(uname)" != "Linux" ]; then
    echo "This script is only for Linux 🐧"
    exit 1
fi

############################################
###### Check and install dependencies ######
############################################

# Change to root if not already
if [ "$(pwd)" != "$ROOT_DIR" ]; then
    cd "$ROOT_DIR" || exit 1
    echo "Changed to root directory ✅"
else
    echo "Already in root directory ✅"
fi

# Check if cmake is installed
if ! command -v cmake &> /dev/null; then
    echo "CMake could not be found ❌"
    # Install cmake
    echo "Installing dependancy (cmake)"
    sudo apt-get install -y cmake
    echo "Dependency (cmake) installed ✅"
else
    echo "CMake is installed ✅"
fi

# Check if make is installed
if ! command -v make &> /dev/null; then
    echo "Make could not be found ❌"
    # Install make
    echo "Installing dependancy (make)"
    sudo apt-get install -y make
    echo "Dependency (make) installed ✅"
else
    echo "CMake is installed ✅"
fi

# Check if g++ is installed
if ! command -v g++ &> /dev/null; then
    echo "G++ could not be found ❌"
    # Install g++
    echo "Installing dependancy (g++)"
    sudo apt-get install -y g++
    echo "Dependency (g++) installed ✅"
else
    echo "G++ is installed ✅"
fi

# Check if opencv is inside /usr/local/include
if ! find /usr/{,local/}include/ -maxdepth 1 -name 'opencv4'; then
    echo "OpenCV could not be found ❌"
    echo "Please use the install_opencv script to build OpenCV 🛠️"
    exit 1
else
    echo "OpenCV is installed ✅"
fi

############################################
############ Check files ###################
############################################

# Check if include directory is there
if [ ! -d "include" ]; then
    echo "include directory cannot be located ❌"
    exit 1
else
    echo "include directory located ✅"
fi

# Check if Cmake files are there
if [ ! -f "CMakeLists.txt" ]; then
    echo "CMakeLists.txt cannot be located❌"
    exit 1
else 
    echo "CMakeLists.txt located ✅"
fi

# Check if theia.cpp is there
if [ ! -f "src/theia.cpp" ]; then
    echo "theia.cpp cannot be located ❌"
    exit 1
else
    echo "theia.cpp located ✅"
fi

# If this script is run with --debug, create "input" and "output" directories
if [ "$DEBUG" == true ]; then
    if [ ! -d "input" ]; then
        mkdir input
        echo "Created input directory ✅"
    else
        echo "input directory already exists ✅"
    fi

    if [ ! -d "output" ]; then
        mkdir output
        echo "Created output directory ✅"
    else
        echo "output directory already exists ✅"
    fi
fi

############################################
############# Build Theia ##################
############################################

# Check if build directory is there
if [ ! -d "build" ]; then
    mkdir build
    echo "Created build directory ✅"
else
    echo "build directory already exists ✅"
fi

# Change to build directory
cd build || exit 1
echo "Changed to build directory ✅"

# Run cmake
cmake ..
echo "Ran cmake ✅"

# Run make
make
echo "Ran make ✅"

# Copy executable to root directory
cp Theia ../Theia
echo "Copied executable to root directory ✅"

# Change to root directory
cd "$ROOT_DIR" || exit 1
echo "Changed to root directory ✅"

############################################
################# Clean up #################
############################################

# Check if build directory is there
if [ ! -d "build" ]; then
    echo "build directory cannot be located ❌"
    echo "Please remove the build directory manually"
    exit 1
else
    # Remove build directory
    rm -rf build
    echo "Removed build directory ✅"
fi

# Finishing statement
echo "Finished building Theia ✅"