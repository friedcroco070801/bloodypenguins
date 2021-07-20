#include "UIObjects/uiobj.h"
#include "UIDisease.h"
#include "UIDiseaseType/UIDiseaseType.h"
#include "Scenes/GameScene/GSDefine.h"

USING_NS_CC;

/*
Add UIDisease to scene
*/
void UIDisease::addToScene(Scene* scene) {
    scene->addChild(this, DISEASE_LAYER_ZORDER);
}

/*
Create a new instance of UIDisease with DiseaseId
*/
UIDisease* UIDisease::create(DiseaseId id) {
    switch (id) {
    // Case id 00: Rabies
    case DISEASE_00_RABIES:
        return UIDisease00::create();
		break;
	case DISEASE_01_SMALLPOX:
		return UIDisease01::create();
		break;
	case DISEASE_02_INFLUENZA:
		return UIDisease02::create();
		break;
	case DISEASE_03_MEASLES:
		return UIDisease03::create();
		break;
	case DISEASE_04_POLIO:
		return UIDisease04::create();
		break;
	case DISEASE_05_MALARIA:
		return UIDisease05::create();
		break;
	case DISEASE_06_EBOLA:
		return UIDisease06::create();
		break;
    }

    return nullptr;
}

void UIDisease::attackAnimate(Direction dir) {
	switch (dir) {
	case DOWN:
	{
		auto movetoattack = MoveTo::create(0.2, Vec2(this->getPositionX(), this->getPositionY() - SIZE_OF_SQUARE));
		auto movebackattack = MoveTo::create(0.2, Vec2(this->getPositionX(), this->getPositionY()));
		auto attackseq = Sequence::create(movetoattack, movebackattack, nullptr);
		this->runAction(attackseq);
	}

	break;

	case LEFT:
	{
		auto movetoattack = MoveTo::create(0.2, Vec2(this->getPositionX() - SIZE_OF_SQUARE, this->getPositionY()));
		auto movebackattack = MoveTo::create(0.2, Vec2(this->getPositionX(), this->getPositionY()));
		auto attackseq = Sequence::create(movetoattack, movebackattack, nullptr);
		this->runAction(attackseq);
	}
	break;

	case RIGHT:
	{
		auto movetoattack = MoveTo::create(0.2, Vec2(this->getPositionX() + SIZE_OF_SQUARE / 2, this->getPositionY()));
		auto movebackattack = MoveTo::create(0.2, Vec2(this->getPositionX(), this->getPositionY()));
		auto attackseq = Sequence::create(movetoattack, movebackattack, nullptr);
		this->runAction(attackseq);
	}
	break;

	case UP:
	{
		auto movetoattack = MoveTo::create(0.2, Vec2(this->getPositionX(), this->getPositionY() + SIZE_OF_SQUARE / 2));
		auto movebackattack = MoveTo::create(0.2, Vec2(this->getPositionX(), this->getPositionY()));
		auto attackseq = Sequence::create(movetoattack, movebackattack, nullptr);
		this->runAction(attackseq);
	}
	break;
	default:
		break;
	}
}

void UIDisease::hitAnimate(Direction dir) {
	auto tintTo = cocos2d::TintTo::create(0.1, cocos2d::Color3B::RED);
	auto tintTo_ = cocos2d::TintTo::create(0.1, cocos2d::Color3B::WHITE);
	auto hitanim = cocos2d::Sequence::create(tintTo, tintTo_, nullptr);
	this->runAction(hitanim);

}

void UIDisease::dieAnimate(Direction dir) {
	this->stopAllActions();
	auto fadeout = FadeOut::create(1);
	auto remove = RemoveSelf::create();
	auto seq = Sequence::create(fadeout, remove, nullptr);
	this->runAction(seq);
}