#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include"Framework/Collision.h"
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Squares.h"
#include "Paddle.h"
#include "Paddle1.h"

class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.
	Squares ball;

	Paddle p1;
	Paddle1 p2;
};