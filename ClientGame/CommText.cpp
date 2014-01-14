#include "stdafx.h"
#include "CommText.h"
#include "defineInit.h"

CommText::CommText()
{
	//Text
	m_textField = new TextActor("Console","",TXT_Center);
	m_textField->SetPosition(0.0f,0.0f);
	m_textField->SetSize(4.0f,1.0f);
	m_textField->SetLayer(CONSOLETEXT);
	theWorld.Add(m_textField);
	//Background
	m_textFieldBack = new Actor();
	m_textFieldBack->SetPosition(m_textField->GetPosition());
	m_textFieldBack->SetSize(m_textField->GetSize());
	m_textFieldBack->SetColor(0.0f,0.0f,0.0f,0.5f);
	m_textFieldBack->SetLayer(CONSOLE);
	theWorld.Add(m_textFieldBack);
}

void CommText::Update()
{
	float f = (0.31f*m_text.size());
	m_textField->SetSize(f,0.8f);
	m_textFieldBack->SetSize(f,0.8f);
	m_textField->SetDisplayString(m_text);
}

void CommText::Hide()
{
	temp = m_textField->GetColor();
	m_textField->SetColor(1.0f,1.0f,1.0f,0.0f);
	m_textFieldBack->SetColor(1.0f,1.0f,1.0f,0.0f);
}


void CommText::Speak(String s, Color c)
{
	m_text = s;
	m_textField->SetColor(c);
	m_textFieldBack->SetSize(m_textField->GetSize());
	m_textFieldBack->SetColor(0.0f,0.0f,0.0f,0.5f);
	Update();
}