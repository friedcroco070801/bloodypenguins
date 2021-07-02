#ifndef __GSCONTROLLAYER_H__
#define __GSCONTROLLAYER_H__

#include "cocos2d.h"
#include "Models/models.h"

struct GameMapInformation
{
    GameMapInformation();
    int CellsMap[7][12]; //ban do dat cell
    unsigned int rowNumbers; //
    unsigned int columnNumbers;
};
struct position
{
	float x;
	float y;
};

class GSControlLayer : public cocos2d::Scene
{
public:
	static GSControlLayer* create(LevelModel* level_) 
	{ 
		GSControlLayer *pRet = new(std::nothrow) GSControlLayer(); 
		if (pRet && pRet->init()) 
		{ 

			pRet->autorelease(); 
			pRet->level = level_;
			return pRet; 
		} 
		else 
		{ 
			delete pRet; 
			pRet = nullptr; 
			return nullptr; 
		} 
	}

	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	GSControlLayer();
    virtual bool init();
    void calculateCellsPosition();
	void SetWay(std::vector<std::vector<MapPosition>> map_can_plant);
	LevelModel* level;
	position cur_ ;
    position cellsPosition_ ;
    GameMapInformation* gameMapInformation_;
};

#endif // !__GSCONTROLLAYER_H__