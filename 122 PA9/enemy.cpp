#include "enemy.h"

Enemy::Enemy(Vector2f size)
{
	enemy.setSize(size);
	enemy.setFillColor(Color::Red);

}

void Enemy::setPos(Vector2f newPos)
{
	enemy.setPosition(newPos);
}

void Enemy::checkColl(Bullet bullet)
{
	if (bullet.getRight() > enemy.getPosition().x &&
		bullet.getTop() < enemy.getPosition().y + enemy.getSize().y
		&& bullet.getBottom() > enemy.getPosition().y) {
		enemy.setPosition(Vector2f(40239, 94039));
	}
}

void Enemy::draw(RenderWindow &window) {
	window.draw(enemy);
}
