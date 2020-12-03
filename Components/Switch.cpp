#include "Switch.h"
#include <string>

Switch::Switch(GraphicsInfo* r_GfxInfo, UI* pUI) :Component(r_GfxInfo)
{
	pUI->PrintMsg("Enter the value of the switch (0: opened, 1: closed)");
	status = static_cast<bool>(stoi(pUI->GetSrting())); 
	pUI->ClearStatusBar();
	sourceVoltage = 0;

	pUI->PrintMsg("Enter the label: ");
	string label = pUI->GetSrting();
	pUI->ClearStatusBar();
	sourceVoltage = 0;
}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, pcomp == this); //update to draw switch

}

void Switch::Operate()
{

}