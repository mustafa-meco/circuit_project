#include "Bulb.h"

Bulb::Bulb(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	x = 0;
	resistance = 1;
	sourceVoltage = 0;
	//pUI->PrintMsg("Enter the value of the resistace: ");
	//resistance = stod(pUI->GetSrting()); // TODO: Take resistance from user
	//pUI->ClearStatusBar();
	//sourceVoltage = 0;

	/*pUI->PrintMsg("Enter the label: ");
	m_Label = pUI->GetSrting();
	pUI->ClearStatusBar();
	sourceVoltage = 0;*/

	//if (!r_GfxInfo) {

		//resistance = R;
		//sourceVoltage = 0;

		/*pUI->PrintMsg("Enter the label: ");
		m_Label = pUI->GetSrting();*/
		
		//sourceVoltage = 0;
	//}

}

void Bulb::Draw(UI* pUI)
{
	//Call output class and pass bulb drawing info to it.
	if (x == 0)
		pUI->DrawBulb(*m_pGfxInfo, pcomp == this); //update to draw bulb
	else
		pUI->DrawON(*m_pGfxInfo, pcomp == this);
}

void Bulb::Operate()
{
	x = this->GetOutStatus();
	
}

string Bulb::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row =  "BLB " + to_string(ID) + " " + m_Label+ " "+to_string((int)resistance) + " "+to_string(p.x)+" "+ to_string(p.y) ;
	return row;
}
void Bulb::load(int id,string LABELi, double VALUE)  //load bulb
{
	ID = id;                  //id for bulb 
	m_Label = LABELi;         // new label for bulb
	resistance = VALUE;       // the resistance of the bulb 
}
Component* Bulb::Copy()
{
	Component* B;
	B = new Bulb(m_pGfxInfo); 
	B->setResistance(this->resistance);
	B->Setlabel(m_Label);
	return B;
}
int Bulb::GetOutStatus()
{
	
	if (term1_volt == term2_volt)
		return 0;
	else
		return 1;

}
int Bulb::GetInputStatus()
{
	return-1;
}

void Bulb::setInputStatus(STATUS s)
{
}