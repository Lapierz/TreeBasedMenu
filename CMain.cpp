#include "pch.h"
#include "CMenu.h"
#include "CVector.h"
#include "CSaveLoad.h"

int main()
{
	CVector* vec = new CVector;
	CMenu menu;
	menu.vInitialize(vec);
	menu.sRun();
	
	//Initializing menu from file(functions won't work) 
	//CSaveLoad c_saveload;
	//c_saveload.vLoad();
	
	return 1;
}
