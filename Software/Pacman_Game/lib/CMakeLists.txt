# Compile the Pacman Game Logic Library
set(PACMAN_GAME_LOGIC_LIB_INC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_CURRENT_SOURCE_DIR}/pacman
    ${CMAKE_CURRENT_SOURCE_DIR}/data_pool
    ${CMAKE_CURRENT_SOURCE_DIR}/message_broker
    ${CMAKE_CURRENT_SOURCE_DIR}/environment_generator
)

set(PACMAN_GAME_LOGIC_LIB_SRC_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/common/custom_assert.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pacman/pacman.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/data_pool/data_pool.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/environment_generator/environment_generator.cpp
)

add_library(${PACMAN_GAME_LOGIC_LIB} STATIC ${PACMAN_GAME_LOGIC_LIB_SRC_FILES})
target_include_directories(${PACMAN_GAME_LOGIC_LIB} PUBLIC ${PACMAN_GAME_LOGIC_LIB_INC_FILES})
target_compile_options(${PACMAN_GAME_LOGIC_LIB} PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
    -Wshadow
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Wcast-align
    -Wconversion
    -Wsign-conversion
    -Wnull-dereference
    -Wdouble-promotion
    -Wformat=2
    -Wdeprecated-declarations
    -Woverloaded-virtual
    -Wuseless-cast
    -O0
    -march=native
    -g
)



