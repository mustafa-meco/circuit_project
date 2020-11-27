#include "Component.h"

Component::Component(GraphicsInfo *r_GfxInfo)
{
	m_pGfxInfo = r_GfxInfo;	
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
}

Component::Component()
{
	m_pGfxInfo = nullptr;
	term1_volt = term2_volt = 0;
	term1_conn_count = term2_conn_count = 0;
}

Component::~Component()
{}

bool Component::isInRegion(int x, int y, UI* pUI)
{
	if (m_pGfxInfo->PointsList[0].x < x && m_pGfxInfo->PointsList[1].x > x && m_pGfxInfo->PointsList[0].y < y && m_pGfxInfo->PointsList[1].y > y)
	{
		pcomp = this;
		return true;
	}
	
}

Component* Component::pcomp = nullptr;