#include "Spring.h"

Spring::Spring() {
	massPoint1 = NULL;
	massPoint2 = NULL;
	initialLength = 0;
}

const char* Spring::getTestCasesStr()
{
	return nullptr;
}

void Spring::initUI(DrawingUtilitiesClass* DUC)
{
}

void Spring::reset()
{
}

void Spring::drawFrame(ID3D11DeviceContext* pd3dImmediateContext)
{
}

void Spring::notifyCaseChanged(int testCase)
{
}

void Spring::externalForcesCalculations(float timeElapsed)
{
}

void Spring::simulateTimestep(float timeStep)
{
}

void Spring::onClick(int x, int y)
{
}

void Spring::onMouse(int x, int y)
{
}
