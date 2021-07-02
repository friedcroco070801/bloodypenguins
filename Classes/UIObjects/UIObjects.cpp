#include "UIObjects.h"
USING_NS_CC;

/*
Convert from cell position to screen position
*/
void UIObjects::setCellPosition(double cellX, double cellY) {
    setPosition(cellX * CELL_WIDTH + POS_X_ORIGIN, cellY * CELL_WIDTH + POS_Y_ORIGIN);
}

/*
Add UIObjects to Scene
*/
void UIObjects::addToScene(Scene* scene) {
    scene->addChild(this);
}

/*
Remove UIObjects from Scene
*/
void UIObjects::removeFromScene() {
    removeFromParent();
}