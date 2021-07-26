#ifndef __UI_WIN_LAYER_H__
#define __UI_WIN_LAYER_H__

#include "cocos2d.h"

#define FLASH_FILENAME "sprites/objects/button/result_layer/flash_bg.jpg"
#define FORE_FILENAME "sprites/objects/button/layer_fore.png"
#define VICTORY_FILENAME "sprites/objects/button/result_layer/victory_noti.png"
#define STAR_FILENAME "sprites/objects/button/result_layer/star.png"

class LevelModel;

class UIWinLayer : public cocos2d::Layer {
public:
    static UIWinLayer* create(LevelModel*);
    bool init(LevelModel*);
protected:
    LevelModel* level;
};

#endif // !__UI_RESULT_LAYER_H__