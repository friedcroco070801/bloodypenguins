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

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

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
	play->setScale(1.25);
	//play->setPosition(Vec2(WIDTH / 2, HEIGHT * 5 / 8));
	MenuItems.pushBack(play);

	auto options = MenuItemImage::create(OPTIONS_LAYER_FILENAME, OPTIONS_LAYER_CLICKED_FILENAME, CC_CALLBACK_1(MMControl::GoToOptionsCom, this));
	options->setScale(1.25);
	//options->setPosition(Vec2(WIDTH / 2, HEIGHT * 4 / 8));
	MenuItems.pushBack(options);

	auto quit = MenuItemImage::create(QUIT_LAYER_FILENAME, QUIT_LAYER_CLICKED_FILENAME, CC_CALLBACK_1(MMControl::ExitGameMain, this));
	quit->setScale(1.25);
	//quit->setPosition(Vec2(WIDTH / 2, HEIGHT * 3 / 8));
	MenuItems.pushBack(quit);

	auto menu = Menu::createWithArray(MenuItems);

	//menu->setScale(1.25);

	menu->alignItemsVerticallyWithPadding(6.5f);

	menu->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height + origin.y + 50.f));
	auto moveto = MoveTo::create(2, Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	menu->runAction(moveto);
	
	auto roto = RotateBy::create(2, Vec3(0, 360, 0));
	auto delay = DelayTime::create(18);
	auto seqname = Sequence::create(roto, delay, nullptr);
	auto repeat = RepeatForever::create(seqname);
	play->runAction(repeat);

	auto roto1 = RotateBy::create(2, Vec3(0, 360, 0));
	auto delay1 = DelayTime::create(20);
	auto seqname1 = Sequence::create(roto1, delay1, nullptr);
	auto repeat1 = RepeatForever::create(seqname1);
	options->runAction(repeat1);

	auto roto2 = RotateBy::create(2, Vec3(0, 360, 0));
	auto delay2 = DelayTime::create(22);
	auto seqname2 = Sequence::create(roto2, delay2, nullptr);
	auto repeat2 = RepeatForever::create(seqname2);
	quit->runAction(repeat2);
	
	//menu->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
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