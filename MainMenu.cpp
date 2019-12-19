#include "MainMenu.h"

MainMenu::MainMenu()
{
	//Set title
	titleFont.loadFromFile("resource\\sansation.ttf");
	title.setFont(titleFont);
	title.setCharacterSize(50);
	title.setString("Brick Breaker");
	title.setPosition(180, 100);


	//Set left box
	leftBox.setSize(sf::Vector2f(200, 60));
	leftBox.setFillColor(sf::Color::Transparent);
	leftBox.setOutlineThickness(2);
	leftBox.setOutlineColor(sf::Color::White);
	leftBox.setPosition(sf::Vector2f(230, 340));
	//Left box text
	leftText.setFont(titleFont);
	leftText.setCharacterSize(20);
	leftText.setString("New Game");
	leftText.setFillColor(sf::Color::White);
	leftText.setPosition(sf::Vector2f(leftBox.getPosition().x + 55, leftBox.getPosition().y + 15));


	//Set right box
	rightBox = leftBox;
	rightBox.setPosition(sf::Vector2f(230, 440));
	//Right box text
	rightText = leftText;
	rightText.setString("Bot Play");
	rightText.setPosition(sf::Vector2f(rightBox.getPosition().x + 65, rightBox.getPosition().y + 15));
	// 
	box3 = leftBox;
	box3.setPosition(sf::Vector2f(230, 540));
	//
	text3 = leftText;
	text3.setString("High Score");
	text3.setPosition(sf::Vector2f(box3.getPosition().x + 55, box3.getPosition().y + 15));
	//
	box4 = leftBox;
	box4.setPosition(sf::Vector2f(230, 640));
	//
	text4 = leftText;
	text4.setString("Saved Games");
	text4.setPosition(sf::Vector2f(box4.getPosition().x + 35, box4.getPosition().y + 15));
}

void MainMenu::setState(int k)
{
	state = k;
}

int MainMenu::getState()
{
	return state;
}

void MainMenu::updateMenu()
{
	//Choose left button
	switch (state)
	{
	case 1:
		leftBox.setFillColor(sf::Color::White);
		leftText.setFillColor(sf::Color::Black);
		rightBox.setFillColor(sf::Color::Transparent);
		rightText.setFillColor(sf::Color::White);
		box3.setFillColor(sf::Color::Transparent);
		text3.setFillColor(sf::Color::White);
		box4.setFillColor(sf::Color::Transparent);
		text4.setFillColor(sf::Color::White);
		break;
	case 2:
		leftBox.setFillColor(sf::Color::Transparent);
		leftText.setFillColor(sf::Color::White);
		rightBox.setFillColor(sf::Color::White);
		rightText.setFillColor(sf::Color::Black);
		box3.setFillColor(sf::Color::Transparent);
		text3.setFillColor(sf::Color::White);
		box4.setFillColor(sf::Color::Transparent);
		text4.setFillColor(sf::Color::White);
		break;
	case 3:
		leftBox.setFillColor(sf::Color::Transparent);
		leftText.setFillColor(sf::Color::White);
		rightBox.setFillColor(sf::Color::Transparent);
		rightText.setFillColor(sf::Color::White);
		box3.setFillColor(sf::Color::White);
		text3.setFillColor(sf::Color::Black);
		box4.setFillColor(sf::Color::Transparent);
		text4.setFillColor(sf::Color::White);
		break;
	case 4:
		leftBox.setFillColor(sf::Color::Transparent);
		leftText.setFillColor(sf::Color::White);
		rightBox.setFillColor(sf::Color::Transparent);
		rightText.setFillColor(sf::Color::White);
		box3.setFillColor(sf::Color::Transparent);
		text3.setFillColor(sf::Color::White);
		box4.setFillColor(sf::Color::White);
		text4.setFillColor(sf::Color::Black);
		break;
	}
}


int MainMenu::Run(sf::RenderWindow& App)
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
					if (state <= 4 && state > 1)
						state--;
					updateMenu();
					break;
				case sf::Keyboard::Down:
					if (state >= 1 && state < 4)
						state++;
					updateMenu();
					break;
				case sf::Keyboard::Enter:
					return state;
				case sf::Keyboard::Escape:
					App.close();
				}
			}
			//updateMenu();
		}
		Render(App);
		App.display();
	}

}

void MainMenu::Render(sf::RenderWindow& App)
{
	App.clear(sf::Color(235, 128, 39));
	App.draw(leftBox);
	App.draw(rightBox);
	App.draw(box3);
	App.draw(box4);
	App.draw(leftText);
	App.draw(rightText);
	App.draw(text3);
	App.draw(text4);
	App.draw(title);
}
