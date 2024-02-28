cmake_minimum_required(VERSION 3.28)

# Global settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/.bin)

# Project definition
project(
  Schemly
  VERSION 0.0.1
  LANGUAGES CXX C)

  
# Generate the config/version.h file
# Get the current git sha
execute_process(
  COMMAND git rev-parse HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_SHA
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
# Get the current git branch
execute_process(
  COMMAND git rev-parse --abbrev-ref HEAD
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_BRANCH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
# configure the version.h file
configure_file(
  ${CMAKE_SOURCE_DIR}/include/config/version.h.in
  ${CMAKE_BINARY_DIR}/include/config/version.h
)

# package manager
include(cmake/CPM.cmake)

CPMAddPackage("gh:raysan5/raylib#5.0")

# sources
add_subdirectory(src)