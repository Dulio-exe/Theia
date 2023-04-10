# Scripts Folder

This folder contains the installation scripts for the required libraries and dependencies for Theia, an image processing program written in C++.

## Contents

The `scripts` folder contains the following files:

- `install_gtests.sh`: Bash script that installs Google Test, a unit testing library for C++
- `install_opencv.sh`: Bash script that installs OpenCV, a library for image processing and computer vision

These scripts can be used to install the necessary dependencies for building and running Theia.

## Running the scripts

To run the scripts, navigate to the `scripts` folder and run the following commands:

```bash
./install_opencv.sh
```

```bash
./install_gtests.sh
```

These scripts will download and install the necessary libraries and dependencies. Make sure to have administrative privileges to install the libraries on your system.

## Dependencies

The installation scripts for Theia depend on the following libraries and tools:

- Git: Used to download and manage the library source code
- CMake: Used to configure and build the libraries
- A C++ compiler: Used to compile the libraries

Make sure to install these dependencies before running the installation scripts.
