#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML works!");
	window.setFramerateLimit(60);
	Texture t1, t2;
	//system("dir");
	t1.loadFromFile("High Resolution Space Images-736288.jpg"); // from http://space-wallpaper.blogspot.com/2013/06/high-resolution-space-images.html
	Sprite sBackground(t1);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	//change
	//
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//hello
		}

		window.clear();
		window.draw(shape);
		window.draw(sBackground);
		window.display();
	}

	return 0;
}
