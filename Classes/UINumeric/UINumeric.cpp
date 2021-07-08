#include "UINumeric.h"
#include "../Scenes/GameScene/GSDefine.h"

USING_NS_CC;


/*
Add to Scene
*/
void UINumeric::addToScene(Scene* scene) {
    scene->addChild(this);
}

/*
Remove from Scene
*/
void UINumeric::removeFromScene() {
    removeFromParent();
}


void UINumeric::changeValue(int value) {
	this->removeFromParent();
	std::string number = std::to_string(value);
	for (int j = 0; j < number.length(); j++) {
		int i = number[j];
		i = i - 48;
		auto sprite = Sprite::create("sprites/InformationLayer/number.png");
		auto ith_number = Sprite::create("sprites/InformationLayer/number.png", Rect(sprite->getContentSize().width / 10 * i, 0, sprite->getContentSize().width / 10, sprite->getContentSize().height));
		ith_number->setContentSize(Size(NUMBER_SIZE, NUMBER_SIZE));
		ith_number->setAnchorPoint(Vec2(0, 0));
		ith_number->setPosition(Vec2(WIDTH / 160 + ICON_SIZE + NUMBER_SIZE * j + NUMBER_SIZE / 2, NUMBER_HEIGHT));
		//ith_number->setPosition(Vec2(WIDTH / 160 + ICON_SIZE + WIDTH* 1/5 + NUMBER_SIZE * j + NUMBER_SIZE / 2, NUMBER_HEIGHT));
		this->addChild(ith_number, 2);
	}
}