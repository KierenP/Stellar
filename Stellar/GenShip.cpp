#include "GenShip.h"


GenShip::GenShip()
{
}


GenShip::~GenShip()
{
}

GenShip::GenShip(float const& pDirection, float const& pThrust, float const& pTurnSpeed)
{
	SetParam(pDirection, pThrust, pTurnSpeed);
}

void GenShip::SetParam(float const& pDirection, float const& pThrust, float const& pTurnSpeed)
{
	mDirection = pDirection;
	mThrust = pThrust;
	mTurnSpeed = pTurnSpeed;
}

void GenShip::Accellerate(float pDeltaTime)					//Direction + 90 becuase in sfml direction "0" is (obviously) unchanged
{
	mVx += mThrust * cos(mDirection + 90) * pDeltaTime;		//and because the sprite faces "up" by defult, 0 is up
	mVy -= mThrust * sin(mDirection + 90) * pDeltaTime;		//but in code 0 degrees would be directly left, and up is 90 degrees
}

void GenShip::Turn(bool pDirection, float pDeltaTime)
{
	if (pDirection == 0)
	{
		mDirection += mTurnSpeed * pDeltaTime;		//turn left
	}
	
	if (pDirection == 1)
	{
		mDirection -= mTurnSpeed * pDeltaTime;		//turn right
	}
}

void GenShip::Update(float pDeltaTime)
{

}