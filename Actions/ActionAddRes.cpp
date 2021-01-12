#include "ActionAddRes.h"
#include "../ApplicationManager.h"
#include"..\Components\Component.h"

ActionAddRes::ActionAddRes(ApplicationManager *pApp):Action(pApp)
{
}

ActionAddRes::~ActionAddRes(void)
{
}

void ActionAddRes::Execute()
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
		&& Cx <pUI->getWidth() - pUI->getToolItemWidth() / 2))
	{
		pUI->GetPointClicked(Cx, Cy);
	}

	string sR;
	bool isNumber;
	do {
		pUI->PrintMsg("Enter the value of the source voltage(enter a number): ");
		sR = pUI->GetSrting();
		isNumber = true;
		for (int i = 0; i < sR.length(); i++)
			if (isdigit(sR[i]) == false)
				isNumber = false;
	} while (!isNumber);


	double R = stod(sR);

	//Clear Status Bar
	pUI->ClearStatusBar();	
	
	
	GraphicsInfo * pGInfo= new GraphicsInfo(2); //Gfx info to be used to construct the Comp
	
	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth/2;
	pGInfo->PointsList[0].y = Cy - compHeight/2;
	pGInfo->PointsList[1].x = Cx + compWidth/2;
	pGInfo->PointsList[1].y = Cy + compHeight/2;

	Resistor* pR = new Resistor(pGInfo);
	pR->setResistance(R);
	pManager->AddComponent(pR);
	comp = pR;
	undo1 = pGInfo;
	undo2 = R;
}

void ActionAddRes::Undo()
{
	pManager->deleteCompounent(comp);
}

void ActionAddRes::Redo()
{
	Resistor* pR = new Resistor(undo1);
	pR->setResistance(undo2);
	pManager->AddComponent(pR);
}

