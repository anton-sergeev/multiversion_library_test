cmake_minimum_required(VERSION 2.8.11)

project(multiversion_3rd_party_lubrary C)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
  add_definitions(-g)

  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
endif("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")


set(LIBA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/A)
set(LIBB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/B)
set(LIBC_V1_DIR ${CMAKE_CURRENT_SOURCE_DIR}/C/v1)
set(LIBC_V2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/C/v2)


add_subdirectory(${LIBC_V1_DIR})
add_subdirectory(${LIBC_V2_DIR})

add_subdirectory(${LIBA_DIR})
add_subdirectory(${LIBB_DIR})


include_directories(
  ${LIBA_DIR}
  ${LIBB_DIR}
)


add_executable(main_A.static main_A.c)
target_link_libraries(main_A.static A.static)

add_executable(main_A.shared main_A.c)
target_link_libraries(main_A.shared A.shared)


add_executable(main_B.static main_B.c)
target_link_libraries(main_B.static B.static)

add_executable(main_B.shared main_B.c)
target_link_libraries(main_B.shared B.shared)


add_executable(main_AB.static main_AB.c)
target_link_libraries(main_AB.static A.static B.static)

add_executable(main_AB.shared main_AB.c)
target_link_libraries(main_AB.shared A.shared B.shared)


add_executable(main_AB.dlopen main_AB.dlopen.c)
target_link_libraries(main_AB.dlopen dl)


