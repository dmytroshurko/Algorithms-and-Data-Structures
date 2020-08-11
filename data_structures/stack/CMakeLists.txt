add_library(stack stack.cpp)
add_executable(test_stack test_stack.cpp)
target_link_libraries(test_stack stack gtest)
