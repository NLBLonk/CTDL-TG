void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int a[MAX], int& n);


void XuatMenu()
{
	cout << "===================== He thong chuc nang =======================";
	cout << "\n0.Thoat chuong trinh";
	cout << "\n1.Tao du lieu";
	cout << "\n2.Xem du lieu";
	cout << "\n3.Chon truc tiep (Selection Straight Sort)";
	cout << "\n4.Chen truc tiep (Insertion Straight Sort)";
	cout << "\n5.Doi cho truc tiep (Interchange Straight Sort)";
	cout << "\n6.Noi bot (Bubble Sort)";
	cout << "\n7.Chen nhi phan (Binary Insertion Sort)";
	cout << "\n8.Radix";
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

void XuLyMenu(int menu , int a[MAX], int &n)
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
		cout << "\n1.Tao du lieu";
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
		cout << "\n2.Xem du lieu";
		cout << "\n Mang vua tao: \n";
		Output(a, n); cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3.Chon truc tiep (Selection Straight Sort)";
		cout << "\nTruoc khi sap xep:\n"; Output(a, n);
		cout << "\nSAU khi sap xep:\n";  Selection_L(a, n); Output(a, n); cout << endl;
		break;
	case 4: 
		system("CLS");
		cout << "\n4.Chen truc tiep (Insertion Straight Sort)";
		cout << "\nTruoc khi sap xep:\n"; Output(a, n);
		cout << "\nSAU khi sap xep:\n";  Interchange_L(a, n); Output(a, n); cout << endl;
		break;
	case 5: 
		system("CLS");
		cout << "\n5.Doi cho truc tiep (Interchange Straight Sort)";
		cout << "\nTruoc khi sap xep:\n"; Output(a, n);
		cout << "\nSAU khi sap xep:\n";  Interchange_L(a, n); Output(a, n); cout << endl;
		break;
	case 6:
		system("CLS");
		cout << "\n6.Noi bot (Bubble Sort)";
		cout << "\nTruoc khi sap xep:\n"; Output(a, n);
		cout << "\nSAU khi sap xep:\n";  Bubble_L(a, n); Output(a, n); cout << endl;
		break;
	case 7:
		system("CLS");
		cout << "\n7.Chen nhi phan (Binary Insertion Sort)";
		cout << "\nTruoc khi sap xep:\n"; Output(a, n);
		cout << "\nSAU khi sap xep:\n";  Binary_Insertion(a, n); Output(a, n); cout << endl;
		break;
	case 8:
		system("CLS");
		cout << "\n8.Radix";
		cout << "\nTruoc khi sap xep:\n"; Output(a, n);
		cout << "\nSAU khi sap xep:\n";   Radix(a, n); Output(a, n); cout << endl;
		break;
	}
}