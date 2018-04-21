#include <SFML\Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Bullet {
	Bullet(Vector2f size) {
		bullet.getSize();
		bullet.setFillColor(Color::Green);

	}
	void fire(int speed);
	int getRight() ;
	int getLeft(); 
	int getTop();
	int getBottom();
	void draw(RenderWindow &window);

private:
	RectangleShape bullet;
};