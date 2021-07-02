#include "GSInformationLayer.h"
#include "GSDefine.h"
USING_NS_CC;
bool GSInformationLayer::init() {
	if (!Scene::init())
	{
		return false;
	}
	UpdateGold(9999);
	UpdateDiamond(9999);
	UpdateEnergy(9999);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	return true;
}
void GSInformationLayer::UpdateGold(int gold_) {
	this->gold = gold_;
	auto goldBackground = Sprite::create("sprites/InformationLayer/gold.png");
	goldBackground->setContentSize(Size(ICON_SIZE, ICON_SIZE));
	goldBackground->setAnchorPoint(Vec2(0, 0));
	goldBackground->setPosition(GOLD_POSITION);
	this->addChild(goldBackground, 2);

	std::string number = std::to_string(gold_);
	for (int j = 0; j < number.length(); j++) {
		int i = number[j];
		i = i - 48;
		auto sprite = Sprite::create("sprites/InformationLayer/number.png");
		auto ith_number = Sprite::create("sprites/InformationLayer/number.png", Rect(sprite->getContentSize().width / 10 * i, 0, sprite->getContentSize().width / 10, sprite->getContentSize().height));
		ith_number->setContentSize(Size(NUMBER_SIZE,NUMBER_SIZE));
		ith_number->setAnchorPoint(Vec2(0, 0));
		ith_number->setPosition(Vec2(WIDTH / 160 + ICON_SIZE + WIDTH * 1 / 5 + NUMBER_SIZE *j + NUMBER_SIZE/2,NUMBER_HEIGHT));
		this->addChild(ith_number, 2);
	}

}
void GSInformationLayer::UpdateDiamond(int diamond_) {
	this->diamond = diamond_;
	auto diamondBackground = Sprite::create("sprites/InformationLayer/diamond.png");
	diamondBackground->setContentSize(Size(ICON_SIZE, ICON_SIZE));
	diamondBackground->setAnchorPoint(Vec2(0, 0));
	diamondBackground->setPosition(DIAMOND_POSITION);
	this->addChild(diamondBackground, 2);
	std::string number = std::to_string(diamond_);
	for (int j = 0; j < number.length(); j++) {
		int i = number[j];
		i = i - 48;
		auto sprite = Sprite::create("sprites/InformationLayer/number.png");
		auto ith_number = Sprite::create("sprites/InformationLayer/number.png", Rect(sprite->getContentSize().width / 10 * i, 0, sprite->getContentSize().width / 10, sprite->getContentSize().height));
		ith_number->setContentSize(Size(NUMBER_SIZE, NUMBER_SIZE));
		ith_number->setAnchorPoint(Vec2(0, 0));
		ith_number->setPosition(Vec2(WIDTH / 160 + ICON_SIZE + WIDTH * 2 / 5 + NUMBER_SIZE * j + NUMBER_SIZE / 2, NUMBER_HEIGHT));
		this->addChild(ith_number, 2);
	}

}
void GSInformationLayer::UpdateEnergy(int energy_) {
	this->energy = energy_;
	auto energyBackground = Sprite::create("sprites/InformationLayer/energy.png");
	energyBackground->setContentSize(Size(ICON_SIZE, ICON_SIZE));
	energyBackground->setAnchorPoint(Vec2(0, 0));
	energyBackground->setPosition(ENERGY_POSITION);
	std::string number = std::to_string(energy_);
	for (int j = 0; j < number.length(); j++) {
		int i = number[j];
		i = i - 48;
		auto sprite = Sprite::create("sprites/InformationLayer/number.png");
		auto ith_number = Sprite::create("sprites/InformationLayer/number.png", Rect(sprite->getContentSize().width / 10 * i, 0, sprite->getContentSize().width / 10, sprite->getContentSize().height));
		ith_number->setContentSize(Size(NUMBER_SIZE, NUMBER_SIZE));
		ith_number->setAnchorPoint(Vec2(0, 0));
		ith_number->setPosition(Vec2(WIDTH / 160 + ICON_SIZE + NUMBER_SIZE * j + NUMBER_SIZE / 2, NUMBER_HEIGHT));
		this->addChild(ith_number, 2);
	}

	this->addChild(energyBackground, 2);
}

