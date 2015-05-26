#pragma once
#include "DrawableEntity.h"

template <typename T>
class GenWeapon :
	public DrawableEntity
{
public:
	GenWeapon();
	GenWeapon(T const& pDamage, T const& pProjectileSpeed);
	~GenWeapon();

	float mDamage;
	float mProjectileSpeed;
	float mDirection;

	void SetParam(T const& pDamage, T const& pProjectileSpeed);
	virtual void Fire();
	float* CalculateVelocities();
};


