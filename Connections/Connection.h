#pragma once
#include "..\UI\UI.h"

class Component;	//forward class declaration

class Connection
{
	//connection connects between two compoenets
	Component* Comp1, *Comp2;
	GraphicsInfo* pGfxInfo;	//The parameters required to draw a connection

public:
	Connection(GraphicsInfo* r_GfxInfo, Component* cmp1 = nullptr, Component* cmp2 = nullptr);
	virtual void Draw(UI*);	//for connection to Draw itself
	string save() const;
	virtual void load( Component * , Component * );


	//Component* getOtherComponent(Component* Cmpnt); // Get component connected to the other end of the connection


};
 