#include "Header.h"


Spaceship::Spaceship()
{
	this->name = "spaceship";
}

void Spaceship::Update()
{
	if (this->thrust) //if the ship is moving
	{
		//perform movement/accelleration
		this->dx += cos(this->angle* degToRadians) *0.2;
		this->dy += sin(this->angle * degToRadians) *0.2;
	}
	else
	{
		//the ship needs to decellerate
		this->dx * 0.99;
		this->dy * 0.99;
	}

	int maxSpeed = 15;
	float speed = sqrt(dx*dx + dy*dy);
	if (speed > maxSpeed) //if ship is trying to go too fast
	{
		this->dx *= maxSpeed / speed;
		this->dy *= maxSpeed / speed;
	}


	////Updating x and y by the new distance of dx and dy to make movement of ship

	this->x += this->dx;
	this->y += this->dy;

	////checking for the case of ship moving off the screen

	if (this->x > Width)
	{
		this->x = 0;
	}
	if (this->x < 0)
	{
		this->x = Width;
	}
	if (this->y > Height)
	{
		this->y = 0;
	}
	if (this->y < 0)
	{
		this->y = Height;
	}
}

