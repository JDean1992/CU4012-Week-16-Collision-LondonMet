#include "Paddle.h"



Paddle::Paddle()
{
}

Paddle::~Paddle()
{
}

void Paddle::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		//input->setKeyUp(sf::Keyboard::W);
			move(0, -0.1);
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		//input->setKeyUp(sf::Keyboard::S);
		move(0, 0.1);
	}
}


void Paddle::collisionResponse(GameObject* collider)
{
	collider->setVelocity(-collider->getVelocity());
}
