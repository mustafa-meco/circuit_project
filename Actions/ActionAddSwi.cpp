#include "ActionAddSwi.h"
#include "../ApplicationManager.h"

ActionAddSwi::ActionAddSwi(ApplicationManager* pApp) :Action(pApp) 
{

}

ActionAddSwi::~ActionAddSwi(void)
{
}

void ActionAddSwi::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new switch: Cli");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);
	while (!(Cy > pUI->getToolBarHeight() + pUI->getCompHeight() / 2
		&& Cy < pUI->getHeight() - pUI->getStatusBarHeight() - pUI->getCompHeight() / 2
		&& Cx>pUI->getCompWidth() / 2
		&& Cx < pUI->getWidth() - pUI->getToolItemWidth() / 2))
	{
		pUI->GetPointClicked(Cx, Cy);
	}

	string sS;
	bool isBool;
	bool S;
	do {
		pUI->PrintMsg("Enter the value of the switch (0: opened, 1: closed)");
		sS = pUI->GetSrting();
		isBool = false;
		if (sS == "0" || sS == "1") {
			isBool = true;
			S = static_cast<bool>(stoi(sS));
		}
	} while (!isBool);

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

	Switch* pS = new Switch(pGInfo/*, S*/);
	pS->setStatus(S);
	pManager->AddComponent(pS);

	comp = pS;
	undo1 = pGInfo;
	undo2 = S;
}

void ActionAddSwi::Undo()
{
	pManager->deleteCompounent(comp);
}

void ActionAddSwi::Redo()
{
	Switch* pS = new Switch(undo1/*, undo2*/);
	pS->setStatus(undo2);
	pManager->AddComponent(pS);
}

