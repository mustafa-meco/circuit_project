#pragma once


#include "Action.h"
#include "../Components/Buzzer.h"
#include "..\ApplicationManager.h"


//Class responsible for adding a new resistor action
class ActionAddBuz : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Component* comp;  //save the graphics info to do undo or redo 
	// to store value of the component
	GraphicsInfo* undo1;
	double undo2;
public:
	ActionAddBuz(ApplicationManager* pApp);//constructor

	virtual ~ActionAddBuz(void);//destructor 


	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo(); //undo for the Buzzer

	virtual void Redo(); //Redo for the Buzzer 
};
