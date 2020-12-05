#include "Resistor.h"
#include <string>

Resistor::Resistor(GraphicsInfo* r_GfxInfo, UI* pUI) :Component(r_GfxInfo)
{
	if (!r_GfxInfo) {
		pUI->PrintMsg("Enter the value of the resistace: ");
		resistance = stod(pUI->GetSrting()); // TODO: Take resistance from user
		pUI->ClearStatusBar();
		sourceVoltage = 0;


		pUI->PrintMsg("Enter the label: ");
		m_Label = pUI->GetSrting();
		pUI->ClearStatusBar();
		sourceVoltage = 0;
	}
}

void Resistor::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawResistor(*m_pGfxInfo, pcomp == this); //update to draw resistor

}


void Resistor::Operate()
{

}

string Resistor::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row =  "RES " + to_string(ID) + " " + m_Label + " " +to_string((int)resistance)+" "+to_string(p.x)+" "+to_string(p.y) ;
	return row;
}
void Resistor::load(int id,string LABELi, double VALUE)
{
	ID= id,
	m_Label = LABELi;
	resistance = VALUE;
}