#include "Models/models.h"
#include "CellModel.h"
#include "UIObjects/uiobj.h"

/* 
Constructor of CellModel
*/
CellModel::CellModel(CellId id) : CharacterModel(CELL) {
    this->id = id;
    ui = nullptr;

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

        // Destroy UIObject
        ui->removeFromScene();
        return;
    }
}

/*
Set UI Object for the CellModel
*/
void CellModel::setUIObject(UICell* ui) {
    this->ui = ui;
}