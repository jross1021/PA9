#include <SFML/Graphics.hpp>
using namespace sf;

const int Width = 900;
const int Height = 600;


int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 600), "SFML works!");
	window.setFramerateLimit(60);
	Texture t1, t2;
	//system("dir");
	t1.loadFromFile("free_space_galaxy_texture_by_lyshastra-d77gh2y.jpg");
	Sprite sBackground(t1);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//hello
		}

		//system("dir");

		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}
