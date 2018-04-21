#include "Bullets.h"

void Bullet::fire(int speed)
{
	bullet.move(speed, 0);
}

int Bullet::getRight()
{
	return bullet.getPosition().x; +bullet.getPosition().x;
}

int Bullet::getLeft()
{
	return bullet.getPosition().x;
}

int Bullet::getTop()
{
	return bullet.getPosition().y;
}

int Bullet::getBottom()
{
	return bullet.getPosition().y + bullet.getPosition().y;

}

void Bullet::draw(RenderWindow & window)
{
	window.draw(bullet);
}
