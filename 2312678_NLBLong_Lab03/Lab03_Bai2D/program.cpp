#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

#include "Thuvien2.h"
#include "Menu2.h"

void ChayCT();

int main()
{
	ChayCT();
	return 1;
}

void ChayCT()
{
	int soMenu = 5, menu;
	int n = 0; sinhvien a[MAX];
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");

	} while (menu > 0);
}