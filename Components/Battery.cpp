#include "Battery.h"

Battery::Battery(GraphicsInfo* r_GfxInfo ) :Component(r_GfxInfo)
{
	//if (!r_GfxInfo) {

		//resistance = 2; // take battery from user
		//sourcevoltage = 0;
		//pUI->PrintMsg("Enter the value of the internal resistance: ");
		//resistance = stod(pUI->GetSrting()); // TODO: Take resistance from user
		//pUI->ClearStatusBar();
		
		//pUI->ClearStatusBar();
		sourceVoltage = 2;

		//pUI->PrintMsg("Enter the label: ");
		//m_Label = pUI->GetSrting();
		
	
}

void Battery::Draw(UI* pUI)
{
	//Call output class and pass battery drawing info to it.
	pUI->DrawBattery(*m_pGfxInfo, pcomp == this); //update to draw battery
}

void Battery::Operate()
{

}

string Battery::save() const {
	Point p;
	p.x = m_pGfxInfo->PointsList[0].x;
	p.y = m_pGfxInfo->PointsList[0].y;
	string row = "BAT " +to_string(ID)+ " " +m_Label +" "+to_string((int)sourceVoltage)+" "+to_string(p.x)+" "+to_string(p.y);
	return row;
}
void Battery::load(int id,string LABELi, double VALUE)    //load the battery
{
	ID = id;               //id for the battery
	m_Label = LABELi;      //new label for the battery 
	resistance = VALUE;    // the internal resistance of the battery
	
}
void Battery::Copy(Component*B ) 
{
	B = new Battery(m_pGfxInfo);
	B->setSourceVoltage(this->sourceVoltage);
}