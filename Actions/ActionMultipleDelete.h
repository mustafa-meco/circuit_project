#pragma once

#include "Action.h"
#include "../ApplicationManager.h"
#include<vector>



//Class responsible for delete component and connection
class ActionMultipleDelete : public Action
{
private:

	Component* comp1; //pointer to component 
	Component* comp;
	//Component* compDelete;
	Connection* connection; //pointer to connection 
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:


	ActionMultipleDelete(ApplicationManager* pApp); //constructor

	virtual ~ActionMultipleDelete(void); //destructor


	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();// undo for the multiple delete
	virtual void Redo();//Redo for the multiple delete

};

