/* #include "ActionSave.h"
#include "../ApplicationManager.h"

ActionSave::ActionSave(ApplicationManager* pApp):Action(pApp)
{

}

ActionSave::~ActionSave()
{
}

void ActionSave::Execute() {
	UI* pUI = pManager->GetUI();

	pUI->PrintMsg("Enter the name of the file to be saved into");
	folder = pUI->GetSrting();
	

	for (int i = 0; i< pManager->getCircuit())
}

void ActionSave::Undo()
{}

void ActionSave::Redo()
{} */