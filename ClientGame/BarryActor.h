#include "stdafx.h"
#include "TreatmentRoom.h"
#include "defineInit.h"

class BarryActor
{
public:
	BarryActor();
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void MoveStop();
	int GetMyNode();
	Room* GetRoom();
	String GetInv();
private:
	Actor* m_Actor;
	Room* roomTest;
	Vector2 m_goTo;
	Vector2 m_position;
	int m_myNode;
	void ScaleBarry(int);
	float CalcWalkTime();
	TreatmentRoom* m_treatment;
};