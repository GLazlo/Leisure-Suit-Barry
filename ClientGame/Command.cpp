#include "stdafx.h"
#include "Command.h"
#include "defineInit.h"

Command::Command()
	:m_commandList(Fill())
{
}

commands* Command::Fill()
{
	commands c[COMMANDNUMBER];

	c->alt = "LOOK";
	c->main = "LOOK";

	(c+1)->alt = "WATCH";
	(c+1)->main = "LOOK";

	(c+2)->alt = "SEE";
	(c+2)->main = "LOOK";

	(c+3)->alt = "WATCH";
	(c+3)->main = "LOOK";

	(c+4)->alt = "OBSERVE";
	(c+4)->main = "LOOK";

	(c+5)->alt = "PEEK";
	(c+5)->main = "LOOK";

	(c+6)->alt = "VIEW";
	(c+6)->main = "LOOK";

	(c+7)->alt = "INSPECT";
	(c+7)->main = "LOOK";

	(c+8)->alt = "WATCH";
	(c+8)->main = "LOOK";

	(c+9)->alt = "GAZE";
	(c+9)->main = "LOOK";
	
	//--------------------
	(c+10)->alt = "OPEN";
	(c+10)->main = "OPEN";

	(c+11)->alt = "UNLOCK";
	(c+11)->main = "OPEN";

	//----------------------
	(c+12)->alt = "USE";
	(c+12)->main = "USE";

	(c+13)->alt = "ACT";
	(c+13)->main = "USE";
	//----------------------------
	(c+14)->alt = "GET";
	(c+14)->main = "GET";

	(c+15)->alt = "OBTAIN";
	(c+15)->main = "GET";

	(c+16)->alt = "ACQUIRE";
	(c+16)->main = "GET";

	//-------------------
	(c+17)->alt = "COMBINE";
	(c+17)->main = "COMBINE";

	(c+18)->alt = "MERGE";
	(c+18)->main = "COMBINE";

	(c+19)->alt = "MIX";
	(c+19)->main = "COMBINE";

	return c;
}

String Command::GetComm(const String str)
{
	for(int i =0; i<COMMANDNUMBER;i++)
	{
		if(strcmp((m_commandList+i)->alt.c_str(),str.c_str()) == 0)
		{
			return (m_commandList+i)->main;
		}
	}
}