#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	ball.setSize(sf::Vector2f(50, 50));
	ball.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	ball.setPosition(100, 500);
	ball.setVelocity(500, 500);
	ball.setFillColor(sf::Color::Red);

	p1.setSize(sf::Vector2f(50, 150));
	p1.setCollisionBox(sf::FloatRect(0, 0, 50, 150));
	p1.setPosition(0, 200);
	p1.setInput(input);
	p1.setFillColor(sf::Color::Blue);

	p2.setSize(sf::Vector2f(50, 150));
	p2.setCollisionBox(sf::FloatRect(0, 0, 50, 150));
	p2.setPosition(1000, 200);
	p2.setInput(input);
	p2.setFillColor(sf::Color::Red);

	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	p1.handleInput(dt);
	p2.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);
	//for (int i = 0; i < 2; i++)
	//{
		//CollisionSquare[i].update(dt);
	//}
	
	//if (Collision::checkBoundingBox(&CollisionSquare[0], &CollisionSquare[1]))
	//{
	//	CollisionSquare[0].CollisionResponse(&CollisionSquare[1]);
	//	CollisionSquare[1].CollisionResponse(&CollisionSquare[0]);
	//}
	if (Collision::checkBoundingBox(&p1, &ball))
	{
		p1.collisionResponse(&ball);
	}
	if (Collision::checkBoundingBox(&p2, &ball))
	{
		p2.collisionResponse(&ball);
	}

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
	window->draw(p1);
	window->draw(p2);
	endDraw();
}
