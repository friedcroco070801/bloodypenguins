#include "Models/models.h"
#include "Cell00ProjectileModel.h"

/*
Constructor of Cell0ProjectileModel
*/
Cell00ProjectileModel::Cell00ProjectileModel(CharacterModel* source, CharacterModel* target) 
    : ProjectileModel(CELL_00_PROJECTILE, source, target) {
    // Temporary data
    speed = 4.0;
    damage = 1;
}