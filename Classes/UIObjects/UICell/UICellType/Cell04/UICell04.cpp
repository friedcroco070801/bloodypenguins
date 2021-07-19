#include "UIObjects/uiobj.h"
#include "UICell04.h"

/*
Create a new instance of UICell00
*/
UICell04* UICell04::create() {
    UICell04 *uicell = new (std::nothrow) UICell04();
    if (uicell && uicell->initWithFile(CELL_04_FILENAME))
    {
        uicell->autorelease();
        return uicell;
    }
    CC_SAFE_DELETE(uicell);
    return nullptr;
}
void UICell04::addToScene(cocos2d::Scene* scene) {
	this->setAnchorPoint(cocos2d::Point(0.5,0.25));
	this->setScale(0.75);
	scene->addChild(this, CELL_LAYER_ZORDER);
	this->idleAnimate();
}
void UICell04::idleAnimate() {
	this->stopAllActions();

	//this->stopActionByTag();

	const int numberSprite = 4;
	this->stopAllActions();
	cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;
	int size = cocos2d::Sprite::create(CELL_04_FILENAME)->getContentSize().height;
	animFrames.reserve(numberSprite);
	for (int i = 0; i < numberSprite; i++) {
		animFrames.pushBack(cocos2d::SpriteFrame::create(CELL_04_FILENAME, cocos2d::Rect(size * i, 0, size, size)));
	}
	cocos2d::Animation* animation = cocos2d::Animation::createWithSpriteFrames(animFrames, 0.05f);
	cocos2d::Animate *animate = cocos2d::Animate::create(animation);
	
	//animate->setTag();

	this->setRotation3D(cocos2d::Vec3(0, 180.0f, 0));
	auto idle = cocos2d::RepeatForever::create(animate);
	this->runAction(idle);
}
void UICell04::effectAnimate() {
	auto scaleBy = cocos2d::ScaleBy::create(0.5f, 2.0f, 2.0f);
	this->runAction(scaleBy);
}
/*
void UICell04::hitAnimate() {
	auto tintTo = cocos2d::TintTo::create(0.1, cocos2d::Color3B::RED);
	auto tintTo_ = cocos2d::TintTo::create(0.1, cocos2d::Color3B::WHITE);
	auto sequenceSprites = cocos2d::Sequence::create(tintTo, tintTo_, nullptr);
	this->runAction(sequenceSprites);
}
*/
void UICell04::dieAnimate() {
	this->stopAllActions();

	//this->stopActionByTag();

	auto fadeOut = cocos2d::FadeOut::create(1.0f);
	auto remove = cocos2d::RemoveSelf::create();
	auto sequence = cocos2d::Sequence::create(fadeOut, remove, nullptr);
	this->runAction(sequence);
}