cmake_minimum_required(VERSION 3.10)
project("Linked Lists" C)


set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3 -march=native")



set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 17)


add_library(node STATIC src/node.c)
target_include_directories(node PUBLIC include)

#singly linked list
add_library(linked_list src/linked_list.c)
target_include_directories(linked_list PUBLIC include)
target_link_libraries(linked_list node)

add_executable(test_linked_list test/test_linked_list.c)
target_include_directories(test_linked_list PUBLIC include)
target_link_libraries(test_linked_list linked_list)


#basic linear stack
add_library(stack src/stack.c)
target_include_directories(stack PUBLIC include)
target_link_libraries(stack linked_list)

add_executable(test_stack test/test_stack.c)
target_include_directories(test_stack PUBLIC include)
target_link_libraries(test_stack stack)


#basic linear queue
add_library(queue src/queue.c)
target_include_directories(queue PUBLIC include)
target_link_libraries(queue linked_list)

add_executable(test_queue test/test_queue.c)
target_include_directories(test_queue PUBLIC include)
target_link_libraries(test_queue queue)


#priority queue
add_library(priority_queue src/priority_queue.c)
target_include_directories(priority_queue PUBLIC include)

add_executable(test_priority_queue test/test_priority_queue.c)
target_include_directories(test_priority_queue PUBLIC include)
target_link_libraries(test_priority_queue priority_queue)

#double linked list
add_library(double_linked_list src/double_linked_list.c)
target_include_directories(double_linked_list PUBLIC include)

add_executable(test_double_linked_list test/test_double_linked_list.c)
target_link_libraries(test_double_linked_list PUBLIC double_linked_list)


#complete library
add_library(everything src/library.c)
target_include_directories(everything PUBLIC include)
target_link_libraries(everything linked_list node stack queue)