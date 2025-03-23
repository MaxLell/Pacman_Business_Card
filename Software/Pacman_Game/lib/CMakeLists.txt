# Compile the Pacman Game Logic Library
set(PACMAN_GAME_LOGIC_LIB_INC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/average    
    ${CMAKE_CURRENT_SOURCE_DIR}/common
    ${CMAKE_CURRENT_SOURCE_DIR}/environment
    ${CMAKE_CURRENT_SOURCE_DIR}/message_broker
)

set(PACMAN_GAME_LOGIC_LIB_SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/average/average.cpp    
    ${CMAKE_CURRENT_SOURCE_DIR}/environment/environment.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/common/assert.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/message_broker/message_broker.cpp
)

add_library(${PACMAN_GAME_LOGIC_LIB} STATIC ${PACMAN_GAME_LOGIC_LIB_SRC_FILES})
target_include_directories(${PACMAN_GAME_LOGIC_LIB} PUBLIC ${PACMAN_GAME_LOGIC_LIB_INC_FILES})

set(UI_LIB_INC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/environment
    ${CMAKE_CURRENT_SOURCE_DIR}/common 
    ${CMAKE_CURRENT_SOURCE_DIR}/ui    
)

set(UI_LIB_SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/environment/environment.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/common/assert.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/ui.cpp
)

add_library(${UI_LIB} STATIC ${UI_LIB_SRC_FILES})
target_include_directories(${UI_LIB} PUBLIC ${UI_LIB_INC_FILES})