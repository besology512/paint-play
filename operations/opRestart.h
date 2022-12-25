#pragma once

#include"..//operations/operation.h"


class opRestart : public operation
{
public:
	opRestart(controller* pCont);
	virtual ~opRestart();

	//Add rectangle to the controller
	virtual void Execute();
	virtual void Undo() override;
};
