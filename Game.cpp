#include "Game.h"
#include <windows.h>
#include <iostream>
#include "../Core/Utils.h"
#include "../Core/Renderer/ASCIIRenderer.h"

using namespace std;
const int SCREEN_WIDTH = 300;  // screen width of the game x axis
const int SCREEN_HEIGHT = 100; // screen height of the game y axis
const int ENEMY_SPACING_X = 1; // enemy spacing between each enemy along horizontal axis
const int ENEMY_SPACING_Y = 1; // enemy spacing between each enemy along vertical axis

#define VK_UP		0x26  // Key defined to be used in the game for e.g. up key for moving up
#define VK_DOWN		0x28// Key defined to be used in the game for e.g. down key for moving down
#define VK_SPACE	0x20  // Key defined to be used in the game for e.g. space key for Firing Missile
#define VK_BACK     0x08// Key defined to be used in the game for e.g. backspace key for exiting the game



// this is for displaying "THE LAST" on the screen
char* GameTitleSprite = "                                                                                                                                                                                                                                                 TTTTTTTTTTTTTTTTTTTTTTTT  HHH               HHH   EEEEEEEEEEEEEEEEEEEEEEEEEE          LLL                       AAAAAAAAAAAAAAAAA SSSSSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTTT                                                                T::::::::::::::::::::::T  H:H               H:H   E::::::::::::::::::::::::E          L:L                       A:::::::::::::::A SSSSSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTTT                                                                TTTTTTTTTTTTTTTTTTTTTTTT  H:H               H:H   EEEEEEEEEEEEEEEEEEEEEEEEEE          L:L                       AAAAAAAAAAAAAAAAA SSSSSSSSSSSSSSSSSS TTTTTTTTTTTTTTTTTTTTTTTT                                                                          TTT             H:H               H:H   E:E                                 L:L                       A:A           A:A S:S                          T:T                                                                                     TTT             H:H               H:H   E:E                                 L:L                       A:A           A:A S:S                          T:T                                                                                     TTT             H:H               H:H   E:E                                 L:L                       A:A           A:A S:S                          T:T                                                                                     TTT             H:H               H:H   E:E                                 L:L                       A:A           A:A S:S                          T:T                                                                                     TTT             H:H:::::::::::::::H:H   E::::::::::::::::::::::::E          L:L                       A:A           A:A S:S                          T:T                                                                                     TTT             H:H:::::::::::::::H:H   E::::::::::::::::::::::::E          L:L                       A:AAAAAAAAAAAAA:A S::::::::::::::SSS           T:T                                                                                     TTT             H:H:::::::::::::::H:H   E:E                                 L:L                       A:AAAAAAAAAAAAA:A S::::::::::::::SSS           T:T                                                                                     TTT             H:H               H:H   E:E                                 L:L                       A:A           A:A                SSS           T:T                                                                                     TTT             H:H               H:H   E:E                                 L:L                       A:A           A:A                SSS           T:T                                                                                     TTT             H:H               H:H   E:E                                 L:L                       A:A           A:A                SSS           T:T                                                                                     TTT             H:H               H:H   EEEEEEEEEEEEEEEEEEEEEEEEEE          LLLLLLLLLLLLLLLLLLLLLLLLL A:A           A:A SSSSSSSSSSSSSSSSSS           T:T                                                                                     TTT             H:H               H:H   E::::::::::::::::::::::::E          L:::::::::::::::::::::::L A:A           A:A SSSSSSSSSSSSSSSSSS           T:T                                                                                     TTT             H:H               H:H   EEEEEEEEEEEEEEEEEEEEEEEEEE          LLLLLLLLLLLLLLLLLLLLLLLLL A:A           A:A SSSSSSSSSSSSSSSSSS           T:T                                                   ";
// this is for displaying "FIRE JET" on the screen
char* GameTitleSprite2 = "                                                                                                                                                                                                                                                          FFFFFFFFFFFFFFFFFFFFFFFF  III  RRRRRRRRRRRRRRRRRRRRR   EEEEEEEEEEEEEEEEEEEEEEEEEE                           JJJ  EEEEEEEEEEEEEEEEE  TTTTTTTTTTTTTTTTTTTTTTTT                                                                                 FFFFFFFFFFFFFFFFFFFFFFFF  III  RRRRRRRRRRRRRRRRRRRRR   EEEEEEEEEEEEEEEEEEEEEEEEEE                           JJJ  EEEEEEEEEEEEEEEEE  TTTTTTTTTTTTTTTTTTTTTTTT                                                                                 FFF                       III  RRR               RRR   EEEEEEEEEEEEEEEEEEEEEEEEEE                           JJJ  EEEEEEEEEEEEEEEEE  TTTTTTTTTTTTTTTTTTTTTTTT                                                                                 FFF                       III  RRR               RRR   EEE                                                  JJJ  EEE                          TTT                                                                                            FFF                       III  RRR               RRR   EEE                                                  JJJ  EEE                          TTT                                                                                            FFF                       III  RRR               RRR   EEE                                                  JJJ  EEE                          TTT                                                                                            FFF                       III  RRR               RRR   EEE                                                  JJJ  EEE                          TTT                                                                                            FFF                       III  RRR               RRR   EEE                                                  JJJ  EEE                          TTT                                                                                            FFFFFFFFFFFFFFFFFFFFFFFF  III  RRRRRRRRRRRRRRRRRRRRR   EEEEEEEEEEEEEEEEEEEEEEEEEE                           JJJ  EEEEEEEEEEEEEEEEE            TTT                                                                                            FFFFFFFFFFFFFFFFFFFFFFFF  III  RRRRRRRRRRRRRRRRRRRRR   EEEEEEEEEEEEEEEEEEEEEEEEEE                           JJJ  EEEEEEEEEEEEEEEEE            TTT                                                                                            FFF                       III  RRR                     EEE                                                  JJJ  EEE                          TTT                                                                                            FFF                       III  RRR RRR                 EEE                                                  JJJ  EEE                          TTT                                                                                            FFF                       III  RRR    RRR              EEE                               JJJ                JJJ  EEE                          TTT                                                                                            FFF                       III  RRR       RRR           EEE                               JJJ                JJJ  EEE                          TTT                                                                                            FFF                       III  RRR          RRR        EEEEEEEEEEEEEEEEEEEEEEEEEE        JJJJJJJJJJJJJJJJJJJJJJ  EEEEEEEEEEEEEEEEE            TTT                                                                                            FFF                       III  RRR             RRR     EEEEEEEEEEEEEEEEEEEEEEEEEE        JJJJJJJJJJJJJJJJJJJJJJ  EEEEEEEEEEEEEEEEE            TTT                                                                                          ";
// this is for displaying "GAME OVER" on the screen
char* GameOverSprite = "        GGGGGGGGGGGGG               AAA               MMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE          OOOOOOOOO     VVVVVVVV           VVVVVVVVEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRRRRRRR        GGG::::::::::::G              A:::A              M:::::::M             M:::::::ME::::::::::::::::::::E        OO:::::::::OO   V::::::V           V::::::VE::::::::::::::::::::ER::::::::::::::::R     GG:::::::::::::::G             A:::::A             M::::::::M           M::::::::ME::::::::::::::::::::E      OO:::::::::::::OO V::::::V           V::::::VE::::::::::::::::::::ER::::::RRRRRR:::::R   G:::::GGGGGGGG::::G            A:::::::A            M:::::::::M         M:::::::::MEE::::::EEEEEEEEE::::E     O:::::::OOO:::::::OV::::::V           V::::::VEE::::::EEEEEEEEE::::ERR:::::R     R:::::R G:::::G       GGGGGG           A:::::::::A           M::::::::::M       M::::::::::M  E:::::E       EEEEEE     O::::::O   O::::::O V:::::V           V:::::V   E:::::E       EEEEEE  R::::R     R:::::RG:::::G                        A:::::A:::::A          M:::::::::::M     M:::::::::::M  E:::::E                  O:::::O     O:::::O  V:::::V         V:::::V    E:::::E               R::::R     R:::::RG:::::G                       A:::::A A:::::A         M:::::::M::::M   M::::M:::::::M  E::::::EEEEEEEEEE        O:::::O     O:::::O   V:::::V       V:::::V     E::::::EEEEEEEEEE     R::::RRRRRR:::::R G:::::G    GGGGGGGGGG        A:::::A   A:::::A        M::::::M M::::M M::::M M::::::M  E:::::::::::::::E        O:::::O     O:::::O    V:::::V     V:::::V      E:::::::::::::::E     R:::::::::::::RR  G:::::G    G::::::::G       A:::::A     A:::::A       M::::::M  M::::M::::M  M::::::M  E:::::::::::::::E        O:::::O     O:::::O     V:::::V   V:::::V       E:::::::::::::::E     R::::RRRRRR:::::R G:::::G    GGGGG::::G      A:::::AAAAAAAAA:::::A      M::::::M   M:::::::M   M::::::M  E::::::EEEEEEEEEE        O:::::O     O:::::O      V:::::V V:::::V        E::::::EEEEEEEEEE     R::::R     R:::::RG:::::G        G::::G     A:::::::::::::::::::::A     M::::::M    M:::::M    M::::::M  E:::::E                  O:::::O     O:::::O       V:::::V:::::V         E:::::E               R::::R     R:::::R G:::::G       G::::G    A:::::AAAAAAAAAAAAA:::::A    M::::::M     MMMMM     M::::::M  E:::::E       EEEEEE     O::::::O   O::::::O        V:::::::::V          E:::::E       EEEEEE  R::::R     R:::::R  G:::::GGGGGGGG::::G   A:::::A             A:::::A   M::::::M               M::::::MEE::::::EEEEEEEE:::::E     O:::::::OOO:::::::O         V:::::::V         EE::::::EEEEEEEE:::::ERR:::::R     R:::::R   GG:::::::::::::::G  A:::::A               A:::::A  M::::::M               M::::::ME::::::::::::::::::::E      OO:::::::::::::OO           V:::::V          E::::::::::::::::::::ER::::::R     R:::::R     GGG::::::GGG:::G A:::::A                 A:::::A M::::::M               M::::::ME::::::::::::::::::::E        OO:::::::::OO              V:::V           E::::::::::::::::::::ER::::::R     R:::::R        GGGGGG   GGGGAAAAAAA                   AAAAAAAMMMMMMMM               MMMMMMMMEEEEEEEEEEEEEEEEEEEEEE          OOOOOOOOO                 VVV            EEEEEEEEEEEEEEEEEEEEEERRRRRRRR     RRRRRRR";
// this is for displaying "YOU WIN" on the screen
char* YouWinSprite = "YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNNY:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN:::::::N       N::::::NY:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN::::::::N      N::::::NY::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::NYYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::N       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::N    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W           I::::::::IN::::::N        N::::::N    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNN";








Game::Game()
:m_pRenderer(NULL)
, m_GameState(E_GAME_STATE_MAIN_MENU)
, m_bInitialised(false)
, m_bExitApp(false)
, m_Score(0)
, m_Health_For_Player(3)
, m_MainMenuCounter(0)
, m_MainMenuCounter2(0)
, m_EndScreenCounter(0)
, m_Missile(nullptr)
{
}

Game::~Game()
{
	SAFE_DELETE_PTR(m_pRenderer);
}

void Game::Initialise()  // initialising all the elements in the game.h so they can render in the game if we do not initialise the element they cannot be seen in the game or they wont be called when debugging.
{
	InitialiseRenderer();

	Update_SELECT_OPTIONS();

	InitialiseMainMenu();

	InitialiseMainMenu2();

	InitialiseGame();

	InitialiseEnemies();

	InitialiseEndScreens();

	m_bInitialised = true;
}

void Game::InitialiseRenderer() // this helps in setting the width and height for screen
{
	m_pRenderer = new ASCIIRenderer();

	m_pRenderer->Initialise(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Game::InitialiseMainMenu() // this shows the "The Last" on screen and initialising its size and position
{
	//Main Menu
	Vector2 titleSize(237, 17);  // Setting the width and height of the sprite for "THE LAST" on the screen
	m_GameTitle.Initialise(GameTitleSprite, FOREGROUND_WHITE, titleSize);

	Vector2 startPosition(50, 10);
	m_GameTitle.SetPosition(startPosition);
}
void Game::InitialiseMainMenu2() // this shows the "fire jet" on screen and initialising its size and position
{
	//Main Menu
	Vector2 titleSize(237, 17); // Setting the width and height of the sprite for "FIRE JET" on the screen 
	m_GameTitle2.Initialise(GameTitleSprite2, FOREGROUND_WHITE, titleSize);

	Vector2 startPosition(50, 30); // setting up the position of the sprite e.g. where to place it on the screen (centre, right or left)
	m_GameTitle2.SetPosition(startPosition);

}
void Game::InitialiseGame()
{
	//Game
	m_PlayerShip.Initialise(Vector2(SCREEN_WIDTH / 8, SCREEN_HEIGHT - 8), VK_UP, VK_DOWN);

	for (int i = 0; i < 4; i++)
	{
		m_ScoreDigit[i].Initialise(Vector2(7 + (i * 10), 7)); // position for the score display 
	}

	for (int i = 0; i < 4; i++)
	{
		m_PlayerLIFE[i].Initialise(Vector2(-275 + (i * 10), 7)); // position for the health display
	}
}

void Game::InitialiseEndScreens() // this is for setting the end screen "YOU WIN" or "YOU LOSE" position.
{
	//End Game Screen
	Vector2 gameOverTitleSize(200, 16);// Setting the width and height of the sprite for "YOU LOSE" on the screen 
	m_GameOverTitle.Initialise(GameOverSprite, FOREGROUND_WHITE, gameOverTitleSize);

	Vector2 gameOverPosition(25, 37);
	m_GameOverTitle.SetPosition(gameOverPosition); // setting up the position of the sprite e.g. where to place it on the screen (centre, right or left)
	

	Vector2 youWinTitleSize(143, 16);  // Setting the width and height of the sprite for "YOU WIN" on the screen 
	m_YouWinTitle.Initialise(YouWinSprite, FOREGROUND_WHITE, youWinTitleSize);

	Vector2 youWinPosition(53, 37);
	m_YouWinTitle.SetPosition(youWinPosition); // setting up the position of the sprite e.g. where to place it on the screen (centre, right or left)
}


void Game::InitialiseEnemies() // setting the position for the enemies
{
	//for loop  to loop through array of ships
		   //if array block is empty AND counter is less tahn 50 then initialise enemy .
			   // increase counter by 1
				   //If enemy is dead, reset it to its start point.
	
	for (int i = 0; i < 5; i++)
	{
			m_EnemyShip[i].Initialise(Vector2((ENEMY_SPACING_X + i) + (NUM_OF_ENEMY  * (20 + ENEMY_SPACING_X)), (TOP_OF_PLAY_SCREEN - 4) + (ENEMY_SPACING_Y + i) + i * (10 + ENEMY_SPACING_Y)), 1, i + 1,  50/* (i+1.f) * 0.3f)*/);
			activeEnemies++;
			NUM_OF_ENEMY++;
	}
}


void Game::Update() //updaing the game for the main menu system, for going in game, exiting the game and loading the game.

{

	if (GetKeyState(VK_BACK) < 0) // when BACKSPACE is pressed the game will exit

	{
		m_bExitApp = true;
		return;
	}

	switch (m_GameState)
	{
	case E_GAME_STATE_MAIN_MENU:  // this shows the main menu where you have options to select to what to do next (go in the game or exit out of the game)
	{

		UpdateMainMenu();
		UpdateMainMenu2();
		Updating_MENU_ITEMS();
	}
	break;
	case E_GAME_STATE_IN_GAME: // this takes you in the game
	{
		UpdateGame();
	}
	break;
	case E_GAME_STATE_WIN_GAME: //fall through
	case E_GAME_STATE_LOSE_GAME:
	{
		UpdateEndGameScreens();
	}
	break;
	default:
	{
	}
	}
}

void Game::UpdateMainMenu() // helping the menu system to work, timer is on so when the user enters 'Y' to play the game after some time the game starts after the loading screen of the game which displays the game title.
{
	m_MainMenuCounter++;

	if (m_MainMenuCounter > 90)
	{
		m_MainMenuCounter = 0;
		m_GameState = E_GAME_STATE_IN_GAME;
	}
}
void Game::UpdateMainMenu2()
{
	m_MainMenuCounter2++;

	if (m_MainMenuCounter2 > 90)
	{
		m_MainMenuCounter2 = 0;
		m_GameState = E_GAME_STATE_IN_GAME;
	}
}

void Game::UpdateGame() // this fucntions helps updating all the elements in the game e.g. movement of the enemies, firing missile by playership, spawning enemies and etc.
{
	if (GetKeyState(VK_SPACE) < 0)
	{
	if (!m_Missile)
	{
		FireMissile();
		new Rockets;
	}
	}
	m_PlayerShip.Update();
	for (int i = 0; i < 5; i++) // setting 50 enemies for appearing in the game.
	{
	if (!m_EnemyShip[i].Active() && NUM_OF_ENEMY < 50)
	{
		m_EnemyShip[i].SetPosition((ENEMY_SPACING_X + i) + (NUM_OF_ENEMY  * (20 + ENEMY_SPACING_X)), (TOP_OF_PLAY_SCREEN - 4) + (ENEMY_SPACING_Y + i) + i * (10 + ENEMY_SPACING_Y));
		m_EnemyShip[i].ResetAnimation();
		m_EnemyShip[i].setActive();
		activeEnemies++;
		NUM_OF_ENEMY++;
	}	
	m_EnemyShip[i].Update(1.0f / 30.0f);
	}
	for (int i = 0; i < 5; i++) 
	{
	if (m_EnemyShip[i].Active())
	{
		if (m_Health_For_Player <= 0)
		{
			m_EnemyShip[i].Explode();
			m_Health_For_Player -= 1;
		}
			
	}
	}
	for (int i = 0; i < 5; i++)
	{

		if (m_Missile) // missile colliding with enemyship will give the player some score
		{
			if (m_EnemyShip[i].Collides(*m_Missile))
			{
				m_EnemyShip[i].Explode();
				m_Missile->Explode();
				m_Score += m_EnemyShip[i].GetScoreValue();
				activeEnemies--;
			}
		}
	}

	for (int i = 0; i < 5; i++) // enemyship colliding with the playership or the screen will decrease 1 life from player.
	{
		if (m_EnemyShip[i].Active())
		{
			if (m_EnemyShip[i].Collides(m_PlayerShip) || m_EnemyShip[i].GetPosition().x <= 0)
			{
				m_EnemyShip[i].Explode();
				m_Health_For_Player -= 1;
			}
		}
	}

	UpdateEnemyMissiles();
	UpdatePlayerMissiles();
	UpdateScoreDisplay();
	CheckWinConditions();
	UpdateHealthDisplay();
	minusHealth();
}


void Game::FireMissile() // this options sets the width and height from where the missile will launch from playership sprite
{
	m_Missile = new Rockets();
	m_Missile->Initialise(Vector2(m_PlayerShip.GetPosition().y + (m_PlayerShip.GetSize().y * 0.5f), m_PlayerShip.GetPosition().y + 2), Vector2(MISSILE_SPEED, 0));
	m_Missile->SetActive(false);
	m_Missile->SetPosition(m_PlayerShip.GetPosition().x + (m_PlayerShip.GetSize().x * 0.5f), m_PlayerShip.GetPosition().y + 9);
	m_Missile->SetActive();
}

void Game::UpdatePlayerMissiles() // updating player missile so when they collide with the enemy or go out of bound they explode
{
	if (!m_Missile)
		return;
	if (!m_Missile->Active())
	{
		delete m_Missile;
		m_Missile = nullptr;
		return;
	}
	m_Missile->Update();

	if (m_Missile->GetPosition().x < 0 || m_Missile->GetPosition().x >= SCREEN_WIDTH)
	{
		m_Missile->Explode();
	}
}

void Game::UpdateEnemyMissiles() // updating player missile so when they collide with the enemy or go out of bound they explode
{
	for (int i = 0; i < m_EnemyMissiles.size(); i++)
	{
		m_EnemyMissiles[i]->Update();
	}
	for (int i = 0; i < m_EnemyMissiles.size(); i++)
	{
		
		{
			if (m_EnemyMissiles[i]->Active() && m_EnemyMissiles[i]->Collides(m_PlayerShip))
			{
				//hit the player
				m_EnemyShip[i].ShouldFire();
				m_EnemyMissiles[i]->Explode();
				m_Health_For_Player -= 1;
			}
		}
	}
}

void Game::Run() // this is function created for exiting the game
{
	while (!m_bExitApp)
	{
		Update();
		Render();
		Sleep(30);
	}
}

void Game::Updating_MENU_ITEMS() // menu system by which if you press 'Y' and enter you can enter in to the game and if you type 'N' you will exit the game
{
	m_MainMenuCounter++;
	if (Decision == 0)
	{
		system("pause");
	}
	else if (Decision == 'y')
	{
		if (m_MainMenuCounter > 60)
		{
			m_MainMenuCounter = 0;
			m_GameState = E_GAME_STATE_IN_GAME;
		}
	}
	else
	{
		m_bExitApp = true;
	}

	

}
void Game::Update_SELECT_OPTIONS() // this is the main menu which you will see when you click the debugging button.
{
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\                                                                               YYYYY                         8 Y   Y  8     T                  l                                 8 N    N  8     T           .oPYo.         o   o          "<< endl;
	cout << "                                                                                 8                           ' `b d'  '     8                  8                                 ' 8b   8  '     8           8.                 8                          " << endl;                                                                                                                        
	cout << "                                                                                 8                           ' `b d'  '     8                  8                                 ' 8b   8  '     8           8.                 8                          " << endl;
	cout << "	                                                                         8   o    o .oPYo. .oPYo.       `b'        o8P .oPYo.   .oPYo. 8 .oPYo. o    o   .oPYo. oPYo.      8`b  8       o8P .oPYo.   `boo   `o  o' o8  o8P                                      " << endl;                                     
	cout << "	                                                                         8   8    8 8    8 8oooo8        8          8  8    8   8    8 8 .oooo8 8    8   8    8 8  `'      8 `b 8        8  8    8   .P      `bd'   8   8								" << endl;
	cout << "                                                                                 8   8    8 8    8 8.            8          8  8    8   8    8 8 8    8 8    8   8    8 8          8  `b8        8  8    8   8       d'`b   8   8						    " << endl;                                   
	cout << "                                                                                 8   `YooP8 8YooP' `Yooo'        8          8  `YooP'   8YooP' 8 `YooP8 `YooP8   `YooP' 8          8   `8        8  `YooP'   `YooP' o'  `o  8   8" << endl;
	cout << "                                                                               ::..:::....8 8 ....::.....::::::::..:::::::::..::.....:::8 ....:..:.....::....8 :::.....:..:::::::::..:::..:::::::..::.....::::.....:..:::..:..::..:::     " << endl;
		cout << "	                                                                       ::::::::ooP'.8 ::::::::::::::::::::::::::::::::::::::::::8 ::::::::::::::::ooP'.::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  " << endl;
	
		
		
		
		cout << " \n\n\n\n\n\n\n\n\n\n\n                                                                o         .oPYo.                                                              .oPYo.      .oo .oPYo.  o   o .oPYo.  .oPYo.      .oo .oPYo. .oPYo.     o           .oPYo.  o    o  o ooooo " << endl;
		cout << "								8         8    8                                                              8   `8     .P 8 8    8  8.P 8 8       8    8     .P 8 8    8 8.         8           8.      `b  d'  8   8   " << endl;
		cout << "								8 odYo.   8      .oPYo. ooYoYo. .oPYo..   oPYo. oPYo. .oPYo. .oPYo. .oPYo.    o8YooP'   .P  8 8       o8ob'  `Yooo. o8YooP'   .P  8 8      `boo      o8P .oPYo.   `boo     `bd'   8   8" << endl;
		cout << "								8 8' `8   8   oo .oooo8 8' 8  8 8oooo8   8    8 8  `' 8oooo8 Yb..    Yb..     8   `b   oPooo8 8       8  `b     `8  8        oPooo8 8      .P         8  8    8   .P       .PY.   8   8" << endl;
		cout << "								8 8   8   8    8 8    8 8  8  8 8.       8    8 8     8.       'Yb.   'Yb.    8    8  .P    8 8    8  8   8      8  8       .P    8 8    8 8          8  8    8   8       .P  Y.  8   8" << endl;
		cout << "								8 8   8   `YooP8 `YooP8 8  8  8 `Yooo'   8YooP' 8     `Yooo' `YooP' `YooP'    8oooP' .P     8 `YooP'  8   8 `YooP'  8      .P     8 `YooP' `YooP'     8  `YooP'   `YooP' .P    Y. 8   8" << endl;
		cout << "                                                              ::....::..:::....8 : ..... : .. : .. ::: : 8 .... : ..:::: : .....::.....::.....::::...... : ..:::: : .. : .....::..::.. : .....::..:::: : ..:::: : .. : .....::::::::::::::::::::::::::::: :" << endl;
		cout << "                                                              :::::::::::::: : 8 ::::::::::::::::::::::::8 :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: : " << endl;
	cin >> Decision;

}

void Game::UpdateScoreDisplay() // this fucntion help score update on the game screen.
{
	for (int i = 0; i < 4; i++)
	{
		m_ScoreDigit[i].Update(0.0f);
	}

	int ScoreValues[4];

	ScoreValues[3] = m_Score > 9999 ? 9 : m_Score % 10;
	ScoreValues[2] = m_Score > 9999 ? 9 : m_Score / 10 % 10;
	ScoreValues[1] = m_Score > 9999 ? 9 : m_Score / 100 % 10;
	ScoreValues[0] = m_Score > 9999 ? 9 : m_Score / 1000 % 10;

	m_ScoreDigit[0].SetDigitValue(ScoreValues[0]);
	m_ScoreDigit[1].SetDigitValue(ScoreValues[1]);
	m_ScoreDigit[2].SetDigitValue(ScoreValues[2]);
	m_ScoreDigit[3].SetDigitValue(ScoreValues[3]);
}
void Game::UpdateHealthDisplay() // this fucntion help health update on the game screen.
{
	for (int i = 0; i < 4; i++)
	{
		m_PlayerLIFE[i].Update(0.0f);
	}

	int HealthValues[4];

	HealthValues[3] = m_Health_For_Player > 9999 ? 9 : m_Health_For_Player % 10;
	HealthValues[2] = m_Health_For_Player > 9999 ? 9 : m_Health_For_Player / 10 % 10;
	HealthValues[1] = m_Health_For_Player > 9999 ? 9 : m_Health_For_Player / 100 % 10;
	HealthValues[0] = m_Health_For_Player > 9999 ? 9 : m_Health_For_Player / 1000 % 10;

	m_PlayerLIFE[0].SetDigitValue(HealthValues[0]);
	m_PlayerLIFE[1].SetDigitValue(HealthValues[1]);
	m_PlayerLIFE[2].SetDigitValue(HealthValues[2]);
	m_PlayerLIFE[3].SetDigitValue(HealthValues[3]);
}
void Game::minusHealth() // this function if enemy missile is active and it collides with playership it will decrease the health of the player but unfortunatley i was not able to pull this off and enemy dont shoot missile.
{
	for (int i = 0; i < m_EnemyMissiles.size(); i++)
	{
		if (m_EnemyMissiles[i]->Active() && m_EnemyMissiles[i]->Collides(m_PlayerShip))
		{

			//hit the player
			m_EnemyMissiles[i]->Explode();

			m_Health_For_Player -= 1;
		}

	}

	

}

void Game::CheckWinConditions() // this is used for checkin the win condition basically if all 50 enemies dies "you win" appears on the screen
{
	if (NUM_OF_ENEMY == 50 && activeEnemies == 0)
	{
		//player wins

		m_GameState = E_GAME_STATE_WIN_GAME;
	}
		if (m_Health_For_Player <= 0) // if the enemyship touches the left side of the wall the player will decrease 1 life or will die depending on his health
		{
			//player loses
			m_GameState = E_GAME_STATE_LOSE_GAME;
		}
}

void Game::UpdateEndGameScreens() // timer for end screen when the the "you win" for "Game over" appears after sometime the console closes down automatically.
{
	m_EndScreenCounter++;

	if (m_EndScreenCounter > 90)
	{
		m_EndScreenCounter = 0;
		m_bExitApp = true;
	}
}



void Game::Render() // this function shows the menu's sprite on to the screen
{
	m_pRenderer->ClearScreen();	

	switch (m_GameState)
	{
		case E_GAME_STATE_MAIN_MENU:
		{
			RenderMainMenu();
			RenderMainMenu2();
		}
		break;

		case E_GAME_STATE_IN_GAME:
		{
			RenderGame();
		}
		break;
		case E_GAME_STATE_WIN_GAME:
		{
			RenderWinScreen();
		}
		break;
		
		case E_GAME_STATE_LOSE_GAME:
		{
			RenderLoseScreen();
		}
		break;

		default:
		{

		}
	}

	//call this last
	m_pRenderer->Render();
}

void Game::RenderMainMenu() // this function calls up of the gametitle (THE LAST) sprite and shows up on the screen
{
	m_GameTitle.Render(m_pRenderer);
}

void Game::RenderMainMenu2()// this function calls up of the gametitle (FIRE JET) sprite and shows up on the screen
{
	m_GameTitle2.Render(m_pRenderer);
}
void Game::RenderGame() // this functions enables all the animation to be running and smooth.
{
	m_PlayerShip.Render(m_pRenderer);
	
	for (int i = 0; i < 5; i++)
	{
		m_EnemyShip[i].Render(m_pRenderer);
	}
	
	if(m_Missile)
		m_Missile->Render(m_pRenderer);
	RenderEnemyMissiles();
	RenderScore();
	RenderHealth();
	RenderEnemiesARMY();
}



void Game::RenderEnemyMissiles()
{
	for (int i = 0; i < m_EnemyMissiles.size(); i++)
	{
		m_EnemyMissiles[i]->Render(m_pRenderer);
	}
}

void Game::RenderScore()
{
	for (int i = 0; i < 4; i++)
	{
		m_ScoreDigit[i].Render(m_pRenderer);
	}
}
void Game::RenderHealth()
{
	//for (int i = 0; i < 4; i++)
	//{
		m_PlayerLIFE[3].Render(m_pRenderer);
	//}
}

void Game::RenderNextRound()
{
	m_NextRoundTitle.Render(m_pRenderer);
}
void Game::RenderWinScreen()
{
	m_YouWinTitle.Render(m_pRenderer);
}

void Game::RenderLoseScreen()
{
	m_GameOverTitle.Render(m_pRenderer);
}

void Game::AddEnemyMissile(Rockets* pMissile)
{
	m_EnemyMissiles.push_back(pMissile);
}


	


void Game::RenderEnemiesARMY()
{
	{
		for (int i = 0; i < 5; i++)
		{
			m_EnemyShip[i].Render(m_pRenderer);
		}
	}
}


