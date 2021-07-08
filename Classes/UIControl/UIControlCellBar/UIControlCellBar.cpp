#include "UIControlCellBar.h"
#include "Scenes/GameScene/GSDefine.h"
USING_NS_CC;

void UIControlCellBar::addToScene(Scene* scene) {
	scene->addChild(this, CELLBAR_LAYER_ZORDER);
}

void UIControlCellBar::addButton() {
	cellbar = ui::Button::create("sprites/hello_world.png");
	cellbar->setScale(0.5);
	cellbar->setAnchorPoint(Vec2(0, 0));
	cellbar->cocos2d::Node::setPosition(Vec2(WIDTH*0.75,0));
	cellbar->setTouchEnabled(false);
	this->addChild(cellbar);
}
/*
void UIControlCellBar::onTouch() {
	auto button = Button::create(CELLBAR_00_FILENAME);

	//button->setPosition(Vec2(Vis));

	button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			CCLOG("Button touch");
			break;
		case ui::Widget::TouchEventType::ENDED:
			CCLOG("Button da clicked");
			break;
		default:
			break;
		}
	});

	this->addChild(button);
}
*/
