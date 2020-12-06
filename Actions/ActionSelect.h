#pragma once

#include "Action.h"
#include"../Components/Component.h"
#include "../ApplicationManager.h"
//Class responsible for adding a new resistor action
class ActionSelect : public Action
{
private:
	//parameters for rectangular area to be occupied by the comp
	Component* comp;
	Connection* connection;
	int cx, cy;	//center point of the comp
	int x1, y1, x2, y2;	//two corners of the rectangluar area
public:
	ActionSelect(ApplicationManager* pApp);
	virtual ~ActionSelect(void);
	//execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};