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

const char* MassSpringSystemSimulator::getTestCasesStr()
{
	return "Demo1,Demo2,Demo3,Demo4";
}

void MassSpringSystemSimulator::initUI(DrawingUtilitiesClass* DUC)
{
	this->DUC = DUC;
	switch (m_iTestCase)
	{
	case 3:
		//TODO UI to dynamically choose integration method
		TwAddVarRW(DUC->g_pTweakBar, "Mass", TW_TYPE_FLOAT, &m_fMass, "min=0.01 step=0.05");
		TwAddVarRW(DUC->g_pTweakBar, "Stiffness", TW_TYPE_FLOAT, &m_fStiffness, "min=0.01 step=0.5");
		TwAddVarRW(DUC->g_pTweakBar, "Damping", TW_TYPE_FLOAT, &m_fDamping, "min=0.0 step=0.05");
		//TwAddVarRW(DUC->g_pTweakBar, "Timestep", TW_TYPE_FLOAT, &timestep, "min=0.0 step=0.005");
		break;
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
	switch (m_iTestCase)
	{
	case 3:
		//Demo 4:draw a Mass Spring System with atleast 10 Masspoints and 10 Springs
		//Draw also outer bounds to serve as walls with which the mass srping system can collide
		break;
	default:
		//draw the basic 3D Mass Spring System from table 1.1of the Exercise Sheet
		break;
	}
}

void MassSpringSystemSimulator::notifyCaseChanged(int testCase)
{
	m_iTestCase = testCase;
	switch (m_iTestCase)
	{
	case 0:
		cout << "Demo 1!\n";
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
	}
}

void MassSpringSystemSimulator::externalForcesCalculations(float timeElapsed)
{
	//I believe this function serves to allow the user to apply external forces on a massspringsystem by using the mouse.
	//For reference watch the video sample exercise 1 on moodle.
}

void MassSpringSystemSimulator::simulateTimestep(float timeStep)
{
	// update current setup for each frame
	switch (this->m_iIntegrator)
	{// handling different Integration methods
	//leap frog method
	case 1:break;
	//midpoint method
	case 2:
		//1.calculate acceleration at start
		//2.calculate position at midpoint: midPos = oldPos + (1/2)*timestep * oldVel
		//3.Calculate Forces at midpoint
		//5.Calculate accelaration at midpoint
		//6.calculate velocity at midpoint
		//7.Calculate new Pos at full timestep: newPos = oldPos + timestep*midVel
		//8.Calculate new Velocity at full timestep: newVel: oldVel + timestep*midAccelaration
		break;
    //Euler method
	default:
		list<Spring>::iterator it = this->springs.begin();
		//new position and velocity values for masspoint 1 of the current spring
		Vec3 newPos1;
		Vec3 newVel1;
		//new position and velocity values for masspoint 2 of the current spring
		Vec3 newPos2;
		Vec3 newVel2;

		for (int i = 1; i <= springs.size(); i++) {
			Spring current = *it;
			//1.update position: newPos = oldPos + velocity*timestep
			newPos1= this->getPositionOfMassPoint(current.massPoint1) + this->getVelocityOfMassPoint(current.massPoint1) * timeStep;
			newPos2 = this->getPositionOfMassPoint(current.massPoint2) + this->getVelocityOfMassPoint(current.massPoint2) * timeStep;
			//2.calculate direction vectors
			Vec3 dir1 = this->getPositionOfMassPoint(current.massPoint1)- this->getPositionOfMassPoint(current.massPoint2);
			Vec3 dir2 = this->getPositionOfMassPoint(current.massPoint2) - this->getPositionOfMassPoint(current.massPoint1);
		//3.calculate length of direction vectors
			float l = sqrt(dir1.x ^ 2 + dir1.y ^ 2 + dir1.z ^ 2);
		//4.normalize direction vectors
			Vec3 dir1norm = dir1 / l;
			Vec3 dir2norm = dir1norm * -1;
		//5.calculate Forces at origin position
			Vec3 f1 =-this->m_fStiffness(l - current.initialLength) * dir1norm;
			Vec3 f2 = f1 * -1;
		//6.calculate acceleration
			Vec3 a1 = f1 / this->m_fMass;
			Vec3 a2 = f2 / this->m_fMass;
		//7.calculate new velocity: newVel = oldVel + accelaration*timestep
			newVel1 = this->getVelocityOfMassPoint(current.massPoint1) + a1 * timeStep;
			newVel2 = this->getVelocityOfMassPoint(current.massPoint2) + a2 * timeStep;
			//set iterator it to the next spring
			std::advance(it, 1);
			//set the values of the masspoints to newPos1+2 and newVel1+2
			//TODO
		}
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
	return MassPointCounter;
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
  
	list<MassPoint>::iterator it = this->massPoints.begin();
	std::advance(it, index);
	MassPoint result = *it;
	return result.position;
}

Vec3 MassSpringSystemSimulator::getVelocityOfMassPoint(int index)
{
	
	list<MassPoint>::iterator it = this->massPoints.begin();
	std::advance(it, index);
	MassPoint result = *it;
	return result.velocity;
}

void MassSpringSystemSimulator::applyExternalForce(Vec3 force)
{
	//I belive this might be to calculate the force variable used in the accelaration calculation or to apply the external forces 
	//generated by the user through the mouse for interactivity with the mass spring system. Or maybe sets forces like
	//gravity to a specific vec3.Not sure.
}
