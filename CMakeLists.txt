cmake_minimum_required(VERSION 3.24)
project(PIAA_Proj2)

set(CMAKE_CXX_STANDARD 14)

add_executable(PIAA_Proj2
        main.cpp graph_matrix.h graph_list.h edge.h graph_list.cpp graph_matrix.cpp ui.h base.h ui.cpp)
