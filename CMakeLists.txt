cmake_minimum_required(VERSION 2.8.11)

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

add_executable(main_A.dynamic main_A.c)
target_link_libraries(main_A.dynamic A.dynamic)


add_executable(main_B.static main_B.c)
target_link_libraries(main_B.static B.static)

add_executable(main_B.dynamic main_B.c)
target_link_libraries(main_B.dynamic B.dynamic)


add_executable(main_AB.static main_AB.c)
target_link_libraries(main_AB.static A.static B.static)

add_executable(main_AB.dynamic main_AB.c)
target_link_libraries(main_AB.dynamic A.dynamic B.dynamic)

