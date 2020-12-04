
#include "Buzzer.h"

Buzzer::Buzzer(GraphicsInfo* r_GfxInfo, UI* pUI) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
	sourceVoltage = 0;
	pUI->PrintMsg("Enter the label: ");
	m_Label = pUI->GetSrting();
	pUI->ClearStatusBar();
	sourceVoltage = 0;
}

void Buzzer::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawBuzzer(*m_pGfxInfo,pcomp==this ); //update to draw resistor
	
}
void Buzzer::Operate()
{


}

string Buzzer::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row =  "BUZ " +m_Label+" " +to_string((int)resistance)+" "+to_string(p.x)+" "+to_string(p.y) ;
	return row;
}