#ifndef __UI_CELL_H__
#define __UI_CELL_H__

#include "UICellDefinitions.h"
#include "cocos2d.h"

class UIObjects;

class UICell : public UIObjects {
public:
    static UICell* create(CellId);
    virtual void addToScene(cocos2d::Scene*);
};

#endif // !__UI_CELL_H__