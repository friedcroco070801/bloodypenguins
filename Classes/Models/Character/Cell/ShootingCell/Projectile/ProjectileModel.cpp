#include "ProjectileModel.h"
#include <cmath>

/*
Constructor of projectile model
*/
ProjectileModel::ProjectileModel(LevelModel* level, ProjectileId id, CharacterModel* source, CharacterModel* target) {
    this->level = level;
    this->id = id;
    this->target = target;
    isDestroyed = false;

    // Set up source and target position
    cellX = source->getPositionCellX();
    cellY = source->getPositionCellY();
    targetX = target->getPositionCellX();
    targetY = target->getPositionCellY();
    float distance = sqrt((cellX - targetX) * (cellX - targetX) + (cellY - targetY) * (cellY - targetY));
    directionVectorX = (targetX - cellX) / distance;
    directionVectorY = (targetY - cellY) / distance; 
}

/*
Get cell position X
*/
float ProjectileModel::getPositionCellX() {
    return cellX;
}

/*
Get cell position Y
*/
float ProjectileModel::getPositionCellY() {
    return cellY;
}

/*
Get cell position
*/
CellPosition ProjectileModel::getPosition() {
    return CellPosition(cellX, cellY);
}

/*
Update on each updating
*/
void ProjectileModel::update() {
    if (!isDestroyed) {
        // Check position
        if ((cellX - targetX) * directionVectorX >= 0.0f && (cellY - targetY) * directionVectorY >= 0.0f) {
            // Destroyed and take effect
            hitTarget();
        }
        else {
            // Update position
            cellX += directionVectorX * UPDATING_FREQUENCY * speed;
            cellY += directionVectorY * UPDATING_FREQUENCY * speed;
        }
    }
}

/*
Take damage and take effect upon hitting target
*/
void ProjectileModel::hitTarget() {
    if (!isDestroyed) {
        target->takeDamage(damage);
        effectOnHit();
        isDestroyed = true;
    }
}