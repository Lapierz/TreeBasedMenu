
#include"pch.h"
#include "CClone.h"

CClone::CClone(vector <CTable*> *v_vector) {
	this->v_vector = v_vector;
}

CClone::~CClone() {
	delete v_vector;
}

void CClone::vRunCommand() {
	if (v_vector->empty()) {
		cout << S_EMPTY_TAB << endl;
		return;
	}
	else {
		cout << S_WHAT_TAB_INPUT << endl;
		int i_input = iUserInput(0, (int)v_vector->size() - 1);
		CTable *pict_newTab = new CTable(*v_vector->at(i_input));
		v_vector->push_back(pict_newTab);
	}
}