#include "ActionDesign.h"
#include "../ApplicationManager.h"


ActionDesign::ActionDesign(ApplicationManager* pApp) :Action(pApp)
{
}
ActionDesign::~ActionDesign(void)
{
}

void ActionDesign::Execute()
{
	pManager->ToDesign();
}

void ActionDesign::Undo()
{
}
void ActionDesign::Redo()
{
}