#pragma once
class Entity
{
public:
	Entity();
	Entity(float pPx, float pPy, float pVx, float pVy) : mPx(pPx), mPy(pPy), mVx(pVx), mVy(pVy) {}
	virtual ~Entity();
	
	float mPx, mPy;			//Position x and y
	float mVx, mVy;			//Velocity x and y
	
	virtual void Update(float pDelta);		//Delta is seconds since last frame	
};

