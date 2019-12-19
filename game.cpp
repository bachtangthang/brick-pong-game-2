#include "game.h"



Game::Game() //: App(sf::VideoMode(wWidth, wHeight), "Pong Game")
{
	defaultWall();
	leftPaddle.defaultPaddle();
	defaultPaddleState();
	defaultBallState();
	middleLine.setSize(sf::Vector2f(1, wHeight));
	middleLine.setPosition(sf::Vector2f(wWidth / 2.f, 0));
	/*isPlaying = true;
	isSingle = true;*/
	//NewBrick.setLevelOne();
	//NewBrick.setLevelTwo();
	font.loadFromFile("resource\\SUBWT___.ttf");
	Score1.setFont(font);
	Score1.setString("0");
	Score1.setCharacterSize(50);
	Score1.setPosition((App.getSize().x) / 4, 20);
	Score1.setFillColor(sf::Color::White);
	text.setFont(font);
	text.setCharacterSize(15);
	text.setFillColor(sf::Color::Black);
	buffer.loadFromFile("resource\\bounce.wav");
	bounce.setBuffer(buffer);
}

int Game::Run(sf::RenderWindow& App)
{
	sf::Event Event;
	bool running = true;
	this->Render(App);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (App.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			while (App.pollEvent(Event))
			{
				if (Event.type == sf::Event::Closed)
				{
					App.close();
					break;
				}
				if (Event.type == sf::Event::KeyPressed)
				{
					switch (Event.key.code)
					{
					case sf::Keyboard::Left:
						leftPaddle.setLeftState(true);
						break;
					case sf::Keyboard::Right:
						leftPaddle.setRightState(true);
						break;
					case sf::Keyboard::Escape:
						return 0;
					}
				}
				else if (Event.type == sf::Event::KeyReleased)
				{
					leftPaddle.setLeftState(false);
					leftPaddle.setRightState(false);
				}
			}
			updateGame(TimePerFrame);
			if (processWinning() == true)
			{
				ofstream fileOut("./HighScore/HighScore.txt", std::ofstream::app);
				fileOut << score << endl;
				App.clear(sf::Color(235, 128, 39));
				sf::Text text;
				font.loadFromFile("resource\\SUBWT___.ttf");
				text.setFont(font);
				text.setCharacterSize(40);
				text.setPosition(100, 100);
				text.setString("WIN, Score = " + to_string(score));
				App.draw(text);
				App.display();
				sf::Time time = sf::seconds(2);
				sf::sleep(time);

				return 0;
			}
			else if (processWinning() == false)
			{
				ofstream fileOut("./HighScore/HighScore.txt", std::ofstream::app);
				fileOut << score << endl;
				App.clear(sf::Color(235, 128, 39));
				sf::Text text;
				font.loadFromFile("resource\\SUBWT___.ttf");
				text.setFont(font);
				text.setCharacterSize(40);
				text.setPosition(100, 100);
				text.setString("LOSE, Score = " + to_string(score));
				App.draw(text);
				App.display();
				sf::Time time = sf::seconds(2);
				sf::sleep(time);
				return 0;
			}
			Render(App);
			App.display();
		}
	}
}

int Game::RunBot(sf::RenderWindow& App)
{
	sf::Event Event;
	bool running = true;
	this->Render(App);
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (App.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processBot(TimePerFrame);
			while (App.pollEvent(Event))
			{
				if (Event.type == sf::Event::Closed)
				{
					App.close();
					break;
				}
				if (Event.type == sf::Event::KeyPressed)
				{
					switch (Event.key.code)
					{
					case sf::Keyboard::Escape:
						return 0;
					}
				}
			}
			updateGame(TimePerFrame);
			if (processWinning() == true)
			{
				App.clear(sf::Color(235, 128, 39));
				sf::Text text;
				font.loadFromFile("resource\\SUBWT___.ttf");
				text.setFont(font);
				text.setCharacterSize(40);
				text.setPosition(100, 100);
				text.setString("WIN, Score = " + to_string(score));
				App.draw(text);
				App.display();
				return 0;
			}
			else
			{
				App.clear(sf::Color(235, 128, 39));
				sf::Text text;
				font.loadFromFile("resource\\SUBWT___.ttf");
				text.setFont(font); text.setCharacterSize(40);
				text.setPosition(100, 100);
				text.setString("LOSE, Score = " + to_string(score));
				App.draw(text);
				App.display();
				return 0;
			}
			Render(App);
			App.display();
		}
	}
}

void Game::Render(sf::RenderWindow& App)
{
	//Set background's color
	App.clear(sf::Color(235, 128, 39));
	App.draw(leftPaddle);
	App.draw(NewBall);
	App.draw(upperWall);
	App.draw(lowerWall);
	App.draw(leftWall);
	App.draw(rightWall);
	for (auto i = NewBrick.vectorBrick.begin(); i != NewBrick.vectorBrick.end(); i++)
	{
		if ((*i).point == 1)
		{
			(*i).setFillColor(sf::Color::Cyan);
		}
		text.setPosition(sf::Vector2f((*i).getPosition().x + 40, (*i).getPosition().y + 15));
		text.setString(std::to_string((*i).point));
		App.draw((*i));
		App.draw(text);
	}
	if (NewBonus.size() == 0) {}
	else
	{
		for (auto i = NewBonus.begin(); i != NewBonus.end(); i++)
		{
			App.draw((*i));
		}
	}
}

void Game::defaultWall()
{
	float wallWidth = 19.f;
	upperWall.setSize(sf::Vector2f(wWidth, wallWidth));
	lowerWall.setSize(sf::Vector2f(wWidth, wallWidth));
	leftWall.setSize(sf::Vector2f(wallWidth, wHeight));
	rightWall.setSize(sf::Vector2f(wallWidth, wHeight));
	upperWall.setFillColor(sf::Color::White);
	lowerWall.setFillColor(sf::Color::White);
	leftWall.setFillColor(sf::Color::White);
	rightWall.setFillColor(sf::Color::White);
	upperWall.setPosition(sf::Vector2f(0.f, 0.f));
	lowerWall.setPosition(sf::Vector2f(0.f, wHeight - wallWidth));
	leftWall.setPosition(sf::Vector2f(0.f, 0.f));
	rightWall.setPosition(sf::Vector2f(wWidth - wallWidth, 0.f));
}

void Game::defaultPaddleState()
{
	leftPaddle.setPosition(sf::Vector2f(wWidth / 2 - 50.f, wHeight / 2 + 430.f));//set vi tri ban dau thanh
	leftPaddle.setScore(0);
	leftPaddle.setSpeed(5);
}

void Game::defaultBallState()
{
	NewBall.setSpeed(2);
	NewBall.setPosition(sf::Vector2f(wWidth / 2.f, wHeight / 2.f));
	//Random element
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uniform_distance(1, std::nextafter(360, DBL_MAX));
	float angle;
	float x, y;
	sf::Vector2f direction(1, 1);
	NewBall.setDirection(direction);
}

void Game::checkWallCollision()
{
	//Bounce with upper wall
	if ((NewBall.getPosition().y - NewBall.getRadius()) <= upperWall.getSize().y)
	{
		NewBall.setDirection(NewBall.getDirection().x, -NewBall.getDirection().y);
	}
	//Bounce with left wall
	if ((NewBall.getPosition().x - NewBall.getRadius()) <= leftWall.getSize().x)
	{
		NewBall.setDirection(-NewBall.getDirection().x, NewBall.getDirection().y);
	}
	//Bounce with right wall
	if ((NewBall.getPosition().x + NewBall.getRadius()) >= (wWidth - rightWall.getSize().x))
	{
		NewBall.setDirection(-NewBall.getDirection().x, NewBall.getDirection().y);
	}
}

void Game::checkPaddleCollision()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> uniform_distance(1, std::nextafter(20, DBL_MAX));
	float rolate;
	float angle;
	sf::Vector2f ballDirection;
	//Bounce with left paddle
	if (NewBall.getPosition().x >= leftPaddle.getPosition().x && NewBall.getPosition().x <= (leftPaddle.getPosition().x + leftPaddle.getSize().x) && ((NewBall.getPosition().y + NewBall.getRadius() >= leftPaddle.getPosition().y && (NewBall.getPosition().y - NewBall.getRadius() <= (leftPaddle.getPosition().y + leftPaddle.getSize().y)))))//cham bien tren, duoi
	{
		NewBall.setDirection(NewBall.getDirection().x, -NewBall.getDirection().y);
		NewBall.setSpeed(NewBall.getSpeed() + NewBall.getSpeed() * 0.1);
		if (NewBall.getDirection().y > 0)//phan xa di xuong
		{

			NewBall.setPosition(sf::Vector2f(NewBall.getPosition().x, NewBall.getPosition().y + NewBall.getRadius()));
			ballDirection = NewBall.getDirection();
			angle = MoveableObject::angleInDegree(ballDirection);
			if (leftPaddle.getDirection().x * NewBall.getDirection().x > 0)
			{
				ballDirection = MoveableObject::rolateVector(ballDirection, angle * 0.2);
				NewBall.setDirection(ballDirection);

			}
			else if (leftPaddle.getDirection().x * NewBall.getDirection().x < 0)
			{
				ballDirection = MoveableObject::rolateVector(ballDirection, -angle * 0.2);
				NewBall.setDirection(ballDirection);
			}

		}
		else if (NewBall.getDirection().y < 0)//phan xa di len
		{
			NewBall.setPosition(sf::Vector2f(NewBall.getPosition().x, NewBall.getPosition().y));
			ballDirection = NewBall.getDirection();
			angle = MoveableObject::angleInDegree(ballDirection);
			if (leftPaddle.getDirection().x * NewBall.getDirection().x > 0)
			{
				ballDirection = MoveableObject::rolateVector(ballDirection, angle * 0.2);
				NewBall.setDirection(ballDirection);

			}
			else if (leftPaddle.getDirection().x * NewBall.getDirection().x < 0)
			{
				ballDirection = MoveableObject::rolateVector(ballDirection, -angle * 0.2);
				NewBall.setDirection(ballDirection);
			}
		}
		bounce.play();
	}
	else if ((NewBall.getPosition().y >= leftPaddle.getPosition().y && NewBall.getPosition().y <= (leftPaddle.getPosition().y + leftPaddle.getSize().y) && (NewBall.getPosition().x + NewBall.getRadius()) >= leftPaddle.getPosition().x && (NewBall.getPosition().x - NewBall.getRadius()) <= leftPaddle.getPosition().x + leftPaddle.getSize().x))
	{
		NewBall.setDirection(-NewBall.getDirection().x, NewBall.getDirection().y);
		NewBall.setSpeed(NewBall.getSpeed() + NewBall.getSpeed() * 0.1);
		if (NewBall.getDirection().x > 0)//phan xa sang phai
		{

			NewBall.setPosition(sf::Vector2f(NewBall.getPosition().x, NewBall.getPosition().y));

		}
		else if (NewBall.getDirection().x < 0)// phan xa sang trai
		{
			NewBall.setPosition(sf::Vector2f(NewBall.getPosition().x, NewBall.getPosition().y));
		}
		bounce.play();
	}
}

void Game::checkBrickCollision()
{
	for (auto i = NewBrick.vectorBrick.begin(); i != NewBrick.vectorBrick.end(); i++)
	{
		if (NewBall.getPosition().x >= (*i).getPosition().x && NewBall.getPosition().x <= ((*i).getPosition().x + (*i).getSize().x) && ((NewBall.getPosition().y + NewBall.getRadius() >= (*i).getPosition().y && (NewBall.getPosition().y - NewBall.getRadius() <= ((*i).getPosition().y + (*i).getSize().y)))))//cham bien tren, duoi
		{
			score++;
			(*i).point--;
			if ((*i).point == 0)//tao bonus
			{
				bonus a(10, 1, (*i).getPosition().x + 100 / 2, (*i).getPosition().y + 50 / 2);
				NewBonus.push_back(a);
			}
			NewBall.setDirection(NewBall.getDirection().x, -NewBall.getDirection().y);
			if (NewBall.getDirection().y > 0)//phan xa di xuong
			{

				NewBall.setPosition(sf::Vector2f(NewBall.getPosition().x, NewBall.getPosition().y + NewBall.getRadius()));

			}
			else if (NewBall.getDirection().y < 0)//phan xa di len
			{
				NewBall.setPosition(sf::Vector2f(NewBall.getPosition().x, NewBall.getPosition().y));
			}
			bounce.play();
		}
		else if ((NewBall.getPosition().y >= (*i).getPosition().y && NewBall.getPosition().y <= ((*i).getPosition().y + (*i).getSize().y) && (NewBall.getPosition().x + NewBall.getRadius()) >= (*i).getPosition().x && (NewBall.getPosition().x - NewBall.getRadius()) <= (*i).getPosition().x + (*i).getSize().x))
		{
			score++;
			(*i).point--;
			NewBall.setDirection(-NewBall.getDirection().x, NewBall.getDirection().y);
			if (NewBall.getDirection().x > 0)//phan xa sang phai
			{

				NewBall.setPosition(sf::Vector2f(NewBall.getPosition().x, NewBall.getPosition().y));

			}
			else if (NewBall.getDirection().x < 0)// phan xa sang trai
			{
				NewBall.setPosition(sf::Vector2f(NewBall.getPosition().x, NewBall.getPosition().y));
			}
			bounce.play();
		}
	}
}

void Game::updateBall()
{
	checkWallCollision();
	if (NewBall.getPosition().y > wHeight)
	{
		life--;
		defaultBallState();
	}
	sf::Vector2f movement;
	movement = NewBall.getDirection() * NewBall.getSpeed();
	NewBall.move(movement);
}

void Game::updatePaddle()
{
	checkPaddleCollision();
	sf::Vector2f leftMove(0, 0);
	sf::Vector2f rightMove(0, 0);
	//Move left paddle
	if (leftPaddle.getLeftState() && (leftPaddle.getPosition().x) > leftWall.getSize().x)
	{
		leftPaddle.setDirection(-1.f, 0.f);
	}
	if (leftPaddle.getRightState() && (leftPaddle.getPosition().x + leftPaddle.getSize().x) < (wWidth - rightWall.getSize().x))
	{
		leftPaddle.setDirection(1.f, 0.f);
	}
	leftMove = leftPaddle.getSpeed() * leftPaddle.getDirection();
	leftMove = leftPaddle.getSpeed() * leftPaddle.getDirection();

	leftPaddle.move(leftMove);

	//Reset paddle direction
	leftPaddle.setDirection(0.f, 0.f);

}

void Game::updateScore()
{
	Score1.setString(std::to_string(leftPaddle.getScore()));
}

void Game::updateBrick()
{
	checkBrickCollision();
	for (auto i = NewBrick.vectorBrick.begin(); i != NewBrick.vectorBrick.end(); i++)
	{
		if ((*i).point == 0)
		{
			NewBrick.vectorBrick.erase(i);
			break;
		}
	}

}
void Game::updateBonus()
{
	checkBonusCollision();
	for (auto i = NewBonus.begin(); i != NewBonus.end(); i++)
	{
		if ((*i).getPosition().y + (*i).getRadius() > wHeight - 2 * leftPaddle.getSize().y)
		{
			NewBonus.erase(i);
			break;
		}
	}
	for (auto i = NewBonus.begin(); i != NewBonus.end(); i++)
	{
		sf::Vector2f movement;
		movement = (*i).getDirection() * (*i).getSpeed();
		(*i).move(movement);
	}
}
void Game::checkBonusCollision()
{
	//touch the bonus
	for (auto i = NewBonus.begin(); i != NewBonus.end(); i++)
	{
		if (((*i).getRadius() + (*i).getPosition().y) >= leftPaddle.getPosition().y && (*i).getPosition().x >= leftPaddle.getPosition().x && (*i).getPosition().x <= leftPaddle.getPosition().x + leftPaddle.getSize().x)
		{
			score = score + (*i).point;
			NewBonus.erase(i);
			break;
		}
	}

}
bool Game::processWinning()
{

	if (NewBrick.vectorBrick.size() == 0)
	{
		return true;
	}
	else if (life == 0)
	{
		return false;
	}
}

void Game::processBot(sf::Time TimePerFrame)
{
	sf::Vector2f ballPosition(NewBall.getPosition());
	sf::Vector2f botPosition(leftPaddle.getPosition());
	float paddleLength = leftPaddle.getSize().x;
	//Move bot
	if (NewBall.getDirection().y < wHeight)
	{
		if (ballPosition.x < botPosition.x)
		{
			leftPaddle.setDirection(sf::Vector2f(-1, 0));
		}
		else if (ballPosition.x > botPosition.x + paddleLength)
		{
			leftPaddle.setDirection(sf::Vector2f(1, 0));
		}
		else
		{
			leftPaddle.setDirection(sf::Vector2f(0, 0));
		}
	}
}

void Game::reset()
{
	//Reset ball and paddle to default
	defaultBallState();
	defaultPaddleState();
	NewBrick.vectorBrick.clear();
	score = 0;
	life = 3;
}

void Game::updateGame(sf::Time TimePerFrame)
{
	updateBall();
	updatePaddle();
	updateBonus();
	updateBrick();
	processWinning();
	updateScore();
}