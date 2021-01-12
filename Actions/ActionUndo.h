#pragma once
#include "Action.h"
class ActionUndo :
    public Action
{
public:
    ActionUndo(ApplicationManager* pApp);
    virtual ~ActionUndo(void);
    virtual void Execute();

    virtual void Undo();
    virtual void Redo();
};

