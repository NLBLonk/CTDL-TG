#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	SinhVien a[MAX];
	int soMenu = 9, menu,n=0;
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");
	} while (menu > 0);
}