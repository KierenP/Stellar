#pragma once
#include "DrawableEntity.h"


class GenWeapon :
	public DrawableEntity
{
public:
	GenWeapon();
	template <typename T>
	GenWeapon(T const& pDamage, T const& pProjectileSpeed);
	~GenWeapon();

	float mDamage;
	float mProjectileSpeed;
	float mDirection;

	template <typename T>
	void SetParam(T const& pDamage, T const& pProjectileSpeed);
	virtual void Fire();
	float* CalculateVelocities();
};


