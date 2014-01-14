#include "stdafx.h"
#include "defineInit.h"

#ifndef COMMAND_STRUCT
#define COMMAND_STRUCT
struct commands
{
	String main;
	String alt;
};
#endif

#ifndef COMMAND_H
#define COMMAND_H
class Command
{
public:
	Command();
	String GetComm(const String &str) ;
private:
	commands* m_commandList[COMMANDALTS];
	void Fill();
};
#endif