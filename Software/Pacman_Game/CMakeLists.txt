cmake_minimum_required(VERSION 3.28)

set(APP_NAME Dummy_Project)

project(${APP_NAME} LANGUAGES CXX)

set(APP_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/app/app.cpp
)
set(APP_LIB_NAME ${APP_NAME}_lib)
add_executable(${APP_NAME} ${APP_SOURCE_FILES})
add_subdirectory(lib)
target_link_libraries(${APP_NAME} PRIVATE ${APP_LIB_NAME})

# For the tests
add_subdirectory(tests)
