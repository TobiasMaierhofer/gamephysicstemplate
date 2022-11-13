#include "MassSpringSystemSimulator.h"

MassSpringSystemSimulator::MassSpringSystemSimulator()
{
	int m_iIntegrator = 0;
	float m_fDamping = 0.0f;
	float m_fStiffness = 0.0f;
	float m_fMass = 0.0f;
	std::list<MassPoint> massPoints = {};
	std::list<Spring> springs ={};

}

const char* MassSpringSystemSimulator::getTestCasesStr()
{
	return "Demo1,Demo2,Demo3,Demo4";
}

void MassSpringSystemSimulator::initUI(DrawingUtilitiesClass* DUC)
{
	this->DUC = DUC;
	switch (m_iTestCase)
	{
	case 0:break;
	case 1:
		//TwAddVarRW(DUC->g_pTweakBar, "Num Spheres", TW_TYPE_INT32, &m_iNumSpheres, "min=1");
		//TwAddVarRW(DUC->g_pTweakBar, "Sphere Size", TW_TYPE_FLOAT, &m_fSphereSize, "min=0.01 step=0.01");
		break;
	case 2:break;
	case 3:break;
	default:break;
	}
}

void MassSpringSystemSimulator::reset()
{
	m_mouse.x = m_mouse.y = 0;
	m_trackmouse.x = m_trackmouse.y = 0;
	m_oldtrackmouse.x = m_oldtrackmouse.y = 0;
	//Bin Mir nicht ganz sicher was diese funktion eig machen soll
}

void MassSpringSystemSimulator::drawFrame(ID3D11DeviceContext* pd3dImmediateContext)
{
}

void MassSpringSystemSimulator::notifyCaseChanged(int testCase)
{
	m_iTestCase = testCase;
	switch (m_iTestCase)
	{
	case 0:
		cout << "Demo 1 !\n";
		//m_vfMovableObjectPos = Vec3(0, 0, 0);
		//m_vfRotate = Vec3(0, 0, 0);
		break;
	case 1:
		cout << "Demo 2!\n";
		//m_iNumSpheres = 100;
		//m_fSphereSize = 0.05f;
		break;
	case 2:
		cout << "Demo 3!\n";
		break;
	case 3:
		cout << "Demo 4!\n";
		break;
	default:
		cout << "Empty Test!\n";
		break;
	}
}

void MassSpringSystemSimulator::externalForcesCalculations(float timeElapsed)
{
}

void MassSpringSystemSimulator::simulateTimestep(float timeStep)
{
	// update current setup for each frame
	switch (this->m_iIntegrator)
	{// handling different Integration methods
	//leap frog method
	case 1:break;
	//midpoint method
	case 2:break;
    //Euler method
	default:
		break;
	}
}

void MassSpringSystemSimulator::onClick(int x, int y)
{
	m_trackmouse.x = x;
	m_trackmouse.y = y;
}

void MassSpringSystemSimulator::onMouse(int x, int y)
{
	m_oldtrackmouse.x = x;
	m_oldtrackmouse.y = y;
	m_trackmouse.x = x;
	m_trackmouse.y = y;
}

void MassSpringSystemSimulator::setMass(float mass)
{
	m_fMass = mass;
}

void MassSpringSystemSimulator::setStiffness(float stiffness)
{
	m_fStiffness = stiffness;
}

void MassSpringSystemSimulator::setDampingFactor(float damping)
{
	m_fDamping = damping;
}

int MassSpringSystemSimulator::addMassPoint(Vec3 position, Vec3 Velocity, bool isFixed)
{
	return 0;
}

void MassSpringSystemSimulator::addSpring(int masspoint1, int masspoint2, float initialLength)
{
}

int MassSpringSystemSimulator::getNumberOfMassPoints()
{
	return 0;
}

int MassSpringSystemSimulator::getNumberOfSprings()
{
	return 0;
}

Vec3 MassSpringSystemSimulator::getPositionOfMassPoint(int index)
{
	return Vec3();
}

Vec3 MassSpringSystemSimulator::getVelocityOfMassPoint(int index)
{
	return Vec3();
}

void MassSpringSystemSimulator::applyExternalForce(Vec3 force)
{
}
