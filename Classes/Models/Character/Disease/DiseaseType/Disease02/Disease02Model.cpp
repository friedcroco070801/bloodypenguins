#include "Models/models.h"
#include "Disease02Model.h"

Disease02Model::Disease02Model() : DiseaseModel(DISEASE_02_INFLUENZA) {
    // Temporary data
    speed = 1.0;
    damage = 2;
    hitRechargeTime = 0.5;
    hp = 7;

    ignoreCell = true;
    betweenCounter = 0.0;
}

/*
Update of Disease02Model
*/
void Disease02Model::update() {
    if (abs(betweenCounter) <= ACCEPTING_TIME_ERROR) {
        DiseaseModel::update();

        // Trigger between effect
        if (action == WAITING && ignoreCell == true) {
            // Replacing path
            auto preDir = dir;
            changeDirectionOnPath();
            if (dir != preDir) {
                dir = preDir;
                ignoreCell = false;
                speed = 0.25;
                betweenCounter = DISEASE_02_BETWEEN_EFFECT_COUNTER;
            }

            // Check if cell in path
            else if (nextPath != path->end()) {
                if ((level->__getMap())[(*nextPath)[0]][(*nextPath)[1]] == EMPTY_CAN_PUT_OCCUPIED) {
                    ignoreCell = false;
                    speed = 0.25;
                    betweenCounter = DISEASE_02_BETWEEN_EFFECT_COUNTER;
                }
            }
        }
    }
    else {
        betweenCounter -= UPDATING_FREQUENCY;
    }
}