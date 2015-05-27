#pragma once
#include <math.h>


class GenWeapon
{
public:
	GenWeapon();
	GenWeapon(float const& pDamage, float const& pProjectileSpeed);
	~GenWeapon();

	float mDamage;
	float mProjectileSpeed;
	float mDirection;

	void SetParam(float const& pDamage, float const& pProjectileSpeed);
	virtual void Fire();
	float* CalculateVelocities();
};


