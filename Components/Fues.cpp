#include"Fues.h"

Fues::Fues(GraphicsInfo* r_GfxInfo, UI* pUI) :Component(r_GfxInfo)
{
	resistance = 2; 
	sourceVoltage = 0;
	pUI->PrintMsg("Enter the label: ");
	m_Label = pUI->GetSrting();
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

string Fues::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row =  "FUS " + m_Label + " "+to_string((int)sourceVoltage)+" "+to_string(p.x)+" "+to_string(p.y) ;
	return row;
}