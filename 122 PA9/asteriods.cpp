#include "Header.h"

Asteroid::Asteroid()
{
	this->dx = rand() % 8 - 4;
	this->dy = rand() % 8 - 4;
	this->name = "asteroid";
}

void Asteroid::Update()
{
	this->x += this->dx;
	this->y += this->dy;

	//accounting for if the asteroid goes off the screen
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
