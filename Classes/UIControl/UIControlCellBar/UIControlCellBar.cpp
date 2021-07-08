#include "UIControlCellBar.h"
#include "Scenes/GameScene/GSDefine.h"
USING_NS_CC;

/*
Add to Scene
*/
void UIControlCellBar::addToScene(Scene* scene) {
	scene->addChild(this, CELLBAR_LAYER_ZORDER);
}


void UIControlCellBar::touchControlEvent(Ref *sender, ui::Widget::TouchEventType type) {
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		CCLOG("Touch");
		break;
	case ui::Widget::TouchEventType::ENDED:
		CCLOG("Cell Hold");
		//Plant Cell
		removeFromScene();
		break;
	default:
		break;
	}
};

UIControlCellBar* UIControlCellBar::create() {
	UIControlCellBar *btn = new (std::nothrow) UIControlCellBar;
	if (btn && btn->init(CELLBAR_00, CELLBAR_00, CELLBAR_00, TextureResType::LOCAL))
	{
		btn->autorelease();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return nullptr;
}

void UIControlCellBar::onTouch() {
	this->addTouchEventListener(CC_CALLBACK_2(UIControlCellBar::touchControlEvent, this));
}