#pragma once
#ifndef CChangeVal_h
#define CChangeVal_h

#include "CMenuTabCommand.h"
#include "CPrintAllTab.h"
#include "CCONS_h.h"

class CChangeVal:public CMenuTabCommand
{
public:
	CChangeVal(vector <CTable*> *v_vector);
	~CChangeVal();
	void vRunCommand();
private:
	vector <CTable*> *v_vector;
};
#endif 