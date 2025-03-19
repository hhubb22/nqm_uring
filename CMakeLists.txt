cmake_minimum_required(VERSION 3.19)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)
set(VCPKG_MANIFEST_MODE ON) 
message(STATUS "Using vcpkg toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

project(NqmUring)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)

include_directories(include)

add_library(NqmUring src/NqmConfigParser.cc src/NqmInstance.cc)

target_link_libraries(NqmUring fmt::fmt yaml-cpp::yaml-cpp)

add_executable(nqm src/main.cc)
target_link_libraries(nqm NqmUring)