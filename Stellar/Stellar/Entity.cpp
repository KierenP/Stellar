#include "Entity.h"


Entity::Entity()
{
}


Entity::~Entity()
{
}


void Entity::Update(float pDelta)
{
	mPx += mVx * pDelta;
	mPy += mVy * pDelta;
}
