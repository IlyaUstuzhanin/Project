cmake_minimum_required (VERSION 3.16)
project (name CXX)

set(CMAKE_CXX_FLAGS "-03")
find_package(LAPACK REQUIRED)
add_evectuable(main Classes.cpp test_blas_lapack.cpp)
target_link_libraries(main PUBLIC LAPACK::LAPACK)
