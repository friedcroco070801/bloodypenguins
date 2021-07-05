#include "UIObjects.h"
#include "Scenes/GameScene/GSDefine.h"
USING_NS_CC;

/*
Convert from cell position to screen position
*/
void UIObjects::setCellPosition(double cellX, double cellY) {
    setPosition(cellX * CELL_WIDTH + POS_X_ORIGIN, cellY * CELL_WIDTH + POS_Y_ORIGIN);

	//setPosition(GRASS_POSITION_LEFT + SIZE_OF_SQUARE * cellX + SIZE_OF_SQUARE / 2, GRASS_POSITION_BOTTOM + SIZE_OF_SQUARE * (cellY + 1) - SIZE_OF_SQUARE / 2);
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