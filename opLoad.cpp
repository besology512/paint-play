#include "opLoad.h"




opLoad::opLoad(controller* pCont) : operation(pCont)
{
}

opLoad::~opLoad()
{
}

void opLoad::Execute()
{
	// Get User input
	GUI* pUI = pControl->GetUI();//howa lazem a3ml getUI ??? wa7ed bs 
	

	pUI->PrintMessage("Enter File Name"); // enter file wanted to be loaded 

	string fileName = pUI->GetSrting();

	inputfile.open(fileName + ".txt"); // open file and store it in folder in working directory 

	if (!inputfile) // to check if file found or not 
	{
		pUI->PrintMessage("This file not found");
	}
	else
	{


		arrayL = new string;
		i = 0;
		j = 0;
		while (getline(inputfile, str,'X')) //  
		{
			while (getline(inputfile, str))
			{
				//data = stoi(str);
				//arrayL[i] = data;
				//i++;
				switch(arrayL[0])
				
				arrayL[i] = str;
				i++;
			}

		}
		//Graph* pGr = pControl->getGraph();
		//pGr->Load(inputfile); // Load operation deal with Load in graph that deal with LOAD in each Shape 


	}

	
	inputfile.close();

	pUI->PrintMessage("Saved Succussfully");




}
