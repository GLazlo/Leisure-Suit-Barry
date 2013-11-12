#include "stdafx.h"
#include "BarryActor.h"

#define theGame MyGameManager::GetInstance()

class MyGameManager : public GameManager
{
public:
	static MyGameManager &GetInstance();

	virtual void Update(float dt);

protected:
	MyGameManager();

	static MyGameManager* m_MyGameManager;
	
private:
	Actor* m_obstacle;
	BarryActor* Barry;
};