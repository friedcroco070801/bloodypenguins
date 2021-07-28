#include "SplashScene.h"
#include "editor-support/cocostudio/SimpleAudioEngine.h"
#include "Scenes/MainMenuScene/MainMenuScene.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* SplashScene::create() {
    SplashScene *ret = new (std::nothrow) SplashScene;
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

bool SplashScene::init() {
    auto appear = CallFuncN::create([](Node* node){
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto origin = Director::getInstance()->getVisibleOrigin();

        auto splash = Sprite::create(SPLASH_FILENAME);
        splash->setOpacity(0);
        node->addChild(splash);
        splash->setPosition(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
        splash->setScale(visibleSize.width * 2.0f / 3.0f / splash->getContentSize().width);
        auto fadeIn = FadeTo::create(0.5f, 255);
        splash->runAction(fadeIn);
    });

    auto delay1 = DelayTime::create(0.5f);

    auto loadMusic = CallFunc::create([](){
        auto data = UserDefault::getInstance();
        auto audio = SimpleAudioEngine::getInstance();
        audio->setBackgroundMusicVolume(data->getFloatForKey("MUSIC_VOLUME", 1.0f));
        audio->setEffectsVolume(data->getFloatForKey("EFFECT_VOLUME", 1.0f));

        // Preload here
    });

    auto delay2 = DelayTime::create(1.5f);

    auto changeScene = CallFunc::create([](){
        Director::getInstance()->replaceScene(TransitionFade::create(0.05f, MainMenuScene::create()));
    });

    auto seq = Sequence::create(appear, delay1, loadMusic, delay2, changeScene, nullptr);

    this->runAction(seq);

    return true;
}