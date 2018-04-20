#include <SFML/Graphics.hpp>

const int Width = 900;
const int Height = 600;

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(Width, Height), "SFML works!");
	
	window.setFramerateLimit(60);

	//Creating a texture for the spaceship using a jpeg file i found
	Texture t1;
	t1.loadFromFile("Spaceship.png");
		
	//Creating a sprite for the ship
	sf::Sprite ship(t1);

	//This should just set the shape of the sprite for the ship and include the png file to it
	ship.setTextureRect((IntRect(40, 0, 40, 40)));
	ship.setOrigin(Width/2, Height/2);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		///
		//system("dir");

		window.clear();
		window.draw(ship);
		window.display();
	}
	return 0;
}
