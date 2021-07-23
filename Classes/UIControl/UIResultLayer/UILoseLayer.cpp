#include "UILoseLayer.h"
USING_NS_CC;

UILoseLayer* UILoseLayer::create() {
    UILoseLayer *ret = new (std::nothrow) UILoseLayer;
    if (ret && ret->init())
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}

bool UILoseLayer::init() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    // Flash upon
    auto flashing = CallFuncN::create([](Node* node){
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto origin = Director::getInstance()->getVisibleOrigin();
    
        auto flash = Sprite::create(FLASH_FILENAME);
        flash->setOpacity(0);
        auto fadeIn = FadeTo::create(0.1f, 255);
        auto fadeOut = FadeTo::create(0.1f, 0);
        auto remove = RemoveSelf::create();
        auto sequence = Sequence::create(fadeIn, fadeOut, remove, nullptr);
        node->addChild(flash);
        flash->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
        flash->runAction(sequence);
    });

    auto delay1 = DelayTime::create(0.5f);

    // Appear foreground
    auto foring = CallFuncN::create([](Node* node){
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto origin = Director::getInstance()->getVisibleOrigin();

        auto fore = Sprite::create(FORE_FILENAME);
        fore->setOpacity(0);
        auto fadeIn = FadeTo::create(0.5f, 160);
        node->addChild(fore);
        fore->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
        fore->runAction(fadeIn);
    });

    // Appear victory text
    auto lose = CallFuncN::create([](Node* node){
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto origin = Director::getInstance()->getVisibleOrigin();

        auto victory = Sprite::create(LOSE_FILENAME);
        victory->setOpacity(0);
        victory->setScale(0.75f);

        node->addChild(victory, 1);
        victory->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
        
        auto fadeIn = FadeTo::create(2.5f, 255);
        auto scaleIn = ScaleTo::create(2.5f, 1.0f);
        auto delay = DelayTime::create(2.0f);
        auto fadeOut = FadeTo::create(2.0f, 0);
        auto remove = RemoveSelf::create();

        auto sequence = Sequence::create(fadeIn, delay, fadeOut, remove, nullptr);

        victory->runAction(scaleIn);
        victory->runAction(sequence);        
    });

    // Finalize
    auto seq = Sequence::create(flashing, delay1, foring, lose, nullptr);
    this->runAction(seq);
    
    return true;
}