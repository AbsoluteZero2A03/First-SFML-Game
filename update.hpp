#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

namespace game 
{
	class ball 
	{ 
		public:
			ball(sf::Image *,float,float,float);
			int update(sf::RenderWindow *, sf::Clock *); 
			int draw(sf::RenderWindow *);
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
	int ball::update (sf::RenderWindow * App, sf::Clock * Clock)
	{
		float ElapsedTime = Clock->GetElapsedTime();
		Clock->Reset();
		float xx = Sprite.GetPosition().x;
		float yy = Sprite.GetPosition().y;
				
		if (App->GetInput().IsKeyDown(sf::Key::Left)) xx -= Speed * ElapsedTime;
		if (App->GetInput().IsKeyDown(sf::Key::Right)) xx += Speed * ElapsedTime;
		if (App->GetInput().IsKeyDown(sf::Key::Up)) yy -= Speed * ElapsedTime;
		if (App->GetInput().IsKeyDown(sf::Key::Down)) yy += Speed * ElapsedTime;
		
		
		Sprite.SetX(xx);
		Sprite.SetY(yy);
		
		return 0;
		
	}
	
	int ball::draw(sf::RenderWindow * App) 
	{
		App->Draw(Sprite);
		
		return 0;
	}
}
