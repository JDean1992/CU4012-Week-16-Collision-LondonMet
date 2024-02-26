#pragma once
#include "Framework/GameObject.h"
class Paddle :
    public GameObject
{

public:

    Paddle();

    ~Paddle();

    void handleInput(float dt);

    void collisionResponse(GameObject* collider);
};

