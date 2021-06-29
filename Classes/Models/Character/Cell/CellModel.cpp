#include "CellModel.h"

/* 
Constructor of CellModel
*/
CellModel::CellModel(LevelModel* level, CellId id) : CharacterModel(level, CELL) {
    this->id = id;
}

/*
Update on each updating
*/
void CellModel::update() {
    // Check for available hp
    if (hp <= 0) {
        alive = false;
        level->dumpCell(this);
        return;
    }
}