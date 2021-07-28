#include "UIRemove.h"
#include "Models/models.h"
#include <functional>
#include "Scenes/GameScene/GSControlLayer.h"
using namespace std;

UIRemove* UIRemove::create(LevelModel* level) {
	UIRemove *btn = new (std::nothrow) UIRemove;
	if (btn && btn->init(REMOVE_BUTTON_FILENAME, REMOVE_BUTTON_CLICKED_FILENAME, REMOVE_BUTTON_CLICKED_FILENAME))
	{
		btn->level = level;
		btn->autorelease();
        btn->onTouch();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return nullptr;
}

void UIRemove::onTouch() {
    function<function<void(Ref*, ui::Widget::TouchEventType)>()> removeTouch = [this]() -> function<void(Ref*, ui::Widget::TouchEventType)> {
        return [&](Ref *sender, ui::Widget::TouchEventType type){
            switch (type)
            {
            case ui::Widget::TouchEventType::BEGAN:
                CCLOG("Touch remove");
                break;
            case ui::Widget::TouchEventType::ENDED:
            {
                CCLOG("Remove!");
                
                auto controlLayer = GSControlLayer::create(level, nullptr);
                this->getParent()->addChild(controlLayer);
                controlLayer->setGlobalZOrder(11.5f);
                controlLayer->setPreviewImage(REMOVE_CELL, 0.0f);
                break;
            }
            default:
                break;
            }
        };
    };

	this->addTouchEventListener(removeTouch());
}