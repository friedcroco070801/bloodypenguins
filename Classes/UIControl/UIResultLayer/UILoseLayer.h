#ifndef __UI_LOSE_LAYER_H__
#define __UI_LOSE_LAYER_H__

#include "cocos2d.h"

#define FLASH_FILENAME "sprites/objects/button/result_layer/flash_bg.jpg"
#define FORE_FILENAME "sprites/objects/button/layer_fore.png"
#define LOSE_FILENAME "sprites/objects/button/result_layer/lose_noti.png"

class UILoseLayer : public cocos2d::Layer {
public:
    static UILoseLayer* create();
    bool init();
};

#endif // !__UI_RESULT_LAYER_H__