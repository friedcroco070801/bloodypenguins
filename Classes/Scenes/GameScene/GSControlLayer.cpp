#include "GSControlLayer.h"
#include "GSdefine.h"
#include "AppDelegate.h"

USING_NS_CC;
//global variable

bool GSControlLayer::init()
{
    // Super init
    if ( !Layer::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Vector<MenuItem*> MenuItems;
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);
	touchListener->onTouchBegan = CC_CALLBACK_2(GSControlLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GSControlLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(GSControlLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
//	setPreviewImage(CELL_00_EOSINOPHILS);
/////////////////////////////////////////////////////////XOA
/*
	auto button = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_0(GSControlLayer::ButtonCall_1, this));
	button->setPosition(Vec2(100, 200));

	auto button2 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_0(GSControlLayer::ButtonCall_2, this));
	button2->setPosition(Vec2(100, 300));

	auto menu = Menu::create(button,button2, NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);
*/
///////////////////////////////////////////////////////////////XOA

	return true;
}
/////////////////////////////
/*
void GSControlLayer::createPreview(int id) {
	std::string link;
	switch (id)
	{
	case 1:
		link = "HelloWorld.png";
		break;
	case 2:
		link = "CloseSelected.png";
		break;
	default:
		break;
	}
	setPreviewImage(CELL_00_EOSINOPHILS);
}
*/
//ham call --------------------------------------------------------------------------
void GSControlLayer::setPreviewImage(CellId id) {

	this->Cell_Id = id;
	this->buttonCheck = true;
	switch (id)
	{
	case CELL_00_EOSINOPHILS:
		this->link_image = "sprites/objects/cell/cell_00.png";
		break;
	default:
		break;
	}
}

/*
void GSControlLayer::ButtonCall_1() {
	createPreview(0);
}

void GSControlLayer::ButtonCall_2() {
	createPreview(0);
}
*/
//////////////////////////////////////XOA
bool GSControlLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {

	auto p = touch->getLocation();

	if (buttonCheck) {
		this->previewImage = new Sprite();
		this->previewImage = Sprite::create(this->link_image);
		this->previewImage->setContentSize(Size(SIZE_OF_SQUARE, SIZE_OF_SQUARE));
		if (GRASS_OUTSIDE(p)) {
			this->previewImage->setColor(Color3B::RED);
			this->previewImage->setOpacity(150);
			this->previewImage->setPosition(Vec2(p.x, p.y));
		}
		else {
			cur_.x = p.x;
			cur_.y = p.y;
			calculateCellsPosition();
			this->previewImage->setPosition(ROW_COLUMN_TO_POSITION(cellsPosition_));

			if (CellModel::canPutOn(this->Cell_Id,this->level,cellsPosition_.x,cellsPosition_.y)) {
				this->previewImage->setColor(Color3B::WHITE);
			}
			else {
				this->previewImage->setColor(Color3B::RED);
			}
		}
		this->addChild(this->previewImage, 2);
	}
	return true;
}

void GSControlLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) {
	auto p = touch->getLocation();
	if (buttonCheck) {
		if (GRASS_OUTSIDE(p)) {
			this->previewImage->setColor(Color3B::RED);
			this->previewImage->setOpacity(150);
			this->previewImage->setPosition(Vec2(p.x, p.y));
		}
		else {
			
			cur_.x = p.x;
			cur_.y = p.y;
			calculateCellsPosition();
			if (CellModel::canPutOn(this->Cell_Id, this->level, cellsPosition_.x, cellsPosition_.y)){
				this->previewImage->setColor(Color3B::WHITE);
			}
			else {
				this->previewImage->setColor(Color3B::RED);
			}
			this->previewImage->setPosition(Vec2(ROW_COLUMN_TO_POSITION(cellsPosition_)));
		}
	}

}
void GSControlLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) {

	auto p = touch->getLocation();
	if (buttonCheck) {
		if (!GRASS_OUTSIDE(p)) {
			cur_.x = p.x;
			cur_.y = p.y;
			GSControlLayer::calculateCellsPosition();
			int b = cellsPosition_.x;
			int a = cellsPosition_.y;
			level->addCell(CellModel::create(this->Cell_Id), cellsPosition_.x, cellsPosition_.y);
		}
		this->previewImage->removeFromParent();
		this->removeFromParent();
	}	
	
}
void GSControlLayer::calculateCellsPosition() {
    for(unsigned int i = 0; i < ROWW;i++){
        for (unsigned int j = 0; j < COLUMNN; j++) {
            if (GRASS_INSIDE(cur_, i, j))
            {
                cellsPosition_.x = j;
                cellsPosition_.y = i;
            }
        }
    }
}
