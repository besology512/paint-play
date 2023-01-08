#pragma once
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..//operations/operation.h"
#include "opScramble.h"
#include "opDuplicateGraph.h"
#include "matchShapes.h"

class opStart : public operation
{
public:
	opStart(controller* pCont);
	virtual ~opStart();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
