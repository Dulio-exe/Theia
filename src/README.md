# Source Code Folder
This folder contains the source code for Theia, an image processing program written in C++.

# Contents
The src folder contains the following files:

### blur.cpp: 
Implementation of a Gaussian blur filter for images
### log.cpp:
Implementation of a Laplacian of Gaussian (LoG) filter for images
### sharp.cpp:
Implementation of a sharpening filter for images
### theia.cpp:
Main program file that loads an image and applies filters to it
### tone.cpp:
Implementation of a tonemapping algorithm for high dynamic range (HDR) images

## Each of these files includes a corresponding header file in the include folder.

# Building the project
## To build the project, you can use the included Makefile by running the following command in the project root directory:

```./theia --debug```

This will compile the source code and create an executable file called theia.

# Running the program
To run the program, first build it using the make command. Then, you can run the program using the following command:

```
./theia <input_image> <output_image>
Replace <input_image> with the path to the input image file, and <output_image> with the desired name and path for the output image file.
```

## The program will apply the following filters to the input image:

Gaussian blur filter
Laplacian of Gaussian (LoG) filter
Sharpening filter
Tonemapping filter (only applied to HDR images)
The output image will be saved to the specified file path.

Dependencies
The source code depends on the following libraries:

OpenCV: Used for image processing and manipulation
Make sure to install OpenCV before building and running the program.