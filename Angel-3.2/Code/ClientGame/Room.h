#include "stdafx.h"

class Room
{
public:
	virtual Vector2 getNextNodeUp(Vector2) = 0;
	virtual Vector2 getNextNodeDown(Vector2) = 0;
	virtual Vector2 getNextNodeLeft(Vector2) = 0;
	virtual Vector2 getNextNodeRight(Vector2) = 0;
protected:
	virtual void InitNodelist() = 0;
	virtual int getMyNode(Vector2) = 0;
	virtual int getMyLayer(Vector2) = 0;
	typedef struct Nodelist
	{
		Vector2 node;
		int layer;
		Vector2 nextRight;
		Vector2 nextLeft;
		Vector2 nextUp;
		Vector2 nextDown;
	};
};