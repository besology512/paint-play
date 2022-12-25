#pragma once

#include "operation.h"

//Add Oval Select/Unselect operation class

class opSelectUnselect : public operation
{
public:
	opSelectUnselect(controller* pCont);
	virtual ~opSelectUnselect();

	//Add the slecect and unselect  to the controller
	virtual void Execute();
	virtual void Undo() override;
};

