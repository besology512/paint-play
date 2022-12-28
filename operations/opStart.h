#pragma once

#include"..//operations/operation.h"


class opStart : public operation
{
public:
	opStart(controller* pCont);
	virtual ~opStart();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
