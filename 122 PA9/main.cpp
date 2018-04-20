#include <SFML/Graphics.hpp>

const int Width = 900;
const int Height = 600;

using namespace sf;

int main()
{
	//resizing ship
	Vector2f targetSize(50.0f, 50.0f);



	RenderWindow window(VideoMode(Width, Height), "SFML works!");	
	window.setFramerateLimit(60);
	//Creating a texture for the spaceship using a jpeg file i found
	Texture shipTexture;
	shipTexture.loadFromFile("anotherShip.png");
	//Creating a sprite for the ship
	sf::Sprite ship(shipTexture);

	ship.setScale(targetSize.x / ship.getGlobalBounds().width, targetSize.y / ship.getGlobalBounds().height);
	
	//This should just set the shape of the sprite for the ship and include the png file to it
	ship.setTexture(shipTexture);
	ship.setPosition(Width / 2, Height / 2);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(ship);
		window.display();
	}
	return 0;
}
