#pragma once

#include"..\operations\operation.h"


class opDrag :public operation {
public:
	opDrag(controller* pCont);
	virtual ~opDrag();
	// Drag the shape in 
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
