
#include <iostream>
#include <sstream>
#include <cmath>
//#include "CMUgraphicsLib/CMUgraphics.h"
#include "ApplicationManager.h"

int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		if (ActType != EXIT)
		{
			AppManager.ExecuteAction(ActType);
		}
		//Update the drawing window
	
		
			AppManager.UpdateInterface();
		

	}while(ActType != EXIT);
		
	return 0;
}

