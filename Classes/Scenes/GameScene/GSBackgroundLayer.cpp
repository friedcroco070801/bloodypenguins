#include "GSBackgroundLayer.h"
#include "GSDefine.h"

USING_NS_CC;

bool GSBackgroundLayer::init() {
	if (!Scene::init())
	{
		return false;
	}
	setBackgroundImagePosition();
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


