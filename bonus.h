#ifndef __BONUS_H__
#define __BONUS_H__
#include "ball.h"
class bonus : public Ball
{
public:
	int point = 5;
	bonus();
	bonus(float radius, float speed, float x, float y);
};
#endif
