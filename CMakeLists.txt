cmake_minimum_required(VERSION 3.3)
project(opencv_sandbox)

set(CMAKE_CXX_COMPILER  "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

find_package( OpenCV REQUIRED )

# executables

add_executable(load_disp_image load_disp_image.cpp)
target_link_libraries(load_disp_image ${OpenCV_LIBS})

add_executable(load_modify_save load_modify_save.cpp)
target_link_libraries(load_modify_save ${OpenCV_LIBS})

add_executable(mat mat.cpp)
target_link_libraries(mat ${OpenCV_LIBS})

add_executable(scan_image scan_image.cpp)
target_link_libraries(scan_image ${OpenCV_LIBS})

add_executable(masks masks.cpp)
target_link_libraries(masks ${OpenCV_LIBS})
