#include "Switch.h"
#include <string>

Switch::Switch(GraphicsInfo* r_GfxInfo/*, bool S*/) :Component(r_GfxInfo)
{
	//if (!r_GfxInfo){
	//	//status = S;
	//	

	//	////pUI->PrintMsg("Enter the label: ");
	//	//m_Label = pUI->GetSrting();
	//	//pUI->ClearStatusBar();
	//}
	
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
	ID= id;
	m_Label = LABELi;
	status = VALUE;
}