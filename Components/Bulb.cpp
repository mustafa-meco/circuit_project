#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo, UI* pUI) :Component(r_GfxInfo)
{
	pUI->PrintMsg("Enter the value of the resistace: ");
	resistance = stod(pUI->GetSrting()); // TODO: Take resistance from user
	pUI->ClearStatusBar();
	sourceVoltage = 0;
}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass bulb drawing info to it.
	pUI->DrawBulb(*m_pGfxInfo); //update to draw bulb

}

void Bulb::Operate()
{

}