# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author F. de Sande
# @date 18 Jun 2020
# @brief CMakeLists.txt example
# CMakeLists.txt defines the whole build
# CMake reads CMakeLists.txt sequentially
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make


cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(date_                # Mandatory
    VERSION 1.0
    DESCRIPTION "Info"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14) 						# Use c++14
set(CMAKE_CXX_STANDARD_REQUIRED True)

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Adds an executable target called "fibonacci_sum" to be built from the source files listed in the command invocation.
add_executable(date_
    src/fecha.cc
    src/fecha.h
    src/fechas.cc)

# tell the linker to bind these objects together
# It's important to place target_link_libraries after the add_executable and find_package lines, so all linked components are known.
target_link_libraries(date_ tools)

# Add expected compiler features to a target.
target_compile_features(date_ PRIVATE cxx_std_14)

# Add compile options to a target.
target_compile_options(date_ PRIVATE -Wall -Wextra -Wpedantic)

