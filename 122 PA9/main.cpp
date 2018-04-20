#include <SFML/Graphics.hpp>

const int Width = 900;
const int Height = 600;


int main()
{
	sf::RenderWindow window(sf::VideoMode(Width, Height), "SFML works!");
	
	
	//Creating a texture for the spaceship using a jpeg file i found
	sf::Texture t1;
	t1.loadFromFile("Spaceship.jpg");
		
	//Creating a sprite for the ship
	sf::Sprite ship(t1);

	//This should just set the shape of the sprite for the ship and include the jpeg file to it
	ship.setTextureRect((sf::IntRect(30, 0, 30, 30)));
	ship.setOrigin(40, 40);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//system("dir");

		window.clear();
		window.draw(ship);
		window.display();
	}
	return 0;
}
