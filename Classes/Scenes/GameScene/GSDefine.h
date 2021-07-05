#ifndef __GSDEFINE_H__
#define __GSDEFINE_H__
#include <cmath>
/*
        
           
        +---------------------720-----------------------+
        |												|
        |-----+---------------630-----------------------|    
        |      |       +----------600--------------+    |
        |      |       |                           |    |
        |    160	  360      GRASSPOSITION     1200 1280
        |      |       |                           |    |
        |      |       |                           |    |
        |      |       +----------110--------------+    |
        |      +----------------90----------------------|
        |      |                                        |    
        +-----+-----------------0-----------------------+
           |
        CARDBAR
*/
#define HEIGHT					Director::getInstance()->getVisibleSize().height
#define WIDTH					Director::getInstance()->getVisibleSize().width
#define TOP						HEIGHT*7/8
#define GRASS_POSITION_LEFT		WIDTH*9/32
#define GRASS_POSITION_RIGHT	WIDTH*15/16
#define GRASS_POSITION_TOP		HEIGHT*5/6    
#define GRASS_POSITION_BOTTOM	HEIGHT*11/72
#define ROWW					5
#define COLUMNN					8	
#define SIZE_OF_SQUARE			std::fmin((GRASS_POSITION_RIGHT-GRASS_POSITION_LEFT)/COLUMNN,(GRASS_POSITION_TOP - GRASS_POSITION_BOTTOM)/ROWW)
#define ROW_COLUMN_TO_POSITION(__ROW_COLUMN__)		Vec2(GRASS_POSITION_LEFT + SIZE_OF_SQUARE*__ROW_COLUMN__.x + SIZE_OF_SQUARE/2, GRASS_POSITION_BOTTOM + SIZE_OF_SQUARE*(__ROW_COLUMN__.y + 1)- SIZE_OF_SQUARE/2)
#define POSITION_TO_ROW_COLUMN(__POSITION__)		Vec2((-GRASS_POSITION_LEFT + __POSITION__.x - SIZE_OF_SQUARE/2) / SIZE_OF_SQUARE, (-GRASS_POSITION_BOTTOM + __POSITION__.y - SIZE_OF_SQUARE/2)/SIZE_OF_SQUARE - 1)
#define CELL_POSITION			1
#define CELL_CANT_POSITION		2
#define	LIMIT_TOP				GRASS_POSITION_BOTTOM + SIZE_OF_SQUARE*ROWW
#define LIMIT_RIGHT				GRASS_POSITION_LEFT + SIZE_OF_SQUARE*COLUMNN
#define MAP_INIT(__MAP__)		for(auto& __ROW__ : __MAP__) { for(auto& __COLUMN__ : __ROW__ ) { __COLUMN__ = CELL_POSITION;} }

#define GRASS_INSIDE(__POSITION__,__X__,__Y__)	(__POSITION__.x >= GRASS_POSITION_LEFT + SIZE_OF_SQUARE * __Y__ && __POSITION__.x <= GRASS_POSITION_LEFT + SIZE_OF_SQUARE * (__Y__ + 1) && __POSITION__.y >= GRASS_POSITION_BOTTOM + SIZE_OF_SQUARE * __X__ && __POSITION__.y <= GRASS_POSITION_BOTTOM + SIZE_OF_SQUARE * (__X__ + 1))
#define GRASS_OUTSIDE(__POSITION__)				(__POSITION__.x < GRASS_POSITION_LEFT || __POSITION__.x>LIMIT_RIGHT || __POSITION__.y < GRASS_POSITION_BOTTOM || __POSITION__.y > LIMIT_TOP)
//SIZE
#define ICON_SIZE				HEIGHT/24
#define NUMBER_SIZE				ICON_SIZE*2/3
#define NUMBER_HEIGHT			TOP + (HEIGHT - TOP - ICON_SIZE)/2 + ICON_SIZE/6
#define DISEA_WAY				3
//POSITION
#define ENERGY_POSITION			Vec2((WIDTH/160),(TOP + (HEIGHT - TOP - ICON_SIZE)/2))

#define GOLD_POSITION			Vec2((WIDTH/160 + WIDTH/5),(TOP + (HEIGHT - TOP - ICON_SIZE)/2))
#define DIAMOND_POSITION	Vec2((WIDTH/160 + WIDTH*2/5),(TOP + (HEIGHT - TOP - ICON_SIZE)/2))







#endif // __GSDEFINE_H__