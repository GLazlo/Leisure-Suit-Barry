#include "stdafx.h"
#include "MyGameManager.h"

MyGameManager* MyGameManager::m_MyGameManager = NULL;

MyGameManager::MyGameManager()
{
	//add background actor
	FullScreenActor* Background = new FullScreenActor();
	if(!Background->SetSprite("res/rooms/treatmentRoom.jpg"))
		std::cout << "failed to load background sprite" << std::endl;
	theWorld.Add(Background);

	Barry = new BarryActor();
	

	m_obstacle = new Actor();

	theWorld.Add(m_obstacle);

	m_obstacle->SetColor(1,1,1,1);
	m_obstacle->SetSize(5.0f);
	m_obstacle->SetDrawShape(ADS_Circle);
	m_obstacle->SetPosition(7.0f, 0.0f);

	m_obstacle->SetSprite("collision.png");

	m_obstacle->SetLayer(3);
}

MyGameManager& MyGameManager::GetInstance()
{
	if(m_MyGameManager == NULL)
	{
		m_MyGameManager = new MyGameManager();
	}

	return *m_MyGameManager;
}

void MyGameManager::Update(float dt)
{
	if(theInput.IsKeyDown(GLFW_KEY_RIGHT))
		Barry->MoveRight();
	else if(theInput.IsKeyDown(GLFW_KEY_LEFT))
		Barry->MoveLeft();
	else if(theInput.IsKeyDown(GLFW_KEY_UP))
		Barry->MoveUp();
	else if(theInput.IsKeyDown(GLFW_KEY_DOWN))
		Barry->MoveDown();
	else
		Barry->MoveStop();
}
