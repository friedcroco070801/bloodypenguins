#include "GSControlLayer.h"
#include "GSdefine.h"
#include "AppDelegate.h"

USING_NS_CC;


GameMapInformation::GameMapInformation() :
    rowNumbers(7),
    columnNumbers(12)
{
	MAP_INIT(CellsMap);
} 

// on "init" you need to initialize your instance
bool GSControlLayer::init()
{
    // Super init
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(GSControlLayer::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    return true;
}
GSControlLayer::GSControlLayer() {
    gameMapInformation_ = new GameMapInformation();
}
bool GSControlLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
	auto p = touch->getLocation();
	cur_.x = p.x;
	cur_.y = p.y;
	GSControlLayer::calculateCellsPosition();
	int b = cellsPosition_.x;
	int a = cellsPosition_.y;
	
  	if (gameMapInformation_->CellsMap[a][b] == CELL_POSITION) {
		auto click = Sprite::create("sprites/gold.png");
		click->setContentSize(Size(30, 30));
		click->setPosition(ROW_COLUMN_TO_POSITION(cellsPosition_));
		gameMapInformation_->CellsMap[a][b] = CELL_CANT_POSITION;
		this->addChild(click, 1);
	}
	else {
		auto click = Sprite::create("sprites/diamond.png");
		click->setContentSize(Size(30, 30));
		click->setPosition(ROW_COLUMN_TO_POSITION(cellsPosition_));
		gameMapInformation_->CellsMap[a][b] = CELL_POSITION;
		this->addChild(click, 1);
	}
	log("giatri %u", gameMapInformation_->CellsMap[a][b]);
	log("---------------");
	return true;
}

void GSControlLayer::calculateCellsPosition() {
    for(unsigned int i = 0; i < gameMapInformation_->rowNumbers;i++){
        for (unsigned int j = 0; j < gameMapInformation_->columnNumbers; j++) {
            if (GRASS_INSIDE(cur_, i, j))
            {
                cellsPosition_.x = j;
                cellsPosition_.y = i;
            }
        }
    }
    if (GRASS_OUTSIDE(cur_)) {
        cellsPosition_.x = 100;
        cellsPosition_.y = 100;
    }
}
