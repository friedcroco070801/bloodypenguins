#include "UIObjects/uiobj.h"
#include "UICell00.h"


/*
Create a new instance of UICell00
*/
UICell00* UICell00::create() {
    UICell00 *uicell = new (std::nothrow) UICell00();
    if (uicell && uicell->initWithFile(CELL_00_FILENAME))
    {
        uicell->autorelease();
        return uicell;
    }
	
    CC_SAFE_DELETE(uicell);
    return nullptr;
}
void UICell00::addToScene(cocos2d::Scene* scene) {
	scene->addChild(this, CELL_LAYER_ZORDER);
	this->idleAnimate();
}

void UICell00::idleAnimate() {
/*
	const int numberSprite_ = 5;

	auto eggcrack = cocos2d::Sprite::create("sprites/objects/cell/animation/eggCracks.png");
	float size = eggcrack->getContentSize().height;
	cocos2d::Vector<cocos2d::SpriteFrame*> animFrames_;
	animFrames_.reserve(numberSprite_);
	for (int i = 0; i < numberSprite_; i++) {
		auto Frame = cocos2d::SpriteFrame::create("sprites/objects/cell/animation/eggCracks.png", cocos2d::Rect(size * i, 0, size, size));
		animFrames_.pushBack(Frame);
	}
	cocos2d::Animation* animation_ = cocos2d::Animation::createWithSpriteFrames(animFrames_, 0.5f);
	cocos2d::Animate *animate_ = cocos2d::Animate::create(animation_);
*/

	const int numberSprite = 20;
	this->stopAllActions();
	cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;
	animFrames.reserve(numberSprite);
	for (int i = 0; i < numberSprite ; i++) {
		auto Frame = cocos2d::SpriteFrame::create("sprites/objects/cell/animation/Bulbasaur.png", cocos2d::Rect(96 * i, 0, 96, 96));
		animFrames.pushBack(Frame);
	}
	cocos2d::Animation* animation = cocos2d::Animation::createWithSpriteFrames(animFrames,0.05f);	
	cocos2d::Animate *animate = cocos2d::Animate::create(animation);
	this->setRotation3D(cocos2d::Vec3(0, 180.0f, 0));
	auto idle = cocos2d::RepeatForever::create(animate);
	this->runAction(idle);
}

void UICell00::attackAnimate() {
	this->stopAllActions();
	const int numberSprite = 40;

	cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;
	animFrames.reserve(numberSprite);
	for (int i = 20; i < numberSprite ; i++) {
		animFrames.pushBack(cocos2d::SpriteFrame::create("sprites/objects/cell/animation/Bulbasaur.png", cocos2d::Rect(96 * i, 0, 96, 96)));
	}
	cocos2d::Animation* animation = cocos2d::Animation::createWithSpriteFrames(animFrames,0.05f);
	cocos2d::Animate *animate = cocos2d::Animate::create(animation);
	this->setRotation3D(cocos2d::Vec3(0, 180.0f, 0));
	this->runAction(cocos2d::RepeatForever::create(animate));
	
	
}
void UICell00::hitAnimate() {

	auto tintTo = cocos2d::TintTo::create(0.1, cocos2d::Color3B::RED);
	auto tintTo_ = cocos2d::TintTo::create(0.1, cocos2d::Color3B::WHITE);
	auto sequenceSprites = cocos2d::Sequence::create(tintTo, tintTo_, nullptr);
	this->runAction(sequenceSprites);
}

void UICell00::dieAnimate() {
	this->stopAllActions();
	auto fadeOut = cocos2d::FadeOut::create(1.0f);
	auto remove = cocos2d::RemoveSelf::create();
	auto sequence = cocos2d::Sequence::create(fadeOut, remove, nullptr);
	this->runAction(sequence);
}
