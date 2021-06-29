#include "ShootingCellModel.h"
using namespace std;

/*
Shoot projectile from source to target
*/
void ShootingCellModel::shoot(CharacterModel* target) {
    auto projectile = new ProjectileModel(level, projectileId, this, target);
}

/*
Update on each updating
*/
void ShootingCellModel::update() {
    CellModel::update();

    // Shoot target in range
    if (isAlive) {
        auto diseaseList = level->__getDiseaseList();
        auto target = diseaseList.end();
        for (auto it = diseaseList.begin(); it != diseaseList.end(); it++) {
            if (getDistanceToOther(*it) <= distance) {
                if (target != diseaseList.end()) {
                    if (getDistanceToOther(*target) > getDistanceToOther(*it)) {
                        target = it;
                    }
                }
                else {
                    target = it;
                }
            }
        }

        // Shoot to target
        if (target != diseaseList.end()) {
            shoot(*target);
        }
    }
}