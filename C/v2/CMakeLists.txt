cmake_minimum_required(VERSION 2.8)

project(C_v2 C)

set(SOURCES
  C.c
)

add_library(${PROJECT_NAME}.static STATIC ${SOURCES})
set_property(TARGET ${PROJECT_NAME}.static PROPERTY POSITION_INDEPENDENT_CODE ON)

# add_library(${PROJECT_NAME}.shared SHARED ${SOURCES})

