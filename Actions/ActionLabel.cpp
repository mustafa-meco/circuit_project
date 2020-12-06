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
	pUI->PrintMsg("Label ");
	pUI->GetPointClicked(x, y);
	Component* comp = pManager->GetComponentByCordinates(x, y);
	
	
	pUI->ClearStatusBar();



	if (comp != nullptr)
	{	//comp->selection();
		pUI->PrintMsg("enter the label");
		comp->Setlabel(pUI->GetSrting());

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


		GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

		//Calculate the rectangle Corners
		int compWidth = pUI->getCompWidth();
		int compHeight = pUI->getCompHeight();

		pGInfo->PointsList[0].x = Cx - compWidth / 2;
		pGInfo->PointsList[0].y = Cy - compHeight / 2;
		pGInfo->PointsList[1].x = Cx + compWidth / 2;
		pGInfo->PointsList[1].y = Cy + compHeight / 2;


	

}


void ActionLabel::Undo()
{}

void ActionLabel::Redo()
{}