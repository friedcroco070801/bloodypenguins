#include "ShootingCellModel.h"
#include <cmath>
using namespace std;

/* 
Constructor of shooting cell model
*/
ShootingCellModel::ShootingCellModel(CellId cellId) : CellModel(cellId) {
    // Temporary data
    shootRechargeTime = 1.0f;
};

/*
Shoot projectile from source to target
*/
void ShootingCellModel::shoot(CharacterModel* target) {
    if (level != NULL) {
        auto projectile = ProjectileModel::create(projectileId, this, target);
        level->addProjectile(projectile);
    }
}

/*
Update on each updating
*/
void ShootingCellModel::update() {
    CellModel::update();

    if (isAlive && level != NULL) {
        // Check if recharge time
        auto timePoint = level->getTimeCounter() / shootRechargeTime;
        auto roundTimePoint = round(timePoint);
        auto deltaError = timePoint - roundTimePoint;
        if (deltaError >= -ACCEPTING_TIME_ERROR && deltaError <= ACCEPTING_TIME_ERROR) {
            // Find target in range
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
}