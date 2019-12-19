#ifndef __GAME_H__
#define __GAME_H__

using namespace std;

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<ctime>
#include<random>
#include<cmath>
#include"ball.h"
#include"Paddle.h"
#include"MainMenu.h"
#include"PauseMenu.h"
#include"OverMessage.h"
#include"brick.h"
#include "LevelMenu.h"
#include "bonus.h"
#include "HighScore.h"
class Game
{
public:
	Game();
	virtual int Run(sf::RenderWindow&);
	int RunBot(sf::RenderWindow&);
	brick NewBrick;
	void reset();
	int score = 0;

private:
	void processEvents();
	void handleInput(sf::Keyboard::Key key, bool isPressed);
	void update(sf::Time); //Change object
	void Render(sf::RenderWindow&); //Draw object
	//Default value
	void defaultWall();
	void defaultPaddleState();
	void defaultBallState();

	void checkWallCollision();
	void checkPaddleCollision();
	void checkBrickCollision();
	void checkBonusCollision();
	void updateBall();
	void updatePaddle();
	void updateScore();
	void updateBrick();
	bool processWinning();
	void processBot(sf::Time TimePerFrame);
	void botPlay(sf::Time TimePerFrame);
	void updateGame(sf::Time TimePerFrame);
	sf::RenderWindow App;
	Ball NewBall;
	sf::RectangleShape upperWall;
	sf::RectangleShape lowerWall;
	sf::RectangleShape leftWall;
	sf::RectangleShape rightWall;
	Paddle leftPaddle;
	void updateBonus();
	bool isPlaying = false;
	bool isOver = false;
	bool isSingle = false;
	bool isMainMenu = true;
	bool isLevel = false;
	bool isPause = false;
	sf::Text Score1, text;
	sf::Font font;
	//OverMessage over;

	sf::RectangleShape middleLine;
	sf::SoundBuffer buffer;
	sf::Sound bounce; //Play sound when bounce with paddle
	int life = 3;
	vector <bonus> NewBonus;
	//HighScore highScore;
};


#endif // !__GAME_H__