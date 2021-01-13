#pragma once
#include "Action.h"
class ActionDesign :
    public Action
{
public:
	ActionDesign(ApplicationManager* pApp); //constructor 
	virtual ~ActionDesign(void); //destructor 

	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo(); //undo for the Battery 
	virtual void Redo(); //Redo for the Battery 

};

