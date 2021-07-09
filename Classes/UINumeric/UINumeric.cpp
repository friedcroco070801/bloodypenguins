#include "UINumeric.h"
#include "../Scenes/GameScene/GSDefine.h"

USING_NS_CC;


/*
Add to Scene
*/
void UINumeric::addToScene(Scene* scene) {
    scene->addChild(this, NUMERIC_LAYER_ZORDER);
}

/*
Remove from Scene
*/
void UINumeric::removeFromScene() {
    removeFromParent();
}


void UINumeric::changeValue(int value) {
	for (auto digit : digitList) {
		getParent()->removeChild(digit);
	}
	digitList.clear();

	std::string number = std::to_string(value);
	for (int j = 0; j < number.length(); j++) {
		int i = number[j];
		i = i - 48;
		auto sprite = Sprite::create(NUMERIC_IMG);
		auto ith_number = Sprite::create(NUMERIC_IMG, Rect(sprite->getContentSize().width / 10 * i, 0, sprite->getContentSize().width / 10, sprite->getContentSize().height));
		//ith_number->setContentSize(Size(NUMBER_SIZE, NUMBER_SIZE));
		//ith_number->setAnchorPoint(Vec2(0, 0));
		sprite->setContentSize(Size(sprite->getContentSize().width * scale, sprite->getContentSize().height * scale));
		ith_number->setContentSize(Size(ith_number->getContentSize().width * scale, ith_number->getContentSize().height * scale));
		ith_number->setPosition(Vec2(getPosition().x + ith_number->getContentSize().width * (1/2 + j), getPosition().y));
		//ith_number->setPosition(Vec2(WIDTH / 160 + ICON_SIZE + WIDTH* 1/5 + NUMBER_SIZE * j + NUMBER_SIZE / 2, NUMBER_HEIGHT));
		getParent()->addChild(ith_number, NUMERIC_LAYER_ZORDER);
		digitList.pushBack(ith_number);
	}
}

UINumeric* UINumeric::create() {
	UINumeric * ret = new (std::nothrow) UINumeric;
    if (ret && ret->init())
    {
		ret->scale = 0.67;
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}