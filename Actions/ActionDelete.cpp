#include"ActionDelete.h"
#include "../ApplicationManager.h"

ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{}
ActionDelete::~ActionDelete(void)
{}


void ActionDelete::Execute()
{
  	int cx = 0;
	int cy = 0;
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("choose the compounent that you want to delete");
	pUI->GetPointClicked(cx, cy);
	do
	{
		comp = pManager->GetComponentByCordinates(cx, cy);

		connection = pManager->GetConnectionByCordinates(cx, cy);

	} while (connection == nullptr && comp == nullptr);

	//GraphicsInfo* pGInfo = new GraphicsInfo(1);
	//comp->DeleteImage(pGInfo, pUI);
	//comp->removeTerm1Connection(connection);
	//comp->removeTerm2Connection(connection);


pManager->deleteCompounent(comp);
	pManager->deleteConnection(connection);
	pUI->ClearStatusBar();
  
}



void ActionDelete::Undo() {}
void ActionDelete::Redo() {}