#include "EnemyArmy.h"
#include <iostream>
#include "../Game.h"

float deltaTime = 1.0f / 30.0f;

 int ENEMY_SPACING_X = 5;
 int NEW_ENEMY_SPACING_X = 8;
 int ENEMY_SPACING_Y = 5;

EnemyArmy::EnemyArmy()
	:m_UpdateTimer(0.0f)
	, m_pGame(NULL)
	, m_ScoreEarned(0)
{

}

EnemyArmy::~EnemyArmy()
{

}

void EnemyArmy::Initialise(Game* pGame)
{
	m_pGame = pGame;
	deltaTime = 1.0f / 10.0f;

	m_MovingLeft = true;

	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			//m_EnemyShip[i][j].Initialise(Vector2(4 + j * 7, 2 + i * 4), 5/*, (i+1.0f) * 0.3f*/ );
			m_EnemyShip[i][j].Initialise(Vector2(ENEMY_SPACING_X + j * (30 + ENEMY_SPACING_X), (TOP_OF_PLAY_SCREEN - 4)+ ENEMY_SPACING_Y + i * (20 + ENEMY_SPACING_Y)), 10, i, (NUM_ROWS_OF_INVADERS + i ) * 200/*, (i+1.0f) * 0.3f*/);
		}
	}
}

void EnemyArmy::Update()
{
	//update enemy movement
	m_UpdateTimer += deltaTime;

	if (m_UpdateTimer >= 1.0f)
	{
		m_UpdateTimer -= 1.0f;

		if (ShouldChangeDirection())
		{
			//change direction
			m_MovingLeft = !m_MovingLeft;

			//increase speed!
			deltaTime += 0.01f;

			for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
			{
				for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
				{
					m_EnemyShip[i][j].MoveDown();
				}
			}
		}
		else if (m_MovingLeft)
		{
			for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
			{
				for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
				{
					m_EnemyShip[i][j].MoveLeft();
				}
			}
		}
		else
		{
			for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
			{
				for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
				{
					m_EnemyShip[i][j].MoveUp();
				}
			}
		}

	}

	//update enemy animations
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			if (m_EnemyShip[i][j].Update(deltaTime))
			{
				Rockets* pMissile = new Rockets();
				pMissile->Initialise(Vector2(m_EnemyShip[i][j].GetPosition().x + (m_EnemyShip[i][j].GetSize().x / 2.0f), m_EnemyShip[i][j].GetPosition().y + 5), Vector2(-MISSILE_SPEED, 0));
				m_pGame->AddEnemyMissile(pMissile);
			}
		}
	}
}

bool EnemyArmy::ShouldChangeDirection()
{
	bool changeDirection = false;

	if (m_MovingLeft)
	{
		for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
		{
			for (int j = NUM_INVADERS_PER_ROW - 1; j >= 0; j--)
			{
				//check the right most ship in this row
				if (m_EnemyShip[i][j].Active())
				{
					if ((m_EnemyShip[i][j].GetPosition().x + (m_EnemyShip[i][j].GetSize().x) >= SCREEN_WIDTH ) )
					{
						changeDirection = true;
						break;
					}
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
		{
			for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
			{
				//check the left most ship in this row
				if (m_EnemyShip[i][j].Active())
				{
					if (  (m_EnemyShip[i][j].GetPosition().x ) <= 0 )
					{
						changeDirection = true;
						break;
					}
				}
			}
		}
	}

	return changeDirection;
}

bool EnemyArmy::HasLanded()
{
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 1 ; j < NUM_INVADERS_PER_ROW + 1; j++)
		{
			//check the right most ship in this row
			if (m_EnemyShip[i][j].Active())
			{
				if ((m_EnemyShip[i][j].GetPosition().x   <= 0) )
				{
					return true;
				}
			}
		}
	}

	return false;
}

void EnemyArmy::Render(ASCIIRenderer* pRenderer)
{
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			m_EnemyShip[i][j].Render(pRenderer);
		}
	}
}


bool EnemyArmy::Collides(Sprite& otherSprite)
{
	bool collision = false;
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			if (m_EnemyShip[i][j].Active() && otherSprite.Collides(m_EnemyShip[i][j].GetCurrentSprite()))
			{
				collision = true;
				m_ScoreEarned += m_EnemyShip[i][j].GetScoreValue();
				
				m_EnemyShip[i][j].Explode();
			}
		}
	}

	return collision;
}

int EnemyArmy::GetNumActiveEnemies()
{
	int activeEnemies = 0;
	for (int i = 0; i < NUM_ROWS_OF_INVADERS; i++)
	{
		for (int j = 0; j < NUM_INVADERS_PER_ROW; j++)
		{
			if (m_EnemyShip[i][j].Active())
			{
				activeEnemies++;
				
			}
		}
	}

	return activeEnemies;
}
