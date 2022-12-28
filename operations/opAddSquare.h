#pragma once
#include"operation.h"

class opAddSquare :public operation 
{
public:

	opAddSquare(controller* pCont);
	virtual ~opAddSquare();

	//Add square to the controller
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};