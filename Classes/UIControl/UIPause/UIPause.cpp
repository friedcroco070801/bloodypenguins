#include "UIPause.h"
#include "Models/models.h"
#include "UIControl/UIPauseLayer/UIPauseLayer.h"
#include <functional>
using namespace std;

UIPause* UIPause::create(LevelModel* level) {
	UIPause *btn = new (std::nothrow) UIPause;
	if (btn && btn->init(PAUSE_BUTTON_FILENAME, PAUSE_BUTTON_CLICKED_FILENAME, PAUSE_BUTTON_CLICKED_FILENAME))
	{
		btn->level = level;
		btn->autorelease();
        btn->onTouch();
		return btn;
	}
	CC_SAFE_DELETE(btn);
	return nullptr;
}

void UIPause::onTouch() {
    function<function<void(Ref*, ui::Widget::TouchEventType)>()> pauseTouch = [this]() -> function<void(Ref*, ui::Widget::TouchEventType)> {
        return [&](Ref *sender, ui::Widget::TouchEventType type){
            switch (type)
            {
            case ui::Widget::TouchEventType::BEGAN:
                CCLOG("Touch pause");
                break;
            case ui::Widget::TouchEventType::ENDED:
                CCLOG("Pause!");
                level->pause();
                getParent()->addChild(UIPauseLayer::create(level), 12);
                break;
            default:
                break;
            }
        };
    };

	this->addTouchEventListener(pauseTouch());
}