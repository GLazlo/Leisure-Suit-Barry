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
	std::ifstream infile;
	std::string line;
	int i;

	infile.open("./res/nodelists/TreatmentRoomNodelist.txt");
	i = 0;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		float nodeX,nodeY;
		int index, layer, nextRight, nextLeft, nextUp, nextDown;
		if ((iss >> index >> nodeX >> nodeY >> layer >> nextRight >> nextLeft >> nextUp >> nextDown ))
		{
			TreatmentRoomNodelist[i] = new Nodelist;
			TreatmentRoomNodelist[i]->index = index;
			TreatmentRoomNodelist[i]->node.X = nodeX;
			TreatmentRoomNodelist[i]->node.Y = nodeY;
			TreatmentRoomNodelist[i]->layer = layer;
			i++;
		}
		m_actualNodelists = i-1;
	}
	infile.close();

	infile.open("./res/nodelists/TreatmentRoomNodelist.txt");
	i = 0;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		float nodeX,nodeY;
		int index, layer, nextRight, nextLeft, nextUp, nextDown;
		if ((iss >> index >> nodeX >> nodeY >> layer >> nextRight >> nextLeft >> nextUp >> nextDown ))
		{
			for(int j=0;j<=m_actualNodelists;j++)
			{
				if(TreatmentRoomNodelist[j]->index==nextRight)
					TreatmentRoomNodelist[i]->nextRight = TreatmentRoomNodelist[j]->node;
				if(TreatmentRoomNodelist[j]->index==nextLeft)
					TreatmentRoomNodelist[i]->nextLeft = TreatmentRoomNodelist[j]->node;
				if(TreatmentRoomNodelist[j]->index==nextUp)
					TreatmentRoomNodelist[i]->nextUp = TreatmentRoomNodelist[j]->node;
				if(TreatmentRoomNodelist[j]->index==nextDown)
					TreatmentRoomNodelist[i]->nextDown = TreatmentRoomNodelist[j]->node;
			}
			i++;
		}
	}
	infile.close();
	m_nodeNumber = i;
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
	return NO_NODE;
}

int TreatmentRoom::getMyLayer(Vector2 nextNode)
{
	return TreatmentRoomNodelist[getMyNode(nextNode)]->layer;
}

Room::Answer TreatmentRoom::allowedCommand(String command,String object,int node)
{
	Room::Answer a;
	if(node<m_nodeNumber)
	{
		switch (node)
		{
			case 0:
				if(strcmp(object.c_str(),"DOOR") == 0)
				{
					if (strcmp(command.c_str(),"OPEN") == 0)
					{
						a.answer = "DOOR IS CLOSED";
						a.result = 2;
					}
					else if (strcmp(command.c_str(),"LOOK") == 0)
					{
						a.answer = "THAT'S A DOOR";
						a.result = 2;
					}
					else
					{
						a.answer = "I CAN'T DO THAT WITH THE DOOR";
						a.result = 1;
					}
				}
				else
				{
					a.answer = "NO CAN'T DO";
					a.result = 0;
				}
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		}
	}
	else
	{
		a.answer = "I'M COULDN'T BE THERE!";
		a.result = 4;
	}
	return a;
}

