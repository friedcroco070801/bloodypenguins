#include "CellModel.h"

/* 
Constructor of CellModel
*/
CellModel::CellModel(CellId id) : CharacterModel(CELL) {
    this->id = id;
}
