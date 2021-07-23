#include "MMBackgroundLayer.h"
#include "Scenes/GameScene/GSDefine.h"

USING_NS_CC;

bool MMBackgroundLayer::init() {
	if (!Scene::init())
	{
		return false;
	}
	setBackgroundImagePosition();
	setNameGamePosition();
	return true;
}

void MMBackgroundLayer::setBackgroundImagePosition()
{	
	auto t = time(NULL);
	auto hour = localtime(&t)->tm_hour;
	auto background = Sprite::create(IMG_MMBGAFTER);
	if (hour <= 6 || hour >= 18) {
		background = Sprite::create(IMG_MMBGNIGHT);
	}
	else if (hour > 6 && hour < 15) {
		background = Sprite::create(IMG_MMBGMOR);
	}
	if (background != nullptr)
	{
		background->setAnchorPoint(Point(0, 0));
		background->setContentSize(Size(WIDTH, HEIGHT));
		background->setPosition(Vec2(0, 0));
		this->addChild(background,-1);
	}
}


void MMBackgroundLayer::setNameGamePosition() {
	auto namegame = Sprite::create(IMG_NAMEGAME);
	namegame->setAnchorPoint(Vec2(0.5f, 0.5f));
	namegame->setPosition(WIDTH/2, HEIGHT*7/8);
	this->addChild(namegame, 0);
}


