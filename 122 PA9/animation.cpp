#include "Header.h"

ObjectAnimation::ObjectAnimation()
{
	//this does nothing
}

ObjectAnimation::ObjectAnimation(Texture &t, int x, int y, int w, int h, int count, float speed)
{
	this->frame = 0;
	this->speed = speed;

	for (int i = 0; i < count; i++)
	{
		this->frames.push_back(IntRect(x + i*w, y, w, h));
	}

	this->sprite.setTexture(t);
	this->sprite.setOrigin(w / 2, h / 2);
	this->sprite.setTextureRect(frames[0]);
}

void ObjectAnimation::Update()
{
	this->frame += this->speed;
	int n = this->frames.size();

	if (this->frame >= n)
	{
		this->frame -= n;
	}
	if (n > 0)
	{
		this->sprite.setTextureRect(this->frames[int(this->frame)]);
	}
}

bool ObjectAnimation::isEnd()
{
	return (this->frame + this->speed >= this->frames.size());
}
