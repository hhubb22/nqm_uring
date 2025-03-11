cmake_minimum_required(VERSION 3.19)

project(NqmUring)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 11.1.4
)
FetchContent_MakeAvailable(fmt)

include(FetchContent)

FetchContent_Declare(
    yaml-cpp
    GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
    GIT_TAG 0.8.0
)
FetchContent_MakeAvailable(yaml-cpp)

include_directories(include)

add_library(NqmUring src/NqmConfigParser.cc src/NqmInstance.cc)

target_link_libraries(NqmUring fmt::fmt yaml-cpp::yaml-cpp)

add_executable(nqm src/main.cc)
target_link_libraries(nqm NqmUring)