#pragma once

#include "operation.h"


class opResize: public operation
{
public:
	float Factor;
	opResize(controller* pCont);
	virtual ~opResize();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};