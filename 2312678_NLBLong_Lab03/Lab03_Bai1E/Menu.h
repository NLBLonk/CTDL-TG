void XuatMenu();
int ChonMenu(int);
void XuLyMenu(int menu, int a[MAX], int& n);


void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu ";
	cout << "\n2. Xem du lieu ";
	cout << "\n3. Thuat giai Chon Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n4. Thuat giai Chon Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n5. Thuat giai Chon hai dau";
	cout << "\n6. Thuat giai Chen Truc tiep - chen vao day con tang ben trai";
	cout << "\n7. Thuat giai Chen Truc tiep - chen vao day con tang ben phai";
	cout << "\n8. Thuat giai Chen nhi phan";
	cout << "\n9. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n10.Thuat giai Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n11.Thuat giai Buble - tai moi buoc dua GTNN ve dau mang";
	cout << "\n12.Thuat giai Buble - tai moi buoc dua GTLN ve cuoi mang";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS"); 
		XuatMenu();
		cout << "\nNhap mot so (0 <= so <= " << soMenu << " ) de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, int a[MAX], int& n)
{
	int kq;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao du lieu";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TapTin_mang1c(filename, a, n);
		} while (!kq);
		cout << "\nMang vua tao:\n";
		Xuat_Mang(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat du lieu";
		cout << "\nMang vua tao:\n";
		Xuat_Mang(a, n);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Chon truc tiep (Selection Straight sort)";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		Selection_L(a, n);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Chon truc tiep (Selection Straight sort)";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		Selection_R(a, n);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Thuat giai chon 2 dau : Selection_R_L(a,n)";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		Selection_R_L(a, n);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Chen truc tiep (Insertion Straight sort)";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		Insertion_L(a, n);
		break;
	case 7:
		system("CLS");
		cout << "\7. Chen truc tiep (Insertion Straight sort)";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		Insertion_R(a, n);
		break;
	case 8:
		system("CLS");
		cout << "\n8. Chen nhi phan (Binary Insertion Sort)";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		Binary_Insertion(a, n);
		break;
	case 9:
		system("CLS");
		cout << "\n9. Doi cho truc tiep (Interchange Straight sort)";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		Interchange_L(a, n);
		break;
	case 10:
		system("CLS");
		cout << "\n10. Doi cho truc tiep (Interchange Straight sort)";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		Interchange_R(a, n);
		break;
	case 11:
		system("CLS");
		cout << "\n11. Noi bot (Bubble sort)";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		Bubble_L(a, n);
		break;
	case 12:
		system("CLS");
		cout << "\n12. Noi bot (Bubble sort)";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		Bubble_R(a, n);
	}
}
