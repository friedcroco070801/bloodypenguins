#ifndef __GSCONTROLLAYER_H__
#define __GSCONTROLLAYER_H__

#include "cocos2d.h"

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
    CREATE_FUNC(GSControlLayer);
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	GSControlLayer();
    virtual bool init();
    void calculateCellsPosition();
	
	position cur_ ;
    position cellsPosition_ ;
    GameMapInformation* gameMapInformation_;
};

#endif // !__GSCONTROLLAYER_H__