#include "Action.h"
#include"../Components/Component.h"
#include "../ApplicationManager.h"
//Class responsible for adding a new resistor action
class ActionRealistic : public Action
{
private:
	//parameters for rectangular area to be occupied by the comp
	//Component* comp; //pointer to component 
	//Connection* connection; // pointer to connection
	int Cx, Cy;	//center point of the comp
	int x1, y1, x2, y2;	//two corners of the rectangluar area
	double Value;        // to store the voltege or resistance of the component
public:
	ActionRealistic(ApplicationManager* pApp); //constructor

	virtual ~ActionRealistic(void); //destructor

	//execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo(); // undo for select

	virtual void Redo(); //Redo for select
};