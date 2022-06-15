add_executable(example suite-a.cpp suite-b.cpp)
target_link_libraries(example PRIVATE nostd-test)
