#include"..\Actions\ActionAddCon.h" 
#include "..\ApplicationManager.h" 


#include "../Components/Component.h"
ActionAddCon::ActionAddCon(ApplicationManager* pApp) :Action(pApp)
{
}

ActionAddCon::~ActionAddCon(void)
{
}

void ActionAddCon::Execute()
{
	UI* pUI = pManager->GetUI();
	if (!pManager->isAvalible())
	{
		pUI->PrintMsg("  You should have two components to connect them : ");

	}
	else {




		//Get a Pointer to the user Interfaces

		pUI->PrintMsg(" choose two points for connection : ");
		do
		{

			pUI->GetPointClicked(Cx1, Cy1);
			comp1 = pManager->GetComponentByCordinates(Cx1, Cy1);
			//comp1->addTerm1Connection();
		} while (comp1 == nullptr);


		do
		{


			pUI->PrintMsg(" You Choose the first point, now choose the second one : ");

			pUI->GetPointClicked(Cx2, Cy2);
			comp2 = pManager->GetComponentByCordinates(Cx2, Cy2);
			pUI->ClearStatusBar();
		} while (comp2 == nullptr || comp2 == comp1);






		GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

		//Calculate the rectangle Corners
		int compWidth = pUI->getCompWidth();
		int compHeight = pUI->getCompHeight();
		pGInfo->PointsList[0].y = comp1->getCompCentery(pUI);
		pGInfo->PointsList[1].y = comp2->getCompCentery(pUI);
		TerminalNum comp1conn, comp2conn;
		if (Cx1 < comp1->getCompCenterx(pUI))
		{
			pGInfo->PointsList[0].x = comp1->getCompCenterx(pUI) - compWidth / 2;

			//comp1->addTerm1Connection();
			comp1conn = TERM1;
		}
		else
		{
			pGInfo->PointsList[0].x = comp1->getCompCenterx(pUI) + compWidth / 2;
			comp1conn = TERM2;
		}
		if (Cx1 < comp2->getCompCenterx(pUI))
		{
			pGInfo->PointsList[1].x = comp2->getCompCenterx(pUI) - compWidth / 2;
			comp2conn = TERM1;
			//comp2->addTerm1Connection();
		}
		else
		{
			pGInfo->PointsList[1].x = comp2->getCompCenterx(pUI) + compWidth / 2;
			comp2conn = TERM2;
		}


		Connection* pCON = new Connection(pGInfo, comp1, comp2);
		if (comp1conn == TERM1)
			comp1->addTerm1Connection(pCON);
		else
			comp1->addTerm2Connection(pCON);
		if (comp2conn == TERM1)
			comp2->addTerm1Connection(pCON);
		else
			comp2->addTerm2Connection(pCON);
		//pUI->DrawConnection(*pGInfo);
		pManager->AddConnection(pCON);
	}
}
 
void ActionAddCon::Undo()
{}

void ActionAddCon::Redo()
{}