#include "UIObjects/uiobj.h"
#include "UIDisease03.h"
#include "Scenes/GameScene/GSDefine.h"
#include "UIDisease03Definitions.h"

/*
Create new instance of UIDisease03
*/
UIDisease03* UIDisease03::create() {
	UIDisease03 *uidisease = new (std::nothrow) UIDisease03();
    if (uidisease && uidisease->initWithFile(DISEASE_03_FILENAME))
    {
        uidisease->autorelease();
		uidisease->setScale(2);
        return uidisease;
    }
    CC_SAFE_DELETE(uidisease);
    return nullptr;
}


void UIDisease03::walkAnimate(Direction dir) {
	this->stopAllActionsByTag(ANIM_BASE);
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(DISEASE_03_SHEETWALK, DISEASE_03_IMGWALK);
	
	const int numberSprite = 16;
	const int maxWord = 50;

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(numberSprite);

	char spriteFrameByName[maxWord] = { 0 };
	switch (dir) {
	case DOWN:
		for (int index = 1; index <= 4; index++){
			sprintf(spriteFrameByName, "disease03walk%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	case LEFT:
		for (int index = 5; index <= 8; index++){
			sprintf(spriteFrameByName, "disease03walk%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	case RIGHT:
		for (int index = 9; index <= 12; index++){
			sprintf(spriteFrameByName, "disease03walk%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	case UP:
		for (int index = 13; index <= 16; index++){
			sprintf(spriteFrameByName, "disease03walk%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	default:
		break;
	}
	animation = Animation::createWithSpriteFrames(animFrames, 0.3f);
	animate = Animate::create(animation);
	auto repeat = RepeatForever::create(animate);
	repeat->setTag(ANIM_BASE);
	this->runAction(repeat);
}

void UIDisease03::idleAnimate(Direction dir) {
	this->stopAllActionsByTag(ANIM_BASE);
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(DISEASE_03_SHEETIDLE, DISEASE_03_IMGIDLE);

	const int numberSprites = 16;
	const int maxWords = 50;

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(numberSprites);

	char spriteFrameByName[maxWords] = { 0 };
	switch (dir) {
	case DOWN:
		for (int index = 1; index <= 4; index++) {
			sprintf(spriteFrameByName, "disease03idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	case LEFT:
		for (int index = 5; index <= 8; index++) {
			sprintf(spriteFrameByName, "disease03idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	case RIGHT:
		for (int index = 9; index <= 12; index++) {
			sprintf(spriteFrameByName, "disease03idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	case UP:
		for (int index = 13; index <= 16; index++) {
			sprintf(spriteFrameByName, "disease03idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	default:
		break;
	}
	animation = Animation::createWithSpriteFrames(animFrames, 0.2f);
	animate = Animate::create(animation);
	auto repeat = RepeatForever::create(animate);
	repeat->setTag(ANIM_BASE);
	this->runAction(repeat);
}

void UIDisease03::attackAnimate(Direction dir) {
	switch (dir) {
	case DOWN:
	{
		auto movetoattack = MoveTo::create(0.2, Vec2(this->getPositionX(), this->getPositionY() - SIZE_OF_SQUARE / 2));
		auto movebackattack = MoveTo::create(0.2, Vec2(this->getPositionX(), this->getPositionY()));
		auto attackseq = Sequence::create(movetoattack, movebackattack, nullptr);
		this->runAction(RepeatForever::create(attackseq));
	}
	break;

	case LEFT:
	{
		auto movetoattack = MoveTo::create(0.2, Vec2(this->getPositionX() - SIZE_OF_SQUARE / 2, this->getPositionY()));
		auto movebackattack = MoveTo::create(0.2, Vec2(this->getPositionX(), this->getPositionY()));
		auto attackseq = Sequence::create(movetoattack, movebackattack, nullptr);
		this->runAction(RepeatForever::create(attackseq));
	}
	break;

	case RIGHT:
	{
		auto movetoattack = MoveTo::create(0.2, Vec2(this->getPositionX() + SIZE_OF_SQUARE / 2, this->getPositionY()));
		auto movebackattack = MoveTo::create(0.2, Vec2(this->getPositionX(), this->getPositionY()));
		auto attackseq = Sequence::create(movetoattack, movebackattack, nullptr);
		this->runAction(RepeatForever::create(attackseq));
	}
	break;

	case UP:
	{
		auto movetoattack = MoveTo::create(0.2, Vec2(this->getPositionX(), this->getPositionY() + SIZE_OF_SQUARE / 2));
		auto movebackattack = MoveTo::create(0.2, Vec2(this->getPositionX(), this->getPositionY()));
		auto attackseq = Sequence::create(movetoattack, movebackattack, nullptr);
		this->runAction(RepeatForever::create(attackseq));
	}
	break;
	default:
		break;
	}
}

void UIDisease03::hitAnimate(Direction dir) {

	auto tintTo = cocos2d::TintTo::create(0.1, cocos2d::Color3B::RED);
	auto tintTo_ = cocos2d::TintTo::create(0.1, cocos2d::Color3B::WHITE);
	auto hitanim = cocos2d::Sequence::create(tintTo, tintTo_, nullptr);
	this->runAction(hitanim);

}

void UIDisease03::dieAnimate(Direction dir) {
	this->stopAllActions();
	auto fadeout = FadeOut::create(1);
	auto remove = RemoveSelf::create();
	auto seq = Sequence::create(fadeout, remove, nullptr);
	this->runAction(seq);
}

