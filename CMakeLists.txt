cmake_minimum_required(VERSION 3.10)
project(load_balancer)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(CMAKE_TOOLCHAIN_FILE "C:/Users/LENOVO/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_definitions(-D_WIN32_WINNT=0x0A00)

add_executable(
    blancer
    main.cpp
    src/load_balancer.cpp
    src/server.cpp
)