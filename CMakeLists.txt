cmake_minimum_required(VERSION 3.20)
project(diffusion CXX)

set(CMAKE_CXX_FLAGS "-O3 -Ofast -flto -march=native")
find_package(LAPACK REQUIRED)

add_executable(main Classes.cpp test_blas_lapack.cpp)
target_link_libraries(main PUBLIC LAPACK::LAPACK)
