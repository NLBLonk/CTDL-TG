#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

#include "Thuvien3.h"
#include "Menu3.h"

void ChayCT();

int main()
{
	ChayCT();
	return 1;
}

void ChayCT()
{
	int soMenu = 8, menu;
	int n = 0; int a[MAX];
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");

	} while (menu > 0);
}