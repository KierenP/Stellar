#include "GenWeapon.h"

template <typename T>
GenWeapon<T>::GenWeapon()
{
}

template <typename T>
GenWeapon<T>::~GenWeapon()
{
}


template<typename T>
GenWeapon<T>::GenWeapon(T const& pDamage, T const& pProjectileSpeed)
{
	SetParam(pDamage, pProjectileSpeed);
}


template<typename T>
void GenWeapon<T>::SetParam(T const& pDamage, T const& pProjectileSpeed)
{
	mDamage = pDamage;
	mProjectileSpeed = mProjectileSpeed;
}

template<typename T>
float* GenWeapon<T>::CalculateVelocities()
{
	float[2] velocities;

	velocities[0] = mProjectileSpeed * cos(mDirection + 90)
	velocities[1] = -(mProjectileSpeed * sin(mDirection + 90))

	return velocities;
}