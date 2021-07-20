#include "UIObjects/uiobj.h"
#include "UICell04.h"
#include "Scenes/GameScene/GSDefine.h"

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
	this->setAnchorPoint(cocos2d::Point(0.5,0.3));
	this->setScale(0.75);
	scene->addChild(this, CELL_LAYER_ZORDER);
	this->idleAnimate();
}
void UICell04::idleAnimate() {
	this->stopAllActionsByTag(ANIM_BASE_TAG);

	//this->stopActionByTag();

	const int numberSprite = 65;
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

	idle->setTag(ANIM_BASE_TAG);

	this->runAction(idle);

}
void UICell04::effectAnimate() {

	auto tintTo = cocos2d::TintTo::create(0.1, cocos2d::Color3B::BLUE);
	auto tintTo_ = cocos2d::TintTo::create(0.1, cocos2d::Color3B::WHITE);
	auto remove = cocos2d::RemoveSelf::create();
	auto sequenceSprites = cocos2d::Sequence::create(tintTo, tintTo_, tintTo->clone(), tintTo_->clone(),remove, nullptr);
	auto scale_ = cocos2d::ScaleBy::create(0.5, 0.5);
	auto mySpawn = cocos2d::Spawn::createWithTwoActions(scale_, sequenceSprites);
	this->runAction(mySpawn);
}


