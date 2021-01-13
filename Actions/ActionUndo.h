#pragma once
#include "Action.h"
class ActionUndo :
    public Action
{
public:
    ActionUndo(ApplicationManager* pApp); //constructor
    virtual ~ActionUndo(void); //destructor
    virtual void Execute();

    virtual void Undo();
    virtual void Redo();
};

