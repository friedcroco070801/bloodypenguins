#include "UIControlEnergy.h"
#include "Scenes/GameScene/GSDefine.h"
#include "UIObjects/uiobj.h"
#include "Models/models.h"

USING_NS_CC;

void UIControlEnergy::setCellPosition(double cellX, double cellY) {
	setPosition(Vec2((float)cellX * CELL_WIDTH + POS_X_ORIGIN, (float)cellY * CELL_WIDTH + POS_Y_ORIGIN));
}

/*
Add UIObjects to Scene
*/
void UIControlEnergy::addToScene(Scene* scene) {
	canCollect = true;
	scene->addChild(this, ENERGY_LAYER_ZORDER);
	idleAnimate();
	onTouch();
}

/*
Remove UIObjects from Scene
*/
void UIControlEnergy::removeFromScene() {
    removeFromParent();
}

void UIControlEnergy::touchControlEvent(Ref *sender, ui::Widget::TouchEventType type) {
	if (canCollect) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			CCLOG("Touch");
			break;
		case ui::Widget::TouchEventType::ENDED:
			CCLOG("Energy update");
			level->addEnergyValue(50);
			canCollect = false;
			destroyAnimate();
			break;
		default:
			break;
		}
	}
};

UIControlEnergy* UIControlEnergy::create(LevelModel* level) {
	UIControlEnergy *btn = new (std::nothrow) UIControlEnergy;
	if (btn && btn->init(IMG_ENERGY, IMG_ENERGY, IMG_ENERGY, TextureResType::LOCAL))
	{
		btn->level = level;
		btn->autorelease();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return nullptr;
}

void UIControlEnergy::onTouch() {
	this->addTouchEventListener(CC_CALLBACK_2(UIControlEnergy::touchControlEvent, this));
}

/*
Pop up animation
*/
void UIControlEnergy::appearAnimate() {
	auto jump = JumpBy::create(ANIM_ENERGY_POPUP_DURATION, Vec2(CCRANDOM_MINUS1_1() * CELL_WIDTH, 0 - CELL_WIDTH / 4), CELL_WIDTH, 1);
	this->runAction(jump);
}

/*
Idle animation
*/
void UIControlEnergy::idleAnimate() {
	auto sheet = Sprite::create("sprites/objects/pickup/animEnergy.png");
	auto width = sheet->getContentSize().width;
	auto height = sheet->getContentSize().height;
	Vector<SpriteFrame*> animFrames;
	for (int i = 0; i < 6; i++) {
		animFrames.pushBack(SpriteFrame::create("sprites/objects/pickup/animEnergy.png", Rect(i * width / 6, 0, width / 6, height)));
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, 1.0f / 8.0f);
	auto animate = Animate::create(animation);

	child = Sprite::create("sprites/objects/pickup/animEnergy.png", Rect(0, 0, width / 6, height));
	child->setAnchorPoint(Vec2(0.0f, 0.0f));
	child->runAction(RepeatForever::create(animate));
	this->addChild(child);
}

/*
Destroy animation
*/
void UIControlEnergy::destroyAnimate() {
	auto fade = FadeTo::create(ANIM_ENERGY_DESTROY_DURATION, 0);
	auto call = CallFuncN::create([] (Node* node) {
		node->getParent()->removeFromParent();
	});
	auto seq = Sequence::create(fade, call, nullptr);
	child->runAction(seq);
}
