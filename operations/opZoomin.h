#pragma once

#include"..\operations\operation.h"


class opZoomin :public operation {
public:
	float Factor;
	opZoomin(controller* pCont);
	virtual ~opZoomin();
	// Zoom the shape in 
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
