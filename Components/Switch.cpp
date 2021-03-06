#include "Switch.h"
#include <string>
#include<iostream>
Switch::Switch(GraphicsInfo* r_GfxInfo) :Component(r_GfxInfo)
{
	resistance = 0;
	sourceVoltage = 0;
	m_Label = "switch" + to_string(ID);
}

void Switch::Draw(UI* pUI)
{
	//Call output class and pass resistor drawing info to it.
	pUI->DrawSwitch(*m_pGfxInfo, pcomp == this); //update to draw switchS
	//status = 0; 
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
void Switch::load(int id,string LABELi , double VALUE)       //load if there is a switch in the saved file 
{
	ID= id;              // id for the switch 
	m_Label = LABELi;    //label for the switch. 
	status = VALUE;      //status for the switch 
}
Component* Switch::Copy()    //Copy the component information 
{
	Component* B;       
	B = new Switch(m_pGfxInfo);      // create a new Component and save the previous info in the new one
	B->Setlabel(m_Label);
	return B;
}

int Switch::GetOutStatus()
{
	return -1;
}
int Switch::GetInputStatus()
{
	if (status == 1)
		return 1;
	else
		return 0;
}

void Switch::setInputStatus(STATUS s)
{
}