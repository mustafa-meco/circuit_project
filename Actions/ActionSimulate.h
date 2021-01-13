#pragma once
#include "Action.h"
class ActionSimulate :
    public Action
{
public:
	ActionSimulate(ApplicationManager* pApp); //constructor 
	virtual ~ActionSimulate(void); //destructor 

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo(); //undo for the Battery 
	virtual void Redo(); //Redo for the Battery 

};

