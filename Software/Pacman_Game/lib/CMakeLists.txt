set(LIB_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/add/add.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/average/average.cpp
)

set(LIB_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/add
    ${CMAKE_CURRENT_SOURCE_DIR}/average
)

add_library(${APP_LIB_NAME} STATIC ${LIB_SOURCE_FILES})

target_include_directories(${APP_LIB_NAME} PUBLIC ${LIB_INCLUDE_DIRS})