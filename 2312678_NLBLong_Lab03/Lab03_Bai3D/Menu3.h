void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int a[MAX], int& n);

void XuatMenu()
{
	cout << "==========================He thong chuc nang===============================";
	cout << "\n0.Thoat chuong trinh";
	cout << "\n1.Tao du lieu mang";
	cout << "\n2.Xem du lieu mang\n";
	cout << "==========================Danh sach thuat toan=============================";
	cout << "\n \t \t SAP XEP DAY TANG DAN DAY SO NGUYEN";
	cout << "\n \t3.Chon truc tiep (Selection Straight sort)";
	cout << "\n \t4.Thuat giai chon 2 dau";
	cout << "\n \t5.Chen truc tiep (Insertion Straight sort)";
	cout << "\n \t6.Doi cho truc tiep (Interchange Straight sort)";
	cout << "\n \t7.Noi bot (Bubble sort)";
	cout << "\n \t8.Thuat giai Shaker sort (Cai tien bubble)";
	cout << "\n===========================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\n Vui long nhap so [0 -> " << soMenu << "] :"; cin >> stt;
		if (0 <= stt && stt <= soMenu) break;
	}
	return stt;
}


void XuLyMenu(int menu, int a[MAX], int& n)
{
	int kq; char filename[MAX];
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0.Thoat chuong trinh";
		break;
	case 1:
		system("CLS");
		cout << "\n1.Tao danh sach sinh vien";
		do
		{
			cout << "\n1.Nhap ten tap tin,filename = "; cin >> filename;
			kq = File_Array(filename, a, n);
		} while (!kq);
		cout << "\n Mang vua tao: \n";
		Output(a, n); cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2.Xem danh sach sinh vien";
		cout << "\n Mang vua tao: \n";
		Output(a, n); cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\t \t SAP XEP DAY TANG DAN DAY SO NGUYEN - Chon truc tiep (Selection Straight sort)\n";
		cout << "Truoc khi sap xep: \n"; Output(a, n); cout << endl;
		cout << "Sau khi sap xep: \n"; Selection_R(a, n); Output(a, n);
		break;
	case 4:
		system("CLS");
		cout << "\t \t SAP XEP DAY TANG DAN DAY SO NGUYEN - Thuat giai chon 2 dau\n";
		cout << "Truoc khi sap xep: \n"; Output(a, n); cout << endl;
		cout << "Sau khi sap xep: \n"; Selection_R_L(a, n); Output(a, n);
		break;
	case 5:
		system("CLS");
		cout << "\t \t SAP XEP DAY TANG DAN DAY SO NGUYEN - Chen truc tiep (Insertion Straight sort)\n";
		cout << "Truoc khi sap xep: \n"; Output(a, n); cout << endl;
		cout << "Sau khi sap xep: \n"; Insertion_R(a, n); Output(a, n);
		break;
	case 6:
		system("CLS");
		cout << "\t \t SAP XEP DAY TANG DAN DAY SO NGUYEN - Doi cho truc tiep (Interchange Straight sort)\n";
		cout << "Truoc khi sap xep: \n"; Output(a, n); cout << endl;
		cout << "Sau khi sap xep: \n"; Interchange_R(a, n); Output(a, n);
		break;
	case 7:
		system("CLS");
		cout << "\t \t SAP XEP DAY TANG DAN DAY SO NGUYEN - Noi bot (Bubble sort)\n";
		cout << "Truoc khi sap xep: \n"; Output(a, n); cout << endl;
		cout << "Sau khi sap xep: \n"; Bubble_R(a, n); Output(a, n);
		break;
	case 8:
		system("CLS");
		cout << "\t \t SAP XEP DAY TANG DAN DAY SO NGUYEN - Thuat giai Shaker sort (Cai tien bubble)\n";
		cout << "Truoc khi sap xep: \n"; Output(a, n); cout << endl;
		cout << "Sau khi sap xep: \n"; Shaker(a, n); Output(a, n);
		break;
	}
}
