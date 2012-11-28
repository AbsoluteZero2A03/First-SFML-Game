#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "update.hpp"

int main() 
{
	sf::RenderWindow App;
	App.Create(sf::VideoMode(500,400), "SFML Window");
	
	sf::Image Image;
	if (!Image.LoadFromFile("Images/ball.png")) { return EXIT_FAILURE; }
	sf::Clock Clock;
	
	game::ball cball (&Image, 3.f, 4.f, 50.0);
	float border1[] = {0,0, 500,0};
	float border2[] = {0,0, 0,400};
	float border3[] = {500,0, 500,400};
	float border4[] = {0,400, 500,400};
	float * borders[] = {border1, border2, border3, border4};
	
	while (App.IsOpened()) 
	{
		sf::Event Event;
		while (App.GetEvent(Event)) 
		{
			if (Event.Type == sf::Event::Closed) 
				App.Close();
		}
		App.Clear();
		
		cball.update(&App, &Clock, &borders);
		cball.draw(&App);
		
		App.Display();
	}
	
	return EXIT_SUCCESS;
}
