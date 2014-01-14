#include "stdafx.h"
#include "BarryActor.h"
#include "TextInput.h"
#include "CommText.h"

#define theGame MyGameManager::GetInstance()

class MyGameManager : public GameManager
{
public:
	static MyGameManager &GetInstance();

	virtual void Update(float dt);
	BarryActor* m_Barry;

protected:
	MyGameManager();

	static MyGameManager* m_MyGameManager;
	
	
private:
	void Subscribe();
	void ReceiveMessage(Message*);
	Actor* m_obstacle;
	
	TextInput* m_input;
	CommText* m_comm;
};