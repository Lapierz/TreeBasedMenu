#pragma once
#ifndef CDeleteAllTab_h
#define CDeleteAllTab_h

#include "CMenuTabCommand.h"
#include "CCONS_h.h"

class CDeleteAllTab : public CMenuTabCommand
{
public:
	CDeleteAllTab(vector <CTable*> *v_vector);
	~CDeleteAllTab();
	void vRunCommand();
private:
	vector <CTable*> *v_vector;
};

#endif