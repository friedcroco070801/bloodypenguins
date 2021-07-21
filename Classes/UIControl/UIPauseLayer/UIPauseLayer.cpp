#include "UIPauseLayer.h"
#include "Models/models.h"
#include "ui/CocosGUI.h"
#include <functional>

USING_NS_CC;
using namespace std;

UIPauseLayer* UIPauseLayer::create(LevelModel* level) {
    UIPauseLayer *ret = new (std::nothrow) UIPauseLayer;
    if (ret)
    {
        ret->init(level);
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

void UIPauseLayer::init(LevelModel* level) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    this->level = level;

    // Add foreground
    auto fore = Sprite::create(PAUSE_LAYER_FORE_FILENAME);
    this->addChild(fore);
    fore->setOpacity(128);
    fore->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);

    // Add layer box
    auto box = Sprite::create(PAUSE_LAYER_FILENAME);
    this->addChild(box);
    box->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);

    // Add resume button
    auto resume = ui::Button::create(PAUSE_LAYER_RESUME_FILENAME, PAUSE_LAYER_RESUME_CLICKED_FILENAME, PAUSE_LAYER_RESUME_CLICKED_FILENAME);
    resume->addTouchEventListener(CC_CALLBACK_2(UIPauseLayer::resumeGame, this));
    this->addChild(resume);
    resume->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 45.0f * 2 + 15.0f * 2));
}

void UIPauseLayer::resumeGame(Ref *sender, ui::Widget::TouchEventType type) {
    switch (type) {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:  
            level->resume();
            this->removeFromParent();   
            break;
        default:
            break;
    }
}