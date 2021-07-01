#include "GSInformationLayer.h"
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
	auto goldBackground = Sprite::create("sprites/gold.png");
	goldBackground->setContentSize(Size(30, 30));
	goldBackground->setAnchorPoint(Vec2(0, 0));
	goldBackground->setPosition(Vec2(600, 650));
	this->addChild(goldBackground, 2);
	int i;
	int count = 1;
	while (gold_ != 0)
	{
		i = gold_ % 10;
		gold_ = gold_ / 10;
		auto sprite = Sprite::create("sprites/number.png");
		auto ith_number = Sprite::create("sprites/number.png", Rect(sprite->getContentSize().width / 10 * i, 0, sprite->getContentSize().width / 10, sprite->getContentSize().height));
		ith_number->setContentSize(Size(15, 15));
		ith_number->setAnchorPoint(Vec2(0, 0));
		ith_number->setPosition(Vec2(600 - count * 15, 650));
		count++;
		this->addChild(ith_number, 2);
	}
}
void GSInformationLayer::UpdateDiamond(int diamond_) {
	this->diamond = diamond_;
	auto diamondBackground = Sprite::create("sprites/diamond.png");
	diamondBackground->setContentSize(Size(30, 30));
	diamondBackground->setAnchorPoint(Vec2(0, 0));
	diamondBackground->setPosition(Vec2(300, 650));
	int i;
	int count = 1;
	while (diamond_ != 0)
	{
		i = diamond_ % 10;
		diamond_ = diamond_ / 10;
		auto sprite = Sprite::create("sprites/number.png");
		auto ith_number = Sprite::create("sprites/number.png", Rect(sprite->getContentSize().width / 10 * i, 0, sprite->getContentSize().width / 10, sprite->getContentSize().height));
		ith_number->setContentSize(Size(15, 15));
		ith_number->setAnchorPoint(Vec2(0, 0));
		ith_number->setPosition(Vec2(300 - count * 15, 650));
		count++;
		this->addChild(ith_number, 2);
	}
	this->addChild(diamondBackground, 2);
}
void GSInformationLayer::UpdateEnergy(int energy_) {
	this->energy = energy_;
	auto energyBackground = Sprite::create("sprites/energy.png");
	energyBackground->setContentSize(Size(30, 30));
	energyBackground->setAnchorPoint(Vec2(0, 0));
	energyBackground->setPosition(Vec2(150, 650));
	int i;
	int count = 1;
	while (energy_ != 0)
	{
		i = energy_ % 10;
		energy_ = energy_ / 10;
		auto sprite = Sprite::create("sprites/number.png");
		auto ith_number = Sprite::create("sprites/number.png", Rect(sprite->getContentSize().width / 10 * i, 0, sprite->getContentSize().width / 10, sprite->getContentSize().height));
		ith_number->setContentSize(Size(15, 15));
		ith_number->setAnchorPoint(Vec2(0, 0));
		ith_number->setPosition(Vec2(150 - count * 15, 650));
		count++;
		this->addChild(ith_number, 2);
	}

	this->addChild(energyBackground, 2);
}

