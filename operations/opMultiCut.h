#pragma once
#include"..\Shapes\Graph.h"
#include"..\operations\operation.h"
#include"..\GUI\GUI.h"
#include"..\controller.h"



class opMultiCut : public operation
{

public:
	opMultiCut(controller* pCont);
	virtual ~opMultiCut();

	//Add Save to the controller
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};