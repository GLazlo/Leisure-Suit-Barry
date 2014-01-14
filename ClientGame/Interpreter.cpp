#include "stdafx.h"
#include "Interpreter.h"

Interpreter::Interpreter()
{
}

String Interpreter::Process(String &command,String &object,String &room,int node, Room* r)
{
	if(strcmp(command.c_str(),"") != 0 && strcmp(object.c_str(),"") != 0)
	{
		if(strcmp(room.c_str(),"TreatmentRoom") == 0)
		{
			Room::Answer result = r->allowedCommand(command,object,node);
		
			//switch (result.result)
			//{
			//case 0:
			//	//Ivalid object with command at node
			//	return result.answer;
			//case 1:
			//	//Invalid command with valid object
			//	return result.answer;
			//case 2:
			//	//Valid command with valid object
			//	return result.answer;
			//default:
			//	//Invalid node
				return result.answer;
			
			//}
	
			//return "";
		}
	}
		return "";
}