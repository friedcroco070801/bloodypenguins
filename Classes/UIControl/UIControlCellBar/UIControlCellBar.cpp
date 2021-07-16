#include "UIControlCellBar.h"
#include "Scenes/GameScene/GSDefine.h"
#include "Scenes/GameScene/GSControlLayer.h"
USING_NS_CC;

/*
Add to Scene
*/
void UIControlCellBar::addToScene(Scene* scene) {
	this->scene = scene;
	scene->addChild(this, CELLBAR_LAYER_ZORDER);
	onTouch();

	loading = Sprite::create(CELLBAR_LOADING_FILENAME);
	loading->setAnchorPoint(Vec2(0.0f, 0.0f));
	addChild(loading);
	loading->setOpacity(170);

	canActivate = false;
}

void UIControlCellBar::touchControlEvent(Ref *sender, ui::Widget::TouchEventType type) {
	if (canActivate) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			CCLOG("Touch");
			break;
		case ui::Widget::TouchEventType::ENDED:
		{
			CCLOG("Cell Hold");
			auto controlLayer = GSControlLayer::create(level);
			scene->addChild(controlLayer, CELLBAR_LAYER_ZORDER);
			controlLayer->setPreviewImage(id);
			break;
		}
		default:
			break;
		}
	}
};

UIControlCellBar* UIControlCellBar::create(LevelModel* level, CellId id) {
	UIControlCellBar *btn = new (std::nothrow) UIControlCellBar;

	std::string filename;

	switch(id) {
	case CELL_00_EOSINOPHILS:
		filename = CELLBAR_00_FILENAME;
		break;
	case CELL_01_ERYTHROCYTES:
		filename = CELLBAR_01_FILENAME;
		break;
	default:
		filename = CELLBAR_00_FILENAME;
		break;
	}

	if (btn && btn->init(filename, filename, filename, TextureResType::LOCAL))
	{
		btn->level = level;
		btn->id = id;
		btn->autorelease();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return nullptr;
}

void UIControlCellBar::onTouch() {
	this->addTouchEventListener(CC_CALLBACK_2(UIControlCellBar::touchControlEvent, this));
}

/*
Update recharge loading
*/
void UIControlCellBar::updateRecharge(double percentage) {
	if (abs(0.0 - percentage) < DOUBLE_PRECISION) {
		if (canActivate == false) {
			flashAnimate();
		}
		canActivate = true;
	} else {
		canActivate = false;
	}
	loading->setScaleY(percentage);
}

/*
Flas animate of cell bar
*/
void UIControlCellBar::flashAnimate() {
	auto flash = Sprite::create(CELLBAR_LOADING_COMPLETE_FILENAME);
	flash->setAnchorPoint(Vec2(0.0f, 0.0f));
	flash->setOpacity(0);
	addChild(flash);

	// Flashing
	auto fadeIn = FadeTo::create(ANIM_CELLBAR_FLASH, 255);
	auto fadeOut = FadeTo::create(ANIM_CELLBAR_FLASH, 0);
	auto remove = RemoveSelf::create();
	auto seq  = Sequence::create(fadeIn, fadeOut, remove, nullptr);
	flash->runAction(seq);
}