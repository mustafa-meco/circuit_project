#pragma once
#include "Action.h"
class ActionRedo :
    public Action
{
public:
    ActionRedo(ApplicationManager* pApp);//constructor

    virtual ~ActionRedo(void);//destructor

    virtual void Execute();

    virtual void Undo();
    virtual void Redo();
};

