#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "basefs.hpp"
namespace game 
{
	class ball 
	{ 
		public:
			ball(sf::Image *,float,float,float);
			void update(sf::RenderWindow *, sf::Clock *, float *[4]); 
			void draw(sf::RenderWindow *);
			float Speed;
			sf::Sprite Sprite; 
			
	};
	ball::ball (sf::Image * Image, float x, float y, float s)
	{
		Sprite.SetImage(*Image);
		Sprite.SetX(x);
		Sprite.SetY(y);
		Speed = s;
	}
	void ball::update (sf::RenderWindow * App, sf::Clock * Clock, float *borders[4])
	{
		float ElapsedTime = Clock->GetElapsedTime();
		Clock->Reset();
		float xx = Sprite.GetPosition().x;
		float yy = Sprite.GetPosition().y;
		float ww = Sprite.GetSize().x;
		float hh = Sprite.GetSize().y;
				
		if (App->GetInput().IsKeyDown(sf::Key::Left)) xx -= Speed * ElapsedTime;
		if (App->GetInput().IsKeyDown(sf::Key::Right)) xx += Speed * ElapsedTime;
		if (App->GetInput().IsKeyDown(sf::Key::Up)) yy -= Speed * ElapsedTime;
		if (App->GetInput().IsKeyDown(sf::Key::Down)) yy += Speed * ElapsedTime;
		
		unsigned int index;
		for (index = 0; index < 4; index++) {
			
			
			if (CheckCollision(xx,yy,ww,hh, borders[index][0], borders[index][1], borders[index][2], borders[index][3]) )
				{
					xx = Sprite.GetPosition().x;
					yy = Sprite.GetPosition().y;
					break;
				}
		}
		Sprite.SetX(xx);
		Sprite.SetY(yy);
		
		
	}
	
	void ball::draw(sf::RenderWindow * App) 
	{
		App->Draw(Sprite);
		
	}
}
