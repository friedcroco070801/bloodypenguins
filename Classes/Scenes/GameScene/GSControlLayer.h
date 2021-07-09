#ifndef __GSCONTROLLAYER_H__
#define __GSCONTROLLAYER_H__

#include "cocos2d.h"
#include "Models/models.h"
#include "GSDefine.h"


struct position
{
	int x;
	int y;
};

class GSControlLayer : public cocos2d::Layer
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
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event*event);
	void setPreviewImage(CellId id);

private:
	std::string link_image;
	CellId Cell_Id;
	cocos2d::Sprite *previewImage ;
	bool buttonCheck = false;

public:
    virtual bool init();
    void calculateCellsPosition();
	LevelModel* level;
	position cur_ ;
    position cellsPosition_ ;
};

#endif // !__GSCONTROLLAYER_H__