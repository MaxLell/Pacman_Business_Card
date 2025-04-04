# Nothing to change here. Just copy this file to your new test folder.
get_filename_component(TEST_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

set(TEST_LIBRARY_NAME ${TEST_NAME}_lib)

set (TEST_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/../../mocks
)

set(TEST_SOURCES
    ${TEST_NAME}.cpp
    ${TEST_RUNNER}
    ${CMAKE_CURRENT_SOURCE_DIR}/../../mocks/assert_mock.cpp
)

# Add the test executable which is only concerned with the current test
add_executable(run_${TEST_NAME} ${TEST_SOURCES})
target_link_libraries(run_${TEST_NAME} PRIVATE CppUTest CppUTestExt ${PACMAN_GAME_LOGIC_LIB})
target_include_directories(run_${TEST_NAME} PRIVATE ${TEST_INCLUDES})
target_compile_options(run_${TEST_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
