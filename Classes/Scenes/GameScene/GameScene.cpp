#include "GameScene.h"
#include "GSControlLayer.h"
#include "UIObjects/uiobj.h"
#include "GSBackgroundLayer.h"

USING_NS_CC;
Scene* GameScene::createScene()
{
	return GameScene::create();
}
bool GameScene::init() {
	if (!Scene::init()) return false;
	level = new LevelModel(1, this);
	level->startCounting();
	//controlLayer(level);
	drawMap();
	addBackground();
    this->schedule(CC_SCHEDULE_SELECTOR(GameScene::updateLevel), 0.01f);
	return true;
}
void GameScene::controlLayer(LevelModel* level) {
	auto controlLayer_ = GSControlLayer::create(level);
	this->addChild(controlLayer_, 1);
}
void GameScene::updateLevel(float) {
	level->update();
}
void GameScene::drawMap() {
	auto drawMapp = GSMap::create();
	drawMapp->createMap(level);
	this->addChild(drawMapp);
}

void GameScene::addBackground() {
	auto backgroundLayer = GSBackgroundLayer::create();
	this->addChild(backgroundLayer, -1);
}
