#pragma once

#include "Action.h"
#include "..\Components\Battery.h"


//#include "..\Components\Ground.h" 

//Class responsible for adding a new resistor action
class ActionAddBat : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Component* comp;
	GraphicsInfo* undo1; //save the graphics info to do undo or redo 
	double undo2;        // to store value of the component
public:
	ActionAddBat(ApplicationManager* pApp); //constructor 
	virtual ~ActionAddBat(void); //destructor 

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo(); //undo for the Battery 
	virtual void Redo(); //Redo for the Battery 
};
