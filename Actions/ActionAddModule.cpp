#include "ActionAddModule.h"
#include "../ApplicationManager.h"
#include"..\Components\Component.h"
#include "../Components/Module.h"
ActionAddModule::ActionAddModule(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddModule::~ActionAddModule(void)
{
}

void ActionAddModule::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Adding a new resistor: Click to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);
	while (!(Cy > pUI->getToolBarHeight() + pUI->getCompHeight() / 2
		&& Cy < pUI->getHeight() - pUI->getStatusBarHeight() - pUI->getCompHeight() / 2
		&& Cx>pUI->getCompWidth() / 2
		&& Cx < pUI->getWidth() - pUI->getToolItemWidth() / 2))
	{
		pUI->GetPointClicked(Cx, Cy);
	}

	string sR[4];
	double R[4];
	bool isNumber;
	for (int j = 0; j < 4; j++) {
		do {
			pUI->PrintMsg("Enter the value of the source voltage(enter a number): ");
			sR[j] = pUI->GetSrting();
			isNumber = true;
			for (int i = 0; i < sR[j].length(); i++)
				if (isdigit(sR[j][i]) == false)
					isNumber = false;
		} while (!isNumber);

		R[j] = stod(sR[j]);
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

	Module* pR = new Module(pGInfo);
	double Re = 1 / ((1 / (R[0] + R[1])) + (1 / (R[2] + R[3])));
	pR->setResistance(Re);
	pManager->AddComponent(pR);
	comp = pR;
	undo1 = pGInfo;
	undo2 = Re;
}

void ActionAddModule::Undo()
{
	pManager->deleteCompounent(comp);
}

void ActionAddModule::Redo()
{
	Module* pR = new Module(undo1);
	pR->setResistance(undo2);
	pManager->AddComponent(pR);
}