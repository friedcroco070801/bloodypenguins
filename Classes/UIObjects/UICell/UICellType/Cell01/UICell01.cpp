#include "UIObjects/uiobj.h"
#include "UICell01.h"

/*
Create a new instance of UICell00
*/
UICell01* UICell01::create() {
    UICell01 *uicell = new (std::nothrow) UICell01();
    if (uicell && uicell->initWithFile(CELL_01_FILENAME))
    {
        uicell->autorelease();
        return uicell;
    }
    CC_SAFE_DELETE(uicell);
    return nullptr;
}
void UICell01::addToScene(cocos2d::Scene* scene) {
	scene->addChild(this, CELL_LAYER_ZORDER);
	this->idleAnimate();
}
void UICell01::idleAnimate() {
	this->stopAllActionsByTag(ANIM_BASE_TAG);
	const int numberSprite = 113;
	cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;
	int size = cocos2d::Sprite::create(CELL_01_FILENAME)->getContentSize().height;
	animFrames.reserve(numberSprite);
	for (int i = 0; i < numberSprite; i++) {
		animFrames.pushBack(cocos2d::SpriteFrame::create(CELL_01_FILENAME, cocos2d::Rect(size * i, 0, size, size)));
	}
	cocos2d::Animation* animation = cocos2d::Animation::createWithSpriteFrames(animFrames, 0.05f);
	cocos2d::Animate *animate = cocos2d::Animate::create(animation);
	this->setRotation3D(cocos2d::Vec3(0, 180.0f, 0));
	auto idle = cocos2d::RepeatForever::create(animate);
	idle->setTag(ANIM_BASE_TAG);

	this->runAction(idle);
}
void UICell01::effectAnimate() {
	auto rotate = cocos2d::RotateBy::create(1.0f, 360.0f);
	auto move = cocos2d::MoveBy::create(0.5f, cocos2d::Vec2(0, 50));
	auto move_ = cocos2d::MoveBy::create(0.5f, cocos2d::Vec2(0, -50));
	auto sequenceSprites = cocos2d::Sequence::create(move, move_, nullptr);
	this->runAction(rotate);
	this->runAction(sequenceSprites);
}
void UICell01::hitAnimate() {
	auto tintTo = cocos2d::TintTo::create(0.1, cocos2d::Color3B::RED);
	auto tintTo_ = cocos2d::TintTo::create(0.1, cocos2d::Color3B::WHITE);
	auto sequenceSprites = cocos2d::Sequence::create(tintTo, tintTo_, nullptr);
	this->runAction(sequenceSprites);
}
void UICell01::dieAnimate() {
	this->stopAllActionsByTag(ANIM_BASE_TAG);
	auto fadeOut = cocos2d::FadeOut::create(1.0f);
	auto remove = cocos2d::RemoveSelf::create();
	auto sequence = cocos2d::Sequence::create(fadeOut, remove, nullptr);
	this->runAction(sequence);
}