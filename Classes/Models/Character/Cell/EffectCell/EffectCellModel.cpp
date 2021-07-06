#include "Models/models.h"
#include "EffectCellModel.h"
#include "EffectCellType/EffectCellType.h"

/*
Constructor of EffectCellModel
*/
EffectCellModel::EffectCellModel(CellId id) : CellModel(id) {

}

/*
Effect Cell Model update on each updating
*/
void EffectCellModel::update() {
    CellModel::update();
    if (alive & level != NULL) {
        effectTimeCounter -= UPDATING_FREQUENCY;
        if (abs(effectTimeCounter) <= ACCEPTING_TIME_ERROR) {
            effectTimeCounter = effectRechargeTime;
            takeEffect();
        }
    }
}