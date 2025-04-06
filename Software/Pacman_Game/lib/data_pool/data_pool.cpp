#include "data_pool.h"

// Singleton instance accessor
DataPool& DataPool::getInstance() {
    static DataPool instance; // Static instance of DataPool
    return instance;
}

// Private constructor
DataPool::DataPool() {
    // Initialize walls with all bits set to 0 (no walls)
    for (auto& row : walls) {
        row.reset();
    }

    // Initialize pacman position to (0, 0)
    pacmanPosition.x = 0;
    pacmanPosition.y = 0;
}

// Private destructor
DataPool::~DataPool() {
    // No dynamic memory to clean up
}

// Setter for Walls
void DataPool::setWalls(const Walls& inputWalls) {
    walls = inputWalls;
}

// Getter for Walls
const Walls& DataPool::getWalls() const {
    return walls;
}

// Check if a wall exists at a specific position
bool DataPool::isWallAt(positionXY pos) const {
    ASSERT(pos.x >= 0);
    ASSERT(pos.y >= 0);
    ASSERT(pos.x < NOF_ROWS); 
    ASSERT(pos.y < NOF_COLUMNS);

    return walls[static_cast<std::size_t>(pos.x)][static_cast<std::size_t>(pos.y)];
}

// Setter für Pacman-Position
void DataPool::setPacmanPosition(positionXY pos) {
    ASSERT(pos.x >= 0);
    ASSERT(pos.y >= 0);
    ASSERT(pos.x < NOF_ROWS);
    ASSERT(pos.y < NOF_COLUMNS);

    pacmanPosition.x = pos.x; 
    pacmanPosition.y = pos.y; 
}

// Getter für Pacman-Position
positionXY DataPool::getPacmanPosition() const {
    return pacmanPosition; 
}

// Setter for Control Inputs
void DataPool::setControlInputs(ctrlInput input) {
    bool validInput = input < ctrlInput::LAST_INPUT;
    ASSERT(validInput); 
    controlInput = input;
}

// Getter for Control Inputs
ctrlInput DataPool::getControlInputs() const {
    return controlInput; // Gib den aktuellen Steuerungseingang zurück
}

void DataPool::runIntegrityChecks() const {
    // Pacman's position must not be the same as a wall
    ASSERT(!isWallAt(pacmanPosition)); 

    // Pacman's position must not be out of bounds
    ASSERT(pacmanPosition.x >= 0);
    ASSERT(pacmanPosition.y >= 0);
    ASSERT(pacmanPosition.x < NOF_ROWS);
    ASSERT(pacmanPosition.y < NOF_COLUMNS);


    // Pacman's position must not the same as a pellet

    // Pacman's position must not be the same as a superpellet

    // Pacman's position must not be the same as a Ghost

    // Control input must be valid
    ASSERT(controlInput < ctrlInput::LAST_INPUT);
}
