#pragma once
#ifndef CVector_h
#define CVector_h

#include <vector>
#include "CTable.h"

class CVector
{
public:
	CVector();
	~CVector();
	vector<CTable*>* pi_pointer();
private:
	vector <CTable*> v_vector;
};
#endif 