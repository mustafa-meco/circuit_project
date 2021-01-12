#pragma once
#include "Action.h"
class ActionSaveDesignedModule :
    public Action
{
public: 
	ActionSaveDesignedModule(ApplicationManager* pApp);
	virtual ~ActionSaveDesignedModule();
	virtual void Execute();

	void Undo();

	void Redo();	

};

