#pragma once

#include "Action.h"
#include "../Components/Component.h"

//Class responsible for adding a new resistor action
class ActionMove : public Action
{
private:
	Component* comp; //pointer to comp 
	Connection* connection; // pointer to conn 
	int cx, cy;	//center point of the comp
	int x1, y1, x2, y2;	//two corners of the rectangluar area
	GraphicsInfo* undo1; 	//save the graphics info to do undo or redo 
public:
	ActionMove(ApplicationManager* pApp); //constructor
	virtual ~ActionMove(void); //destructor
		//Execute action (code depends on action type)
	virtual void Execute(); 

	virtual void Undo();//undo for the move 
	virtual void Redo();//Redo for the move 
};
