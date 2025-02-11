#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

#include"ThuVien.h"
#include"Menu.h"

void ChayCT();

int main()
{
	ChayCT();
	return 1;
}

void ChayCT()
{
	LIST danhSach;

	int soMenu = 18,
		menu;
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, danhSach);
		system("PAUSE");
	} while (menu > 0);
}