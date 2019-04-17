#pragma once
#ifndef CClone_h
#define CClone_h

#include"CMenuTabCommand.h"
#include "CPrintAllTab.h"
#include "CCONS_h.h"


class CClone : public CMenuTabCommand
{
public:
	CClone(vector <CTable*> *v_vector);
	~CClone();
	void vRunCommand();
private:
	vector <CTable*> *v_vector;
};
#endif 