#pragma once

#include"..\operations\operation.h"


class opZoomout :public operation {
public:
	opZoomout(controller* pCont);
	virtual ~opZoomout();
	// Zoom the shape out 
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};