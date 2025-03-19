cmake_minimum_required(VERSION 2.8)

project(A C)

set(SOURCES
  A.c
)

include_directories(
  ${LIBC_V1_DIR}
)

add_library(${PROJECT_NAME}.static STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME}.static C_v1.static)


add_library(${PROJECT_NAME}.shared SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME}.shared C_v1.static)
