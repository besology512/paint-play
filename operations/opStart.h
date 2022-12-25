#pragma once

#include"..//operations/operation.h"


class opStart : public operation
{
public:
	opStart(controller* pCont);
	virtual ~opStart();

	//Add rectangle to the controller
	virtual void Execute();
	virtual void Undo() override;
};
