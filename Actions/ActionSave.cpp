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
	outFile.open(folder + ".txt");

	outFile << CompCount << endl;
	for (int i = 0 ; i<CompCount;i++)
		outFile << data[i] << endl;
	outFile << "Connections" << endl;
	outFile << ConnCount << endl;
	for (int i = 0; i < CompCount; i++)
		outFile << data[i+CompCount] << endl;

	/*for (int i = 1; i <= CompCount; i++) {
		outFile << data[i - 1][0] + " " + to_string(i);
		for (int j = 1; i < 5; j++)
			outFile << " " + data[i - 1][j];
		outFile << endl;
	}*/
}

void ActionSave::Undo()
{}

void ActionSave::Redo()
{} 