#include "ActionUndo.h"
#include "../ApplicationManager.h"

ActionUndo::ActionUndo(ApplicationManager* pApp) :Action(pApp)
{
}
ActionUndo::~ActionUndo(void)
{
}

void ActionUndo::Execute()
{
	pManager->ExcuteUndo();
}

void ActionUndo::Undo()
{
}
void ActionUndo::Redo()
{
}