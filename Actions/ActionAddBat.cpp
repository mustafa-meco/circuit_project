
#include "..\ApplicationManager.h"
#include "ActionAddBat.h"

ActionAddBat::ActionAddBat(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddBat::~ActionAddBat(void)
{
}

void ActionAddBat::Execute()
{

	UI* pUI = pManager->GetUI();

	pUI->PrintMsg("Adding a new battery: Click anywhere to add");

	pUI->GetPointClicked(Cx, Cy);
	

	while (!(Cy > pUI->getToolBarHeight() + pUI->getCompHeight() / 2
		&& Cy < pUI->getHeight() - pUI->getStatusBarHeight() - pUI->getCompHeight() / 2
		&& Cx>pUI->getCompWidth() / 2
		&& Cx < pUI->getWidth() - pUI->getToolItemWidth() / 2)
		)
	{
		pUI->GetPointClicked(Cx, Cy);
	}

	string sV;
	bool isNumber;
	do {
		pUI->PrintMsg("Enter the value of the source voltage(enter a number): ");
		sV = pUI->GetSrting();
		isNumber = true;
		for (int i = 0; i < sV.length(); i++)
			if (isdigit(sV[i]) == false)
				isNumber = false;
	} while (!isNumber);

	double V = stod(sV);
	

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

	Battery* pR = new Battery(pGInfo/*, V*/);
	pR->setSourceVoltage(V);
	pManager->AddComponent(pR);
	comp = pR;
	undo1 = pGInfo;
	undo2 = V;
}

void ActionAddBat::Undo()
{

	pManager->deleteCompounent(comp);
}

void ActionAddBat::Redo()
{
	Battery* pR = new Battery(undo1/*, undo2*/);
	pR->setSourceVoltage(undo2);
	pManager->AddComponent(pR);
}