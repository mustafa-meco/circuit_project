#include "Action.h"
#include"ActionSelect.h"

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{}
ActionSelect::~ActionSelect(void)
{}

void ActionSelect::Execute()
{
    UI* pUI = pManager->GetUI();
	pUI->PrintMsg("select a component");
	pUI->GetPointClicked(cx,cy);
	comp = pManager->GetComponentByCordinates(cx, cy);
	connection = pManager->GetConnectionByCordinates(cx, cy);
	if (comp)
	{
		pUI->PrintMsg("label: " + comp->getlabel());
		//comp->selection();
		/*pUI->ClearStatusBar();*/


	}

}


void ActionSelect::Undo() {}
void ActionSelect::Redo() {}