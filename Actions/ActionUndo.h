#pragma once
#include "Action.h"
class ActionUndo :
    public Action
{
private:
    Action* list[5];

    virtual void Execute();

    virtual void Undo();
    virtual void Redo();



};

