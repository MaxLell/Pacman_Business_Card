set(TEST_NAME run_all_tests)

################################################################
# CppUTest install
include(FetchContent)
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        latest-passing-build # or use release tag, eg. v3.8
)
# Set this to ON if you want to have the CppUTests in your project as well.
set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")
set(MEMORY_LEAK_DETECTION ON CACHE BOOL "Enable memory leak detection in CppUTest") # Aktiviert Memory Leak Detection
set(CPPUTEST_USE_STD_CPP_LIB ON CACHE BOOL "Use the standard C++ library for CppUTest") # Nutzt die Standard-C++-Bibliothek
FetchContent_MakeAvailable(CppUTest)

################################################################

set(TEST_RUNNER ${CMAKE_CURRENT_SOURCE_DIR}/test_utils/test_runner.cpp)

set(ALL_TEST_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/../mocks)
set(ALL_TEST_SOURCES  ${CMAKE_CURRENT_SOURCE_DIR}/../mocks/custom_assert_mock.cpp)

# This section does multiple things
# 1. It fetches all the folders in which there are test files (these folder both contain a source and a CMakeFile)
# 2. It adds these folders (add_subdirctory) and therefore executes its internal CMakeFile. This CMakeFile builds
#    an executable of the current test and also creates a library which can be linked to the run_all_tests binary
#    later in this CMakeFile
file(GLOB ALL_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
foreach(subdir ${ALL_FILES})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir})
        if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt)
            add_subdirectory(${subdir})
            set(ALL_TEST_SOURCES ${ALL_TEST_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/${subdir}.cpp)
        endif()
    endif()
endforeach()

add_executable(${TEST_NAME} ${TEST_RUNNER} ${ALL_TEST_SOURCES})
target_link_libraries(${TEST_NAME} PRIVATE CppUTest CppUTestExt ${PACMAN_GAME_LOGIC_LIB})
target_include_directories(${TEST_NAME} PRIVATE ${ALL_TEST_INCLUDES})

