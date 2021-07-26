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
	CreateButtonLevel();
	return true;
}
void levelScene::CreateButtonLevel() {

	auto background = Sprite::create("sprites/Background/backgroundpokemon.png");
	background->setPosition(Vec2(640, 360));
	for (int level = 1; level <= 8; level++) {
		levelButton* button = levelButton::create(level);
		button->setPosition(Vec2(level * background->getContentSize().width / 9 , background->getContentSize().height * 4 / 5));
		background->addChild(button, 5);
	}
	this->addChild(background);
}

	