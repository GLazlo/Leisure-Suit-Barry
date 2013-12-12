#include "stdafx.h";

struct commands
{
	String main;
	String alt;
};

class Command
{
public:
	Command();
	String GetComm(const String str);
private:
	commands* m_commandList;
	commands* Fill();
};