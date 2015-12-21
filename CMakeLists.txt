cmake_minimum_required(VERSION 3.3)
project(opencv_sandbox)

set(CMAKE_CXX_COMPILER  "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package( OpenCV REQUIRED )

add_executable(load_disp_image load_disp_image.cpp)
target_link_libraries(load_disp_image ${OpenCV_LIBS})