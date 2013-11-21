#include "stdafx.h"
#include "MyGameManager.h"

/*** Help class to find nodes ***/
class Mouse : public MouseListener
{
public:
	Mouse()
	{
		i=1;
	}
	void MouseDownEvent(Vec2i screenCoordinates, MouseButtonInput button)
	{
		Vector2 worldC;
		worldC = MathUtil::ScreenToWorld(screenCoordinates.X, screenCoordinates.Y);
		std::cout << "cord" << i << ": " << worldC.X << " " << worldC.Y << std::endl;
		i++;
	}
private:
	unsigned int i;
};

MyGameManager* MyGameManager::m_MyGameManager = NULL;

MyGameManager::MyGameManager()
{
	//add background actor
	FullScreenActor* Background = new FullScreenActor();
	if(!Background->SetSprite("res/rooms/treatmentRoom.jpg"))
		std::cout << "failed to load background sprite" << std::endl;
	theWorld.Add(Background);

	Barry = new BarryActor();

	Mouse* myMouse = new Mouse();
	
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


