#pragma once
#ifndef CNewTable_h
#define CNewTable_h

#include "CMenuTabCommand.h" 
#include "CCONS_h.h"


class CNewTable: public CMenuTabCommand
{
public:
	CNewTable(vector <CTable*> *v_vector);
	~CNewTable();
	void vRunCommand();
private:
	vector <CTable*> *v_vector;
};

#endif