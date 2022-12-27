#pragma once

#include "operation.h"


class opRedo : public operation
{
public:
	opRedo(controller* pCont);
	virtual ~opRedo();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
