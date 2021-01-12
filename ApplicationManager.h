#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include "Actions/ActionAddGro.h"
#include "Actions/ActionAddBat.h"



//Main class that manages everything in the application.
class ApplicationManager
{

	enum 
	{
		MaxCompCount = 200,
		MaxConnCount = 1000
	};	//Max no of components and connectors


private:
	Component** multiCompList;
	Connection** multiConnList;
	int lineCount;
	
	bool IsSimulation; // True when in simulation mode
	int CompCount;		//Actual number of Components
	int ConnCount;		//Actual number of Connections
	Component* CopyComp;                // variable to save the component type
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers) 
	Connection* ConnList[MaxConnCount];	//List of all Connections (Array of pointers) 

	string compLineList[MaxCompCount + MaxConnCount + 3];
	string connLineList[MaxCompCount + MaxConnCount + 3];

	UI* pUI; //pointer to the UI

	Action* UndoList[10];
	Action* RedoList[10];
	int undoNum;
	int redoNum;
public:
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();

	///int getCircuit() const;
	
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	void AddConnection(Connection* pConn);

	Component* GetComponentByCordinates(int x, int y); //returns pointer to the component if (x,y) is in the component region  
                                                       //through this function you can know the component type. 

	Connection* GetConnectionByCordinates(int x, int y);
	// Simulation Mode Functions
	bool ValidateCircuit();
	void ToSimulation(); // Switches to simulation mode
	void ToDesign();
	double CalculateCurrent();                         // Mustafa Mahmoud Tayil 
	void CalculateVoltages(double current);
	//void save(ActionType);
	string* save(int&,int&) const;
	//destructor
	~ApplicationManager();

		//void Exit();

	void load( string * , double* , Component**, Component** );     //load the	Circuit. 

	bool isAvalible();   // to check if the user create two components before connect them or not
	Component* GetCopyComp() const;		 	   //Getter for the component after coping or cutting the component.
	void SetCopyComp(Component* comp1);        //Setter for the component   

	
	void deleteCompounent(Component*);
	void deleteConnection(Connection*);
	

	int multipleStoreComp(Component* multi,int m);
	int multipleStoreCon(Connection* multi, int m);
	void  MultipleDelete(int comp, int conn);
	void AddToUndoList(Action*);
	void AddToRedoList(Action*);
	void ExcuteUndo();
	void ExcuteRedo();
	Component* getOne(Connection*);

};

#endif