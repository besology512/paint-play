#pragma once

#include"..\operations\operation.h"


class opDelete :public operation {
public:
	opDelete(controller* pCont);
	virtual ~opDelete();
	// Delete a single shape 
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
