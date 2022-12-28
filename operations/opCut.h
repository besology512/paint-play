#pragma once

#include "operation.h"


class opCut : public operation
{
public:
	opCut(controller* pCont);
	virtual ~opCut();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
