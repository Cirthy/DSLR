cmake_minimum_required(VERSION 3.3)
project(trainer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        sources/main.cpp
        sources/utils.cpp
        sources/trainer.cpp
        sources/managment.cpp
        sources/calculus.cpp
        sources/trainer.h sources/writer.cpp sources/predict.cpp sources/reader.cpp)


add_executable(trainer ${SOURCE_FILES})