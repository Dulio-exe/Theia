cmake_minimum_required(VERSION 3.0)
project( Theia )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( include ) # Add this line to include the "include" directory
add_executable( Theia src/theia.cpp src/log.cpp src/sharp.cpp src/blur.cpp src/tone.cpp)
target_link_libraries( Theia ${OpenCV_LIBS} stdc++fs)
