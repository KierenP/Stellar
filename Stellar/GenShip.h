#pragma once
#include "DrawableSpriteEntity.h"
#include "GenWeapon.h"
#include <memory>
#include <vector>

class GenShip :
	public DrawableSpriteEntity
{
public:
	GenShip();
	GenShip(float const& pDirection, float const& pThrust, float const& pTurnSpeed, float const& pPx, float const& pPy, float pVx, float pVy);
	~GenShip();

	float mDirection;
	float mThrust;
	float mTurnSpeed;
	float Targetx, Targety;

	std::vector<std::unique_ptr<GenWeapon>> mWeapons;

	void GenShip::SetParam(float const& pDirection, float const& pThrust, float const& pTurnSpeed, float const& pPx, float const& pPy, float pVx, float pVy);
	void Accellerate(float pDeltaTime);
	void Turn(bool pDirection, float pDeltaTime);				//0 = left, 1 = right
	void Update();
	void PointTargetDir();
};

