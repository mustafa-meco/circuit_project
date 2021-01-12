#pragma once
#include "..\UI\UI.h"

class Component;	                               //forward class declaration

class Connection
{
	//connection connects between two compoenets
	
	string connLabel;

	Component* Comp1, *Comp2; 	                    //connection connects between two compoenets
	GraphicsInfo* pGfxInfo;	                        //The parameters required to draw a connection
	static Connection* pconnection;                 //pointer to connection which is selected
	

public:
	Connection(GraphicsInfo* r_GfxInfo, Component* cmp1 = nullptr, Component* cmp2 = nullptr); //Constructor 
	virtual void Draw(UI*);                          //for connection to Draw itself

	bool IsInRegion(int x, int y, UI* pUI);          //Check the point which the user click on is in the region of the connection or not 
	string save() const;                             //save the connection
	virtual void load( Component * , Component * );  //load connection

	void EditConnection(Component* component1, Component* component2, GraphicsInfo* pGInfo,UI*); //edit the connection
	string SetConnectionlabel(string input);
	Component* getOtherComponent(Component* Cmpnt);  //Get component connected to the other end of the connection
	
	Connection* copyconnection();                    //is used in Undo and Redo to return the connection after deleting it 
	Connection* copyconnectionAndChange(Component*); // replaced the deleted connection with a new one 
	~Connection();                                   // destructor 



};
 