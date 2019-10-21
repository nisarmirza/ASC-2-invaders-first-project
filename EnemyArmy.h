#ifndef _ENEMY_ARMY_H_
#define _ENEMY_ARMY_H_

#include "EnemyShip.h"

class ASCIIRenderer;
class Game;

const int NUM_INVADERS_PER_ROW = 1;
const int NUM_ROWS_OF_INVADERS = 4;
const int TOP_OF_PLAY_SCREEN = 10;

class EnemyArmy
{
public:
	EnemyArmy();
	~EnemyArmy();

	void Initialise(Game* pGame);
	void Update();
	void Render(ASCIIRenderer* pRenderer);

	bool Collides(Sprite& otherSprite);

	int GetScore() { int retVal = m_ScoreEarned; m_ScoreEarned = 0; return retVal; }
	int GetNumActiveEnemies();

	bool HasLanded();

private:

	bool ShouldChangeDirection();

	bool m_MovingLeft;

	EnemyShip m_EnemyShip[NUM_ROWS_OF_INVADERS][NUM_INVADERS_PER_ROW];

	float m_UpdateTimer;

	Game* m_pGame;

	int m_ScoreEarned;

};

#endif
