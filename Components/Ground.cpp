#include "Ground.h"
//#include "../Electric Circuit Simulator - Code Framework/Components/Component.h"

Ground::Ground(GraphicsInfo* r_GfxInfo, UI* pUI) :Component(r_GfxInfo) 
{

	resistance = 0; // TODO: Take resistance from user
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