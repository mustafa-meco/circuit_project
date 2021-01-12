#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../UI/UI.h"
#include "../Components/Component.h"
#include "../Components/Resistor.h"
#include "../Components/Battery.h"
#include "../Components/Bulb.h"
#include "../Components/Buzzer.h"
#include "../Components/Fues.h"
#include "../Components/Ground.h"
#include "../Components/Switch.h"
class ActionAddPaste : public Action
{
	int Cx; 
	int Cy;
public:
	ActionAddPaste(ApplicationManager* pApp);
	~ActionAddPaste(void); 

	//Execute action
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};