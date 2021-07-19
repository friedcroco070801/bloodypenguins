#include "GSBackgroundLayer.h"
#include "GSDefine.h"

USING_NS_CC;

bool GSBackgroundLayer::init() {
	if (!Scene::init())
	{
		return false;
	}
	setBackgroundImagePosition();
	setEnergyBarImage();
	return true;
}

void GSBackgroundLayer::setBackgroundImagePosition()
{
	auto background = Sprite::create(IMG_BG1);
	if (background != nullptr)
	{
		background->setAnchorPoint(Point(0, 0));
		background->setContentSize(Size(WIDTH, HEIGHT));
		background->setPosition(Vec2(0, 0));
		this->addChild(background,-1);
	}
}

void GSBackgroundLayer::setEnergyBarImage() {
	auto energy = Sprite::create(ENERGY_BAR_FILENAME);
	energy->setAnchorPoint(Vec2(0.0f, 0.5f));
	energy->setPosition(5.0f + Director::getInstance()->getVisibleOrigin().x, Director::getInstance()->getVisibleSize().height * 15 / 16 + Director::getInstance()->getVisibleOrigin().y);
	this->addChild(energy, -1);
}

