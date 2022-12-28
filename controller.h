#pragma once
#include "operations/operation.h"
#include "DEFS.h"
#include "Shapes\Graph.h"
#include "GUI\GUI.h"
#include <stack>

class operation; //forward declaration

//Main class that manages everything in the application.
class controller
{

	Graph* pGraph;	//pointer to the graph
	GUI* pGUI;		//Pointer to UI class
	stack<operation*> Operations;
	stack<operation*> UndoneOperations;
public:
	controller(); 
	~controller();
	
	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	operation* createOperation(operationType) ; //Creates an operation
	void Run();
	
	Graph* getGraph() const;
	
	// -- Interface Management Functions
	GUI *GetUI() const; //Return pointer to the UI
	void UpdateInterface() const;	//Redraws all the drawing window	
	operation* getLastOperation();
	void addToCurrentOperation(operation* newOperation);
	operation* getUndoneOperation();
	void UndoOperation();
	void RedoOperation();
};

