#include "header.h"

Bullet::Bullet(){
	name = "bullet";
}

void Bullet::update()
{
	if (bullThrust == true) {
		this->dx += cos(this->angle* degToRadians) *15;
		this->dy += sin(this->angle * degToRadians) *15;
		angle+=rand()%6-3;
	}
	this->x += this->dx;
	this->y += this->dy;
	if (x > Width || x<0 || y>Height || y < 0) 
	{
		life = 0;
	}
}



