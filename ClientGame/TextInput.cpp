#include "stdafx.h"
#include "TextInput.h";
#include "defineInit.h";

TextInput::TextInput()
	:m_command(""),m_order(""),m_object(""),m_secObject("")
{
	m_TextActor = new TextActor("Console", "Welcome to Leisure Suit Barry!",TXT_Left);
	m_TextActor->SetPosition(-11.0f,-8.0f);
	m_TextActor->SetColor(1.0f,1.0f,1.0f);
	m_TextActor->SetLayer(CONSOLETEXT);
	theWorld.Add(m_TextActor);

	//Console Background
	m_consoleBack = new Actor();
	m_consoleBack->SetPosition(-1.0f,-7.9f);
	m_consoleBack->SetColor(0.0f,0.0f,0.0f,0.5f);
	m_consoleBack->SetSize(20.0f,0.8f);
	m_consoleBack->SetLayer(CONSOLE);
	theWorld.Add(m_consoleBack);
}
void TextInput::AddChar(int c)
{
	if(m_command.size()<TEXTLENGTH)
	{
		m_command += c;
		Update();
	}
	else
	{
		m_command = "COMMAND TOO LONG";
		Update();
		m_command = "";
	}
   
}
String TextInput::Execute(int node)
{
	Parse();
	m_command = "";
	if(strcmp(m_secObject.c_str(),"") == 0)
	{
		Update();
		return m_interpreter.Process(m_order,m_object,"TreatmentRoom",node);
	}
	else
	{
		Update();
		//TODO Process overload
		return "";
	}
	Update();
}
void TextInput::Parse()
{
	if(m_command != "")
	{
		int i;
		int word = 0;
		m_order = "";
		m_object = "";
		for(i=0;i<m_command.size();++i)
		{
			if(m_command[i] == GLFW_KEY_SPACE)
			{
				++word;
			}
			else if(word == 0)
			{
				m_order += m_command[i];
			}
			else if(word == 1)
			{
				m_object += m_command[i];
			}

			//in case of combine the word between object and secObject
			/*else if(word == 2)
			{

			}*/

			else if(word == 3)
			{
				m_secObject += m_command[i];
			}
		}
	}
}

void TextInput::Update()
{
	m_TextActor->SetDisplayString(m_command);
}