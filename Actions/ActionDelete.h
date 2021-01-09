#pragma once

#include "Action.h"
#include "../ApplicationManager.h"




//Class responsible for delete component and connection
class ActionDelete : public Action
{
private:

	Component* comp;
	Component* compDelete;
	Connection* connection;
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:


	ActionDelete(ApplicationManager* pApp);
	virtual ~ActionDelete(void);
	
	//Execute action (code depends on action type)
	virtual void Execute();
	//virtual void del();
	virtual void Undo();
	virtual void Redo();
	
};
