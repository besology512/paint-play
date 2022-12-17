#pragma once
#include ".//operation.h"
#include <fstream>
//Add Save operation class
class opLoad : public operation
{
	
	ifstream inputfile; // make output file to use in Save function

	public:
		opLoad(controller* pCont);
		virtual ~opLoad();

		//Add Save to the controller
		virtual void Execute();

};

