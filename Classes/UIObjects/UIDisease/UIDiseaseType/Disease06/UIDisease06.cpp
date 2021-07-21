#include "UIObjects/uiobj.h"
#include "UIDisease06.h"
#include "Scenes/GameScene/GSDefine.h"
#include "UIDisease06Definitions.h"

/*
Create new instance of UIDisease06
*/
UIDisease06* UIDisease06::create() {
	UIDisease06 *uidisease = new (std::nothrow) UIDisease06();
    if (uidisease && uidisease->initWithFile(DISEASE_06_FILENAME))
    {
        uidisease->autorelease();
		uidisease->setScale(2);
        return uidisease;
    }
    CC_SAFE_DELETE(uidisease);
    return nullptr;
}


void UIDisease06::walkAnimate(Direction dir) {
	this->stopAllActionsByTag(ANIM_BASE);
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(DISEASE_06_SHEETWALK, DISEASE_06_IMGWALK);
	
	const int numberSprite = 16;
	const int maxWord = 50;

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(numberSprite);

	char spriteFrameByName[maxWord] = { 0 };
	switch (dir) {
	case DOWN:
		for (int index = 1; index <= 4; index++){
			sprintf(spriteFrameByName, "disease06walk%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			frame->setAnchorPoint(Point(0.5, 0.25));
			animFrames.pushBack(frame);
		}
		break;
	case LEFT:
		for (int index = 5; index <= 8; index++){
			sprintf(spriteFrameByName, "disease06walk%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			frame->setAnchorPoint(Point(0.5, 0.25));
			animFrames.pushBack(frame);
		}
		break;
	case RIGHT:
		for (int index = 9; index <= 12; index++){
			sprintf(spriteFrameByName, "disease06walk%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			frame->setAnchorPoint(Point(0.5, 0.25));
			animFrames.pushBack(frame);
		}
		break;
	case UP:
		for (int index = 13; index <= 16; index++){
			sprintf(spriteFrameByName, "disease06walk%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			frame->setAnchorPoint(Point(0.5, 0.25));
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

void UIDisease06::idleAnimate(Direction dir) {
	this->stopAllActionsByTag(ANIM_BASE);
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(DISEASE_06_SHEETIDLE, DISEASE_06_IMGIDLE);

	const int numberSprites = 8;
	const int maxWords = 50;

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(numberSprites);

	char spriteFrameByName[maxWords] = { 0 };
	switch (dir) {
	case DOWN:
		for (int index = 1; index <= 2; index++) {
			sprintf(spriteFrameByName, "disease06idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			frame->setAnchorPoint(Point(0.5, 0.25));
			animFrames.pushBack(frame);
		}
		break;
	case LEFT:
		for (int index = 3; index <= 4; index++) {
			sprintf(spriteFrameByName, "disease06idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			frame->setAnchorPoint(Point(0.5, 0.25));
			animFrames.pushBack(frame);
		}
		break;
	case RIGHT:
		for (int index = 5; index <= 6; index++) {
			sprintf(spriteFrameByName, "disease06idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			frame->setAnchorPoint(Point(0.5, 0.25));
			animFrames.pushBack(frame);
		}
		break;
	case UP:
		for (int index = 7; index <= 8; index++) {
			sprintf(spriteFrameByName, "disease06idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			frame->setAnchorPoint(Point(0.5, 0.25));
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

void UIDisease06::attackAnimate(Direction dir) {

	if (dir == DOWN || dir == LEFT || dir == RIGHT || dir == UP) {
		auto jumpto = JumpTo::create(0.5, Vec2(this->getPositionX(), this->getPositionY() + SIZE_OF_SQUARE), 100, 1);
		auto jumpback = JumpTo::create(0.5, Vec2(this->getPositionX(), this->getPositionY()), 100, 1);
		//auto rotate = RotateBy::create(1.0f, Vec3(360.0f,0,0));
		auto scalef = ScaleBy::create(0.2, 2);
		auto scaleb = ScaleBy::create(0.2, 0.5);
		auto attackseq = Sequence::create(jumpto, scalef, jumpback, DelayTime::create(1), scaleb, nullptr);

		auto camera = Director::getInstance()->getRunningScene()->getDefaultCamera();
		//auto movetocamera = MoveBy::create(0.5, Vec2(0, 10));
		//auto movebackcamera = MoveBy::create(0.5, Vec2(0, -10));
		//auto seqcamera = Sequence::create(movetocamera, movebackcamera, nullptr);
		auto scalecamf = ScaleBy::create(0.5, 2);
		auto scalecamb = ScaleBy::create(0.5, 0.5);
		//auto tintTo = TintTo::create(0.5, cocos2d::Color3B::RED);
		//auto tintTo_ = TintTo::create(0.5, cocos2d::Color3B::WHITE);
		//auto spawn = Spawn::createWithTwoActions(scalecamf, tintTo);
		//auto spawn1 = Spawn::createWithTwoActions(scalecamb, tintTo_);
		auto seqcamera = Sequence::create(scalecamf, scalecamb, nullptr);
		//camera->runAction(seqcamera);
		//camera->setPosition3D(Vec3(0, 100, 300));
		this->getParent()->runAction(seqcamera);
		this->runAction(attackseq);
	}
}

void UIDisease06::hitAnimate(Direction dir) {
	UIDisease::hitAnimate(dir);

}

void UIDisease06::dieAnimate(Direction dir) {
	UIDisease::dieAnimate(dir);
}

