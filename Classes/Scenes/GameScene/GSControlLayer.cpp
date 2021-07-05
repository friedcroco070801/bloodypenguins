#include "GSControlLayer.h"
#include "GSdefine.h"
#include "AppDelegate.h"

USING_NS_CC;
Sprite *preview;


GameMapInformation::GameMapInformation() :
    rowNumbers(5),
    columnNumbers(8)
{
	MAP_INIT(CellsMap);
} 
GSControlLayer::GSControlLayer()	
{
	
	gameMapInformation_ = new GameMapInformation();
}
GSControlLayer::~GSControlLayer()
{
	delete gameMapInformation_;
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
	auto map_sprite = Sprite::create("sprites/InformationLayer/map__.png");
	map_sprite->setContentSize(Size(SIZE_OF_SQUARE * 8, SIZE_OF_SQUARE * 5));
	map_sprite->setAnchorPoint(Vec2(0, 0));
	map_sprite->setPosition(Vec2(360, 110));
	this->addChild(map_sprite, 1);

	ButtonCall();

    return true;
}

/*
bool GSControlLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
	auto p = touch->getLocation();
	cur_.x = p.x;
	cur_.y = p.y;
	GSControlLayer::calculateCellsPosition();
	int b = cellsPosition_.x;
	int a = cellsPosition_.y;
	
  	if (gameMapInformation_->CellsMap[a][b] == CELL_POSITION) {
		level->addCell(CellModel::create(CELL_00_EOSINOPHILS), cellsPosition_.x, cellsPosition_.y);
		gameMapInformation_->CellsMap[a][b] = CELL_CANT_POSITION;
	}
	return true;
}
*/
void GSControlLayer::ButtonCall() {
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(GSControlLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GSControlLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(GSControlLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

bool GSControlLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
	auto p = touch->getLocation();
	preview = new Sprite();
	preview = Sprite::create("HelloWorld.png");
	preview->setContentSize(Size(SIZE_OF_SQUARE, SIZE_OF_SQUARE));
	if (GRASS_OUTSIDE(p)) {
		preview->setPosition(Vec2(p.x, p.y));
	}
	else {
		cur_.x = p.x;
		cur_.y = p.y;
		calculateCellsPosition();
		preview->setPosition(Vec2(ROW_COLUMN_TO_POSITION(cellsPosition_)));
	}
	this->addChild(preview, 6);
	
	return true;
}

void GSControlLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) {
	auto p = touch->getLocation();
	if (GRASS_OUTSIDE(p)) {
		preview->setPosition(Vec2(p.x, p.y));
	}
	else {

		cur_.x = p.x;
		cur_.y = p.y;
		calculateCellsPosition();
		preview->setPosition(Vec2(ROW_COLUMN_TO_POSITION(cellsPosition_)));
	}
}
void GSControlLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) {
	preview->setPosition(Vec2(2000, 2000));
	auto p = touch->getLocation();
	cur_.x = p.x;
	cur_.y = p.y;
	GSControlLayer::calculateCellsPosition();
	int b = cellsPosition_.x;
	int a = cellsPosition_.y;
	if (gameMapInformation_->CellsMap[a][b] == CELL_POSITION) {
		level->addCell(CellModel::create(CELL_00_EOSINOPHILS), cellsPosition_.x, cellsPosition_.y);
		gameMapInformation_->CellsMap[a][b] = CELL_CANT_POSITION;
	}
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
void GSControlLayer::SetWay(std::vector< std::vector<MapPosition> >&map_can_plant) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (map_can_plant[i][j] == 5 || map_can_plant[i][j] == 1 || map_can_plant[i][j] == 2) {
				gameMapInformation_->CellsMap[i][j] == DISEA_WAY;
				cellsPosition_.x = i;
				cellsPosition_.y = j;
				auto check = Sprite::create("HelloWorld.png");
				check->setContentSize(Size(98, 98));
				this->addChild(check,2);
			}
		}
	}
};
