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
}

void UIControlCellBar::touchControlEvent(Ref *sender, ui::Widget::TouchEventType type) {
	switch (type)
	{
	case ui::Widget::TouchEventType::BEGAN:
		CCLOG("Touch");
		break;
	case ui::Widget::TouchEventType::ENDED:
		CCLOG("Cell Hold");
		auto controlLayer = GSControlLayer::create(level);
		scene->addChild(controlLayer, CELLBAR_LAYER_ZORDER);
		controlLayer->setPreviewImage(id);
		break;
	// default:
	// 	break;
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