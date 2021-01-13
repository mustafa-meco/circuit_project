#pragma once
#include "Action.h"
#include"../Components/Component.h"
#include "../ApplicationManager.h"
//Class responsible for adding a new resistor action
class ActionSelect : public Action
{
private:
	//parameters for rectangular area to be occupied by the comp
	Component* comp; //pointer to component 
	Connection* connection; // pointer to connection
	int cx, cy;	//center point of the comp
	int x1, y1, x2, y2;	//two corners of the rectangluar area
public:
	ActionSelect(ApplicationManager* pApp); //constructor

	virtual ~ActionSelect(void); //destructor

	//execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo(); // undo for select

	virtual void Redo(); //Redo for select
};
