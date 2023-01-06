#pragma once
#include"..\Shapes\Graph.h"
#include"..\operations\operation.h"
#include"..\GUI\GUI.h"
#include"..\controller.h"


//Add Save operation class
class opMultiCopy : public operation
{

public:
	opMultiCopy(controller* pCont);
	virtual ~opMultiCopy();

	//Add Save to the controller
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
