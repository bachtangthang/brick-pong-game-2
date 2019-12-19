#ifndef __MAINMENU_H__
#define __MAINMENU_H__
#include"Menu.h"

class MainMenu : public Menu
{
private:
	int state = 1;
public:
	sf::Font titleFont;
	sf::Text title;
	sf::Text leftText, rightText, text3, text4;
	sf::RectangleShape leftBox, rightBox, box3, box4;

	MainMenu();
	virtual ~MainMenu() = default;


	void setState(int);
	int getState();

	void updateMenu();
	virtual int Run(sf::RenderWindow&);
	virtual void Render(sf::RenderWindow&);
};





#endif // !__MAINMENU_H__