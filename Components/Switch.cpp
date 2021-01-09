#include "Switch.h"
#include <string>

Switch::Switch(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	
	
}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, pcomp == this); //update to draw switchS
	status = 0; 
}

void Switch::Operate()
{

}

string Switch::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row =  "SWT "+ to_string(ID) + " " + m_Label+" "+to_string((int)sourceVoltage)+" "+to_string(p.x)+" "+to_string(p.y) ;
	return row;
	
}
void Switch::load(int id,string LABELi , double VALUE)
{
	ID= id;              // id for the switch 
	m_Label = LABELi;    //label for the switch. 
	status = VALUE;      //status for the switch 
}
void Switch::Copy(Component* &B)   
{
	B = new Switch(m_pGfxInfo); 
	B->Setlabel(m_Label);
}