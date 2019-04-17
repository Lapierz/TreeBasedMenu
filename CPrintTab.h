#pragma once
#ifndef CPrintTab_h
#define CPrintTab_h

#include "CMenuTabCommand.h"
#include "CCONS_h.h"


class CPrintTab : public CMenuTabCommand
{
public:
	CPrintTab(vector <CTable*> *v_vector);
	~CPrintTab();
	void vRunCommand();
private:
	vector <CTable*> *v_vector;
};
#endif 