#include "stdafx.h"

#ifndef INV_H
#define INV_H
class Inventory
{
public:
	static Inventory* getInstance();
	String GetInventory();
	void AddItem(String&);
	void Combine(String&,String&);

private:
	Inventory();
	static Inventory* m_instance;
};
#endif