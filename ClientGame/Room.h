#include "stdafx.h"

#ifndef ROOM_H
#define ROOM_H
class Room
{
public:
	virtual Vector2 getNextNodeUp(Vector2) = 0;
	virtual Vector2 getNextNodeDown(Vector2) = 0;
	virtual Vector2 getNextNodeLeft(Vector2) = 0;
	virtual Vector2 getNextNodeRight(Vector2) = 0;
	virtual int getMyNode(Vector2) = 0;
	virtual int getMyLayer(Vector2) = 0;
	virtual String getMyClass() = 0;
	virtual String getInvRoom() = 0;

	typedef struct Answer
	{
		int result;
		String answer;
	};
	virtual Answer allowedCommand(String&,String&,int) = 0;

protected:
	virtual void InitNodelist() = 0;
	virtual void InitCommandList() = 0;
	
	
	typedef struct Nodelist
	{
		int index;
		Vector2 node;
		int layer;
		Vector2 nextRight;
		Vector2 nextLeft;
		Vector2 nextUp;
		Vector2 nextDown;
	};
	
	typedef struct CommandAnswer
	{
		std::string command;
		std::string answer;
		std::string answerRepeat;
		std::string answerUsed;
	};

	typedef struct ObjectList
	{
		int nodeIndex;
		std::string name;
		CommandAnswer* command;
		int repeat;
		bool used;
		bool inventory;
		
	};
	
	int m_nodeNumber;
	
};
#endif