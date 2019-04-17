#include "pch.h"
#include "CDeleteAllTab.h"

CDeleteAllTab::CDeleteAllTab(vector <CTable*> *v_vector) {
	this->v_vector = v_vector;
}

CDeleteAllTab::~CDeleteAllTab() {
	delete v_vector;
}

void CDeleteAllTab::vRunCommand() {
	if (!v_vector->empty()) {
		int i_size = v_vector->size();
		for (int i = 0; i < i_size; i++) {
			CTable *pict_temp = v_vector->at(i);
			delete pict_temp;
		}
		v_vector->erase(v_vector->begin(), v_vector->end());
		cout << S_DEL_SUCC << endl;
	}
	else {
		cout << S_DEL_SUCC << endl;
	}
}