#include "LevelButton.h"
#include "Scenes/GameScene/GameScene.h"
#include "UIObjects/uiobj.h"
#include "UINumeric/UINumeric.h"
#define TRANSITION_TIME 0.5f
USING_NS_CC;
using namespace cocos2d;
levelButton* levelButton::create(int number) {
	levelButton*  button = new(std::nothrow) levelButton;
	std::string filename = "sprites/objects/button/levelButton/numberic";
	std::string png = ".png";
	std::string num = std::to_string(number);
	filename = filename + num + png;
	if (button && button->init(filename, filename, filename)) {
		CCLOG("true");
		button->setScale(0.75);
		button->level = number;
		button->autorelease();
		button->onTouch();
		return button;
	}
	CC_SAFE_DELETE(button);
	return nullptr;
}
void levelButton::onTouch() {
	this->addTouchEventListener(CC_CALLBACK_2(levelButton::touchControlEvent, this));
}
void levelButton::touchControlEvent(Ref *sender, ui::Widget::TouchEventType type) {
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		CCLOG("Touch level!");
		break;
	case ui::Widget::TouchEventType::ENDED:
	{
		CCLOG("level!");
		auto scene = GameScene::create(level);
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
		break;
	}
	default:
		break;
	}
}