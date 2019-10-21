#ifndef _GAME_H_
#define _GAME_H

#include "GameStates.h"
#include "GameObjects\FireJet.h"
#include "GameObjects/EnemyShip.h"
#include "GameObjects\Rockets.h"
#include "../Core/Renderer/Sprite.h"
#include "GameObjects\ScoreDisplay.h"
#include "GameObjects/PlayerLives.h"
#include <vector>

class ASCIIRenderer;

class Game : public AnimatedSprite
{
public:
	Game();
	~Game();

	void Initialise();

	void Run();

	void AddEnemyMissile(Rockets* pMissile);
	const int TOP_OF_PLAY_SCREEN = 15;
private:

	void InitialiseRenderer();
	void InitialiseMainMenu();
	void InitialiseMainMenu2();
	void InitialiseGame();
	void InitialiseEndScreens();
	void InitialiseEnemies();
	



	void Update();
	void UpdateScoreDisplay();
	void UpdateHealthDisplay();
	



	void Render();
	void RenderEnemiesARMY();
    void RenderMainMenu();
	void RenderMainMenu2();
	void RenderGame();
	void RenderWinScreen();
	void RenderLoseScreen();
	void RenderNextRound();
	void RenderEnemyMissiles();
	void RenderScore();
	void RenderHealth();

	


	void minusHealth();
	

	



	void Update_SELECT_OPTIONS();
	void Updating_MENU_ITEMS();
	void UpdateMainMenu();
	void UpdateMainMenu2();
	void UpdateGame();
	void UpdatePlayerMissiles();
	void UpdateEnemyMissiles();
	void UpdateEndGameScreens();
	
	
	void CheckWinConditions();
	void FireMissile();



	
	
	ASCIIRenderer* m_pRenderer;

	E_GAME_STATE m_GameState;

	bool m_bInitialised;
	bool m_bExitApp;
	
	
	int m_Score;
	int m_Health_For_Player;
	int activeEnemies = 0;

	FireJet m_PlayerShip; // FireJet (the player)
	EnemyShip m_EnemyShip[5]; // The EnemyShip for spawing enemies from right side of the screen

	Rockets* m_Missile; //player missile
	std::vector<Rockets*> m_EnemyMissiles;

	ScoreDisplay m_ScoreDigit[4];
	ScoreDisplay m_PlayerLIFE[4];
	
	//FireJet m_HealthValue;
	Sprite m_GameTitle;
	Sprite m_GameTitle2;
	
	int m_MainMenuCounter;
	int m_MainMenuCounter2;
	int m_NextRoundCounter;

	Sprite m_GameOverTitle;
	int m_EndScreenCounter;
	char Decision = 'y';
	Sprite m_YouWinTitle;
	Sprite m_NextRoundTitle;
	int NUM_OF_ENEMY = 0;
	
};


#endif
