cmake_minimum_required(VERSION 3.28)
project(Pacman_Game LANGUAGES CXX)

# Set runner for the Pacman game
set(PACMAN_GAME Pacman_Game) # This is the human playable game
set(UI_LIB ui_lib)
set(PACMAN_GAME_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/app/pacman_game.cpp
)

# Build the Pacman Logic Library
set(PACMAN_GAME_LOGIC_LIB ${PACMAN_GAME}_lib)
add_subdirectory(lib)


# Compile the Pacman Game executable
add_executable(${PACMAN_GAME} ${PACMAN_GAME_SRC})
target_link_libraries(${PACMAN_GAME} PRIVATE ${PACMAN_GAME_LOGIC_LIB} {UI_LIB})



# For the tests
add_subdirectory(tests)
