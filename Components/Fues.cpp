#include"Fues.h"

Fues::Fues(GraphicsInfo* r_GfxInfo, UI* pUI) :Component(r_GfxInfo)
{
	resistance = 2; 
	sourceVoltage = 0;
	pUI->PrintMsg("Enter the label: ");
	string label = pUI->GetSrting();
	pUI->ClearStatusBar();
	sourceVoltage = 0;
}

void Fues::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawFues(*m_pGfxInfo, pcomp == this); //update to draw Fues

}
void Fues::Operate()
{


}