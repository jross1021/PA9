#include "Bullets.h"

class Enemy {
public:
	Enemy(Vector2f size);
	void setPos(Vector2f newPos);
	void checkColl(Bullet bullet);

	void draw(RenderWindow & window);

	
private:
	RectangleShape enemy;
};