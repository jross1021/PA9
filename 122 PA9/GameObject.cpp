#include "Header.h"

GameObject::GameObject()
{
	this->life = 1;
}

void GameObject::settings(ObjectAnimation &animation, int X, int Y, float Angle, int radius)
{
	this->x = X;
	this->y = Y;
	this->angle = Angle;
	this->R = radius;
	this->anim = animation;
}

void GameObject::Update()
{
	//this function will be overridden in a derived class
}

void GameObject::draw(RenderWindow &window)
{
	this->anim.sprite.setPosition(this->x, this->y);
	this->anim.sprite.setRotation(this->angle + 90);

	window.draw(this->anim.sprite);

	CircleShape circle(this->R);
	circle.setFillColor(Color(255, 0, 0, 170));
	circle.setPosition(this->x, this->y);
	circle.setOrigin(this->R, this->R);
	//window.draw(circle);
}
