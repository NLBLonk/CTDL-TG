#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <conio.h>
using namespace std;

#include"ThuVien.h"

void ChayCT();

int main()
{
	ChayCT();
	return 1;
}

void ChayCT()
{
	LL l;
	BD g;
	//FIXED PROBLEM HERE
	if (TapTin_List_LL((char*)"LLSV.txt", l) && TapTin_List_BD((char*)"DiemQT.txt", g))
		XuatBangDiem(l, g);
	else
		cout << "\nLoi mo tap tin";
	_getch();
}