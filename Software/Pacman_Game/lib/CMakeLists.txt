# Compile the Pacman Game Logic Library
set(PACMAN_GAME_LIB_SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/average/average.cpp
)
set(PACMAN_GAME_LIB_INC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/average
)
add_library(${PACMAN_GAME_LIB} STATIC ${PACMAN_GAME_LIB_SRC_FILES})
target_include_directories(${PACMAN_GAME_LIB} PUBLIC ${PACMAN_GAME_LIB_INC_FILES})

# Compile the UI Library
set(UI_LIB_SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/ui.cpp
)
set(UI_LIB_INC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/ui
)
add_library(${UI_LIB} STATIC ${UI_LIB_SRC_FILES})
target_include_directories(${UI_LIB} PUBLIC ${UI_LIB_INC_FILES})