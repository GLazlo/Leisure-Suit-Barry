#include "stdafx.h"
#include "Room.h"

#ifndef INTERPRETER_H
#define INTERPRETER_H
class Interpreter
{
public:
	Interpreter();
	String Process(String&,String&,String&,int, Room*);
private:
};
#endif