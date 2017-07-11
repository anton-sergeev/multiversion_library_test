cmake_minimum_required(VERSION 2.8)

project(B)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
#   add_definitions(-g)

  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
endif("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")


set(SOURCES
  B.c
)
include_directories(
  ${LIBC_V2_DIR}
)

add_library(${PROJECT_NAME}.static STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME}.static C_v2.static)


add_library(${PROJECT_NAME}.dynamic SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME}.dynamic C_v2.static)

