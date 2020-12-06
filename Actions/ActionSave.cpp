#include "ActionSave.h"
#include "../ApplicationManager.h"
#include <fstream>
ActionSave::ActionSave(ApplicationManager* pApp):Action(pApp)
{

}

ActionSave::~ActionSave()
{
}

void ActionSave::Execute() {
	UI* pUI = pManager->GetUI();
	int CompCount, ConnCount;
	string* data = pManager->save(CompCount, ConnCount);

	

	pUI->PrintMsg("Enter the name of the file to be saved into");
	string folder = pUI->GetSrting();
		
	ofstream outFile;
	outFile.open(folder);

	outFile << CompCount << endl;
	for (int i = 0 ; i<CompCount;i++)
		outFile << data[i] << endl;
	outFile << "Connections" << endl;
	outFile << ConnCount << endl;
	for (int i = 0; i < CompCount; i++)
		outFile << data[i+CompCount] << endl;

	
}

void ActionSave::Undo()
{}

void ActionSave::Redo()
{} 