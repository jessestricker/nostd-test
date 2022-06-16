cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(
  nostd-test
  VERSION 0.1.0
  LANGUAGES CXX)

add_library(
  nostd-test STATIC
  src/nostd-test/private/main.cpp
  src/nostd-test/private/registry.cpp
  src/nostd-test/private/runner.cpp
  src/nostd-test/registry-entry.cpp)

target_include_directories(nostd-test PUBLIC src)
target_compile_features(nostd-test PUBLIC cxx_std_20)

if(${PROJECT_IS_TOP_LEVEL})
  add_subdirectory(example)

  find_package(Doxygen)
  set(DOXYGEN_QUIET YES)
  set(DOXYGEN_EXTRACT_ALL YES)
  set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
  doxygen_add_docs(docs src)
endif()
