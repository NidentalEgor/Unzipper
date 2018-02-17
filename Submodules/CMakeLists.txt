if (UNIX)
    file(
        GLOB LZMA_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/ziplib/Source/ZipLib/extlibs/lzma/unix/*.c)
else()
    file(
        GLOB LZMA_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/ziplib/Source/ZipLib/extlibs/lzma/*.c)
endif()

file(
    GLOB BZIP2_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/ziplib/Source/ZipLib/extlibs/bzip2/*.c)

file(
    GLOB ZLIB_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/ziplib/Source/ZipLib/extlibs/zlib/*.c)

file(
    GLOB ZIPLIB_SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/ziplib/Source/ZipLib/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ziplib/Source/ZipLib/detail/*.cpp)
        
add_library(
    ZipLib
    ${LZMA_SOURCE}
    ${BZIP2_SOURCE}
    ${ZLIB_SOURCE}
    ${ZIPLIB_SOURCE})

target_link_libraries(
    ZipLib
    pthread)
