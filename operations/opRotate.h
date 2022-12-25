#pragma once

#include "operation.h"


class opRotate : public operation
{
public:
	opRotate(controller* pCont);
	virtual ~opRotate();
	virtual void Execute();
	virtual void Undo() override;
};