#include "UIObjects/uiobj.h"
#include "UICell.h"
#include "UICellType/UICellType.h"
USING_NS_CC;

/*
Add UICell to scene
*/
void UICell::addToScene(Scene* scene) {
    scene->addChild(this, CELL_LAYER_ZORDER);
}

/*
Create a new instance of UICell with CellId
*/
UICell* UICell::create(CellId id) {
    switch (id) {
    // Case id 00: Eosinophils
    case CELL_00_EOSINOPHILS:
        return UICell00::create();
        break;
    
    // Case id 01: Ethry
    case CELL_01_ERYTHROCYTES:
        return UICell01::create();
        break;
    }
    return nullptr;
}