#include <SFML/Graphics.hpp>

const int Width = 1200;
const int Height = 900;

/////see ship movement section for source reference
const float degToRadians = 0.017453f;
/////////////////////////////////////////////////


using namespace sf;

int main()
{

	////Background
	sf::RenderWindow window(sf::VideoMode(Width, Height), "SFML works!");
	window.setFramerateLimit(60);
	Texture t1;
	t1.loadFromFile("High Resolution Space Images-736288.jpg");
	Sprite sBackground(t1);

	///////Ship//////////////////////
	//Creating a texture for the spaceship using a jpeg file i found
	Texture shipTexture;
	//resizing ship
	Vector2f targetSize(50.0f, 50.0f);
	shipTexture.loadFromFile("anotherShip.png");
	//Creating a sprite for the ship
	sf::Sprite ship(shipTexture);

	ship.setScale(targetSize.x / ship.getGlobalBounds().width, targetSize.y / ship.getGlobalBounds().height);

	//This should just set the shape of the sprite for the ship and include the png file to it
	ship.setTexture(shipTexture);
	ship.setPosition(Width / 2, Height / 2);


	//////////////////////Ship Movement//////////////////
	////utilizing help from tutorial for angles https://www.youtube.com/watch?v=rWaSo2usU4A

	float x = 300, y = 300;
	float dx = 0, dy = 0, angle = 0;
	bool thrust;

	//////////////////////////////////////////////////////////////////


	/////////////Game Loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			angle += 5;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			angle -= 5;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			thrust = true;
		}
		else
		{
			thrust = false;
		}

		if (thrust)
		{
			dx += cos(angle*degToRadians) *0.2;
			dy += sin(angle*degToRadians) *0.2;
		}
		else
		{
			dx * 0.99;
			dy * 0.99;
		}


		int maxSpeed = 10;
		float speed = sqrt(dx*dx + dy*dy);
		if (speed > maxSpeed)
		{
			dx *= maxSpeed / speed;
			dy *= maxSpeed / speed;
		}

		x += dx;
		y += dy;

		//if we leave the window
		if (x > Width)
		{
			x = 0;
		}
		if (x < 0)
		{
			x = Width;
		}
		if (y > Height)
		{
			y = 0;
		}
		if (y < 0)

		{
			y = Height;
		}

		ship.setPosition(x, y);
		ship.setRotation(angle + 90);

		window.clear();
		window.draw(sBackground);
		window.draw(ship);
		window.display();
	}




	return 0;
}
