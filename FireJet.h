#ifndef _FireJet_H_
#define _FireJet_H_

#include "../../Core/Renderer/Sprite.h"

class ASCIIRenderer;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class FireJet : public Sprite
{
public:

	FireJet();
	~FireJet();

	void Initialise(Vector2& position, int UpKey, int DownKey);  // intialisng the player position and setting keyboard input to move
	void Update();
	void Render(ASCIIRenderer* pRenderer);
	
	
private:
	// keyboard inputs to move the sprite
	void MoveUp();
	void MoveDown();
	int m_UpKey;
	int m_DownKey;
	
	bool UpKeyPressed();
	bool DownKeyPressed();

	bool m_bInitialised;
	
};

#endif
