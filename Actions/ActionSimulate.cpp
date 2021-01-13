#include "ActionSimulate.h"
#include "../ApplicationManager.h"


ActionSimulate::ActionSimulate(ApplicationManager* pApp) :Action(pApp)
{
}
ActionSimulate::~ActionSimulate(void)
{
}

void ActionSimulate::Execute()
{
	pManager->ToSimulation();
}

void ActionSimulate::Undo()
{
}
void ActionSimulate::Redo()
{
}