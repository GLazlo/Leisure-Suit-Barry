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

	m_Barry = new BarryActor();

	Mouse* myMouse = new Mouse();
	m_input = new TextInput();
	m_comm = new CommText();
	Subscribe();
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
		m_Barry->MoveRight();
	else if(theInput.IsKeyDown(GLFW_KEY_LEFT))
		m_Barry->MoveLeft();
	else if(theInput.IsKeyDown(GLFW_KEY_UP))
		m_Barry->MoveUp();
	else if(theInput.IsKeyDown(GLFW_KEY_DOWN))
		m_Barry->MoveDown();

	else
		m_Barry->MoveStop();

	
}

void MyGameManager::Subscribe()
{
	theSwitchboard.SubscribeTo(this,"RA");
	theSwitchboard.SubscribeTo(this,"RB");
	theSwitchboard.SubscribeTo(this,"RC");
	theSwitchboard.SubscribeTo(this,"RD");
	theSwitchboard.SubscribeTo(this,"RE");
	theSwitchboard.SubscribeTo(this,"RF");
	theSwitchboard.SubscribeTo(this,"RG");
	theSwitchboard.SubscribeTo(this,"RH");
	theSwitchboard.SubscribeTo(this,"RI");
	theSwitchboard.SubscribeTo(this,"RJ");
	theSwitchboard.SubscribeTo(this,"RK");
	theSwitchboard.SubscribeTo(this,"RL");
	theSwitchboard.SubscribeTo(this,"RM");
	theSwitchboard.SubscribeTo(this,"RN");
	theSwitchboard.SubscribeTo(this,"RO");
	theSwitchboard.SubscribeTo(this,"RP");
	theSwitchboard.SubscribeTo(this,"RQ");
	theSwitchboard.SubscribeTo(this,"RR");
	theSwitchboard.SubscribeTo(this,"RS");
	theSwitchboard.SubscribeTo(this,"RT");
	theSwitchboard.SubscribeTo(this,"RU");
	theSwitchboard.SubscribeTo(this,"RV");
	theSwitchboard.SubscribeTo(this,"RW");
	theSwitchboard.SubscribeTo(this,"RX");
	theSwitchboard.SubscribeTo(this,"RY");
	theSwitchboard.SubscribeTo(this,"RZ");
	theSwitchboard.SubscribeTo(this,"RSPACE");
	theSwitchboard.SubscribeTo(this,"RENTER");
}

void MyGameManager::ReceiveMessage(Message *message)
{
	m_comm->Hide();
	if (message->GetMessageName() == "RA")
	{
		m_input->AddChar(GLFW_KEY_A);
	}
	else if(message->GetMessageName() == "RB")
	{
		m_input->AddChar(GLFW_KEY_B);
	}
	else if(message->GetMessageName() == "RC")
	{
		m_input->AddChar(GLFW_KEY_C);
	}
	else if(message->GetMessageName() == "RD")
	{
		m_input->AddChar(GLFW_KEY_D);
	}
	else if(message->GetMessageName() == "RE")
	{
		m_input->AddChar(GLFW_KEY_E);
	}
	else if(message->GetMessageName() == "RF")
	{
		m_input->AddChar(GLFW_KEY_F);
	}
	else if(message->GetMessageName() == "RG")
	{
		m_input->AddChar(GLFW_KEY_G);
	}
	else if(message->GetMessageName() == "RH")
	{
		m_input->AddChar(GLFW_KEY_H);
	}
	else if(message->GetMessageName() == "RI")
	{
		m_input->AddChar(GLFW_KEY_I);
	}
	else if(message->GetMessageName() == "RJ")
	{
		m_input->AddChar(GLFW_KEY_J);
	}
	else if(message->GetMessageName() == "RK")
	{
		m_input->AddChar(GLFW_KEY_K);
	}
	else if(message->GetMessageName() == "RL")
	{
		m_input->AddChar(GLFW_KEY_L);
	}
	else if(message->GetMessageName() == "RM")
	{
		m_input->AddChar(GLFW_KEY_M);
	}
	else if(message->GetMessageName() == "RN")
	{
		m_input->AddChar(GLFW_KEY_N);
	}
	else if(message->GetMessageName() == "RO")
	{
		m_input->AddChar(GLFW_KEY_O);
	}
	else if(message->GetMessageName() == "RP")
	{
		m_input->AddChar(GLFW_KEY_P);
	}
	else if(message->GetMessageName() == "RQ")
	{
		m_input->AddChar(GLFW_KEY_Q);
	}
	else if(message->GetMessageName() == "RR")
	{
		m_input->AddChar(GLFW_KEY_R);
	}
	else if(message->GetMessageName() == "RS")
	{
		m_input->AddChar(GLFW_KEY_S);
	}
	else if(message->GetMessageName() == "RT")
	{
		m_input->AddChar(GLFW_KEY_T);
	}
	else if(message->GetMessageName() == "RU")
	{
		m_input->AddChar(GLFW_KEY_U);
	}
	else if(message->GetMessageName() == "RV")
	{
		m_input->AddChar(GLFW_KEY_V);
	}
	else if(message->GetMessageName() == "RW")
	{
		m_input->AddChar(GLFW_KEY_W);
	}
	else if(message->GetMessageName() == "RX")
	{
		m_input->AddChar(GLFW_KEY_X);
	}
	else if(message->GetMessageName() == "RY")
	{
		m_input->AddChar(GLFW_KEY_Y);
	}
	else if(message->GetMessageName() == "RZ")
	{
		m_input->AddChar(GLFW_KEY_Z);
	}
	else if(message->GetMessageName() == "RSPACE")
	{
		m_input->AddChar(GLFW_KEY_SPACE);
	}
	else if(message->GetMessageName() == "RENTER")
	{
		m_comm->Speak(m_input->Execute(m_Barry->GetMyNode()),Color(0.0f,0.0f,1.0f));		
	}
}


