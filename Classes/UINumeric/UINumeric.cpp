#include "UINumeric.h"
#include "../Scenes/GameScene/GSDefine.h"

USING_NS_CC;

/*
Convert from cell position to screen position
*/
void UINumeric::setPosition(double X, double Y) {

	float anchorX = X * WIDTH + POS_X_ORIGIN - 20.0f;
	float anchorY = Y * HEIGHT + POS_Y_ORIGIN - 20.0f - Sprite::create("sprites/InformationLayer/number.png")->getContentSize().height / 2;

	setPosition(anchorX, anchorY);

	//setPosition(GRASS_POSITION_LEFT + SIZE_OF_SQUARE * cellX + SIZE_OF_SQUARE / 2, GRASS_POSITION_BOTTOM + SIZE_OF_SQUARE * (cellY + 1) - SIZE_OF_SQUARE / 2);
}

/*
Add UIObjects to Scene
*/
void UINumeric::addToScene(Scene* scene) {
    scene->addChild(this);
}

/*
Remove UIObjects from Scene
*/
void UINumeric::removeFromScene() {
    removeFromParent();
}

void UINumeric::changeValue(int value) {
	
		
}