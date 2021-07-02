#include "UIObjects/uiobj.h"
#include "UICell.h"
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
        UICell *uicell = new (std::nothrow) UICell();
        if (uicell && uicell->initWithFile(CELL_00_FILENAME))
        {
            uicell->autorelease();
            return uicell;
        }
        CC_SAFE_DELETE(uicell);
        return nullptr;
    }
    return nullptr;
}