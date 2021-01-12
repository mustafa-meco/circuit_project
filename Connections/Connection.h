#pragma once
#include "..\UI\UI.h"

class Component;	//forward class declaration

class Connection
{
	//connection connects between two compoenets
	Component* Comp1, *Comp2;
	GraphicsInfo* pGfxInfo;	//The parameters required to draw a connection
	static Connection* pconnection;
	

public:
	Connection(GraphicsInfo* r_GfxInfo, Component* cmp1 = nullptr, Component* cmp2 = nullptr);
	virtual void Draw(UI*);	//for connection to Draw itself

	bool IsInRegion(int x, int y, UI* pUI);
	string save() const;
	virtual void load( Component * , Component * );  //load connection

	void EditConnection(Component* component1, Component* component2, GraphicsInfo* pGInfo,UI*);

	Component* getOtherComponent(Component* Cmpnt);// Get component connected to the other end of the connection
	
	Connection* copyconnection();
	Connection* copyconnectionAndChange(Component*);
	~Connection();



};
 