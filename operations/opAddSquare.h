#pragma once
#include"../operations/operation.h"

class opAddSquare :public operation {
public:

	opAddSquare(controller* pCont);
	virtual ~opAddSquare();

	//Add square to the controller
	virtual void Execute();

};