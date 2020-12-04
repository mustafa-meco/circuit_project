
#include "Buzzer.h"

Buzzer::Buzzer(GraphicsInfo* r_GfxInfo, UI* pUI) :Component(r_GfxInfo)
{
	resistance = 2; // TODO: Take resistance from user
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