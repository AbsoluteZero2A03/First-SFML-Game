#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
namespace game
{
	bool CheckCollision (float x1, float y1, float w1, float h1, 	float x2, float y2, float w2, float h2) 
	{
		if (x1 > x2 + w2 - 1 or y1 > y2 + h2 - 1 or	x2 > x1 + w1 - 1 or	y2 > y1 + h1 - 1)
			return false;
		else 
			return true;
	}
	
}
