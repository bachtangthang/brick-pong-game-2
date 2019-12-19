#include "SaveGame.h"

SaveGame::SaveGame()
{
	titleFont.loadFromFile("resource\\sansation.ttf");
	text.setFont(titleFont);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setPosition(230, 400);
	text.setString("");
}

void SaveGame::Render(sf::RenderWindow& App)
{
	App.clear(sf::Color(235, 128, 39));
	App.draw(text);
}

void SaveGame::Run(sf::RenderWindow& App)
{
	sf::Event Event;
	bool running = true;
	while (running)
	{

		while (App.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				App.close();
				break;
			}
			else if(Event.type == sf::Event::TextEntered)
			{
				if (Event.text.unicode < 128 && Event.text.unicode)
				{
					text.setString(text.getString()+Event.text.unicode);
				}
				break;
			}
			else if (Event.type == sf::Event::MouseButtonPressed)
			{
				
				return;
			}
		}
		Render(App);
		App.display();
	}
}

void SaveGame::WriteToFile(Game& A)
{
	//std::string temp1 = "./SaveGame/";
	//std::string temp = text.getString();
	//temp1 = temp1 + temp;
	//std::cout << temp1;
	
	std::string temp2 = text.getString();
	//temp1 += ".txt";
	//std::cout << temp1;
	std::ofstream fileOut(temp2 + ".txt");
	fileOut << A.score << endl;
	for (auto i = A.NewBrick.vectorBrick.begin(); i != A.NewBrick.vectorBrick.end(); i++)
	{
		fileOut << (*i).getPosition().x << endl;
		fileOut << (*i).getPosition().y << endl;
		fileOut << (*i).getScore() << endl;
	}
	fileOut.close();
}
