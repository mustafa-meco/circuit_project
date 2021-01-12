
#pragma once
#include "Action.h"
#include "../Components/Bulb.h"

//Class responsible for adding a new bulb action
class ActionAddBul : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	          //Center point of the comp
	int x1, y1, x2, y2;	  //Two corners of the rectangluar area
	Component* comp;      //pointer to component 
	GraphicsInfo* undo1;  //save the graphics info to do undo or redo 
	// to store value of the component
	double undo2;        
public:
	ActionAddBul(ApplicationManager* pApp); //constructor 
	virtual ~ActionAddBul(void); //destructor 

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo(); //undo for the Battery 
	virtual void Redo(); //Redo for the Battery 
};
