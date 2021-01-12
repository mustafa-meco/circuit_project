#pragma once

#include "Action.h"
#include "..\Components\Ground.h"

//Class responsible for adding a new resistor action
class ActionAddGro : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Component* comp;  //pointer to component 
	GraphicsInfo* undo1; //save the graphics info to do undo or redo 
	
public:
	ActionAddGro(ApplicationManager* pApp); //constructor

	virtual ~ActionAddGro(void);    //destructor 


	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo(); //undo for the ground

	virtual void Redo(); //Redo for the ground 

};


