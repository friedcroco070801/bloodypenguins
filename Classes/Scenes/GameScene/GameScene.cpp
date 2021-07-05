#include "GameScene.h"
#include "GSControlLayer.h"
#include "GSInformationLayer.h"
#include "UIObjects/uiobj.h"

USING_NS_CC;
Scene* GameScene::createScene()
{
	return GameScene::create();
}
bool GameScene::init() {
	if (!Scene::init()) return false;
	level = new LevelModel(1, this);
	level->startCounting();
	//level->addCell(CellModel::create(CELL_00_EOSINOPHILS), 7, 4);
	//backgroundLayer();
	controlLayer(level);
	informationLayer();

	// Added level


	// Schedule update
    this->schedule(CC_SCHEDULE_SELECTOR(GameScene::updateLevel), 0.01f);

	return true;
}
void GameScene::controlLayer(LevelModel* level) {
	auto controlLayer_ = GSControlLayer::create(level);
	this->addChild(controlLayer_, 1);
}
void GameScene::informationLayer() {
	auto informationLayer_ = GSInformationLayer::create();
	this->addChild(informationLayer_, 0);
}

void GameScene::updateLevel(float) {
	level->update();
}

