#include "MainMenuScene.h"
#include "UIObjects/uiobj.h"
#include "MMBackgroundLayer.h"
#include "MMControl.h"

USING_NS_CC;
Scene* MainMenuScene::createScene()
{
	return MainMenuScene::create();
}
bool MainMenuScene::init() {
	if (!Scene::init()) return false;
	
	addBackground();
	controlButton();
	return true;
}


void MainMenuScene::addBackground() {
	auto backgroundLayer = MMBackgroundLayer::create();
	this->addChild(backgroundLayer, -1);
}


void MainMenuScene::controlButton() {
	auto buttonLayer = MMControl::create();
	this->addChild(buttonLayer, -1);
}

