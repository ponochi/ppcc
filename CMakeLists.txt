cmake_minimum_required(VERSION 3.9)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

project(ppcc CXX)

set(SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/ppcc.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/parser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/import_def.cpp
)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBUILD_TYPE=\\\"Debug\\\"")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBUILD_TYPE=\\\"BUILD_TYPE=Release\\\"")
endif()

add_executable(ppcc ${SRCS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -stdlib=libc++ -v")
