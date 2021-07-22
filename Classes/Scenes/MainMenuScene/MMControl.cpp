#include "MMControl.h"
#include "Scenes/GameScene/GSDefine.h"
#include "AppDelegate.h"
#include "UIObjects/UICell/UICellDefinitions.h"

USING_NS_CC;
//global variable

bool MMControl::init()
{
	// Super init
	if (!Scene::init())
	{
		return false;
	}

	addButtonMenu();

	return true;
}

void MMControl::addButtonMenu() {

	/*
	// Add play button
	auto play = ui::Button::create(PLAY_LAYER_FILENAME, PLAY_LAYER_CLICKED_FILENAME, PLAY_LAYER_CLICKED_FILENAME);
	play->addTouchEventListener(CC_CALLBACK_1(MMControlLayer::GoToGameScene, this));
	this->addChild(play);
	play->setPosition(Vec2(WIDTH/2, HEIGHT*5/8));

	// Add options button
	auto options = ui::Button::create(OPTIONS_LAYER_FILENAME, OPTIONS_LAYER_CLICKED_FILENAME, OPTIONS_LAYER_CLICKED_FILENAME);
	options->addTouchEventListener(CC_CALLBACK_1(MMControlLayer::GoToOptionsCom, this));
	this->addChild(options);
	options->setPosition(Vec2(WIDTH / 2, HEIGHT * 4 / 8));

	// Add quit button
	auto quit = ui::Button::create(QUIT_LAYER_FILENAME, QUIT_LAYER_CLICKED_FILENAME, QUIT_LAYER_CLICKED_FILENAME);
	quit->addTouchEventListener(CC_CALLBACK_1(MMControlLayer::ExitGame, this));
	this->addChild(quit);
	quit->setPosition(Vec2(WIDTH / 2, HEIGHT * 3 / 8));
	*/

	Vector<MenuItem*> MenuItems;

	auto play = MenuItemImage::create(PLAY_LAYER_FILENAME, PLAY_LAYER_CLICKED_FILENAME, CC_CALLBACK_1(MMControl::GoToGameScene, this));
	//play->setPosition(Vec2(WIDTH / 2, HEIGHT * 5 / 8));
	MenuItems.pushBack(play);

	auto options = MenuItemImage::create(OPTIONS_LAYER_FILENAME, OPTIONS_LAYER_CLICKED_FILENAME, CC_CALLBACK_1(MMControl::GoToOptionsCom, this));
	//play->setPosition(Vec2(WIDTH / 2, HEIGHT * 4 / 8));
	MenuItems.pushBack(options);

	auto quit = MenuItemImage::create(QUIT_LAYER_FILENAME, QUIT_LAYER_CLICKED_FILENAME, CC_CALLBACK_1(MMControl::ExitGameMain, this));
	//play->setPosition(Vec2(WIDTH / 2, HEIGHT * 3 / 8));
	MenuItems.pushBack(quit);

	auto menu = Menu::createWithArray(MenuItems);

	menu->alignItemsVerticallyWithPadding(6.5f);
	menu->setPosition(Point(WIDTH / 2, HEIGHT / 2));
	this->addChild(menu);

}

void MMControl::GoToGameScene(cocos2d::Ref *sender) {
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1, scene));
}

void MMControl::ExitGameMain(cocos2d::Ref *sender)
{
	//CocosDenshion::SimpleAudioEngine::getInstance()->end();
	Director::getInstance()->end();
}

//temporary
void MMControl::GoToOptionsCom(cocos2d::Ref *sender) {
	Director::getInstance()->end();
}