#pragma once
#include"operation.h"
#include <fstream>

//Add Save operation class
class opSave : public operation
{
//private :
	//Graph OGraph; // make compostion of graph to use function in it (object form graph)
	ofstream outfile; // make output file to use in Save function 
public:
	opSave(controller* pCont);
	virtual ~opSave();

	//Add Save to the controller
	virtual void Execute();

};
