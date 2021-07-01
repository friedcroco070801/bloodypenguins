#include "Models/models.h"
#include "CellModel.h"

/* 
Constructor of CellModel
*/
CellModel::CellModel(CellId id) : CharacterModel(CELL) {
    this->id = id;

    // Temporary data
    distance = 2.0;
    cost = 100;
}

/* 
Create new instance of CellModel with factory
*/
CellModel* CellModel::create(CellId id) {
    return new ShootingCellModel(id);
} 

/*
Update on each updating
*/
void CellModel::update() {
    // Check for available hp
    if (hp <= 0 && alive && level != NULL) {
        alive = false;
        level->dumpCell(this);
        this->level = NULL;
        return;
    }
}