cmake_minimum_required(VERSION 3.13)
project(ofig)

set(CMAKE_CXX_STANDARD 11)

#Add project lib variables
set(PROJECT_LIBRARY_DIR "${PROJECT_SOURCE_DIR}/libraries")
set(SCITER_SDK_ROOT "${PROJECT_LIBRARY_DIR}/sciter-sdk")
set(SCITER_SDK_INCLUDE "${SCITER_SDK_ROOT}/include")
set(SCITER_BIN_GTK "${SCITER_SDK_ROOT}/bin.gtk")

#Find and link GTK-3 libraries
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
add_definitions(${GTK3_CFLAGS_OTHER})
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
link_libraries(${GTK3_LIBRARIES})

#Find and link Catch2
find_package(Catch2 REQUIRED)
include_directories(${CATCH_INCLUDE_DIRS})


#Inlude source dirs
include_directories(${SCITER_SDK_INCLUDE})
include_directories(src)

link_directories(${SCITER_BIN_GTK})

#Link external libs
link_libraries("-ldl")
link_libraries(${SCITER_BIN_GTK}/x64/libsciter-gtk.so)

#Add tests
add_executable(tests tests/test_base.cpp tests/php-detector-test.cpp)
add_test(NAME MyTests COMMAND tests)


#set source and add executables
set(SOURCE_FILES ${SCITER_SDK_INCLUDE}/sciter-gtk-main.cpp)
add_executable(ofig ${SOURCE_FILES} src/frame.h src/app.cpp)
