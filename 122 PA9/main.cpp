#include "header.h"



/*Accepts two GameObjects (such as ship and asteroid, or asteroid and bullet) and uses the position of the
sprites for the objects to see if they have collided with one another. */
bool IsCollided(GameObject *lhs, GameObject *rhs)
{
	return ((rhs->x - lhs->x) * (rhs->x - lhs->x) + (rhs->y - lhs->y) * (rhs->y - lhs->y) < (lhs->R + rhs->R) * (lhs->R + rhs->R));
}



int main()
{
	srand(time(0));

	////Background
	sf::RenderWindow window(sf::VideoMode(Width, Height), "Asteroids!");
	window.setFramerateLimit(60);


	Texture t1, shipTexture, asteroidTexture, asteroidTextureSmall, bulletTexture;
	t1.loadFromFile("High Resolution Space Images-736288.jpg");
	asteroidTexture.loadFromFile("rock.png");
	asteroidTextureSmall.loadFromFile("rock_small.png");
	shipTexture.loadFromFile("spaceship.png");
	bulletTexture.loadFromFile("fire_blue.png");


	t1.setSmooth(true);
	shipTexture.setSmooth(true);

	Sprite sBackground(t1), asteroid(asteroidTexture);


	/*
	Animations and image sources for the animations were gathered from a tutorial linked
	at the bottom. The animation works by passing in the image saved as a texture.
	The original image is saved as a long block of images. The parameters help to specify
	the size of each individual image block within the whole block. The ObjectAnimation
	class then holds a vector of IntRects called frames, which holds each individual
	image block as a frame. The ObjectAnimation class then updates the animation class
	within its Update() function to cycle through the frames and display the proper frame,
	essentially creating the animation.
	*/

	ObjectAnimation ship(shipTexture, 40, 0, 40, 40, 1, 0);
	ObjectAnimation ship_go(shipTexture, 40, 40, 40, 40, 1, 0);
	ObjectAnimation sRockSmall(asteroidTextureSmall, 0, 0, 64, 64, 16, 0.2);
	ObjectAnimation sRock(asteroidTexture, 0, 0, 64, 64, 16, 0.2);

	////Animation to use for the bullets////////////////
	ObjectAnimation bulletAnim(bulletTexture, 0, 0, 32, 64, 16, 0.8);

	sRock.sprite.setPosition(400, 400);
	//A list of all the objects populating the game, including the spaceship
	std::list<GameObject*> objects;

	for (int i = 0; i < 15; i++)
	{
		//randomly spawning and setting position of asteroids
		Asteroid *a = new Asteroid();
		a->settings(sRock, rand() % Width, rand() % Height, rand() % 360, 25);
		objects.push_back(a);
	}

	//creating the player spaceship, adding to the objects list
	Spaceship *Playership = new Spaceship;
	Playership->settings(ship, 200, 200, 0, 20);
	objects.push_back(Playership);
	/////////////Game Loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//bool isFire = false;
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			Bullet *b = new Bullet();
			//isFire = true;
			b->settings(bulletAnim,Playership->x, Playership->y,Playership->angle, 10);
			//b->bullThrust = true;
			objects.push_back(b);
		}
		/*
		Here is where the bullets can be put in.
		if (event.type == event::keypressed)
		if(event.key.code == keyboard::whatever key we want here)
		{
		create the new bullet here. using a *bullet, passing in the
		Playership x and Playership y for the x and y value for the
		bullet constructor and Playership's angle for the angle value
		as well. The animation is the bulletAnim, and the last int value
		that is passed in will be the size we want the bullets to be.

		(bulletAnimation, playership x, playership y, playership angle, any int for size)


		entities.push_back(bullet);
		}
		*/
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			Playership->angle += 3;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			Playership->angle -= 3;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			Playership->thrust = true;
		}
		else
		{
			Playership->thrust = false;
		}
		//checking for collisions
		for (auto a : objects)
		{
			for (auto b : objects)
			{
				if (a->name == "asteroid" && b->name == "bullet")
				{
					if (IsCollided(a, b))
					{
						a->life = false;
						b->life = false;


						for (int i = 0; i < 2; i++)
						{
							if (a->R == 15) continue;
							GameObject *e = new Asteroid();
							e->settings(sRockSmall, a->x, a->y, rand() % 360, 15);
							objects.push_back(e);
						}

					}
				}

				//checking asteroid and spaceship collision
				if (a->name == "spaceship" && b->name == "asteroid")
				{
					if (IsCollided(a, b))
					{
						b->life = false;
						//GameObject *o = new GameObject();
						//o->settings()

						Playership->settings(ship, Width / 2, Height / 2, 0, 20);
						Playership->dx = 0; Playership->dy = 0;
					}
				}
			}
		}


		//if the player is using up arrow
		//do the animation
		if (Playership->thrust)
		{
			Playership->anim = ship_go;
		}
		else
		{
			Playership->anim = ship;
		}

		//randomly spawn asteroids during gameplay
		if (rand() % 150 == 0)
		{

			Asteroid *a = new Asteroid();
			a->settings(sRock, 0, rand() % Height, rand() % 360, 25);
			objects.push_back(a);
		}
		//going through the list, and updating/displaying GameObjects to screen
		for (auto i = objects.begin(); i != objects.end();)
		{
			GameObject *e = *i;

			e->Update();
			e->anim.Update();

			//if the object has been destroyed/lost its life, remove the object
			if (e->life == false)
			{
				i = objects.erase(i);
				delete e;
			}

			//otherwise keep going through the list
			else
			{
				i++;
			}
		}

		sRock.Update();

		////Display everything to the screen

		window.draw(sBackground);
		//window.draw(sRock.sprite);
		//displaying everyting in the objects list
		for (auto i : objects)
		{
			i->draw(window);
		}
		window.display();
	}

	return 0;
}




//		//////////////////////Ship Movement//////////////////
//			////utilizing help from tutorial for angles https://www.youtube.com/watch?v=rWaSo2usU4A

//float x = 300, y = 300;
//float dx = 0, dy = 0, angle = 0;
//bool thrust;

//		//////////////////////////////////////////////////////////////////

/////////Ship//////////////////////
//
////resizing ship
//Vector2f targetSize(50.0f, 50.0f);
//shipTexture.loadFromFile("anotherShip.png");
////Creating a sprite for the ship
//sf::Sprite ship(shipTexture);

//ship.setScale(targetSize.x / ship.getGlobalBounds().width, targetSize.y / ship.getGlobalBounds().height);

//This should just set the shape of the sprite for the ship and include the png file to it
//ship.setTexture(shipTexture);
//ship.setPosition(Width / 2, Height / 2);


//if (Playership->thrust)
//{
//	Playership->dx += cos(Playership->angle*degToRadians) *0.2;
//	Playership->dy += sin(Playership->angle*degToRadians) *0.2;
//}
//else
//{
//	dx * 0.99;
//	dy * 0.99;
//}


//int maxSpeed = 10;
//float speed = sqrt(dx*dx + dy*dy);
//if (speed > maxSpeed)
//{
//	dx *= maxSpeed / speed;
//	dy *= maxSpeed / speed;
//}

//x += dx;
//y += dy;

////if we leave the window
//if (x > Width)
//{
//	x = 0;
//}
//if (x < 0)
//{
//	x = Width;
//}
//if (y > Height)
//{
//	y = 0;
//}
//if (y < 0)

//{
//	y = Height;
//}

/*	ship.setPosition(x, y);
ship.setRotation(angle + 90);

window.clear();
window.draw(sBackground);
window.draw(ship);
window.display();*/