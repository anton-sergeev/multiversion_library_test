cmake_minimum_required(VERSION 2.8)

project(C_v2)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
#   add_definitions(-g)

  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
  
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
endif("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")


set(SOURCES
  C.c
)

add_library(${PROJECT_NAME}.static STATIC ${SOURCES})
set_property(TARGET ${PROJECT_NAME}.static PROPERTY POSITION_INDEPENDENT_CODE ON)

# add_library(${PROJECT_NAME}.shared SHARED ${SOURCES})

