#pragma once
#include "Action.h"
class ActionSaveDesignedModule :
    public Action
{
public: 
	ActionSaveDesignedModule(ApplicationManager* pApp);//constructor
	virtual ~ActionSaveDesignedModule();//destructor
	virtual void Execute();

	void Undo(); // undo for save designed module

	void Redo(); //Redo for save designed module


};


