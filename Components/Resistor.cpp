#include "Resistor.h"
#include <string>

Resistor::Resistor(GraphicsInfo *r_GfxInfo, UI* pUI):Component(r_GfxInfo)
{
	pUI->PrintMsg("Enter the value of the resistace: ");
	resistance = stod(pUI->GetSrting()); // TODO: Take resistance from user
	pUI->ClearStatusBar(); 
	sourceVoltage = 0;
}

void Resistor::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo, pcomp == this); //update to draw resistor

}


void Resistor::Operate()
{

}