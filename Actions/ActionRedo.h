#pragma once
#include "Action.h"
class ActionRedo :
    public Action
{
public:
    ActionRedo(ApplicationManager* pApp);
    virtual ~ActionRedo(void);
    virtual void Execute();

    virtual void Undo();
    virtual void Redo();
};

