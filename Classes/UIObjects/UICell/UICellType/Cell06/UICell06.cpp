#include "UIObjects/uiobj.h"
#include "UICell06.h"

/*
Create a new instance of UICell00
*/
UICell06* UICell06::create() {
	UICell06 *uicell = new (std::nothrow) UICell06();
	if (uicell && uicell->initWithFile(CELL_06_FILENAME, cocos2d::Rect(4 * 46.0f, 0.0f, 46.0f, 46.0f)))
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

	// const int numberSprite = 65;
	// cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;
	// int size = cocos2d::Sprite::create(CELL_06_FILENAME)->getContentSize().height;
	// animFrames.reserve(numberSprite);
	// for (int i = 0; i < numberSprite; i++) {
	// 	animFrames.pushBack(cocos2d::SpriteFrame::create(CELL_06_FILENAME, cocos2d::Rect(size * i, 0, size, size)));
	// }
	// cocos2d::Animation* animation = cocos2d::Animation::createWithSpriteFrames(animFrames, 0.05f);
	// cocos2d::Animate *animate = cocos2d::Animate::create(animation);

	//animate->setTag();

	this->setRotation3D(cocos2d::Vec3(0, 180.0f, 0));
	// auto idle = cocos2d::RepeatForever::create(animate);

	// idle->setTag(ANIM_BASE_TAG);

	// this->runAction(idle);

	// Scale and explosion
	auto delay1 = cocos2d::DelayTime::create(0.3f);
	auto delay2 = cocos2d::DelayTime::create(0.3f);
	auto scaleBy2 = cocos2d::ScaleTo::create(0.0f, this->getScale() * 1.5f);
	auto scaleBy3 = cocos2d::ScaleTo::create(0.0f, this->getScale() * 2.25f);
	auto changeRed = cocos2d::TintTo::create(0.0f, cocos2d::Color3B::RED);
	auto scaleSeq = cocos2d::Sequence::create(delay1, scaleBy2, delay2, scaleBy3, changeRed, nullptr);
	this->runAction(scaleSeq);

	auto fluctuateRange = 10.0f;
	auto fluct1 = cocos2d::MoveBy::create(0.025f, cocos2d::Vec2(0.0f - fluctuateRange, 0.0f));
	auto fluct2 = cocos2d::MoveBy::create(0.05f, cocos2d::Vec2(2 * fluctuateRange, 0.0f));
	auto fluct3 = cocos2d::MoveBy::create(0.025f, cocos2d::Vec2(0.0f - fluctuateRange, 0.0f));
	auto fluct4 = cocos2d::MoveBy::create(0.025f, cocos2d::Vec2(0.0f - fluctuateRange / 2, 0.0f));
	auto fluct5 = cocos2d::MoveBy::create(0.05f, cocos2d::Vec2(fluctuateRange, 0.0f));
	auto fluct6 = cocos2d::MoveBy::create(0.025f, cocos2d::Vec2(0.0f - fluctuateRange / 2, 0.0f));
	auto fluct7 = cocos2d::MoveBy::create(0.025f, cocos2d::Vec2(0.0f - fluctuateRange / 4, 0.0f));
	auto fluct8 = cocos2d::MoveBy::create(0.025f, cocos2d::Vec2(fluctuateRange / 4, 0.0f));
	auto fluct9 = cocos2d::DelayTime::create(0.05f);
	auto fluctMonoSeq = cocos2d::Sequence::create(fluct1, fluct2, fluct3, fluct4, fluct5, fluct6, fluct7, fluct8, fluct9, nullptr);
	auto fluctSeq = cocos2d::Repeat::create(fluctMonoSeq, 3);
	this->runAction(fluctSeq);
}

void UICell06::effectAnimate() {
	for (int j = 0; j < 50; j++) {
	    auto after = Sprite::create(CELL_06_EFFECT_FILENAME, cocos2d::Rect(0.0f, 0.0f, 64.0f, 64.0f));
	    this->getParent()->addChild(after, PROJECTILE_LAYER_ZORDER);
	    
	    auto distance = CCRANDOM_0_1() * 140.0f;
	    auto jumpX = distance * CCRANDOM_MINUS1_1();
	    auto jumpY = (CCRANDOM_0_1() <= 0.5f ? -1 : 1) * sqrt(distance * distance - jumpX * jumpX);

		after->setPosition(this->getPosition() + cocos2d::Vec2(jumpX, jumpY));
		after->setOpacity(0);

		cocos2d::Vector<cocos2d::SpriteFrame*> frames;
		for (unsigned int i = 0; i < 8; i++) {
			auto frame = cocos2d::SpriteFrame::create(CELL_06_EFFECT_FILENAME, cocos2d::Rect(i * 64.0f, 0.0f, 64.0f, 64.0f));
			frames.pushBack(frame);
		}
	    auto animate = cocos2d::Animate::create(cocos2d::Animation::createWithSpriteFrames(frames, 0.075f));

		auto remove = cocos2d::RemoveSelf::create();
		auto time = CCRANDOM_0_1() * 0.3f;
		auto delay = cocos2d::DelayTime::create(time);

		auto appear = cocos2d::FadeTo::create(0.0f, 255);

	    auto seq = cocos2d::Sequence::create(delay, appear, animate, remove, nullptr);
	    after->runAction(seq);

	    after->setScale(0.1f + 1.3f * CCRANDOM_0_1() * (180.0f - distance) / 140.0f);
	}
}

