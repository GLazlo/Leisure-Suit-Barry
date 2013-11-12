#include "stdafx.h"
#include "Room.h"
#include "defineInit.h"

class TreatmentRoom : public Room
{
public:
	explicit TreatmentRoom();
	virtual Vector2 getNextNodeUp(Vector2);
	virtual Vector2 getNextNodeDown(Vector2);
	virtual Vector2 getNextNodeLeft(Vector2);
	virtual Vector2 getNextNodeRight(Vector2);
	virtual int getMyLayer(Vector2);
private:
	virtual void InitNodelist();
	virtual int getMyNode(Vector2);
	Nodelist* TreatmentRoomNodelist[MAX_NODELIST];
	int m_actualNodelists;
};