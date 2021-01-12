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
	Connection* con;
	Component* compA;
	Component* compB;
	GraphicsInfo* undo1;
	TerminalNum comp1conn, comp2conn;
public:
	ActionAddCon(ApplicationManager* pApp);//constructor

	virtual ~ActionAddCon(void);//destructor 


	//Execute action (code depends on action type)
	virtual void Execute();

	//void addTerm1Connection(Connection* pConn);
	//void addTerm2Connection(Connection* pConn);

	virtual void Undo(); //undo for the connection

	virtual void Redo(); //Redo for the connection 

};

