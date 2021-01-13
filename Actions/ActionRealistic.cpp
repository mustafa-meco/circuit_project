#include "ActionRealistic.h"
#include "../ApplicationManager.h"
#include"..\Components\Component.h"

ActionRealistic::ActionRealistic(ApplicationManager* pApp) :Action(pApp)
{

}

ActionRealistic::~ActionRealistic(void)
{
}

void ActionRealistic::Execute()
{

	UI* pUI = pManager->GetUI();
	pUI->DrawReal();
	pUI->GetPointClicked(Cx, Cy);
	do
	{
		pUI->GetPointClicked(Cx, Cy);
		pUI->DrawRealistic();

	} while (!(Cx < 25 && Cy<pUI->getHeight() - pUI->getStatusBarHeight() && Cy > pUI->getHeight() - pUI->getStatusBarHeight() - 40));


	pUI->ClearStatusBar();
}



void ActionRealistic::Undo()
{}

void ActionRealistic::Redo()
{}