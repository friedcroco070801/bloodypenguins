#include "Models/models.h"
#include "Disease06Model.h"
#include "UIObjects/uiobj.h"

Disease06Model::Disease06Model() : DiseaseModel(DISEASE_06_EBOLA) {
    // Temporary data
    speed = 0.2;
    damage = 50;
    hitRechargeTime = 2;
    hp = 120;
    distance = 1.5;
    waitingUntilNextMove = 0.0;
}

/*
Boss hit target
*/
void Disease06Model::hitTarget(CellModel*) {
    ui->attackAnimate(dir);
    auto cellList = level->__getCellList();
    for (auto it = cellList.begin(); it != cellList.end(); it++) {
        if (getDistanceToOther(*it) <= distance + 0.000001) {
            (*it)->takeDamage(damage);
            (*it)->__getUIObject()->hitAnimate();
        }
    }

    // Update counter
    waitingUntilNextMove = 2.0;
    ui->idleAnimate(dir);
}

/*
Update on each updating of Disease06
*/
void Disease06Model::update() {
    // Check waiting for next move
    if (waitingUntilNextMove <= ACCEPTING_TIME_ERROR) {
        DiseaseModel::update();
    }
    else {
        waitingUntilNextMove -= UPDATING_FREQUENCY;
    }
}