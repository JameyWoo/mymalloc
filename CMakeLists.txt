# cmake_minimum_required(VERSION <specify CMake version here>)
project(mymalloc)

set(CMAKE_CXX_STANDARD 14)

set(
        mymallocSource
        mymalloc.h
        mymalloc.cpp
        bitmap.h
        consts.h
        span.cpp
        central.cpp
)

add_executable(
        mymalloc
        main.cpp
        ${mymallocSource}
)

add_executable(
        mallocTest
        test/mallocTest.cpp
        ${mymallocSource}
)

add_executable(
        freeTest
        test/freeTest.cpp
        ${mymallocSource}
)

add_executable(
        mapTest
        test/mapTest.cpp
)

add_executable(
        threadTest
        test/threadTest.cpp
)

target_link_libraries(
        threadTest
        pthread
)

add_executable(
        threadMallocTest
        test/threadMallocTest.cpp
)

target_link_libraries(
        threadMallocTest
        pthread
)