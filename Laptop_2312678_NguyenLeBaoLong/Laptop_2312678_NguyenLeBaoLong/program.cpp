#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
using namespace std;

#include"Thuvien.h"
#include"Menu.h"


void ChayCT();

int main()
{
	ChayCT();
	return 1;
}

void ChayCT()
{
	int soMenu = 10, menu, n = 0;
	sinhvien a[MAX];
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");
	} while (menu > 0);
}