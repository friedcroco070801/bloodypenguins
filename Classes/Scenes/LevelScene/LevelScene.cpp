#include "LevelScene.h"
#include "UIObjects/uiobj.h"
#include "LevelButton.h"
USING_NS_CC;
Scene* levelScene::createScene()
{
	return levelScene::create();
}
bool levelScene::init() {
	if (!Scene::init()) return false;
	LoopCreate();
	return true;
}
void levelScene::CreateButtonLevel(int level) {
	levelButton* button = levelButton::create(level);
	button->setPosition(Vec2(level * 100.0f, 500.0f));
	this->addChild(button, 5);
}
void levelScene::LoopCreate() {
	for (int i = 1; i <= NUMBER_LEVEL; i++) {
		CreateButtonLevel(i);
	}
}
	