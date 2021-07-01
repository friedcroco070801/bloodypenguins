#include "GameScene.h"
#include "GSControlLayer.h"
#include "GSInformationLayer.h"


USING_NS_CC;
Scene* GameScene::createScene()
{
	return GameScene::create();
}
bool GameScene::init() {
	if (!Scene::init()) return false;
	//backgroundLayer();
	controlLayer();
	informationLayer();
	return true;
}
void GameScene::controlLayer() {
	auto controlLayer_ = GSControlLayer::create();
	this->addChild(controlLayer_, 1);
}
void GameScene::informationLayer() {
	auto informationLayer_ = GSInformationLayer::create();
	this->addChild(informationLayer_, 1);
}

