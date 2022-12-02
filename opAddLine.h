#pragma once

#include "operations/operation.h"
//Add Line operation class
class opAddLine : public operation
{
private:
	Point P1, P2;
public:
	opAddLine(controller* pCont);
	virtual ~opAddLine();

	//Add Circle to the controller
	virtual void Execute();
	void Save(ofstream& OutFile);
};





