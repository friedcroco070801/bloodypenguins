#include "GSMap.h"
#include "AppDelegate.h"

USING_NS_CC;

bool GSMap::init() {
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	return true;
}
void GSMap::createMap(LevelModel *level) {
	int a = level->getMap().size();
	int b = level->getMap()[0].size();

	auto mapImage = Sprite::create("sprites/InformationLayer/khonggian.png");
	mapImage->setContentSize(Size(WIDTH,HEIGHT));
	mapImage->setContentSize(Size(SIZE_OF_SQUARE*COLUMNN, SIZE_OF_SQUARE*ROWW));
	mapImage->setAnchorPoint(Vec2(0,0));
	positionCell temp;
	mapImage->setPosition(Vec2(GRASS_POSITION_LEFT,GRASS_POSITION_BOTTOM));

	for (int i = 0; i < a;i++) {
		for (int j = 0; j < b; j++) {
			temp.x = i;
			temp.y = j;
			if (level->getMap()[i][j] == 5 || level->getMap()[i][j] == 1 || level->getMap()[i][j] == 2) {
				auto enemyWay = Sprite::create("sprites/InformationLayer/black.png");
				enemyWay->setContentSize(Size(SIZE_OF_SQUARE, SIZE_OF_SQUARE));
				enemyWay->setPosition(ROW_COLUMN_TO_POSITION(temp));
				this->addChild(enemyWay);
			}
		}
	}
	this->addChild(mapImage,-1);
}