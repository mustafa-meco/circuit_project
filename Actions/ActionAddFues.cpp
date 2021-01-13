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
	pUI->PrintMsg("Adding a new Fuanywhere to add");
	//Get a Pointer to the user Interfaces
	
	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);
	while (!(Cy > pUI->getToolBarHeight() + pUI->getCompHeight() / 2
		&& Cy < pUI->getHeight() - pUI->getStatusBarHeight() - pUI->getCompHeight() / 2
		&& Cx>pUI->getCompWidth() / 2
		&& Cx < pUI->getWidth() - pUI->getToolItemWidth() / 2))
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


	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

	//Calculate the rectangle Corners
	int compWidth = pUI->getCompWidth();
	int compHeight = pUI->getCompHeight();

	pGInfo->PointsList[0].x = Cx - compWidth / 2;
	pGInfo->PointsList[0].y = Cy - compHeight / 2;
	pGInfo->PointsList[1].x = Cx + compWidth / 2;
	pGInfo->PointsList[1].y = Cy + compHeight / 2;

	Fues* pR = new Fues(pGInfo/*, R*/);
	pR->setResistance(R);
	pManager->AddComponent(pR);
	comp = pR;
	undo1 = pGInfo;
	undo2 = R;
}

void ActionAddFues::Undo()
{
	pManager->deleteCompounent(comp);
}

void ActionAddFues::Redo()
{
	Fues* pR = new Fues(undo1/*, undo2*/);
	pR->setResistance(undo2);
	pManager->AddComponent(pR);
}
