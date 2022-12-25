#pragma once
#include "operation.h"


class opPickColor :public operation {
public:
	opPickColor(controller* pCont);
	virtual ~opPickColor();
	// pick the color and return it back in a pointer
	virtual void Execute();
	virtual void Undo() override;
};