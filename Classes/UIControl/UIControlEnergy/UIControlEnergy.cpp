#include "UIControlEnergy.h"
#include "../../Scenes/GameScene/GSDefine.h"

USING_NS_CC;

void UIControlEnergy::setCellPosition(double cellX, double cellY) {
	//setPosition(cellX * CELL_WIDTH + POS_X_ORIGIN, cellY * CELL_WIDTH + POS_Y_ORIGIN);
}

/*
Add UIObjects to Scene
*/
void UIControlEnergy::addToScene(Scene* scene) {
	scene->addChild(this, ENERGY_LAYER_ZORDER);
}

void UIControlEnergy::addButton() {

}
/*
Remove UIObjects from Scene
*/
void UIControlEnergy::removeFromScene() {
    removeFromParent();
}

void UIControlEnergy::touchControlEvent(Ref *sender, ui::Widget::TouchEventType type) {
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		CCLOG("Touch");
		break;
	case ui::Widget::TouchEventType::ENDED:
		CCLOG("Energy update");
		//update energy
		removeFromScene();
		break;
	default:
		break;
	}
};

