#ifndef _Rockets_H_
#define _Rockets_H_

#include "../../Core/Renderer/Sprite.h"

class ASCIIRenderer;

const int MISSILE_SPEED = 5;

class Rockets : public Sprite
{
public:

	Rockets();
	~Rockets();

	void Initialise(Vector2& position, Vector2& velocity);
	void Update();
	void Render(ASCIIRenderer* pRenderer);
	void Explode();

	void SetActive(bool active = true) { m_Active = active; };
	bool Active() { return m_Active; }

private:

	Vector2 m_Velocity;

	bool m_bInitialised;
	bool m_Active;

};

#endif
