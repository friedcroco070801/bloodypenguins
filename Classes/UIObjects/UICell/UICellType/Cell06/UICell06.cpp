#include "UIObjects/uiobj.h"
#include "UICell06.h"

/*
Create a new instance of UICell00
*/
UICell06* UICell06::create() {
	UICell06 *uicell = new (std::nothrow) UICell06();
	if (uicell && uicell->initWithFile(CELL_06_FILENAME))
	{
		uicell->autorelease();
		return uicell;
	}
	CC_SAFE_DELETE(uicell);
	return nullptr;
}
void UICell06::addToScene(cocos2d::Scene* scene) {
	//this->setAnchorPoint(cocos2d::Point(0.5, 0.5));
	//this->setScale(0.75);
	scene->addChild(this, CELL_LAYER_ZORDER);
	this->idleAnimate();
}
void UICell06::idleAnimate() {
	this->stopAllActionsByTag(ANIM_BASE_TAG);

	//this->stopActionByTag();

	const int numberSprite = 65;
	cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;
	int size = cocos2d::Sprite::create(CELL_06_FILENAME)->getContentSize().height;
	animFrames.reserve(numberSprite);
	for (int i = 0; i < numberSprite; i++) {
		animFrames.pushBack(cocos2d::SpriteFrame::create(CELL_06_FILENAME, cocos2d::Rect(size * i, 0, size, size)));
	}
	cocos2d::Animation* animation = cocos2d::Animation::createWithSpriteFrames(animFrames, 0.05f);
	cocos2d::Animate *animate = cocos2d::Animate::create(animation);

	//animate->setTag();

	this->setRotation3D(cocos2d::Vec3(0, 180.0f, 0));
	auto idle = cocos2d::RepeatForever::create(animate);

	idle->setTag(ANIM_BASE_TAG);

	this->runAction(idle);
}
void UICell06::effectAnimate() {
	auto scaleBy = cocos2d::ScaleBy::create(1.0f, 3.0f, 3.0f);
	auto remove = cocos2d::RemoveSelf::create();
	auto squence = cocos2d::Sequence::create(scaleBy, remove, nullptr);
	this->runAction(squence);
}

