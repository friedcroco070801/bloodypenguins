#include "GameScene.h"
#include "GSControlLayer.h"
#include "UIObjects/uiobj.h"
#include "GSBackgroundLayer.h"

USING_NS_CC;
Scene* GameScene::createScene(int level)
{
	return GameScene::create(level);
}
bool GameScene::init(int _level) {
	if (!Scene::init()) return false;
	level = new LevelModel(_level, this);
	level->startCounting();
	drawMap();
	addBackground();
	this->schedule(CC_SCHEDULE_SELECTOR(GameScene::updateLevel), 0.01f);
	return true;
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
