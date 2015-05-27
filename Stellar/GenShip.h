#pragma once
#include "DrawableEntity.h"
#include "GenWeapon.h"
#include <memory>
#include <vector>

class GenShip :
	public DrawableEntity
{
public:
	GenShip();
	GenShip(float const& pDirection, float const& pThrust, float const& pTurnSpeed);
	~GenShip();

	float mDirection;
	float mThrust;
	float mTurnSpeed;

	std::vector<std::unique_ptr<GenWeapon>> mWeapons;

	void SetParam(float const& pDirection, float const& pThrust, float const& pTurnSpeed);
	void Accellerate(float pDeltaTime);
	void Turn(bool pDirection, float pDeltaTime);				//0 = left, 1 = right
	void Update(float pDeltaTime);
};

