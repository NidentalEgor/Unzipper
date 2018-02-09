cmake_minimum_required (VERSION 3.5)
project (Unzipper)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++14")

find_package(Qt5Widgets)

add_subdirectory(Submodules)

add_executable(
    Unzipper
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp)

target_link_libraries(
    Unzipper
    Qt5::Widgets)