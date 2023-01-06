#pragma once


#include"..\operations\operation.h"


class opHide :public operation {
public:
	opHide(controller* pCont);
	virtual ~opHide();
	// Zoom the shape in 
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
