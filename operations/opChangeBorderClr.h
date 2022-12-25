#pragma once
#include"../operations/operation.h"

class opChangeBorderClr :public operation {
public:

	opChangeBorderClr(controller* pCont);
	virtual ~opChangeBorderClr();

	//Add the operation to the controller
	virtual void Execute();
	virtual void Undo() override;
};