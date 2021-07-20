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

	auto tintTo = cocos2d::TintTo::create(0.1, cocos2d::Color3B::BLUE);
	auto tintTo_ = cocos2d::TintTo::create(0.1, cocos2d::Color3B::WHITE);
	auto sequenceSprites = cocos2d::Sequence::create(tintTo, tintTo_, tintTo->clone(), tintTo_->clone(), nullptr);
	auto scale_ = cocos2d::ScaleBy::create(0.5, 0.5);
	auto mySpawn = cocos2d::Spawn::createWithTwoActions(scale_, sequenceSprites);
	this->runAction(mySpawn);
}
void UICell04::effectAnimate() {
	for (int j = 0; j < 50; j++) {
	    auto after = Sprite::create(CELL_04_EFFECT_FILENAME, cocos2d::Rect(0.0f, 0.0f, 32.0f, 32.0f));
	    this->getParent()->addChild(after, PROJECTILE_LAYER_ZORDER);
	    after->setPosition(this->getPosition());

		auto rotate = cocos2d::RepeatForever::create(cocos2d::RotateBy::create(1.0f, 360 * CCRANDOM_MINUS1_1()));
		rotate->setTag(3);
		after->runAction(rotate);

	    auto time = CCRANDOM_0_1() * 0.7f + 0.3f;
	    auto distance = 50.0f + CCRANDOM_0_1() * 80.0f;
	    auto jumpX = distance * CCRANDOM_MINUS1_1();
	    auto jumpY = (CCRANDOM_0_1() <= 0.5f ? -1 : 1) * sqrt(distance * distance - jumpX * jumpX);
	    auto jumpH = 40.0f + 20.0f * CCRANDOM_0_1();

	    auto jump = cocos2d::JumpBy::create(time + 0.25f, cocos2d::Vec2(jumpX, jumpY), jumpH, 1);
	    auto call = cocos2d::CallFuncN::create([](Node* node){
	        node->stopActionByTag(3);
	    });

		cocos2d::Vector<cocos2d::SpriteFrame*> frames;
		for (unsigned int i = 1; i < 6; i++) {
			auto frame = cocos2d::SpriteFrame::create(CELL_04_EFFECT_FILENAME, cocos2d::Rect(i * 32, 0, 32, 32));
			frames.pushBack(frame);
		}
	    auto animate = cocos2d::Animate::create(cocos2d::Animation::createWithSpriteFrames(frames, 0.05f));

		auto remove = cocos2d::RemoveSelf::create();
		auto delay = cocos2d::DelayTime::create(time);

	    auto seq = cocos2d::Sequence::create(delay, call, animate, remove, nullptr);
	    after->runAction(seq);
		after->runAction(jump);

	    after->setScale(0.1f + 0.9f * CCRANDOM_0_1());
	}
}


