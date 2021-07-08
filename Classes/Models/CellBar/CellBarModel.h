#ifndef __CELL_BAR_MODEL_H__
#define __CELL_BAR_MODEL_H__

enum CellId;
class LevelModel;
#ifdef __HAS_UICELLBAR__
class UICellBar;
#endif // __HAS_UICELLBAR__

class CellBarModel {
public:
    CellBarModel(CellId);
    virtual ~CellBarModel(){}
    void update();

    // Reset the counter of rechargeTime
    void resetCounter() {rechargeTimeCounter = rechargeTime;}

    // Get the CellId of the Cell bar model
    CellId getCellId() {return id;}

    // Get the cost of the Cell
    int getCost() {return cost;}

    // Get the recharge percentage
    double getRechargePercent() {return 1.0 - rechargeTimeCounter / rechargeTime;}

    // Set level model of the model
    void __setLevel(LevelModel* level) {this->level = level;} 

protected:
    LevelModel* level;
    CellId id;
    double rechargeTime;
    double rechargeTimeCounter;
    int cost;
    #ifdef __HAS_UICELLBAR__
    UICellBar* ui;
    #endif // __HAS_UICELLBAR__
};

#endif // !__CELL_BAR_MODEL_H__