#include "bonus.h"

bonus::bonus()
{
	setRadius(10);
	setOrigin(getRadius() / 2, getRadius() / 2);
	setPosition((float)wWidth / 2, (float)wHeight / 2);
}

bonus::bonus(float radius, float speed, float x, float y)
{
	setRadius(radius);
	setOrigin(getRadius() / 2, getRadius() / 2);
	mSpeed = speed;
	setPosition(x, y);
	setDirection(0, 1);
	setFillColor(sf::Color::Blue);
}
