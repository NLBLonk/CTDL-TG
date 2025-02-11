#include<iostream>
#include<iomanip>
#include<fstream>

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
	int somenu = 13, menu;
	int a[MAX],
		n = 0;
	do
	{
		system("CLS");
		menu = ChonMenu(somenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");
	} while (menu > 0);

}