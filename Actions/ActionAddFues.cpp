#include "..\Actions\ActionAddFues.h"
#include "..\ApplicationManager.h"

ActionAddFues::ActionAddFues(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddFues::~ActionAddFues(void)
{
}

void ActionAddFues::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new Fues: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

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

	Fues* pR = new Fues(pGInfo);
	pManager->AddComponent(pR);
}

void ActionAddFues::Undo()
{}

void ActionAddFues::Redo()
{}