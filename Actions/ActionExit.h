#pragma once
#include "Action.h"
//#include "../Components/Switch.h"

//Class responsible for adding a new Exit action
class ActionExit : public Action
{
private:
	//Parameters for rectangular area to be occupied by the comp
	int Cx, Cy;	//Center point of the comp
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ActionExit(ApplicationManager* pApp);//constructor

	virtual ~ActionExit(void);//destructor 



	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo(); //undo for the exit
 
	virtual void Redo(); //Redo for the exit 
};
