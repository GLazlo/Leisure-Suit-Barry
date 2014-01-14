#include "stdafx.h"
#include "BarryActor.h"
#include <math.h>



BarryActor::BarryActor()
{
	m_Actor = new Actor();

	theWorld.Add(m_Actor);

	m_Actor->SetColor(1,1,1,1);
	m_Actor->SetSize(4.766666f, 7.8f);
	m_Actor->ChangeSizeTo(6,0.000001f);
	m_Actor->SetPosition(-8.515f,-4.687f);

	m_Actor->LoadSpriteFrames("./res/barryWalk/barryWalkRight_001.png");
	m_Actor->SetSpriteFrame(0);

	m_Actor->SetLayer(6);

	m_treatment = new TreatmentRoom();
	roomTest = m_treatment;
}

void BarryActor::MoveRight()
{
	m_position = m_Actor->GetPosition();
	m_myNode = roomTest->getMyNode(m_position);
	if(m_myNode!=NO_NODE)
	{
		m_goTo = roomTest->getNextNodeRight(m_position);
		m_Actor->MoveTo(m_goTo, CalcWalkTime(), true);

		ScaleBarry(roomTest->getMyLayer(m_goTo));

		m_Actor->LoadSpriteFrames("./res/barryWalk/barryWalkRight_001.png");
		m_Actor->PlaySpriteAnimation(0.1f, SAT_Loop, 0, 9, "barryWalkRight");
	}

	
}

void BarryActor::MoveLeft()
{
	m_position = m_Actor->GetPosition();
	m_myNode = roomTest->getMyNode(m_position);
	if(m_myNode!=NO_NODE)
	{
		m_goTo = roomTest->getNextNodeLeft(m_position);
		m_Actor->MoveTo(m_goTo, CalcWalkTime(), true);

		ScaleBarry(roomTest->getMyLayer(m_goTo));

		m_Actor->LoadSpriteFrames("./res/barryWalk/barryWalkLeft_001.png");
		m_Actor->PlaySpriteAnimation(0.1f, SAT_Loop, 0, 9, "barryWalkLeft");
	}
}

void BarryActor::MoveDown()
{
	m_position = m_Actor->GetPosition();
	m_myNode = roomTest->getMyNode(m_position);
	if(m_myNode!=NO_NODE)
	{

		m_goTo = roomTest->getNextNodeDown(m_position);
		m_Actor->MoveTo(m_goTo, CalcWalkTime(), true);

		ScaleBarry(roomTest->getMyLayer(m_goTo));

		m_Actor->LoadSpriteFrames("./res/barryWalk/barryWalkLeft_001.png");
		m_Actor->PlaySpriteAnimation(0.1f, SAT_Loop, 0, 9, "barryWalkLeft");
	}
}

void BarryActor::MoveUp()
{
	m_position = m_Actor->GetPosition();
	m_myNode = roomTest->getMyNode(m_position);
	if(m_myNode!=NO_NODE)
	{
		m_goTo = roomTest->getNextNodeUp(m_position);
		m_Actor->MoveTo(m_goTo, CalcWalkTime(), true);

		ScaleBarry(roomTest->getMyLayer(m_goTo));

		m_Actor->LoadSpriteFrames("./res/barryWalk/barryWalkRight_001.png");
		m_Actor->PlaySpriteAnimation(0.1f, SAT_Loop, 0, 9, "barryWalkRight");
	}
}

//stops barryWalk animation when he arrives a new node
void BarryActor::MoveStop()
{
	m_position = m_Actor->GetPosition();
	if((m_position.X==m_goTo.X)&&(m_position.Y==m_goTo.Y))
	{
		m_Actor->PlaySpriteAnimation(0.1f, SAT_None, 0, 0, "barryWalkRight");
	}
}

void BarryActor::ScaleBarry(int layer)
{
	m_Actor->ChangeSizeTo((float)layer,CalcWalkTime());
}
	
float BarryActor::CalcWalkTime()
{
	return ((sqrt(pow(m_goTo.X-m_position.X,2)+pow(m_goTo.Y-m_position.Y,2)))*0.25f);
}

int BarryActor::GetMyNode()
{
	m_position = m_Actor->GetPosition();
	m_myNode = roomTest->getMyNode(m_position);
	if(m_myNode!=NO_NODE)
	{
		return m_myNode;
	}
	return NO_NODE;
}

Room* BarryActor::GetRoom()
{
	return roomTest;
}
String BarryActor::GetInv()
{
	String inv = "";
	inv += m_treatment->getInvRoom();
	return inv;
}