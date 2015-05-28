#pragma once
#include "Entity.h"
#include "GenWeapon.h"
#include <memory>
#include <vector>
#include <SFML\Graphics.hpp>

class GenShip :
	public Entity
{
public:
	GenShip();
	GenShip(float const& pThrust, float const& pTurnSpeed, float const& pPx, float const& pPy, float pVx = 0, float pVy = 0);
	~GenShip();

	float mSpriteDirection;
	float mThrustDirection;
	float mThrust;
	float mTurnSpeed;
	float Targetx, Targety;
	bool HasTarget;
	float StartDistanceToTarget;

	sf::Sprite DrawObj;
	std::vector<std::unique_ptr<GenWeapon>> mWeapons;

	void GenShip::SetParam(float const& pThrust, float const& pTurnSpeed, float const& pPx, float const& pPy, float pVx = 0, float pVy = 0);
	void Accellerate(float pDeltaTime);
	void Turn(bool pDirection, float pDeltaTime);				//0 = left, 1 = right
	void Update(float pDeltaTime);
	void PointTargetDir(float pDeltaTime);
	void SetTarget(float tx, float ty);
};

