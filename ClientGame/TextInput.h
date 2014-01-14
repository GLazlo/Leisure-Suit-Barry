#include "stdafx.h"
#include "Interpreter.h"
#include "Command.h"

#ifndef TEXTINPUT_H
#define TEXTINPUT_H
class TextInput
{
public:
	TextInput();	
	void AddChar(int);
	void RemoveChar();
	void ClearAll();
	String Execute(int, Room*);
	
private:
	void Parse();
	void Update();
	TextActor* m_TextActor;
	Actor* m_consoleBack;
	String m_command;
	String m_order;
	String m_object;
	String m_secObject;
	Interpreter m_interpreter;
	Command* m_commandList;
};
#endif