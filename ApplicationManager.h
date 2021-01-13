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

	enum //Max no of components and connectors
	{
		MaxCompCount = 200,
		MaxConnCount = 1000
	};	


private:
	Component** multiCompList;           // store the selected components to do multiple delete
	Connection** multiConnList;          // store the selected connections to do multiple delete
	int lineCount;
	
	bool IsSimulation;                   // True when in simulation mode
	bool IsModulation;                   // checks if the situation is modulation or not 
	int CompCount;		                 //Actual number of Components
	int ConnCount;		                 //Actual number of Connections
	Component* CopyComp;                 // variable to save the component type
	Component* CompList[MaxCompCount];	 //List of all Components (Array of pointers) 
	Connection* ConnList[MaxConnCount];	 //List of all Connections (Array of pointers) 

	string compLineList[MaxCompCount + MaxConnCount + 3]; //
	string connLineList[MaxCompCount + MaxConnCount + 3]; //

	UI* pUI;                             //pointer to the UI

	Action* UndoList[10];                //array to store the last ten actions to undo them
	Action* RedoList[10];                //array to store the last ten actions to redo them
	int undoNum;                         // counter
	int redoNum;                         // counter  
public:
	ApplicationManager(); //constructor

	bool isSim();
	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();

	///int getCircuit() const;
	
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);               //increase the number of components in comp list

	void AddConnection(Connection* pConn);              //increase the number of connection in comp list

	Component* GetComponentByCordinates(int x, int y); //returns pointer to the component if (x,y) is in the component region  
                                                       //through this function you can know the component type. 

	Connection* GetConnectionByCordinates(int x, int y); //find the connection in the required conn list to edit them 
	// Simulation Mode Functions
	bool ValidateCircuit();                            //chech if  the circuit validate or not and doesn't break some rules like (two grounds) 
	void ToSimulation();                               // Switches to simulation mode
	void ToDesign();                                   //to get back to the design mode
	double CalculateCurrent();                         // calculate the current throught the circuit 
	void CalculateVoltages(double current);           // calculate the voltage start from the ground 
	//void save(ActionType);
	string* save(int&,int&);                     //save the date of the circuit components 
	//destructor
	~ApplicationManager();

		//void Exit();

	void load( string * , double* , Component**, Component** );     //load the	Circuit. 

	bool isAvalible();                                              // to check if the user create two components before connect them or not
	Component* GetCopyComp() const;		 	                        //Getter for the component after coping or cutting the component.
	void SetCopyComp(Component* comp1);                             //Setter for the component   

	
	void deleteCompounent(Component*);                              // delete the component 
	void deleteConnection(Connection*);                             // delete the connection which connected to the components
	

	int multipleStoreComp(Component* multi,int m);                 //storing multiple components to delete them 
	int multipleStoreCon(Connection* multi, int m);                //storing multiple connections to delete them 
	void MultipleDelete(int comp, int conn);                      // delete multiple components  
	void AddToUndoList(Action*);                                   //storing the last ten actions done the user to undo them one by one  
	void AddToRedoList(Action*);                                   //storing the last ten actions done the user to redo them one by one
	void ExcuteUndo();                                             // excute the action of undo 
	void ExcuteRedo();                                             // excute the action of redo 

	bool ValidateModule();                                         //checking if the module valid to be drawn or not 
	void ToModulation();                                           //moving from thr design mode to the modulation mode
	double saveModule();                                           //save the designed module
	bool ValidateClear();                                          // make sure that the design area is clear 
	
	Component* getOne(Connection*);                                //return one of the components which was connected to before deleting it
	void deleteAll();											   //delete all the components and connections in the program
	void operation();
};

#endif