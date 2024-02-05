set(_WIN_PLATFORM_ false)
set(_LINUX_PLATFORM_ false)

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    set(_WIN_PLATFORM_ true)
    add_definitions(-D _WIN_PLATFORM_)
endif()

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
    set(_LINUX_PLATFORM_ true)
    add_definitions(-D _LINUX_PLATFORM_)
endif()
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    add_definitions(-D DEBUG)
endif()
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    add_definitions(-D RELEASE)
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(PLATFORM "x64")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(PLATFORM "x86")
endif()

# 引入所有依赖
include_directories(SYSTEM "${PROJECT_SOURCE_DIR}/Dependencies/wil/include/")
include_directories(SYSTEM "${PROJECT_SOURCE_DIR}/Dependencies/webview2/build/native/include/")
include_directories(SYSTEM "${PROJECT_SOURCE_DIR}/Dependencies/meojson/")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/platform/include/")

if(_WIN_PLATFORM_)
    include_directories("${CMAKE_CURRENT_SOURCE_DIR}/platform/WinInclude/")
    FILE(GLOB PLATFORM_SOURCES  "${CMAKE_CURRENT_SOURCE_DIR}/platform/src/*_win.cpp")
elseif(_LINUX_PLATFORM_)
    include_directories("${CMAKE_CURRENT_SOURCE_DIR}/platform/LinuxInclude/")
    FILE(GLOB PLATFORM_SOURCES  "${CMAKE_CURRENT_SOURCE_DIR}/platform/src/*_linux.cpp")
endif()

link_libraries("${PROJECT_SOURCE_DIR}/Dependencies/webview2/build/native/${PLATFORM}/WebView2LoaderStatic.lib")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

if(_WIN_PLATFORM_)
    add_executable (NuCat WIN32 "NuCat.cpp" "Nucat.exe.manifest")
elseif(_LINUX_PLATFORM_)
    add_executable (NuCat  "NuCat.cpp" "Nucat.exe.manifest")
endif()

set_property(TARGET NuCat PROPERTY CXX_STANDARD 20)
target_link_libraries(NuCat PRIVATE bit7z )