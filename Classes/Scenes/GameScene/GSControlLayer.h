#ifndef __GSCONTROLLAYER_H__
#define __GSCONTROLLAYER_H__

#include "cocos2d.h"
#include "Models/models.h"
#include "GSDefine.h"


struct position
{
	float x;
	float y;
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
	void ButtonCall_1();
	void ButtonCall_2();
	void createPreview(int id);

	
private:
	std::string link_image;
	CellId Cell_Id;
	cocos2d::Sprite *previewImage ;
	bool buttonCheck = false;
public:
	void setPreviewImage(std::string link, CellId id);

    virtual bool init();
    void calculateCellsPosition();
	CellModel* cellMod;
	LevelModel* level;
	position cur_ ;
    position cellsPosition_ ;

};

#endif // !__GSCONTROLLAYER_H__