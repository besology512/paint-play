#pragma once
#include"../operations/operation.h"

class opChangeFill :public operation {
public:

	opChangeFill(controller* pCont);
	virtual ~opChangeFill();

	//Add square to the controller
	virtual void Execute();
};