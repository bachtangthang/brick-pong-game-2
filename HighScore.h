#ifndef __HIGHSCORE_H__
#define __HIGHSCORE_H__
#include "Menu.h"
#include <fstream>
using namespace std;
class HighScore
{
public:
	std::vector <int> list;
	std::ifstream fileIn;
	void ReadFile();
	sf::Font font;
	sf::Text text1, text2, text3, text4, text5;
	HighScore();
	void Render(sf::RenderWindow&);
	void loadToFile();
	void updateFile(int x);
};
#endif
