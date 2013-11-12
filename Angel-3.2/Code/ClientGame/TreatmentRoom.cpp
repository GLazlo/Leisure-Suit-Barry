#include "stdafx.h"
#include "TreatmentRoom.h"

#include <sstream>
#include <string>
#include <fstream>

TreatmentRoom::TreatmentRoom()
{
	m_actualNodelists=0;
	InitNodelist();
}

void TreatmentRoom::InitNodelist()
{
	std::ifstream infile("res/nodelists/TreatmentRoomNodelist.txt");

	std::string line;
	int i = 0;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		float nodeX,nodeY,nextRightX,nextRightY,nextLeftX,nextLeftY,nextUpX,nextUpY,nextDownX,nextDownY;
		int layer;
		if ((iss >> nodeX >> nodeY >> layer >> nextRightX >> nextRightY >> nextLeftX >> nextLeftY >> nextUpX >> nextUpY >> nextDownX >>nextDownY))
		{
			TreatmentRoomNodelist[i] = new Nodelist;
			TreatmentRoomNodelist[i]->node.X = nodeX;
			TreatmentRoomNodelist[i]->node.Y = nodeY;
			TreatmentRoomNodelist[i]->layer = layer;
			TreatmentRoomNodelist[i]->nextRight.X = nextRightX;
			TreatmentRoomNodelist[i]->nextRight.Y = nextRightY;
			TreatmentRoomNodelist[i]->nextLeft.X = nextLeftX;
			TreatmentRoomNodelist[i]->nextLeft.Y = nextLeftY;
			TreatmentRoomNodelist[i]->nextUp.X = nextUpX;
			TreatmentRoomNodelist[i]->nextUp.Y = nextUpY;
			TreatmentRoomNodelist[i]->nextDown.X = nextDownX;
			TreatmentRoomNodelist[i]->nextDown.Y = nextDownY;

			i++;
		}
		m_actualNodelists = i-1;
	}
}

Vector2 TreatmentRoom::getNextNodeRight(Vector2 position)
{
	return TreatmentRoomNodelist[getMyNode(position)]->nextRight;
}
Vector2 TreatmentRoom::getNextNodeLeft(Vector2 position)
{
	return TreatmentRoomNodelist[getMyNode(position)]->nextLeft;
}
Vector2 TreatmentRoom::getNextNodeUp(Vector2 position)
{
	return TreatmentRoomNodelist[getMyNode(position)]->nextUp;
}
Vector2 TreatmentRoom::getNextNodeDown(Vector2 position)
{
	return TreatmentRoomNodelist[getMyNode(position)]->nextDown;
}

int TreatmentRoom::getMyNode(Vector2 position)
{
	for(int i=0;i<=m_actualNodelists;i++)
	{
		if(position.X==TreatmentRoomNodelist[i]->node.X && position.Y==TreatmentRoomNodelist[i]->node.Y)
			return i;
	}
	return 0;
}

int TreatmentRoom::getMyLayer(Vector2 position)
{
	return TreatmentRoomNodelist[getMyNode(position)]->layer;
}

