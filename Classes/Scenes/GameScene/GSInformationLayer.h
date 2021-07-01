#ifndef __GS_INFORMATION_LAYER_H__
#define __GS_INFORMATION_LAYER_H__

#include "cocos2d.h"
#include <string>
#include <vector>

class GSInformationLayer:public cocos2d :: Scene
{
public:
	CREATE_FUNC(GSInformationLayer);
	virtual bool init();
	
	void UpdateGold(int gold_);
	void UpdateDiamond(int diamond_);
	void UpdateEnergy(int energy_);

private:
	int energy;
	int gold;
	int diamond;
};
#endif // !__GS_INFORMATION_LAYER_H__