#ifndef __SAVEGAME_H__
#define __SAVEGAME_H__
#include "Menu.h"
#include <fstream>
#include <string>
#include "game.h"
#include <iostream>
class SaveGame
{
public:
	sf::Font titleFont;
	sf::Text text;
	
	SaveGame();
	virtual ~SaveGame() = default;
	void Render(sf::RenderWindow&);
	void Run(sf::RenderWindow&);
	void WriteToFile(Game&);
}; 
#endif