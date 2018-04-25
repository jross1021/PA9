#include "header.h"

Bullet::Bullet() : GameObject() {
	/*this->dx = rand() % 8 - 4;
	this->dy = rand() % 8 - 4;*/
	name = "bullet";
}

void Bullet::Update()
{
	this->dx = cos(this->angle* degToRadians) *6;
	this->dy = sin(this->angle * degToRadians) *6;
	//angle+=rand()%6-3;
	this->x += this->dx;
	this->y += this->dy;
	if (x > Width || x<0 || y>Height || y < 0) 
	{
		life = 0;
	}
}



