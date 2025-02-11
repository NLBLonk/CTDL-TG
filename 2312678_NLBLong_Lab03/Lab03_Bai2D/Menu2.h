void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, sinhvien a[MAX], int& n);

void XuatMenu()
{
	cout << "==========================He thong chuc nang===============================";
	cout << "\n0.Thoat chuong trinh";
	cout << "\n1.Tao danh sach sinh vien";
	cout << "\n2.Xem danh sach sinh vien";
	cout << "\n===========================================================================";
	cout << "\nSap xep danh sach sinh vien TANG DAN theo 'DIEM TRUNG BINH' voi cac thuat giai nhu sau:";
	cout << "\n \t3.Quick Sort";
	cout << "\n \t4.Heap Sort";
	cout << "\n \t5.Merge Sort \n";
	cout << "===========================================================================";
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


void XuLyMenu(int menu, sinhvien a[MAX], int& n)
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
		cout << "\n Danh sach sinh vien: \n";
		Output_Arr(a,n); cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2.Xem danh sach sinh vien";
		cout << "\n Danh sach sinh vien vua tao: \n";
		Output_Arr(a, n); cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\nSap xep danh sach sinh vien TANG DAN theo 'DIEM TRUNG BINH' voi thuat giai - QUICK SORT\n";
		cout << "\n Truoc khi sap xep:"; Output_Arr(a, n);
		cout << "\n Sau khi sap xep:"; QuickSort(a, n); Output_Arr(a, n);
		break;
	case 4:
		system("CLS");
		cout << "\nSap xep danh sach sinh vien TANG DAN theo 'DIEM TRUNG BINH' voi thuat giai - HEAP SORT\n";
		cout << "\n Truoc khi sap xep:"; Output_Arr(a, n);
		cout << "\n Sau khi sap xep:"; HeapSort(a, n); Output_Arr(a, n);
		break;
	case 5:
		system("CLS");
		cout << "\nSap xep danh sach sinh vien TANG DAN theo 'DIEM TRUNG BINH' voi thuat giai - MERGE SORT\n";
		cout << "\n Truoc khi sap xep:"; Output_Arr(a, n);
		cout << "\n Sau khi sap xep:"; MergeSort(a, n); Output_Arr(a, n);

		break;
	}
}