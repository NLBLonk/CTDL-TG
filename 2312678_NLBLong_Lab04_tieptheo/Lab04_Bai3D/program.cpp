#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

#include"thuvien.h"
#include"menu.h"

void ChayCT();

int main()
{
	ChayCT();
	return 1;
}

void ChayCT()
{
	int soMenu = 6,
		menu;
	LIST l;
	int	n = 0;
	do
	{
		system("CLS");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, l);
		system("PAUSE");
	} while (menu >= 0);
}