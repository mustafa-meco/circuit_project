#include "..\ApplicationManager.h"
#include "ActionLabel.h"

ActionLabel::ActionLabel(ApplicationManager* pApp) :Action(pApp)
{
}

ActionLabel::~ActionLabel(void)
{
}


void ActionLabel::Execute()
{
	int x = 0;
	int y = 0;
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Choose the components or connections to Label ");
	pUI->GetPointClicked(x, y);
	Component* comp = pManager->GetComponentByCordinates(x, y);
	Connection* connection = pManager->GetConnectionByCordinates(x, y);
	pUI->ClearStatusBar();

	if (comp != nullptr)
	{	//comp->selection();
		pUI->PrintMsg("enter the label");
		comp->SetComponentlabel(pUI->GetSrting());
		connection->SetConnectionlabel(pUI->GetSrting());
		pUI->ClearStatusBar();

	}
		pUI->GetPointClicked(Cx, Cy);
		while (!(Cy > 80 + 50 / 2 &&
			Cy < 650 - 50 - 50 / 2 &&
			Cx>50 / 2 &&
			Cx < 1200 - 80 / 2))
		{
			pUI->GetPointClicked(Cx, Cy);
		}		
}


void ActionLabel::Undo()
{}

void ActionLabel::Redo()
{}