#include "Rockets.h"
#include "../../Core/Renderer/ConsoleColours.h"
#include <cstdlib>


const int MaxPlayerRocketTypes = 5;  // maximum number of rockets, types of rocket (different colour for each rocket)
CHAR_INFO PlayerRockets[MaxPlayerRocketTypes][4] =// setting the sprite for the rocket e.g. thier color and looks 
{
	{
		{ ' ' , BACKGROUND_PURPLE },
		{ '- ', BACKGROUND_PURPLE  },
		{ ' ', BACKGROUND_PURPLE  },
	},
	{
		{ ' ' , BACKGROUND_TURQOISE },
		{ '- ', BACKGROUND_TURQOISE  },
		{ ' ', BACKGROUND_TURQOISE  },
	},
	{
		{ '- ' , BACKGROUND_MUSTARD },
		{ '-' , BACKGROUND_MUSTARD  },
		{ '- ', BACKGROUND_MUSTARD  },
	},
	{
		{ ' ' , BACKGROUND_BRIGHT_RED },
		{ '/ ', BACKGROUND_BRIGHT_RED  },
		{ ' ', BACKGROUND_BRIGHT_RED  },
	},
	{
		{ '/ ' , BACKGROUND_YELLOW },
		{ '/ ', BACKGROUND_YELLOW  },
		{ '/ ', BACKGROUND_YELLOW  },
	},
};

CHAR_INFO EnemyMissileSprite[] = // enemy rocket sprite
{
	{ ' ', BACKGROUND_BRIGHT_RED },
	{ ' ', BACKGROUND_BRIGHT_RED },
	{ ' ', BACKGROUND_BRIGHT_RED },
};

Rockets::Rockets()
:m_bInitialised(false)
, m_Active(0)
{

}

Rockets::~Rockets()
{

}

CHAR_INFO* SelectRandomRocket() // this function for selecting random rocket when ever we fire. which means everytime we fire different selected colour will be outputted
{
	int random = rand() % MaxPlayerRocketTypes;

	return PlayerRockets[random];
}

void Rockets::Initialise(Vector2& position, Vector2& velocity) // setting the position of the rocket and which position the rocket will fire
{
 	m_Velocity = velocity;

	Sprite::Initialise(m_Velocity.x > 0.0f ? SelectRandomRocket() : EnemyMissileSprite, Vector2(3, 1));

	Vector2 startPosition(  (Sprite::GetSize().x / 10) + position.x  , position.y - (Sprite::GetSize().y / 5)  );
	SetPosition(startPosition);

	m_bInitialised = true;
}



void Rockets::Update()  //updating the movement of the rocket so they fire horizontal towards the enemy and enemy fire towards the player.
{
	if (!m_bInitialised || !m_Active)
		return;

 	SetPosition(Vector2(GetPosition().x + m_Velocity.x,GetPosition().y  + m_Velocity.y ));

}

void Rockets::Render(ASCIIRenderer* pRenderer)       // this function allows the rocket to appear 
{
	if (!m_bInitialised || !m_Active)
		return;
	
	
	Sprite::Render(pRenderer);
	
}

void Rockets::Explode() // this function is used when the the rockets collide with where enemy or player so they explode and dont go thorough the pass the enemy or player.
{
	m_Active = false;
}

