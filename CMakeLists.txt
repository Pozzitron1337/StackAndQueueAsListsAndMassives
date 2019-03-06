cmake_minimum_required(VERSION 3.8)
project(Lab4ASD)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp StackAsMassive.cpp StackAsList.cpp QueueAsMassive.cpp QueueAsList.cpp list.h StackX2InMassive.cpp Expression.cpp StackSTL.cpp QueueSTL.cpp)
add_executable(Lab4ASD ${SOURCE_FILES} StackAsMassive.cpp QueueAsList.cpp StackX2InMassive.cpp QueueSTL.cpp)