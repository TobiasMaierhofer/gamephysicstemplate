#ifndef SPRING_h
#define SPRING_h
#include "Simulator.h"

class Spring : public Simulator {
public:
	Spring();

	//data Attributes
	int massPoint1;
	int massPoint2;
	float initialLength;;

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
