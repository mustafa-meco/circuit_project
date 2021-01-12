#pragma once

#include "Action.h"
#include "../ApplicationManager.h"




//Class responsible for delete component and connection
class ActionDelete : public Action
{
private:
	int C1, C2;
	Component* comp;
	//Component* compDelete;
	Connection* connection;
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Component* comp2;
	Connection* connection2;

	Component* temp1;
	Connection* temp2;
	Connection* temp3[10];
	Connection* temp4[10];
	Connection* undo1[10];
	Connection* undo2[10];
	TerminalNum t[10];
public:


	ActionDelete(ApplicationManager* pApp);
	virtual ~ActionDelete(void);
	
	//Execute action (code depends on action type)
	virtual void Execute();
	
	virtual void Undo();
	virtual void Redo();
	
};
