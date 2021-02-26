# cmake_minimum_required(VERSION <specify CMake version here>)
project(mymalloc)

set(CMAKE_CXX_STANDARD 14)

set(
        mymalloc_src
        heap.h
        heap.cpp
        bitmap.h
        consts.h
        span.cpp
        central.cpp
        cache.cpp
        amalloc.h
)

add_executable(
        mymalloc
        main.cpp
        ${mymalloc_src}
)

add_executable(
        mallocTest
        test/mallocTest.cpp
        ${mymalloc_src}
)

add_executable(
        freeTest
        test/freeTest.cpp
        ${mymalloc_src}
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
        ${mymalloc_src}
)

target_link_libraries(
        threadMallocTest
        pthread
)

add_executable(
        cpuTest
        test/cpuTest.cpp
)

target_link_libraries(
        cpuTest
        pthread
)

add_executable(
        redefineTest
        test/redefine/redefineTest.cpp
        test/redefine/redefine.h
)

add_executable(
        staticTest
        test/staticTest.cpp
        ${mymalloc_src}
)

add_executable(
        overrideTest
        test/new_delete/override.cpp
        ${mymalloc_src}
)