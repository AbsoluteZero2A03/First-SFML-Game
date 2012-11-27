#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "update.hpp"

int main() 
{
	sf::RenderWindow App;
	App.Create(sf::VideoMode(500,400), "SFML Window");
	
	sf::Image Image;
	if (!Image.LoadFromFile("Images/ball.png")) { return EXIT_FAILURE; }
	sf::Clock Clock;
	
	game::ball ball (&Image, 0.f, 0.f, 50.0);
	

	while (App.IsOpened()) 
	{
		sf::Event Event;
		while (App.GetEvent(Event)) 
		{
			if (Event.Type == sf::Event::Closed) 
				App.Close();
		}
		App.Clear();
		
		ball.update(&App, &Clock);
		ball.draw(&App);

		App.Display();
	}
	
	return EXIT_SUCCESS;
}
