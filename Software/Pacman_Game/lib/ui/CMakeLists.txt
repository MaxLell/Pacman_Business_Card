# Compile the UI Library
set(UI_LIB_SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../environment/environment.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../common/assert.cpp
)
set(UI_LIB_INC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/../ui
    ${CMAKE_CURRENT_SOURCE_DIR}/../common
    ${CMAKE_CURRENT_SOURCE_DIR}/../environment
)
add_library(${UI_LIB} STATIC ${UI_LIB_SRC_FILES})
target_include_directories(${UI_LIB} PUBLIC ${UI_LIB_INC_FILES})