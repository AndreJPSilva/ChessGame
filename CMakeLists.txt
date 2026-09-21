cmake_minimum_required(VERSION 3.22)

project(chess LANGUAGES CXX)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include")

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)

set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 23
  CXX_STANDARD_REQUIRED ON
  EXPORT_COMPILE_COMMANDS ON
)

if (WIN32)
  target_link_libraries(${PROJECT_NAME} PRIVATE -lstdc++exp)
endif()
