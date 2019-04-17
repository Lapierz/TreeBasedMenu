#include "pch.h"
#include "CVector.h"

CVector::CVector() {}

CVector::~CVector() {
	int size =(int)v_vector.size();
	for (int i = 0; i < size; i++) {
		CTable* pointer = v_vector.at(i);
		delete pointer;
	}
}

vector<CTable*>* CVector::pi_pointer() {
	 return &v_vector;
}