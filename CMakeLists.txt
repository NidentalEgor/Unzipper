cmake_minimum_required (VERSION 3.5)
project (Unzipper)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++14")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Submodules/ziplib/Source/ZipLib)

add_subdirectory(Submodules)
add_subdirectory(Zipper)
add_subdirectory(Unzipper)
