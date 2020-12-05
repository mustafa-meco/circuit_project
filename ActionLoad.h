#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include "Actions/Action.h"
#include "..\circuit_project\ApplicationManager.h"
#include "ActionLoad.h"
#include "UI/UI.h"
#include <string>
#include "Components/Battery.h"
#include "Components/Bulb.h"
#include "Components/Buzzer.h"
#include  "Components/Component.h"
#include "Components/Fues.h"
#include "Components/Ground.h"
#include "Components/Resistor.h"
#include "Components/Switch.h"

class ActionLoad : public Action
{
	string filename;
	int ComID;
	string input;
	Component* comp01; 
	Component* comp02; 
public :
	ActionLoad(ApplicationManager* pApp);

	~ActionLoad(void);
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};



