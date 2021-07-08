#ifndef __GS_BACKGROUND_LAYER_H__
#define __GS_BACKGROUND_LAYER_H__

#include "cocos2d.h"
#include <string>
#include <vector>

#define IMG_BG1 "sprites/Background/bg1.jpg"

class GSBackgroundLayer:public cocos2d :: Scene
{
public:
	CREATE_FUNC(GSBackgroundLayer);

	virtual bool init();

	//static void backgroundRunAction();
	//void addLayer(Node* node, const int order, const string& name) { node->addChild(this, order, name); }
private:
	void setBackgroundImagePosition();
};
#endif // !__GS_BACKGROUND_LAYER_H__