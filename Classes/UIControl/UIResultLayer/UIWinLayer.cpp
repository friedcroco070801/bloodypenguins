#include "UIWinLayer.h"
USING_NS_CC;

UIWinLayer* UIWinLayer::create() {
    UIWinLayer *ret = new (std::nothrow) UIWinLayer;
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

bool UIWinLayer::init() {
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
    auto victory = CallFuncN::create([](Node* node){
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto origin = Director::getInstance()->getVisibleOrigin();

        auto victory = Sprite::create(VICTORY_FILENAME);
        victory->setOpacity(0);
        victory->setScale(3.0f);

        node->addChild(victory, 1);
        victory->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
        
        auto fadeIn = FadeTo::create(0.15f, 255);
        auto scaleIn = ScaleTo::create(0.3f, 1.0f);
        auto delay = DelayTime::create(1.0f);
        auto fadeOut = FadeTo::create(1.0f, 0);
        auto remove = RemoveSelf::create();

        auto sequence = Sequence::create(fadeIn, delay, fadeOut, remove, nullptr);

        victory->runAction(scaleIn);
        victory->runAction(sequence);        
    });

    auto delay2 = DelayTime::create(0.3f);

    // Appear stars
    auto stars = CallFuncN::create([](Node* node){
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto origin = Director::getInstance()->getVisibleOrigin();

        for (int j = 0; j < 100; j++) {
            auto star = Sprite::create(STAR_FILENAME);
            auto scale = CCRANDOM_0_1() * 0.85f + 0.15f;
            star->setScale(scale);
            
            auto time = CCRANDOM_0_1() * 1.0f + 1.0f;
            auto rotate = RotateBy::create(time + 0.5f, CCRANDOM_MINUS1_1() * 720.0f);
            
            auto jump = JumpBy::create(time + 0.5f, Vec2(CCRANDOM_MINUS1_1() * 1.5f * visibleSize.width / 2, CCRANDOM_MINUS1_1() * 1.5f * visibleSize.height / 2), (CCRANDOM_0_1() * 0.5f + 0.5f) * visibleSize.height / 10, 1);
            
            auto delay = DelayTime::create(time);
            auto fadeOut = FadeTo::create(0.5f, 0);
            auto remove = RemoveSelf::create();
            auto seq = Sequence::create(delay, fadeOut, remove, nullptr);

            node->addChild(star);
            star->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
            star->runAction(rotate);
            star->runAction(jump);
            star->runAction(seq);
        }
    });

    // Finalize
    auto seq = Sequence::create(flashing, delay1, foring, victory, delay2, stars, nullptr);
    this->runAction(seq);
    
    return true;
}