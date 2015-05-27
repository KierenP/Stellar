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
	float velocity[2];											

	velocity[0] = mProjectileSpeed * cos(mDirection + 90);
	velocity[1] = -(mProjectileSpeed * sin(mDirection + 90));

	return velocity;

	
}