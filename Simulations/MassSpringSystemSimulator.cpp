#include "MassSpringSystemSimulator.h"

MassSpringSystemSimulator::MassSpringSystemSimulator()
{
	m_iIntegrator = 0;
    m_fDamping = 0.0f;
	m_fStiffness = 0.0f;
	m_fMass = 0.0f;
	massPoints;
	springs;
	//provides int indices for masspoints
	MassPointCounter = 0;

}

MassPoint::MassPoint() {
	position = NULL;
	velocity = NULL;
	isFixed = NULL;
}

Spring::Spring() {
	massPoint1 = NULL;
	massPoint2 = NULL;
	initialLength = 0;
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
	//TODO get the constructors to work
	MassPoint Masspoint;
	Masspoint.position = position;
	Masspoint.velocity = Velocity;
	Masspoint.isFixed = isFixed;
	//add new MassPoint to the masspoints list of the massspringsystem
	this->massPoints.push_back(Masspoint);
	this->MassPointCounter++;
	return 0;
}

void MassSpringSystemSimulator::addSpring(int masspoint1, int masspoint2, float initialLength)
{
	Spring spring;
	spring.massPoint1 = masspoint1;
	spring.massPoint2 = masspoint2;
	spring.initialLength = initialLength;
	//add new spring to the Springs list of the massspringsystem
	this->springs.push_back(spring);
	return;
}

int MassSpringSystemSimulator::getNumberOfMassPoints()
{
	return this->MassPointCounter;
}

int MassSpringSystemSimulator::getNumberOfSprings()
{
	return this->springs.size();
}

Vec3 MassSpringSystemSimulator::getPositionOfMassPoint(int index)
{
    // TODO
	Vec3 pos;
	auto massPoint = this->massPoints.begin();
	std::advance(massPoint, index);
	pos =(MassPoint) massPoint.position;
	return pos;
}

Vec3 MassSpringSystemSimulator::getVelocityOfMassPoint(int index)
{
	// TODO
	Vec3 vel;
	auto massPoint = this->massPoints.begin();
	std::advance(massPoint, index);
	vel = (MassPoint)massPoint.velocity;
	return vel;
}

void MassSpringSystemSimulator::applyExternalForce(Vec3 force)
{
	//I belive this might be to calculate the force variable used in the accelaration calculation
}
