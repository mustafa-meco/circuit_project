#include"ActionMultipleDelete.h"
#include "../ApplicationManager.h"

ActionMultipleDelete::ActionMultipleDelete(ApplicationManager* pApp) :Action(pApp)
{}
ActionMultipleDelete::~ActionMultipleDelete(void)
{}


void ActionMultipleDelete::Execute()
{


	int cx = 0;
	int cy = 0;
	UI* pUI = pManager->GetUI();
	int counterSelected = 0;
	pUI->DrawConfirm();
	int compcountm=	pManager->multipleStoreComp(nullptr, 1);
	int conncountm=	pManager->multipleStoreCon(nullptr, 1);
	
	while (!(Cx < 25 && Cy<pUI->getHeight() - pUI->getStatusBarHeight() && Cy > pUI->getHeight() - pUI->getStatusBarHeight() - 40))
	{
		pUI->PrintMsg("choose ALL compounents that you want to delete and then click the purple squere to end action");
		
		do
		{
			pUI->GetPointClicked(Cx, Cy);
		comp = pManager->GetComponentByCordinates(Cx, Cy);

		connection = pManager->GetConnectionByCordinates(Cx, Cy);

		} while (connection == nullptr && comp == nullptr&& !(Cx < 25 && Cy<pUI->getHeight() - pUI->getStatusBarHeight() && Cy > pUI->getHeight() - pUI->getStatusBarHeight() - 40));

		if (comp)
		{
			compcountm=pManager->multipleStoreComp(comp,0);
			comp = nullptr;
		}
		else if(connection)
		{
			conncountm=pManager->multipleStoreCon(connection,0);
			connection = nullptr;
		}
	
		pUI->ClearStatusBar();

	}
	pManager->MultipleDelete(compcountm, conncountm);
}




void ActionMultipleDelete::Undo() {}
void ActionMultipleDelete::Redo() {}