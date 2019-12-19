#ifndef __LEVELMENU_H__
#define __LEVELMENU_H__
#include "Menu.h"
class LevelMenu
{
private:
	int mstate = 1;
public:
	sf::Font titleFont;
	sf::Text text1, text2, text3;
	sf::RectangleShape box1, box2, box3;
	LevelMenu();
	virtual ~LevelMenu() = default;
	void setState(int k);
	int getState();
	virtual void updateMenu();
	virtual int Run(sf::RenderWindow&);
	virtual void Render(sf::RenderWindow&);

};
#endif
