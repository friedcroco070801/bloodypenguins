#ifndef __GSDEFINE_H__
#define __GSDEFINE_H__

/*
        
           
        +---------------------720-----------------------+
        |												|
        |-----+---------------630-----------------------|    
        |      |       +----------600--------------+    |
        |      |       |                           |    |
        |    160  360      GRASSPOSITION         1200 1280
        |      |       |                           |    |
        |      |       |                           |    |
        |      |       +----------110--------------+    |
        |      +----------------90----------------------|
        |      |                                        |    
        +-----+-----------------0-----------------------+
           |
        CARDBAR
*/
#define GRASS_POSITION_LEFT     360
#define GRASS_POSITION_RIGHT 1200
#define GRASS_POSITION_TOP     600
#define GRASS_POSITION_BOTTOM 110
#define ROW 7
#define COLUMN 12
#define ROW_COLUMN_TO_POSITION(__ROW_COLUMN__) Vec2(GRASS_POSITION_LEFT + 70*__ROW_COLUMN__.x + 30, GRASS_POSITION_BOTTOM + 70*(__ROW_COLUMN__.y + 1)-40)
#define POSITION_TO_ROW_COLUMN(__POSITION__) Vec2((-GRASS_POSITION_LEFT + __POSITION__.x - 30) / 70, (-GRASS_POSITION_BOTTOM + __POSITION__.y - 30)/70 - 1)
#define CELL_POSITION -1
#define CELL_CANT_POSITION -2
#define MAP_INIT(__MAP__)  for(auto& __ROW__ : __MAP__) { for(auto& __COLUMN__ : __ROW__ ) { __COLUMN__ = CELL_POSITION;} }

#define GRASS_INSIDE(__POSITION__,__X__,__Y__) (__POSITION__.x > GRASS_POSITION_LEFT + 70 * __Y__ && __POSITION__.x < GRASS_POSITION_LEFT + 70 * (__Y__ + 1) && __POSITION__.y > 110 + 70 * __X__ && __POSITION__.y < 110 + 70 * (__X__ + 1))
#define GRASS_OUTSIDE(__POSITION__) (__POSITION__.x < GRASS_POSITION_LEFT || __POSITION__.x>GRASS_POSITION_RIGHT || __POSITION__.y < GRASS_POSITION_BOTTOM || __POSITION__.y>GRASS_POSITION_TOP)




#endif // __GSDEFINE_H__