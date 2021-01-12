#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include "Action.h"
#include "../ApplicationManager.h"
#include "../UI/UI.h"
#include <string>
#include "../Components/Battery.h"
#include "../Components/Bulb.h"
#include "../Components/Buzzer.h"
#include "../Components/Component.h"
#include "../Components/Fues.h"
#include "../Components/Ground.h"
#include "../Components/Resistor.h"

#include "../Components/Switch.h"
class ActionLoad : public Action
{
	string filename;    // name of the file which will be loaded
	int ComID;          // id for the component 
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



