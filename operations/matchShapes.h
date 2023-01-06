#pragma once

#include "operation.h"

//Add Circle operation class
class matchShapes : public operation
{
public:
	matchShapes(controller* pCont);
	virtual ~matchShapes();

	//Add Circle to the controller
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};