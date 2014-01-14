#include "stdafx.h"
#include "TreatmentRoom.h"

#include <sstream>
#include <string>
#include <fstream>

TreatmentRoom::TreatmentRoom()
{
	m_actualNodelists=0;
	InitNodelist();
	InitCommandList();
}

String TreatmentRoom::getMyClass()
{
	return "TreatmentRoom";
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

void TreatmentRoom::InitCommandList()
{
	TreatmentRoomObjectList[0] = new ObjectList();	
	TreatmentRoomObjectList[0]->nodeIndex = 0;
	TreatmentRoomObjectList[0]->name = "HANDY";
	TreatmentRoomCommandList[0] = new CommandAnswer();
	TreatmentRoomCommandList[0]->command = "GET";
	TreatmentRoomCommandList[0]->answer = "Wow Barry what a nice Mobile Phone!";
	TreatmentRoomObjectList[0]->command = TreatmentRoomCommandList[0];
	if(TreatmentRoomObjectList[0]->used != true)
	{
		TreatmentRoomObjectList[0]->used = false;
		if(TreatmentRoomObjectList[0]->inventory != true)
		{
			TreatmentRoomObjectList[0]->inventory = false;
		}
	}
	TreatmentRoomCommandList[0]->answerUsed = "Barry you already got your Mobile Phone!";
	//Repeat set to 0
	TreatmentRoomObjectList[1] = new ObjectList();
	TreatmentRoomObjectList[1]->nodeIndex = 0;
	TreatmentRoomObjectList[1]->name = "FLU";
	TreatmentRoomCommandList[1] = new CommandAnswer();
	TreatmentRoomCommandList[1]->command = "GET";
	TreatmentRoomCommandList[1]->answer = "Wow Barry you got the Flu!";
	TreatmentRoomObjectList[1]->command = TreatmentRoomCommandList[1];
	if(TreatmentRoomObjectList[1]->used != true)
	{
		TreatmentRoomObjectList[1]->used = false;
		if(TreatmentRoomObjectList[1]->inventory != true)
		{
			TreatmentRoomObjectList[1]->inventory = false;
		}
	}
	TreatmentRoomCommandList[1]->answerUsed = "Barry you already got Flu!";
	
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

TreatmentRoom::Answer TreatmentRoom::allowedCommand(String &command,String &object,int node)
{
	Answer a;
	a.answer = "WHAAAT?";
	a.result = 0;
	if(strcmp(command.c_str(),"") != 0 && strcmp(object.c_str(),"") != 0)
	{
		
		if(node<m_nodeNumber)
		{
			switch (node)
			{
				case 0:
					for(int f = 0; f < OBJECTSTREATMENT;f++)
					{
						if(this->TreatmentRoomObjectList[f]->nodeIndex == 0)
						{
							for(int i = 0;i<OBJECTSTREATMENT;i++)
							{
								if(strcmp((this->TreatmentRoomObjectList[i]->name).c_str(),object.c_str()) == 0)
								{
									for(int j = 0;j<COMMANDSTREATMENT;j++)
									{
										if(strcmp((this->TreatmentRoomObjectList[i]->command[j].command).c_str(), command.c_str()) ==0)
										{
											if(this->TreatmentRoomObjectList[i]->used == false)
											{
												this->TreatmentRoomObjectList[i]->used = true;
												a.answer = this->TreatmentRoomObjectList[i]->command[j].answer;
												a.result = 2;

												if(strcmp(command.c_str(), "GET") == 0)
												{
													this->TreatmentRoomObjectList[i]->inventory = true;
												}
											}
											else
											{
												a.answer = this->TreatmentRoomObjectList[i]->command[j].answerUsed;
												a.result = 2;
											}									
											//Check if not repeated
									
											return a;
										}
									}
								}
							}
						}
					}
				
					/*if(strcmp(object.c_str(),"DOOR") == 0)
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
					}*/
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
	}
	else
	{
		a.answer = "WHAT?";
		a.result = 0;
	}
	return a;
}

String TreatmentRoom::getInvRoom()
{
	String inv = "";
	for(int i = 0; i < OBJECTSTREATMENT;i++)
	{
		if(this->TreatmentRoomObjectList[i]->inventory == true)
		{
			inv += (TreatmentRoomObjectList[i]->name + "\n");
		}
	}
	return inv;
}