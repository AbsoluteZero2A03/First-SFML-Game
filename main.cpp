#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "update.hpp"

int main() 
{
	sf::RenderWindow App;
	App.Create(sf::VideoMode(500,400), "SFML Window");
	/*
	sf::Sprite Sprite;
	Sprite.SetImage(Image);
	
	float Speed = 50.f;*/
	
	sf::Image Image;
	if (!Image.LoadFromFile("Images/ball.png")) { return EXIT_FAILURE; }
	sf::Clock Clock;
	
	game::ball ball (&Image, 0.f, 0.f, 50.0);
	

	while (App.IsOpened()) 
	{
		sf::Event Event;
		while (App.GetEvent(Event)) 
		{
			if (Event.Type == sf::Event::Closed) App.Close();
		}
		App.Clear();
		/*float ElapsedTime = Clock.GetElapsedTime();
		
		Clock.Reset();
		
		float x=Sprite.GetPosition().x;
		float y=Sprite.GetPosition().y;
		
		if (App.GetInput().IsKeyDown(sf::Key::Left)) x -= Speed * ElapsedTime;
		if (App.GetInput().IsKeyDown(sf::Key::Right)) x += Speed * ElapsedTime;
		if (App.GetInput().IsKeyDown(sf::Key::Up)) y -= Speed * ElapsedTime;
		if (App.GetInput().IsKeyDown(sf::Key::Down)) y += Speed * ElapsedTime;
		
		Sprite.SetX(x);
		Sprite.SetY(y);
		App.Draw(Sprite);*/
		
		ball.update(&App, &Clock);
		ball.draw(&App);

		App.Display();
	}
	
	return EXIT_SUCCESS;
}
