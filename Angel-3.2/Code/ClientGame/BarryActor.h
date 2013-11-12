#include "stdafx.h"
#include "TreatmentRoom.h"

class BarryActor
{
public:
	explicit BarryActor();
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void MoveStop();

private:
	Actor* m_Actor;
	TreatmentRoom* roomTest;
	Vector2 m_goTo;
	Vector2 m_position;
	void ScaleBarry(int);

};