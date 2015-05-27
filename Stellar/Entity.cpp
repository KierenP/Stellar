#include "Entity.h"


Entity::Entity()
{
}


Entity::~Entity()
{
}


void Entity::Update(float pDelta)
{
	mPx += mVx * pDelta;		//position x += velocity x * time since last frame
	mPy += mVy * pDelta;
}
