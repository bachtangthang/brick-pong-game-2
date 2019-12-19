#include "HighScore.h"

void HighScore::ReadFile()
{
	fileIn.open("./HighScore/HighScore.txt");

	while (!fileIn.eof())
	{
		int a;
		fileIn >> a;
		list.push_back(a);
	}
	for (int i = 0; i < list.size(); i++)
	{
		for (int j = i; j < list.size(); j++)
		{
			if (list[i] <= list[j])
			{
				swap(list[i], list[j]);
			}
		}
	}
}

HighScore::HighScore()
{
	ReadFile();
	font.loadFromFile("resource\\sansation.ttf");
	text1.setFont(font);
	text1.setCharacterSize(30);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(230, 100);
	text1.setString(to_string(list[0]));
	text2 = text1;
	text2.setPosition(230, 200);
	text2.setString(to_string(list[1]));
	text3 = text1;
	text3.setPosition(230, 300);
	text3.setString(to_string(list[2]));
	text4 = text1;
	text4.setPosition(230, 400);
	text4.setString(to_string(list[3]));
	text5 = text1;
	text5.setPosition(230, 500);
	text5.setString(to_string(list[4]));
}

void HighScore::Render(sf::RenderWindow& App)
{
	App.clear(sf::Color(235, 128, 39));
	App.draw(text1);
	App.draw(text2);
	App.draw(text3);
	App.draw(text4);
	App.draw(text5);
	App.display();
	sf::Time time = sf::seconds(5);
	sf::sleep(time);

}


void HighScore::loadToFile()
{
	ofstream fout("./HighScore/HighScore.txt");
	for (int i = 0; i <= list.size(); i++)
	{
		for (int j = i; j <= list.size(); j++)
		{
			if (list[i] < list[j])
			{
				swap(list[i], list[j]);
			}
		}
	}
	for (auto i = list.begin(); i != list.end(); i++)
	{
		fout << (*i) << endl;
	}
	
}
void HighScore::updateFile(int x)
{
	list.push_back(x);
	loadToFile();
}