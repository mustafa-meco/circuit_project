#include "ActionSaveDesignedModule.h"
#include "../ApplicationManager.h"
#include <fstream>
ActionSaveDesignedModule::ActionSaveDesignedModule(ApplicationManager* pApp):Action(pApp)
{

}

ActionSaveDesignedModule::~ActionSaveDesignedModule()
{
}

void ActionSaveDesignedModule::Execute() {
	UI* pUI = pManager->GetUI();
	double ResistaceT = pManager->saveModule();
	
	

	pUI->PrintMsg("Enter the name of the file to be saved into");
	string folder = pUI->GetSrting();
		
	ofstream outFile;
	outFile.open(folder);

	outFile << "MOD " << to_string(ResistaceT) << endl;
	
	outFile.close();
	
}

void ActionSaveDesignedModule::Undo()
{}

void ActionSaveDesignedModule::Redo()
{} 