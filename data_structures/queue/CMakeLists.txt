add_library(queue queue.cpp)
add_executable(test_queue test_queue.cpp)
target_link_libraries(test_queue queue gtest)
