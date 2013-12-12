#include "stdafx.h"
#include "Interpreter.h"

class TextInput
{
public:
	TextInput();	
	void AddChar(int);
	String Execute(int);
	
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
};