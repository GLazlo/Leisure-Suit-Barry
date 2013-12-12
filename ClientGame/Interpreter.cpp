#include "stdafx.h"
#include "Interpreter.h"
#include "TreatmentRoom.h"

Interpreter::Interpreter()
{
}

String Interpreter::Process(String command,String object,String room,int node)
{
	if(strcmp(room.c_str(),"TreatmentRoom") == 0)
	{
		TreatmentRoom t;
		Room::Answer result = t.allowedCommand(command,object,node);
		
		switch (result.result)
		{
		case 0:
			//Ivalid object with command at node
			return result.answer;
		case 1:
			//Invalid command with valid object
			return result.answer;
		case 2:
			//Valid command with valid object
			return result.answer;
		default:
			//Invalid node
			return result.answer;
			
		}
	
		return "";
	}
	return "";
}