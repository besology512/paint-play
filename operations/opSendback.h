#pragma once

#include"..\operations\operation.h"


class opSendback :public operation {
public:
	opSendback(controller* pCont);
	virtual ~opSendback();
	// Send the selected shape back
	virtual void Execute ();
	virtual void Undo() override;
	virtual void Redo() override;
};
