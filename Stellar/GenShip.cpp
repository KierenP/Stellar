#include "GenShip.h"


GenShip::GenShip()
{
}


GenShip::~GenShip()
{
}

GenShip::GenShip(float const& pThrust, float const& pTurnSpeed, float const& pPx, float const& pPy, float pVx, float pVy)
{
	SetParam(pThrust, pTurnSpeed, pPx, pPy, pVx, pVy);
}

void GenShip::SetParam(float const& pThrust, float const& pTurnSpeed, float const& pPx, float const& pPy, float pVx, float pVy)
{
	mThrust = pThrust;
	mTurnSpeed = pTurnSpeed;
	mPx = pPx;
	mPy = pPy;
	mVx = pVx;
	mVy = pVy;
	HasTarget = false;
	mSpriteDirection = 0;
}

void GenShip::Accellerate(float pDeltaTime)					//Direction + 90 becuase in sfml direction "0" is (obviously) unchanged
{
	mVx += mThrust * cos(mThrustDirection * 3.14159 / 180) * pDeltaTime;		//and because the sprite faces "up" by defult, 0 is up
	mVy += mThrust * sin(mThrustDirection * 3.14159 / 180) * pDeltaTime;		//but in code 0 degrees would be directly left, and up is 90 degrees
}

void GenShip::Turn(bool pDirection, float pDeltaTime)
{
	if (pDirection == 0)
	{
		mSpriteDirection += mTurnSpeed * pDeltaTime;		//turn left
	}
	
	if (pDirection == 1)
	{
		mSpriteDirection -= mTurnSpeed * pDeltaTime;		//turn right
	}
}

void GenShip::Update(float pDeltaTime)
{
	DrawObj.setPosition(sf::Vector2f(mPx, mPy));
	DrawObj.setRotation(mSpriteDirection + 90);

	if (HasTarget)
	{
		Accellerate(pDeltaTime);
		PointTargetDir(pDeltaTime);
	}
		
	mPx += mVx;
	mPy += mVy;
}

void GenShip::PointTargetDir(float pDeltaTime)
{
	float DistanceToTarget = sqrt((mPx - Targetx) * (mPx - Targetx) + (mPy - Targety) * (mPy - Targety));

	float TargetDirection = atan2f(Targety - (mPy + DrawObj.getOrigin().y / 2), Targetx - (mPx + DrawObj.getOrigin().x / 2)) / 3.14159 * 180;

	if (DistanceToTarget < StartDistanceToTarget / 2)	//Is more than 1/2 way there
	{
		mThrustDirection = atan2f(-mVy, -mVx) / 3.14159 * 180;	//Thrust against velocity
	}
	else
	{
		mThrustDirection = TargetDirection; //thrust towards target
	}

	if (DistanceToTarget > 50)	//Hardcoded value, need to change to somthing relitive to original distance
	{
		if (TargetDirection > mSpriteDirection + 5)
		{
			Turn(0, pDeltaTime);
		}

		if (TargetDirection < mSpriteDirection - 5)
		{
			Turn(1, pDeltaTime);
		}
	}
}

void GenShip::SetTarget(float tx, float ty)
{
	Targetx = tx;
	Targety = ty;
	HasTarget = true;

	StartDistanceToTarget = sqrt((mPx - tx) * (mPx - tx) + (mPy - ty) * (mPy - ty));
}