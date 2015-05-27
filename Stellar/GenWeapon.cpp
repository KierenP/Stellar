#include "GenWeapon.h"


GenWeapon::GenWeapon()
{
}


GenWeapon::~GenWeapon()
{
}



GenWeapon::GenWeapon(float const& pDamage, float const& pProjectileSpeed)
{
	SetParam(pDamage, pProjectileSpeed);
}


void GenWeapon::SetParam(float const& pDamage, float const& pProjectileSpeed)
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

void GenWeapon::Fire()
{
	
}