#pragma once

#include"..//operations/operation.h"


class opSwitch : public operation
{
public:
	opSwitch(controller* pCont);
	virtual ~opSwitch();

	//Add rectangle to the controller
	virtual void Execute();
	virtual void Undo() override;
};
