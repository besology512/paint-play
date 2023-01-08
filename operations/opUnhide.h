#pragma once

#include"..\operations\operation.h"


class opUnhide :public operation {
public:
	opUnhide(controller* pCont);
	virtual ~opUnhide();
	// Zoom the shape in 
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};