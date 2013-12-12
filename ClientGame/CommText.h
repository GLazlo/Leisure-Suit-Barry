#include "stdafx.h"

class CommText
{
public:
	CommText();
	void Speak(String,Color);
	void Hide();
	
private:
	void Update();
	String m_text;
	TextActor* m_textField;
	Actor* m_textFieldBack;
	Color temp;
};