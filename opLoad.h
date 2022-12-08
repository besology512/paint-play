#pragma once
#include "operations/operation.h"
#include "Shapes/Graph.h"
#include "GUI/GUI.h"
#include "controller.h"
#include <fstream>
#include "Line.h"

//Add Load operation class
class opLoad : public operation
{
private:
	ifstream inputfile; // make output file to use in Save function
	string str; // variable that take data from getline function 
	int data;
	string* arrayL;
	int size;
	int i,j;

public:
	
	opLoad(controller* pCont);
	virtual ~opLoad();

	//Add Save to the controller
	virtual void Execute();

};

