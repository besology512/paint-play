#pragma once

#include "operation.h"


class opPaste : public operation
{
public:
	opPaste(controller* pCont);
	virtual ~opPaste();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
