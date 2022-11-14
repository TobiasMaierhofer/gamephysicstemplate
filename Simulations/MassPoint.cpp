#include "MassPoint.h"

MassPoint::MassPoint() {
	position = NULL;
	velocity = NULL;
	isFixed = NULL;
}

Vec3 MassPoint::getPosition()
{
	return this->position;
}

Vec3 MassPoint::getVelocity()
{
	return this->velocity;
}

Vec3 MassPoint::getIsFixed()
{
	return this->isFixed;
}