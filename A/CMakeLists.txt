cmake_minimum_required(VERSION 2.8)

project(A)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
#   add_definitions(-g)

  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
endif("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")


set(SOURCES
  A.c
)

include_directories(
  ${LIBC_V1_DIR}
)

add_library(${PROJECT_NAME}.static STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME}.static C_v1.static)


add_library(${PROJECT_NAME}.dynamic SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME}.dynamic C_v1.static)
