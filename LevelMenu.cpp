#include "LevelMenu.h"

LevelMenu::LevelMenu()
{
	titleFont.loadFromFile("resource\\sansation.ttf");
	//level 1
	box1.setSize(sf::Vector2f(200, 60));
	box1.setFillColor(sf::Color::Transparent);
	box1.setOutlineThickness(2);
	box1.setOutlineColor(sf::Color::White);
	box1.setPosition(sf::Vector2f(230, 340));
	text1.setFont(titleFont);
	text1.setCharacterSize(20);
	text1.setString("Level 1");
	text1.setFillColor(sf::Color::White);
	text1.setPosition(sf::Vector2f(box1.getPosition().x + 55, box1.getPosition().y + 15));
	//level 2
	box2.setSize(sf::Vector2f(200, 60));
	box2.setFillColor(sf::Color::Transparent);
	box2.setOutlineThickness(2);
	box2.setOutlineColor(sf::Color::White);
	box2.setPosition(sf::Vector2f(230, 440));
	text2.setFont(titleFont);
	text2.setCharacterSize(20);
	text2.setString("Level 2");
	text2.setFillColor(sf::Color::White);
	text2.setPosition(sf::Vector2f(box2.getPosition().x + 55, box2.getPosition().y + 15));
	// level 3
	box3.setSize(sf::Vector2f(200, 60));
	box3.setFillColor(sf::Color::Transparent);
	box3.setOutlineThickness(2);
	box3.setOutlineColor(sf::Color::White);
	box3.setPosition(sf::Vector2f(230, 540));
	text3.setFont(titleFont);
	text3.setCharacterSize(20);
	text3.setString("Level 3");
	text3.setFillColor(sf::Color::White);
	text3.setPosition(sf::Vector2f(box3.getPosition().x + 55, box3.getPosition().y + 15));
}

void LevelMenu::setState(int k)
{
	mstate = k;
}

int LevelMenu::getState()
{
	return mstate;
}

void LevelMenu::updateMenu()
{
	switch (mstate)
	{
	case 1:
		box1.setFillColor(sf::Color::White);
		text1.setFillColor(sf::Color::Black);
		box2.setFillColor(sf::Color::Transparent);
		text2.setFillColor(sf::Color::White);
		box3.setFillColor(sf::Color::Transparent);
		text3.setFillColor(sf::Color::White);
		break;
	case 2:
		box1.setFillColor(sf::Color::Transparent);
		text1.setFillColor(sf::Color::White);
		box2.setFillColor(sf::Color::White);
		text2.setFillColor(sf::Color::Black);
		box3.setFillColor(sf::Color::Transparent);
		text3.setFillColor(sf::Color::White);
		break;
	case 3:
		box1.setFillColor(sf::Color::Transparent);
		text1.setFillColor(sf::Color::White);
		box2.setFillColor(sf::Color::Transparent);
		text2.setFillColor(sf::Color::White);
		box3.setFillColor(sf::Color::White);
		text3.setFillColor(sf::Color::Black);
		break;
	default:
		break;
	}
}

int LevelMenu::Run(sf::RenderWindow& App)
{
	sf::Event Event;
	bool running = true;
	updateMenu();
	while (running)
	{

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
				case sf::Keyboard::Up:
					if (mstate <= 3 && mstate > 1)
						mstate--;
					updateMenu();
					break;
				case sf::Keyboard::Down:
					if (mstate >= 1 && mstate < 3)
						mstate++;
					updateMenu();
					break;
				case sf::Keyboard::Enter:
					return mstate;
				case sf::Keyboard::Escape:
					return 0;
					break;
				}
			}
		}
		Render(App);
		App.display();
	}
}

void LevelMenu::Render(sf::RenderWindow& App)
{
	App.clear(sf::Color(235, 128, 39));
	App.draw(box1);
	App.draw(box2);
	App.draw(box3);
	App.draw(text1);
	App.draw(text2);
	App.draw(text3);
}
