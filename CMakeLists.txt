Cmake_minimum_required (VERSION 3.20)
project (name.cxx)

set(CMAKE_CXX_FLAGS "_03")
find_package(LAPACK REQUIRED)
add_evectuable(main Classes.cpp test_blas_lapack.cpp)
target_link.libraries(main PUBLIC LAPACK::LAPACK)
