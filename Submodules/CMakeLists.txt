# add_subdirectory(zipper)
# add_subdirectory(libarchive)

# IF(UNIX)
# find_package(ZLIB REQUIRED)
# ELSE(UNIX)
# SET(ZLIB_INCLUDE_DIRS "${QT_ROOT}/src/3rdparty/zlib" CACHE STRING "Path to ZLIB headers of Qt")
# SET(ZLIB_LIBRARIES "")
# IF(NOT EXISTS "${ZLIB_INCLUDE_DIRS}/zlib.h")
#     MESSAGE("Please specify a valid zlib include dir")
# ENDIF(NOT EXISTS "${ZLIB_INCLUDE_DIRS}/zlib.h")
# ENDIF(UNIX)

# add_subdirectory(quazip)

# add_custom_target(
#    ZipLib
#    command make
#    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ziplib)

# Sources of external libraries
file(GLOB SRC_ZLIB ${CMAKE_CURRENT_SOURCE_DIR}/ziplib/Source/ZipLib/extlibs/zlib/*.c)
# file(GLOB SRC_LZMA  ${CMAKE_CURRENT_SOURCE_DIR}/ziplib/Source/ZipLib/extlibs/lzma/unix/*.c)
file(GLOB SRC_LZMA  ${CMAKE_CURRENT_SOURCE_DIR}/ziplib/Source/ZipLib/extlibs/lzma/*.c)
file(GLOB SRC_BZIP2 ${CMAKE_CURRENT_SOURCE_DIR}/ziplib/Source/ZipLib/extlibs/bzip2/*.c)

# ZipLib sources
file(GLOB SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/ziplib/Source/ZipLib/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ziplib/Source/ZipLib/detail/*.cpp)
        
add_library(ZipLib ${SRC_ZLIB} ${SRC_LZMA} ${SRC_BZIP2} ${SRC})