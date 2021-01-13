
#include "ActionAddDesignedModule.h"

ActionAddDesignedModule::ActionAddDesignedModule(ApplicationManager* pApp) : Action(pApp)
{
}

ActionAddDesignedModule::~ActionAddDesignedModule(void)
{
}
void ActionAddDesignedModule::Execute()
{
	UI* pUI = pManager->GetUI();
	ifstream inFile;                   // the file which will be read from

	pUI->PrintMsg("Do you want to draw (1) or load pre drawed one(2) : (1 for draw : 2 for load)");
	string op;
	bool isNumber1;
	
		do {
			pUI->PrintMsg("Do you want to draw (1) or load pre drawed one(2) : (1 for draw : 2 for load)");
			op = pUI->GetSrting();
			isNumber1 = true;
			for (int i = 0; i < op.length(); i++)
				if (isdigit(op[i]) == false)
					isNumber1 = false;
		} while (!isNumber1);

		int op1 = stoi(op);

		if(op1==1)
			pManager->ToModulation();
		else {

			pUI->PrintMsg("Enter the file name : ");
			string filename = pUI->GetSrting();      // save the file name 


			inFile.open(filename);            // open the file 
			while (!inFile)                   // if the file isnot existed print a message and take the file name again 
			{
				pUI->PrintMsg("Enter the file name : ");
				filename = pUI->GetSrting();
				inFile.open(filename);
			}

			string input;
			getline(inFile, input, ' ');
			if (input != "MOD")
				pUI->CreateErrorWind("invalid file (must start with (MOD))");
			else {
				getline(inFile, input);
				pUI->PrintMsg("Adding a new MOD: Click to add");

				//Get Center point of the area where the Comp should be drawn
				pUI->GetPointClicked(Cx, Cy);
				while (!(Cy > pUI->getToolBarHeight() + pUI->getCompHeight() / 2
					&& Cy < pUI->getHeight() - pUI->getStatusBarHeight() - pUI->getCompHeight() / 2
					&& Cx>pUI->getCompWidth() / 2
					&& Cx < pUI->getWidth() - pUI->getToolItemWidth() / 2))
				{
					pUI->GetPointClicked(Cx, Cy);
				}

				string sR[4];
				double R[4];
				bool isNumber;
				for (int j = 0; j < 4; j++) {
					do {
						pUI->PrintMsg("Enter the value of the source voltage(enter a number): ");
						sR[j] = pUI->GetSrting();
						isNumber = true;
						for (int i = 0; i < sR[j].length(); i++)
							if (isdigit(sR[j][i]) == false)
								isNumber = false;
					} while (!isNumber);

					R[j] = stod(sR[j]);
				}





				//Clear Status Bar
				pUI->ClearStatusBar();


				GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

				//Calculate the rectangle Corners
				int compWidth = pUI->getCompWidth();
				int compHeight = pUI->getCompHeight();

				pGInfo->PointsList[0].x = Cx - compWidth / 2;
				pGInfo->PointsList[0].y = Cy - compHeight / 2;
				pGInfo->PointsList[1].x = Cx + compWidth / 2;
				pGInfo->PointsList[1].y = Cy + compHeight / 2;

				Module* pR = new Module(pGInfo);
				double Re = stod(input);
				pR->setResistance(Re);
				pManager->AddComponent(pR);
			}
			inFile.close();
		}
}


void ActionAddDesignedModule::Undo() {

}
void ActionAddDesignedModule::Redo() {

}