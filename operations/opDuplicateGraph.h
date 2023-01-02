#pragma once

#include "operation.h"


class opDuplicateGraph :public operation {
public:
	opDuplicateGraph(controller* pCont);
	virtual ~opDuplicateGraph();

	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};