#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <list>

const int Width = 1200;
const int Height = 800;
/////see ship movement section for source reference
const float degToRadians = 0.017453f;
/////////////////////////////////////////////////

using namespace sf;
using std::string;

class ObjectAnimation
{
public:
	//default constructor
	ObjectAnimation();

	float frame, speed;
	Sprite sprite;
	std::vector<IntRect> frames;

	ObjectAnimation(Texture &t, int x, int y, int w, int h, int count, float speed);

	/////Updates the texture of the object depending on where it is at in its animation
	void Update();

	////Checking to see if it is the end of the animation
	bool isEnd();

};


class GameObject
{
public:
	// Default Constructor for a game Object
	GameObject();

	//set the settings of the overall object, including animation;
	void settings(ObjectAnimation &animation, int X, int Y, float Angle = 0, int radius = 1);

	//virtual function, will be overridden in derived classes
	virtual void Update();

	//draw the object to the screen
	void draw(RenderWindow &window);

////////////Data Members
	float x;
	float y;
	float dx;
	float dy;
	float angle;
	float R;
	bool life;
	string name;
	ObjectAnimation anim;

	virtual ~GameObject() {};
};

class Asteroid : public GameObject
{
public:
	//constructor
	Asteroid();

	//overriding update from the base class object
	void Update() override;
};

class Spaceship : public GameObject
{
public:
	//Constructor
	Spaceship();

	//overridden Update() function from the base Class
	void Update() override;

	//Data Member
	bool thrust;
};
