#include "stdafx.h"
#include "Command.h"
#include "defineInit.h"

Command::Command()
{
	Fill();
}

void Command::Fill()
{
	for(int i = 0;i<COMMANDALTS;++i)
	{
		m_commandList[i] = new commands();
	}
	
	m_commandList[0]->alt = "LOOK";
	m_commandList[0]->main = "LOOK";

	
	m_commandList[1]->alt = "WATCH";
	m_commandList[1]->main = "LOOK";

	
	m_commandList[2]->alt = "SEE";
	m_commandList[2]->main = "LOOK";

	m_commandList[3]->alt = "WATCH";
	m_commandList[3]->main = "LOOK";

	m_commandList[4]->alt = "OBSERVE";
	m_commandList[4]->main = "LOOK";

	m_commandList[5]->alt = "PEEK";
	m_commandList[5]->main = "LOOK";

	m_commandList[6]->alt = "VIEW";
	m_commandList[6]->main = "LOOK";

	m_commandList[7]->alt = "INSPECT";
	m_commandList[7]->main = "LOOK";

	m_commandList[8]->alt = "WATCH";
	m_commandList[8]->main = "LOOK";

	m_commandList[9]->alt = "GAZE";
	m_commandList[9]->main = "LOOK";
	
	//--------------------
	m_commandList[10]->alt = "OPEN";
	m_commandList[10]->main = "OPEN";

	m_commandList[11]->alt = "UNLOCK";
	m_commandList[11]->main = "OPEN";

	//----------------------
	m_commandList[12]->alt = "USE";
	m_commandList[12]->main = "USE";

	m_commandList[13]->alt = "ACT";
	m_commandList[13]->main = "USE";
	//----------------------------
	m_commandList[14]->alt = "GET";
	m_commandList[14]->main = "GET";

	m_commandList[15]->alt = "OBTAIN";
	m_commandList[15]->main = "GET";

	m_commandList[16]->alt = "ACQUIRE";
	m_commandList[16]->main = "GET";

	//-------------------
	m_commandList[17]->alt = "COMBINE";
	m_commandList[17]->main = "COMBINE";

	m_commandList[18]->alt = "MERGE";
	m_commandList[18]->main = "COMBINE";

	m_commandList[19]->alt = "MIX";
	m_commandList[19]->main = "COMBINE";

	//-----------------
	m_commandList[20]->alt = "I";
	m_commandList[20]->main = "INV";

	m_commandList[21]->alt = "INV";
	m_commandList[21]->main = "INV";

	m_commandList[22]->alt = "INVENTORY";
	m_commandList[22]->main = "INV";
}

 String Command::GetComm(const String &str)
{
	String command = "BLA";
	if(strcmp(str.c_str(),"") != 0)
	{
		for(int i =0; i<COMMANDALTS;i++)
		{
			if(strcmp((m_commandList[i])->alt.c_str(),str.c_str()) == 0)
			{
				command = (m_commandList[i])->main;
			}
		}
	}
	return command;
}