cmake_minimum_required(VERSION 3.6)
project(ImageTrans)

set(CMAKE_CXX_STANDARD 11)
set(CUDA_USE_STATIC_CUDA_RUNTIME OFF)
FIND_PACKAGE(OpenCV REQUIRED)

set(SOURCE_FILES main.cpp define.h util.h util.cpp imageDeal.h ImageDeal.cpp test.cpp)
add_executable(ImageTrans ${SOURCE_FILES})

target_link_libraries(ImageTrans ${OpenCV_LIBS})

