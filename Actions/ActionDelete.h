#pragma once

#include "Action.h"
#include "../ApplicationManager.h"




//Class responsible for delete component and connection
class ActionDelete : public Action
{
private:

	Component* comp;
	Connection* connection;
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	Component* comp2;
	Connection* connection2;

	//undo redo for componnents
	int C1, C2;
	Component* Comp1;
	Component* Comp2;
	Component* temp1;
	Connection* temp3[10];
	Connection* temp4[10];
	Connection* undo1[10];
	Connection* undo2[10];
	TerminalNum tt1[10];
	TerminalNum tt2[10];
	//undo redo for connections

	TerminalNum t1;
	TerminalNum t2;
	Connection* temp2;
public:


	ActionDelete(ApplicationManager* pApp);//constructor

	virtual ~ActionDelete(void);//destructor 

	
	//Execute action (code depends on action type)
	virtual void Execute();
	
	virtual void Undo(); //undo for delete

	virtual void Redo(); //Redo for delete 

	
};

