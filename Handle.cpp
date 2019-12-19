#include "Handle.h"
void handle()
{
	Game NewGame;
	MainMenu mMenu;
	LevelMenu lMenu;
	PauseMenu pMenu;
	HighScore hMenu;
	SaveGame sMenu;
	//sf::Clock clock;
	sf::RenderWindow app(sf::VideoMode(wWidth, wHeight), "Brick Breaker Game");
	//sf::Time timeSinceLastUpdate = sf::Time::Zero;
	bool ismMenu = true;
	bool islMenu = false;
	bool ispMenu = false;
	bool isGame = false;
	bool isBot = false;
	bool isMan = false;
	bool isHighScore = false;
	bool issMenu = false;
	while (app.isOpen())
	{
		if (ismMenu)
		{
			int i = mMenu.Run(app);
			if (i == 1)
			{
				ismMenu = false;
				islMenu = true;
				isMan = true;
				isBot = false;
			}
			else if (i == 2)
			{
				ismMenu = false;
				islMenu = true;
				isBot = true;
				isMan = false;
			}
			else if (i == 3)
			{
				ismMenu = false;
				islMenu = false;
				isHighScore = true;
			}
		}
		else if (islMenu)
		{
			int j = lMenu.Run(app);
			if (j == 1)
			{
				islMenu = false;
				isGame = true;
				NewGame.reset();
				NewGame.NewBrick.setLevelOne();
			}
			else if (j == 2)
			{
				islMenu = false;
				isGame = true;
				NewGame.reset();
				NewGame.NewBrick.setLevelTwo();
			}
		}
		else if (isGame && isMan)
		{
			int k = NewGame.Run(app);
			if (k == 0)
			{
				isGame = false;
				ispMenu = true;
				
			}
		}
		else if (ispMenu)
		{
			int l = pMenu.Run(app);
			if (l == 1)
			{
				isGame = true;
				ispMenu = false;
				
			}
			else if (l == 2)
			{
				ismMenu = true;
				ispMenu = false;
				isBot = false;
				isMan = false;
			}
			else if (l == 3)
			{
				ispMenu = false;
				issMenu = true;
			}
		}
		else if (isBot && isGame)
		{
			int m = NewGame.RunBot(app);
			if (m == 0)
			{
				isGame = false;
				ispMenu = true;
				
			}
		}
		else if (isHighScore)
		{
			hMenu.list.clear();
			hMenu.ReadFile();
			hMenu.Render(app);
			ismMenu = true;
			isHighScore = false;
			
		}
		else if (issMenu)
		{
			sMenu.Run(app);
			sMenu.WriteToFile(NewGame);
			issMenu = false;
			ispMenu = true;
		}
		


			/*int j = lMenu.Run(app);
			if (j == 1)
			{
				NewGame.reset();
				NewGame.NewBrick.setLevelOne();
			}
			else if (j == 2)
			{
				NewGame.reset();
				NewGame.NewBrick.setLevelTwo();
			}
			int k = NewGame.Run(app);
			if (k == 0)
			{
				int m = pMenu.Run(app);
				if (m == 1)
				{
					NewGame.Run(app);
				}
				else  if (m == 2)
				{
					
				}*/
			

	}
}