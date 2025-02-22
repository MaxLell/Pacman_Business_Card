# Compile the Pacman Game Logic Library
set(PACMAN_GAME_LOGIC_LIB_SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/average/average.cpp    
    ${CMAKE_CURRENT_SOURCE_DIR}/environment/environment.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pacman_game_logic/pacman_game_logic.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/common/assert.cpp
)
set(PACMAN_GAME_LOGIC_LIB_INC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/average    
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_CURRENT_SOURCE_DIR}/environment
    ${CMAKE_CURRENT_SOURCE_DIR}/pacman_game_logic
)

add_library(${PACMAN_GAME_LOGIC_LIB} STATIC ${PACMAN_GAME_LOGIC_LIB_SRC_FILES})
target_include_directories(${PACMAN_GAME_LOGIC_LIB} PUBLIC ${PACMAN_GAME_LOGIC_LIB_INC_FILES})

add_subdirectory(ui)