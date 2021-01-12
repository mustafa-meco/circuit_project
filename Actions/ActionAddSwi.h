#pragma once

#include "Action.h"
#include "../Components/Switch.h"

//Class responsible for adding a new resistor action
class ActionAddSwi : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	         //Center point of the comp
	int x1, y1, x2, y2;	 //Two corners of the rectangluar area
	Component* comp;     // pointer to comp 
	GraphicsInfo* undo1; //save the graphics info to do undo or redo 
	// to store value of the component
	double undo2;       
public:
	ActionAddSwi(ApplicationManager* pApp);//constructor

	virtual ~ActionAddSwi(void);//destructor 



	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo(); //undo for the switch

	virtual void Redo(); //Redo for the switch 

};


