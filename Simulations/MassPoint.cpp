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

const char* MassPoint::getTestCasesStr()
{
	return nullptr;
}

void MassPoint::initUI(DrawingUtilitiesClass* DUC)
{
}

void MassPoint::reset()
{
}

void MassPoint::drawFrame(ID3D11DeviceContext* pd3dImmediateContext)
{
}

void MassPoint::notifyCaseChanged(int testCase)
{
}

void MassPoint::externalForcesCalculations(float timeElapsed)
{
}

void MassPoint::simulateTimestep(float timeStep)
{
}

void MassPoint::onClick(int x, int y)
{
}

void MassPoint::onMouse(int x, int y)
{
}
