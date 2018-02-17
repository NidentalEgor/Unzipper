set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets)
find_package(Qt5Concurrent)

qt5_add_resources(RESOURCES resources.qrc)

file(
    GLOB UNZIPPER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(
    Unzipper
    ${UNZIPPER_SOURCES}
    ${RESOURCES})

source_group(
    Gui
    ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.*)

source_group(
    Unzipper
    ${CMAKE_CURRENT_SOURCE_DIR}/Unzipper.*)

source_group(
    ExecutableRunner
    ${CMAKE_CURRENT_SOURCE_DIR}/ExecutableRunner.*)

target_link_libraries(
    Unzipper
    ZipLib
    Qt5::Widgets)
