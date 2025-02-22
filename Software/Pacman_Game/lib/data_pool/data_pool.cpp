#include "data_pool.h"

DataPool::DataPool(/* args */){

}

DataPool::~DataPool(){

}

void DataPool::setPacmanPosition(u8 x, u8 y){
    pacman_position.x = x;
    pacman_position.y = y;
}

Coordinate DataPool::getPacmanPosition() const{
    return pacman_position;
}