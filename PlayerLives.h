#ifndef _PlayerLives_H_
#define _PlayerLives_H_

#include "../../Core/Renderer/AnimatedSprite.h"

class ASCIIRenderer;

extern const int SCREEN_WIDTH;

const int Health = 3;
const int Health_WIDTH = 8;
const int Health_HEIGHT = 10;



class PlayerLives : public AnimatedSprite
{
public:

	PlayerLives();
	~PlayerLives();

	void Initialise(Vector2& position);
	void Update(float deltaTime);
	void Render(ASCIIRenderer* pRenderer);

	void SetHealthValue(int value);

private:

	bool m_bInitialised;

};

#endif
