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
private:
	Actor* m_Actor;
	TreatmentRoom* roomTest;
	Vector2 m_goTo;
	Vector2 m_position;
	int m_myNode;
	void ScaleBarry(int);
	float CalcWalkTime();
};