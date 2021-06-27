#include "LevelModel.h"
using namespace std;

LevelModel::LevelModel(int level) {
    int arr[10][5] = {
        {0, 2, 0, 2, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 1, 0}
    };
    map = vector< vector<MapPosition> >();
    for (int i = 0; i < 10; i++) {
        vector<MapPosition> temp;
        for (int j = 0; j < 5; j++) {
            temp.push_back((MapPosition) arr[i][j]);
        }
        map.push_back(temp);
    }
}