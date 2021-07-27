#include "LevelScene.h"
#include "UIObjects/uiobj.h"
#include "LevelButton.h"
#include "Scenes/GameScene/GSDefine.h"
#include "SwitchSceneButton.h"
#include "Scenes/MainMenuScene/MainMenuScene.h"
USING_NS_CC;
Scene* levelScene::createScene()
{
	return levelScene::create();
}
bool levelScene::init() {
	if (!Scene::init()) return false;
	CreateButtonLevel();
	SetBackGround();
	CreateBackButton();
	return true;
}
void levelScene::SetBackGround() {
	auto t = time(NULL);
	auto hour = localtime(&t)->tm_hour;
	auto background = Sprite::create(BACK_GROUND_1);
	if (hour <= 6 || hour >= 18) {
		background = Sprite::create(BACK_GROUND_2);
	}
	else if (hour > 6 && hour < 15) {
		background = Sprite::create(BACK_GROUND_2);
	}
	if (background != nullptr)
	{
		background->setAnchorPoint(Point(0, 0));
		background->setContentSize(Size(WIDTH, HEIGHT));
		background->setPosition(Vec2(0, 0));
		background->setOpacity(175);
		this->addChild(background);
	}
}
void levelScene::CreateButtonLevel() {

	int level_current = 2;	
	for (int level = 1; level <= 8; level++) {
		if (level <= level_current) {
			levelButton* button = levelButton::create(level);
			button->setPosition(Vec2(level * WIDTH / 9,HEIGHT  * 4 / 5));
			this->addChild(button, 5);
		}
		else {
			auto lock = Sprite::create(LOCK_BUTTON);
			lock->setPosition(Vec2(level * WIDTH / 9, HEIGHT * 4 / 5));
			this->addChild(lock, 5);
		}
	}
}
void levelScene::CreateBackButton() {
	next = MainMenuScene::create();
	SwitchSceneButton* back_button = SwitchSceneButton::create( BUTTON_BACK, BUTTON_BACK_CLICKED);
	back_button->setScale(1.25);
	back_button->setPosition(Vec2(WIDTH / 10, HEIGHT / 6));
	this->addChild(back_button,5);
}

	