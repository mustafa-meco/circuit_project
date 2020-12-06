#include "Ground.h"
//#include "../Electric Circuit Simulator - Code Framework/Components/Component.h"

Ground::Ground(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 0; 
	sourceVoltage = 0;
	//pUI->PrintMsg("Enter the label: ");
	//m_Label = pUI->GetSrting();
	//pUI->ClearStatusBar();
	//sourceVoltage = 0;

	resistance = -1; 
	//sourceVoltage = 0;
	/*pUI->PrintMsg("Enter the label: ");
	m_Label = pUI->GetSrting();
	pUI->ClearStatusBar();
	sourceVoltage = 0;*/

}



void Ground::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawGround(*m_pGfxInfo, pcomp == this); //update to draw resistor

} 

void Ground::Operate()
{

}

string Ground::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row =  "GND " + to_string(ID) + " " + m_Label + " " + to_string((int)sourceVoltage) + " " + to_string(p.x) + " " + to_string(p.y);
	return row;
}
void Ground::load(int id,string LABELi, double VALUE)
{
	ID = id;
	m_Label = LABELi; 
	resistance = VALUE;
}