#ifndef __UI_CONTROL_CELLBAR_DEFINITIONS_H__
#define __UI_CONTROL_CELLBAR_DEFINITIONS_H__

#include "Models/Character/Cell/CellModelDefinitions.h"

#define DOUBLE_PRECISION 0.00001

#define CELLBAR_LAYER_ZORDER 10

#define CELLBAR_POSITION_X 80
#define CELLBAR_POSITION_Y(index) Director::getInstance()->getVisibleSize().height / 16 * (13 - 2 * index)

#define CELLBAR_LOADING_FILENAME "sprites/objects/cell/cellbar/cellbar_loading.png"
#define CELLBAR_LOADING_COMPLETE_FILENAME "sprites/objects/cell/cellbar/cellbar_loading_complete.png"
#define ANIM_CELLBAR_FLASH 0.1f

#define CELLBAR_00_FILENAME "sprites/objects/cell/cellbar/cellbar_00.png"
#define CELLBAR_01_FILENAME "sprites/objects/cell/cellbar/cellbar_01.png"

#endif // !__UI_CONTROL_CELLBAR_DEFINITIONS_H__