#include "UIControlEnergy.h"
#include "Scenes/GameScene/GSDefine.h"
#include "UIObjects/uiobj.h"

USING_NS_CC;

void UIControlEnergy::setCellPosition(double cellX, double cellY) {
	setPosition(Vec2((float)cellX * CELL_WIDTH + POS_X_ORIGIN, (float)cellY * CELL_WIDTH + POS_Y_ORIGIN));
}

/*
Add UIObjects to Scene
*/
void UIControlEnergy::addToScene(Scene* scene) {
	scene->addChild(this, ENERGY_LAYER_ZORDER);
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

UIControlEnergy* UIControlEnergy::create() {
	UIControlEnergy *btn = new (std::nothrow) UIControlEnergy;
	if (btn && btn->init(IMG_ENERGY, IMG_ENERGY, IMG_ENERGY, TextureResType::LOCAL))
	{
		btn->autorelease();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return nullptr;
}

void UIControlEnergy::onTouch() {
	this->addTouchEventListener(CC_CALLBACK_2(UIControlEnergy::touchControlEvent, this));
}

