cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(NqmUring)

include_directories(include)

find_package(fmt CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(tomlplusplus REQUIRED IMPORTED_TARGET tomlplusplus)

add_library(NqmUring src/NqmConfigParser.cc src/NqmInstance.cc)

target_link_libraries(NqmUring fmt::fmt PkgConfig::tomlplusplus)

add_executable(nqm src/main.cc)
target_link_libraries(nqm NqmUring)