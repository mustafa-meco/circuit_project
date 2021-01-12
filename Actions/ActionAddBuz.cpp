#include "..\Actions\ActionAddBuz.h"
#include "..\ApplicationManager.h"


ActionAddBuz::ActionAddBuz(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBuz::~ActionAddBuz(void)
{
}

void ActionAddBuz::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new buzzer: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);
	while (!(Cy > pUI->getToolBarHeight() + pUI->getCompHeight() / 2
		&& Cy < pUI->getHeight() - pUI->getStatusBarHeight() - pUI->getCompHeight() / 2
		&& Cx>pUI->getCompWidth() / 2
		&& Cx < pUI->getWidth() - pUI->getToolItemWidth() / 2))
	{
		pUI->GetPointClicked(Cx, Cy);
	}
	//Clear Status Bar
	pUI->ClearStatusBar();


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Buzzer* pR = new Buzzer(pGInfo);
	pManager->AddComponent(pR);
	comp = pR;
	undo1 = pGInfo;
}

void ActionAddBuz::Undo()
{
	pManager->deleteCompounent(comp);
}

void ActionAddBuz::Redo()
{
	Battery* pR = new Battery(undo1);
	pManager->AddComponent(pR);
}
