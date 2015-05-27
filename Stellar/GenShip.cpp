#include "GenShip.h"


GenShip::GenShip()
{
}


GenShip::~GenShip()
{
}

GenShip::GenShip(float const& pDirection, float const& pThrust, float const& pTurnSpeed, float const& pPx, float const& pPy, float pVx, float pVy)
{
	SetParam(pDirection, pThrust, pTurnSpeed, pPx, pPy, pVx, pVy);
}

void GenShip::SetParam(float const& pDirection, float const& pThrust, float const& pTurnSpeed, float const& pPx, float const& pPy, float pVx, float pVy)
{
	mDirection = pDirection;
	mThrust = pThrust;
	mTurnSpeed = pTurnSpeed;
	mPx = pPx;
	mPy = pPy;
	mVx = pVx;
	mVy = pVy;
}

void GenShip::Accellerate(float pDeltaTime)					//Direction + 90 becuase in sfml direction "0" is (obviously) unchanged
{
	mVx -= mThrust * cos(mDirection * 3.14159 / 180) * pDeltaTime;		//and because the sprite faces "up" by defult, 0 is up
	mVy -= mThrust * sin(mDirection * 3.14159 / 180) * pDeltaTime;		//but in code 0 degrees would be directly left, and up is 90 degrees
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

void GenShip::Update()
{
	DrawObj.setPosition(sf::Vector2f(mPx, mPy));
	DrawObj.setRotation(mDirection - 90);
	PointTargetDir();

	Accellerate(0.001);

	mPx += mVx;
	mPy += mVy;
}

void GenShip::PointTargetDir()
{
	mDirection = atan2f(mPy + DrawObj.getTexture()->getSize().y / 2 - Targety, mPx + DrawObj.getTexture()->getSize().y / 2 - Targetx) / 3.14159 * 180;
}