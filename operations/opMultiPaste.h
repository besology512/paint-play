#pragma once
#include"..\Shapes\Graph.h"
#include"..\operations\operation.h"
#include"..\GUI\GUI.h"
#include"..\controller.h"



class opMultiPaste : public operation
{

public:
	opMultiPaste(controller* pCont);
	virtual ~opMultiPaste();

	//Add Save to the controller
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};