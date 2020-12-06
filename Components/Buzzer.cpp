
#include "Buzzer.h"

Buzzer::Buzzer(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
		
		//sourceVoltage = 0;
		/*pUI->PrintMsg("Enter the label: ");
		m_Label = pUI->GetSrting();
		pUI->ClearStatusBar();
		sourceVoltage = 0;
	*/
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
	string row =  "BUZ " + to_string(ID) + " " + m_Label+" " +to_string((int)resistance)+" "+to_string(p.x)+" "+to_string(p.y) ;
	return row;
}
void Buzzer::load(int id,string LABELi, double VALUE)  //load the buzzer 
{
	ID= id;                // id for the Buzzer
	m_Label = LABELi;      //label for the Buzzer.
	resistance = VALUE;  
}