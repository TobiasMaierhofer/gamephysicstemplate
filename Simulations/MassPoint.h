#ifndef MASSPOINT_h
#define MASSPOINT_h
#include "Simulator.h"

class MassPoint : public Simulator {
public:
	MassPoint();

	//data Attributes
	Vec3 position;
	Vec3 velocity;
	boolean isFixed;

	Vec3 MassPoint::getPosition();
	Vec3 MassPoint::getVelocity();
	Vec3 MassPoint::getIsFixed();

	const char* getTestCasesStr();
	void initUI(DrawingUtilitiesClass* DUC);
	void reset();
	void drawFrame(ID3D11DeviceContext* pd3dImmediateContext);
	void notifyCaseChanged(int testCase);
	void externalForcesCalculations(float timeElapsed);
	void simulateTimestep(float timeStep);
	void onClick(int x, int y);
	void onMouse(int x, int y);

};

#endif