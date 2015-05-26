#include "GenWeapon.h"


GenWeapon::GenWeapon()
{
}


GenWeapon::~GenWeapon()
{
}


template <typename T>
GenWeapon<T>::GenWeapon(T const& pDamage, T const& pProjectileSpeed)
{
	SetParam(pDamage, pProjectileSpeed);
}


template <typename T>
void GenWeapon<T>::SetParam(T const& pDamage, T const& pProjectileSpeed)
{
	mDamage = pDamage;
	mProjectileSpeed = pProjectileSpeed;
}


float* GenWeapon::CalculateVelocities()
{
	float velocities[2];											

	velocities[0] = mProjectileSpeed * cos(mDirection + 90);
	velocities[1] = -(mProjectileSpeed * sin(mDirection + 90));

	return velocities;

	
}