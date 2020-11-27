#include "ApplicationManager.h"
#include "Actions\ActionAddRes.h"
#include "Actions\ActionAddBul.h"
#include "Actions/ActionAddSwi.h"
#include "Actions\ActionAddBuz.h"
#include "Actions\ActionAddFues.h"
#include "Actions/ActionSave.h"
//#include "Actions/ActionSave.h"
#include "Actions/ActionSelect.h"
#include <iostream>
using namespace std;


ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;

	lineCount = 0;	

	IsSimulation = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = nullptr;
	for (int i = 0; i<MaxCompCount; i++)
		ConnList[i] = nullptr;

	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
//void ApplicationManager::save(ActionType act) {
//	string compType[] = { "RES","SWT","BLB","GND","BAT","BZR","FUS" };
//	if (act <= 6) {
//		if (CompCount < 10)
//			compLineList[CompCount] = { compType[act] , char(CompCount)  , CompList[CompCount]->getResistance() };
//		else if (CompCount < 100)
//			compLineList[CompCount] = { compType[act] , char(CompCount / 10) + char(CompCount % 10) };
//		else
//			compLineList[CompCount] = { compType[act] , char(CompCount / 100) + char((CompCount % 100) / 10) + char(CompCount % 10) };
//
//	}
//}
//string* ApplicationManager::getSaved(int &m, int &n) {
//	m = CompCount;
//	n = ConnCount;
//	return compLineList;
//}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = nullptr;
	switch (ActType)
	{
		case ADD_RESISTOR:
			pAct= new ActionAddRes(this);
			break;
		// TODO: Add remaining actions
		case ADD_BULB:
			pAct = new ActionAddBul(this);
			break;
		case ADD_SWITCH:
			pAct = new ActionAddSwi(this);
			break;
		case ADD_GROUND:
			pAct = new ActionAddGro(this);
			break;
		case ADD_BATTERY:
			pAct = new ActionAddBat(this);
			break;
		case ADD_BUZZER:
			pAct = new ActionAddBuz(this);
			break;
		case ADD_FUES:
			pAct = new ActionAddFues(this);
			break;
		case SELECT:
			pAct = new ActionSelect(this);
			break;
		/*case SAVE:
			pAct = new ActionSave(this);
			break;*/
		case SIM_MODE:
			ToSimulation();
			break;
		case DSN_MODE:
			ToDesign();
			break;
	//	case LOAD:
			//pAct = new ActionLoad(this);
		case EXIT:
			//TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		//save(ActType);
		pAct->Execute();
		delete pAct;
		pAct = nullptr;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	for(int i=0; i<CompCount; i++)
		CompList[i]->Draw(pUI);
	for (int i = 0; i < ConnCount; i++)
		ConnList[i]->Draw(pUI);
}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}
////////////////////////////////////////////////////////////////////
// Validates the circuit before going into simultion mode
bool ApplicationManager::ValidateCircuit() {
	return true;
}

////////////////////////////////////////////////////////////////////
/*Component* GetComponentByCordinates(int x, int y) {

}*/

////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
void ApplicationManager::ToSimulation() {
	if (!ValidateCircuit()) {
		// TODO
	}
	else {
		this->IsSimulation = true;
		// Compute all needed voltages and current
		double current = CalculateCurrent();
		CalculateVoltages(current);
		pUI->CreateSimulationToolBar();
	}
}
void ApplicationManager::ToDesign() {
	this->IsSimulation = false;
	// Compute all needed voltages and current
	pUI->CreateDesignToolBar();
}
////////////////////////////////////////////////////////////////////
// Calculates current passing through the circuit
double ApplicationManager::CalculateCurrent() {
	// TODO
	return 0;
}

// Calculates voltage at each component terminal
void ApplicationManager::CalculateVoltages(double current) {
	// TODO
}

////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	// TODO
}
Component* ApplicationManager::GetComponentByCordinates(int x, int y)
{

	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->isInRegion(x, y, pUI) == true)
		{
			return	CompList[i];
		}

	}
}