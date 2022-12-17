#pragma once

#include"..\operations\operation.h"
#include<fstream>


class opExit :public operation {
private:
	ofstream outfile;
public:
	opExit(controller* pCont);
	virtual ~opExit();
	// Exit operation 
	virtual void Execute();
	//ofstream outfile;
};
