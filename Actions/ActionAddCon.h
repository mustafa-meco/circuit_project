#pragma once

#include "Action.h"
#include "..\Connections\Connection.h" 

//Class responsible for adding a new resistor action
class ActionAddCon : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx1, Cy1;	//Center point of the comp
	int Cx2, Cy2;
	//int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Component* comp1;
	Component* comp2;
public:
	ActionAddCon(ApplicationManager* pApp);
	virtual ~ActionAddCon(void);

	//Execute action (code depends on action type)
	virtual void Execute();

	
	
	
	
	
	
	
	virtual void Undo();
	virtual void Redo();
};

