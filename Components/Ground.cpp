#include "Ground.h"
//#include "../Electric Circuit Simulator - Code Framework/Components/Component.h"

Ground::Ground(GraphicsInfo* r_GfxInfo, UI* pUI) :Component(r_GfxInfo)
{
	resistance = 0; 
	sourceVoltage = 0;
	pUI->PrintMsg("Enter the label: ");
	string label = pUI->GetSrting();
	pUI->ClearStatusBar();
	sourceVoltage = 0;
}

void Ground::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawGround(*m_pGfxInfo, pcomp == this); //update to draw resistor

} 

void Ground::Operate()
{

}