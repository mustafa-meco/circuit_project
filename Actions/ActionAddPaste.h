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
	int Cx; //Center point of the comp
	int Cy;
	Component* comp1; // pointer to components
	Component* comp2;
public:
	ActionAddPaste(ApplicationManager* pApp); //constructor

	~ActionAddPaste(void); //destructor 


	//Execute action
	virtual void Execute();

	virtual void Undo(); //undo for paste

	virtual void Redo(); //Redo for paste
};
