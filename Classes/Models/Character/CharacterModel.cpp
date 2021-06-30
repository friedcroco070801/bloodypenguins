#include "CharacterModel.h"
#include <cmath>

/* 
Constructor of CharacterModel
*/
CharacterModel::CharacterModel(CharacterType type) {
    this->type = type;
    this->level = NULL;
    status = NORMAL;
    alive = true;

    // Temporary data
    hp = 5;
}

/*
Set level model of the character
*/
void CharacterModel::__setLevel(LevelModel* level) {
    this->level = level;
}

/*
Reduce hp of the Character
*/
void CharacterModel::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) {
        alive = false;
    }
}

/*
Set status of the character
*/
void CharacterModel::setStatus(CharacterStatus status) {
    this->status = status;
}

/*
Check if the character is alive or not
*/
bool CharacterModel::isAlive() {
    return alive;
}
/*
Set cell position of the character
*/
void CharacterModel::setPosition(float cellX, float cellY) {
    this->cellX = cellX;
    this->cellY = cellY;
}

/* 
Get cell position of the character. The result is a struct with 2 properties: cellX and cellY.
*/
CellPosition CharacterModel::getPosition() {
    return CellPosition(cellX, cellY);
}

/* 
Get cellX position of the character.
*/
float CharacterModel::getPositionCellX() {
    return cellX;
}

/* 
Get cellY position of the character.
*/
float CharacterModel::getPositionCellY() {
    return cellY;
}

/*
Get distance to other character
*/
float CharacterModel::getDistanceToOther(CharacterModel* other) {
    return sqrt((cellX - other->cellX) * (cellX - other->cellX) + (cellY - other->cellY) * (cellY - other->cellY));
}