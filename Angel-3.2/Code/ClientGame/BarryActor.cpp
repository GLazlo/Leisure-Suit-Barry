#include "stdafx.h"
#include "BarryActor.h"




BarryActor::BarryActor()
{
	m_Actor = new Actor();

	theWorld.Add(m_Actor);

	m_Actor->SetColor(1,1,1,1);
	m_Actor->SetSize(7.15f, 11.7f);
	m_Actor->SetPosition(5.0f,5.0f);

	m_Actor->LoadSpriteFrames("barryWalkRight_001.png");
	m_Actor->SetSpriteFrame(0);

	m_Actor->SetLayer(1);

	roomTest = new TreatmentRoom();
}

void BarryActor::MoveRight()
{
	m_position = m_Actor->GetPosition();
	if(roomTest->getMyNode(m_position)!=NO_NODE)
	{
		ScaleBarry(roomTest->getMyLayer(m_position));

		m_goTo = roomTest->getNextNodeRight(m_position);
		m_Actor->MoveTo(m_goTo, 3.0f, true);

		m_Actor->LoadSpriteFrames("res/barryWalk/barryWalkRight_001.png");
		m_Actor->PlaySpriteAnimation(0.1f, SAT_Loop, 0, 9, "barryWalkRight");
	}

	
}

void BarryActor::MoveLeft()
{
	m_position = m_Actor->GetPosition();
	if(roomTest->getMyNode(m_position)!=NO_NODE)
	{
		ScaleBarry(roomTest->getMyLayer(m_position));

		m_goTo = roomTest->getNextNodeLeft(m_position);
		m_Actor->MoveTo(m_goTo, 3.0f, true);

		m_Actor->LoadSpriteFrames("res/barryWalk/barryWalkLeft_001.png");
		m_Actor->PlaySpriteAnimation(0.1f, SAT_Loop, 0, 9, "barryWalkLeft");
	}
}

void BarryActor::MoveDown()
{
	m_position = m_Actor->GetPosition();
	if(roomTest->getMyNode(m_position)!=NO_NODE)
	{
		ScaleBarry(roomTest->getMyLayer(m_position));

		m_goTo = roomTest->getNextNodeDown(m_position);
		m_Actor->MoveTo(m_goTo, 3.0f, true);

		m_Actor->LoadSpriteFrames("res/barryWalk/barryWalkLeft_001.png");
		m_Actor->PlaySpriteAnimation(0.1f, SAT_Loop, 0, 9, "barryWalkLeft");
	}
}

void BarryActor::MoveUp()
{
	m_position = m_Actor->GetPosition();
	if(roomTest->getMyNode(m_position)!=NO_NODE)
	{
		ScaleBarry(roomTest->getMyLayer(m_position));

		m_goTo = roomTest->getNextNodeUp(m_position);
		m_Actor->MoveTo(m_goTo, 3.0f, true);

		m_Actor->LoadSpriteFrames("res/barryWalk/barryWalkRight_001.png");
		m_Actor->PlaySpriteAnimation(0.1f, SAT_Loop, 0, 9, "barryWalkRight");
	}
}

//stops barryWalk animation when he arrives a new node
void BarryActor::MoveStop()
{
	m_position = m_Actor->GetPosition();
	if((m_position.X==m_goTo.X)&&(m_position.Y==m_goTo.Y))
		m_Actor->SetSpriteFrame(0);
}

void BarryActor::ScaleBarry(int layer)
{
	m_Actor->ChangeSizeTo((float)layer,3.0f);
}
	