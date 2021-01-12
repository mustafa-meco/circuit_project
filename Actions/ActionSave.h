#pragma once
#include "Action.h"

class ActionSave : public Action
{
public:
	ActionSave(ApplicationManager* pApp);
	virtual ~ActionSave();
	virtual void Execute();

	void Undo();

	void Redo();

private:

};

