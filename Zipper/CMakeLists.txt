set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets)

add_executable(
    Zipper
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp)

target_link_libraries(
    Zipper
    ZipLib
    Qt5::Widgets)