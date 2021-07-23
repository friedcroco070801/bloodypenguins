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
	//auto visibleSize = Director::getInstance()->getVisibleSize();
	//Vec2 origin = Director::getInstance()->getVisibleOrigin();
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
		//background->setContentSize(visibleSize);
		//background->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		background->setOpacity(175);
		this->addChild(background,-1);
	}
}


void MMBackgroundLayer::setNameGamePosition() {

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto namegame = Sprite::create(IMG_NAMEGAME);
	namegame->setAnchorPoint(Vec2(0.5f, 0.375f));
	namegame->setScale(1.25);
	namegame->setPosition(Vec2(10.f + visibleSize.width / 2 + origin.x, visibleSize.height + origin.y));
	auto moveto = MoveTo::create(2, Vec2(10.f + visibleSize.width / 2 + origin.x, visibleSize.height * 7 / 8 + origin.y - 10.f));
	namegame->runAction(moveto);
	auto roto = RotateBy::create(2, Vec3(0, 360, 0));
	auto delay = DelayTime::create(16);
	auto seqname = Sequence::create(roto, delay, nullptr);
	auto repeat = RepeatForever::create(seqname);
	namegame->runAction(repeat);
	this->addChild(namegame, 0);
}


