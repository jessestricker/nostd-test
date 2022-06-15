cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(
  nostd-test
  VERSION 0.1.0
  LANGUAGES CXX)

add_library(nostd-test STATIC src/nostd-test/nostd-test.cpp)

target_include_directories(nostd-test PUBLIC include)
target_compile_features(nostd-test PUBLIC cxx_std_20)

if(${PROJECT_IS_TOP_LEVEL})
  add_subdirectory(example)
endif()
