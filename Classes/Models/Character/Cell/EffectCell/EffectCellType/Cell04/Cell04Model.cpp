#include "Models/models.h"
#include "Cell04Model.h"

/*
Cell04Model constructor
*/
Cell04Model::Cell04Model() : EffectCellModel(CELL_04_MONOCYTES) {
    rechargeTime = 40.0;
    distance = 1.0;
    cost = 50;
    hp = 80;

    // Do not use
    effectRechargeTime = 0.5;
    effectTimeCounter = 0.5;
} 

/*
Cell04Model take effect: None
*/
void Cell04Model::takeEffect() {

}

/* 
Check if can put the plant on map
*/
bool Cell04Model::canPutOn(LevelModel* level, int cellX, int cellY) {
    if (level != NULL) {
        auto map = level->getMap();
        auto maxX = map.size();
        auto maxY = map[0].size();
        if (cellX < 0 || cellX >= maxX) return false;
        if (cellY < 0 || cellY >= maxY) return false;
        if (map[cellX][cellY] == ENEMY_PATH) return true;
    }
    return false;
}

