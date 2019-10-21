#include "EnemyShip.h"
#include "../../Core/Maths/Vector3.h"
#include "../../Core/Renderer/ConsoleColours.h"
#include <Windows.h>



/*
const int ENEMY_SPRITE_WIDTH = 5;
const int ENEMY_SPRITE_HEIGHT = 2;

CHAR_INFO EnemyShipSprite0[ENEMY_SPRITE_ANIMATION_FRAMES][ENEMY_SPRITE_WIDTH * ENEMY_SPRITE_HEIGHT] =
{
	{
		{ '/' ,FOREGROUND_WHITE },{ '_' ,FOREGROUND_WHITE },{ '_' ,FOREGROUND_WHITE } ,{ '_' ,FOREGROUND_WHITE },{ '\\' ,FOREGROUND_WHITE },
		{ 0 ,BACKGROUND_BLACK },{ '/' ,FOREGROUND_WHITE },{ 0 ,BACKGROUND_BLACK },{ '\\' ,FOREGROUND_WHITE },{ 0 ,BACKGROUND_BLACK },
	},
	{
		{ '\\' ,FOREGROUND_WHITE },{ '_' ,FOREGROUND_WHITE },{ '_' ,FOREGROUND_WHITE } ,{ '_' ,FOREGROUND_WHITE },{ '/' ,FOREGROUND_WHITE },
		{ 0 ,BACKGROUND_BLACK },{ '\\' ,FOREGROUND_WHITE },{ 'V' ,FOREGROUND_WHITE },{ '/' ,FOREGROUND_WHITE },{ 0 ,BACKGROUND_BLACK },
	},
	{
		{ 0 ,BACKGROUND_BLACK },{ '\\' , FOREGROUND_YELLOW },{ '|' ,FOREGROUND_YELLOW } ,{ '/' ,FOREGROUND_YELLOW },{ 0 ,BACKGROUND_BLACK },
		{ 0 ,BACKGROUND_BLACK },{ '/' , FOREGROUND_YELLOW },{ '|' ,FOREGROUND_YELLOW },{ '\\' ,FOREGROUND_YELLOW },{ 0 ,BACKGROUND_BLACK },
	},
	{
		{ 0 ,FOREGROUND_RED },{ '\\' , FOREGROUND_BRIGHT_RED },{ 0 ,FOREGROUND_BRIGHT_RED } ,{ '/' ,FOREGROUND_BRIGHT_RED },{ 0 ,FOREGROUND_BRIGHT_RED },
		{ 0 ,FOREGROUND_RED },{ '/' , FOREGROUND_BRIGHT_RED },{ 0 ,FOREGROUND_BRIGHT_RED },{ '\\' ,FOREGROUND_BRIGHT_RED },{ 0 ,FOREGROUND_BRIGHT_RED },
	},
};

CHAR_INFO EnemyShipSprite1[ENEMY_SPRITE_ANIMATION_FRAMES][ENEMY_SPRITE_WIDTH * ENEMY_SPRITE_HEIGHT] =
{
	{
		{ '|' ,FOREGROUND_WHITE },{ '_' ,FOREGROUND_WHITE },{ 1 ,FOREGROUND_WHITE } ,{ '_' ,FOREGROUND_WHITE },{ 0 ,BACKGROUND_BLACK },
		{ 0 ,BACKGROUND_BLACK },{ '|' ,FOREGROUND_WHITE },{ 0 ,BACKGROUND_BLACK },{ '|' ,FOREGROUND_WHITE },{ '|' ,FOREGROUND_WHITE },
	},
	{
		{ 0 ,BACKGROUND_BLACK },{ '_' ,FOREGROUND_WHITE },{ 1 ,FOREGROUND_WHITE } ,{ '_' ,FOREGROUND_WHITE },{ '|' ,FOREGROUND_WHITE },
		{ '|' ,FOREGROUND_WHITE },{ '|' ,FOREGROUND_WHITE },{ 0 ,BACKGROUND_BLACK },{ '|' ,FOREGROUND_WHITE },{ 0 ,BACKGROUND_BLACK },
	},
	{
		{ 0 ,BACKGROUND_BLACK },{ '\\' , FOREGROUND_YELLOW },{ '|' ,FOREGROUND_YELLOW } ,{ '/' ,FOREGROUND_YELLOW },{ 0 ,BACKGROUND_BLACK },
		{ 0 ,BACKGROUND_BLACK },{ '/' , FOREGROUND_YELLOW },{ '|' ,FOREGROUND_YELLOW },{ '\\' ,FOREGROUND_YELLOW },{ 0 ,BACKGROUND_BLACK },
	},
	{
		{ 0 ,FOREGROUND_RED },{ '\\' , FOREGROUND_BRIGHT_RED },{ 0 ,FOREGROUND_BRIGHT_RED } ,{ '/' ,FOREGROUND_BRIGHT_RED },{ 0 ,FOREGROUND_BRIGHT_RED },
		{ 0 ,FOREGROUND_RED },{ '/' , FOREGROUND_BRIGHT_RED },{ 0 ,FOREGROUND_BRIGHT_RED },{ '\\' ,FOREGROUND_BRIGHT_RED },{ 0 ,FOREGROUND_BRIGHT_RED },
	},
};
*/

const int ENEMY_SPRITE_WIDTH = 13; // maximum width for the enemy sprite
const int ENEMY_SPRITE_HEIGHT = 10; // maximum height for the enemy sprite


CHAR_INFO EnemyShipSprite0[ENEMY_SPRITE_ANIMATION_FRAMES][ENEMY_SPRITE_WIDTH * ENEMY_SPRITE_HEIGHT] = // Enemy sprite, this is used for creating the sprite
{
	{ // this is for the first animation for the enemy ship
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_GREEN } ,{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN } ,{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN } ,{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN } ,{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ',BACKGROUND_BLACK},{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN } ,{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN } ,{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_GREEN } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_GREEN } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_GREEN } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_GREEN },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		},
	{// second animation for the enemy sprite and you can change the colour of sprite from here
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_PINK } ,{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK } ,{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK } ,{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK } ,{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ',BACKGROUND_BLACK},{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK } ,{ ' ' ,BACKGROUND_BRIGHT_BLUE },{ ' ' ,BACKGROUND_BRIGHT_BLUE },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BRIGHT_BLUE },{ ' ' ,BACKGROUND_BRIGHT_BLUE } ,{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK } ,{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK } ,{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_PINK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_PINK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_PINK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		},
	{// when an enemy ship is destroyed this animations shows up
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
	},
	{// when an enemy ship is destroyed this animations shows up
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
	},
};


CHAR_INFO EnemyShipSprite1[ENEMY_SPRITE_ANIMATION_FRAMES][ENEMY_SPRITE_WIDTH * ENEMY_SPRITE_HEIGHT] =   //sprite number 2 for enemyship
{
	{                  // this is for the first animation for the enemy ship
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ',BACKGROUND_BLACK},{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
	},
	{                // second animation for the enemy sprite and you can change the colour of sprite from here
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ',BACKGROUND_BLACK},{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
	},
	{                  // when an enemy ship is destroyed this animations shows up
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_YELLOW },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_YELLOW } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_YELLOW },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
	},
	{                    // when an enemy ship is destroyed this animations shows up
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
		{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BRIGHT_RED } ,{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK } ,{ ' ' ,BACKGROUND_BRIGHT_RED },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },{ ' ' ,BACKGROUND_BLACK },
	},
};





EnemyShip::EnemyShip() 
:m_bInitialised(false)
,m_AnimationTimer(0.0f)
,m_Active(true)
,m_FireRate(0)
,m_ScoreValue(0)
{
}

EnemyShip::~EnemyShip()
{
}


void EnemyShip::Initialise(Vector2& position, int fireRate, int sprite, int scoreValue, float initialTime) // this is for setting the position, fire rate of the enemyship and score value of the ship and animation of the spirtes
{
	m_FireRate = fireRate;

	m_ScoreValue = scoreValue;

	m_AnimationTimer = initialTime;

	AnimatedSprite::Initialise(sprite == 2 ? &EnemyShipSprite0[0][0] : &EnemyShipSprite1[0][0], Vector3(ENEMY_SPRITE_WIDTH, ENEMY_SPRITE_HEIGHT, ENEMY_SPRITE_ANIMATION_FRAMES));

	Vector2 startPosition(  position.x + (AnimatedSprite::GetSize().x * 20) , position.y - (AnimatedSprite::GetSize().y / 18));
	SetPosition(startPosition);
	

	m_bInitialised = true;
}

bool EnemyShip::Update(float deltaTime) //updating the movement of the enemies so they move left side of the screen
{
	if (!m_bInitialised || !m_Active)
		return false;
		
	MoveLeft();

	m_AnimationTimer += deltaTime;
	if (m_AnimationTimer >= 1.0f)
	{
		if (GetAnimationFrame() == 2)
		{
			m_AnimationTimer -= 0.15f;
			SetAnimationFrame(3);
		}
		else if (GetAnimationFrame() == 3)
		{
			m_Active = false;
		}
		else
		{
			m_AnimationTimer -= 1.0f;
			SetAnimationFrame(GetAnimationFrame() == 0 ? 1 : 0);
		}
		
		return ShouldFire();
	}

	return false;
}

bool EnemyShip::ShouldFire() // random function used here so the enemy fire at random times in the game
{
	bool shouldFire = false;
	int chance = rand() % 100;

	if (m_FireRate > chance)
	{
		shouldFire = true;
	}

	return shouldFire;
}

void EnemyShip::Render(ASCIIRenderer* pRenderer) // this function allows to show up the enemies on the screen
{
	if (!m_bInitialised || !m_Active)
		return;

	AnimatedSprite::Render(pRenderer);
}

void EnemyShip::MoveLeft() // this function allows the the enemy to move left side of the screen
{
	SetPosition(Vector2(GetPosition().x - MOVEMENT_AMMOUNT, GetPosition().y));
}



void EnemyShip::Explode()  // function for exploding the enemy or the missile or playership
{
	if (GetAnimationFrame() < 2)
	{
		
		m_AnimationTimer = 0.85f;
		SetAnimationFrame(2);
	}
	m_Active = false;
}


