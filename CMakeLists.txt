cmake_minimum_required(VERSION 3.1)
project(hw2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c90")

set(SOURCE_FILES cscd340asgn2.c linked_list.c utility.c words.c)
set(HEADER_FILES students.h words.h linkedList.h utility.h)

add_executable(hw2 ${SOURCE_FILES} ${HEADER_FILES})
