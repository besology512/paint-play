#pragma once
#include"../operations/operation.h"

class opChangeBorderWidth :public operation {
public:

	opChangeBorderWidth(controller* pCont);
	virtual ~opChangeBorderWidth();

	//Add the operation to the controller
	virtual void Execute();
};