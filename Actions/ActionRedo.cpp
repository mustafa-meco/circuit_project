#include "ActionRedo.h"
#include "../ApplicationManager.h"


ActionRedo::ActionRedo(ApplicationManager* pApp) :Action(pApp)
{
}
ActionRedo::~ActionRedo(void)
{
}

void ActionRedo::Execute()
{
	pManager->ExcuteRedo();
}

void ActionRedo::Undo()
{
}
void ActionRedo::Redo()
{
}