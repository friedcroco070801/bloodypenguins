#include "UIObjects/uiobj.h"
#include "UIDisease00.h"
#include "Scenes/GameScene/GSDefine.h"
#include "UIDisease00Definitions.h"

/*
Create new instance of UIDisease00
*/
UIDisease00* UIDisease00::create() {
    UIDisease00 *uidisease = new (std::nothrow) UIDisease00();
    if (uidisease && uidisease->initWithFile(DISEASE_00_FILENAME))
    {
        uidisease->autorelease();
		uidisease->setScale(2);
        return uidisease;
    }
    CC_SAFE_DELETE(uidisease);
    return nullptr;
}


void UIDisease00::walkAnimate(Direction dir) {
	this->stopAllActions();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(DISEASE_00_SHEETWALK, DISEASE_00_IMGWALK);
	
	const int numberSprite = 16;
	const int maxWord = 50;

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(numberSprite);

	//*******************************************************
	// chuỗi trung gian để đọc tên ảnh trong file format
	char spriteFrameByName[maxWord] = { 0 };
	switch (dir) {
	case DOWN:
		for (int index = 1; index <= 4; index++){
			// Lấy sprite frame name
			sprintf(spriteFrameByName, "disease00walk%d.png", index);

			// Tạo 1 khung, lấy ra từ bộ đệm SpriteFrameCache có tên là spriteFrameByName;
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			// Push frame.
			animFrames.pushBack(frame);
		}
		break;
	case LEFT:
		for (int index = 5; index <= 8; index++){
			// Lấy sprite frame name
			sprintf(spriteFrameByName, "disease00walk%d.png", index);

			// Tạo 1 khung, lấy ra từ bộ đệm SpriteFrameCache có tên là spriteFrameByName;
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			// Push frame.
			animFrames.pushBack(frame);
		}
		break;
	case RIGHT:
		for (int index = 9; index <= 12; index++){
			// Lấy sprite frame name
			sprintf(spriteFrameByName, "disease00walk%d.png", index);

			// Tạo 1 khung, lấy ra từ bộ đệm SpriteFrameCache có tên là spriteFrameByName;
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			// Push frame.
			animFrames.pushBack(frame);
		}
		break;
	case UP:
		//disease00 = Sprite::createWithSpriteFrameName("disease00walk13.png");
		for (int index = 13; index <= 16; index++){
			// Lấy sprite frame name
			sprintf(spriteFrameByName, "disease00walk%d.png", index);

			// Tạo 1 khung, lấy ra từ bộ đệm SpriteFrameCache có tên là spriteFrameByName;
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			// Push frame.
			animFrames.pushBack(frame);
		}
		break;
	default:
		break;
	}
	// Khởi tạo một khung hình animation từ Vector SpriteFrame.  
	animation = Animation::createWithSpriteFrames(animFrames, 0.5f);
	animate = Animate::create(animation);

	// Chạy Acction animation với số lần lặp vô hạn.
	this->runAction(RepeatForever::create(animate));
}

void UIDisease00::idleAnimate(Direction dir) {
	this->stopAllActions();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(DISEASE_00_SHEETIDLE, DISEASE_00_IMGIDLE);

	const int numberSprites = 16;
	const int maxWords = 50;

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(numberSprites);

	// chuỗi trung gian để đọc tên ảnh trong file format
	char spriteFrameByName[maxWords] = { 0 };
	switch (dir) {
	case DOWN:
		for (int index = 1; index <= 4; index++) {
			sprintf(spriteFrameByName, "disease00idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	case LEFT:
		for (int index = 5; index <= 8; index++) {
			sprintf(spriteFrameByName, "disease00idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			// Push frame.
			animFrames.pushBack(frame);
		}
		break;
	case RIGHT:
		for (int index = 9; index <= 12; index++) {

			sprintf(spriteFrameByName, "disease00idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	case UP:
		for (int index = 13; index <= 16; index++) {
			sprintf(spriteFrameByName, "disease00idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	default:
		break;
	}
	animation = Animation::createWithSpriteFrames(animFrames, 0.2f);
	animate = Animate::create(animation);

	this->runAction(RepeatForever::create(animate));
}

void UIDisease00::attackAnimate(Direction dir) {
	this->stopAllActions();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(DISEASE_00_SHEETATTACK, DISEASE_00_IMGATTACK);

	const int numberSprites = 16;
	const int maxWords = 50;

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(numberSprites);

	// chuỗi trung gian để đọc tên ảnh trong file format
	char spriteFrameByName[maxWords] = { 0 };
	switch (dir) {
	case DOWN:
		for (int index = 1; index <= 4; index++) {
			sprintf(spriteFrameByName, "disease00idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	case LEFT:
		for (int index = 5; index <= 8; index++) {
			sprintf(spriteFrameByName, "disease00idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			// Push frame.
			animFrames.pushBack(frame);
		}
		break;
	case RIGHT:
		for (int index = 9; index <= 12; index++) {

			sprintf(spriteFrameByName, "disease00idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	case UP:
		for (int index = 13; index <= 16; index++) {
			sprintf(spriteFrameByName, "disease00idle%d.png", index);
			auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameByName);
			animFrames.pushBack(frame);
		}
		break;
	default:
		break;
	}
	animation = Animation::createWithSpriteFrames(animFrames, 0.3f);
	animate = Animate::create(animation);

	this->runAction(RepeatForever::create(animate));
}

void UIDisease00::hitAnimate(Direction dir) {
	
	this->stopAllActions();
	auto hitanim = Blink::create(1, 3);
	this->runAction(hitanim);
	
}

void UIDisease00::dieAnimate(Direction dir) {
	this->stopAllActions();
	auto fadeout = FadeOut::create(1);
	auto remove = RemoveSelf::create();
	auto seq = Sequence::create(fadeout, remove, nullptr);
	this->runAction(seq);
}

