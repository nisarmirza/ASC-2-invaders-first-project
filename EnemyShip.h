#ifndef _EnemyShip_H_
#define _EnemyShip_H_

#include "../../Core/Renderer/AnimatedSprite.h"

class ASCIIRenderer;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
const int MOVEMENT_AMMOUNT = 1;
const int ENEMY_SPRITE_ANIMATION_FRAMES = 4;

class EnemyShip : public AnimatedSprite
{
public:
	
	EnemyShip();
	~EnemyShip();
	
	void Initialise(Vector2& position, int fireRate, int sprite, int scoreValue, float initialTime = 0.0f);
	bool Update(float deltaTime);
	void Render(ASCIIRenderer* pRenderer);
	
	void Explode();

	bool Active() { return m_Active; }
	void setActive() { m_Active = true; }
	void ResetAnimation() { SetAnimationFrame(0); }
	void MoveLeft();

	int GetScoreValue() { return m_ScoreValue; };
	bool ShouldFire();

private:

	

	

	bool m_bInitialised;

	float m_AnimationTimer;
	bool m_Active;

	int m_FireRate;

	int m_ScoreValue;

};

#endif
