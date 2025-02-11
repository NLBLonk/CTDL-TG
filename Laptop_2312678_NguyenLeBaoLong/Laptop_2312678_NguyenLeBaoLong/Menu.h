void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, sinhvien a[MAX], int& n);

void XuatMenu()
{
	cout << "===================He thong chuc nang=====================";
	cout << "\n0.Thoat chuong chinh";
	cout << "\n1.Tao danh sach sinh tu file";
	cout << "\n2.Xem danh sach sinh vien";
	cout << "\n3. Tim kiem tuyen tinh: xuat tat ca cac sinh vien trung ho, ten cho truoc và co nam sinh < x.";
	cout << "\n4. Tim kiem tuyen tinh linh canh: tra ve chi so dau tien sinh vien co ten cho truoc. ";
	cout << "\n5. Dung thuat giai chon truc tiep sap danh sach tang dan theo nam sinh";
	cout << "\n6. Dung thuat giai Quick sort sap danh sach giam dan theo diem trung binh.";
	cout << "\n7. Tim kiem nhi phan: tra ve chi so cuoi cung sinh vien co nam sinh cho truoc.";
	cout << "\n8. Tim kiem nhi phan: tra ve chi so cuoi cung sinh vien co diem trung binh cho truoc.";
	cout << "\n==========================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\n Vui long chon so [0 ->" << soMenu << "] ="; cin >> stt;
		if (0 <= stt && stt <= soMenu) break;
	}
	return stt;
}

void XuLyMenu(int menu, sinhvien a[MAX], int& n)
{
	int kq; 
	int i, x, nSinh; double dtb;
	char filename[MAX], ho[10], ten[10];
	
	switch (menu)
	{
	case 0:
		cout << "\n0.Thoat chuong chinh"; exit(0);
		break;
	case 1:
		cout << "\n1.Tao danh sach sinh tu file";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = File_MangCT(filename, a, n);
		} while (!kq);
		cout << "\nDanh sach sinh vien vua nhap:\n";
		Xuat_DSSV(a, n);
		break;
	case 2:
		cout << "\2.Xem danh sach sinh vien";
		Xuat_DSSV(a, n);
		break;
	case 3:
		cout << "\n3. Tim kiem tuyen tinh: xuat tat ca cac sinh vien trung ho, ten cho truoc và co nam sinh < x.";
		Xuat_DSSV(a, n); 
		cout << "Nhap ho:"; cin >> ho; 
		cout << "Nhap ten:"; cin >> ten;
		cout << "Nhap nam sinh x de tim kiem co nam sinh < x:"; cin >> x;
		Tim_Ho_Ten_NamSinh(a, n, ho, ten, x);
		break;
	case 4:
		cout << "\n4. Tim kiem tuyen tinh linh canh: tra ve chi so dau tien sinh vien co ten cho truoc. "; 
		Xuat_DSSV(a, n);
		cout << "Nhap ten:"; cin >> ten;
		kq= TimKiem_Ten_CoLinhCanh(a, n, ten); 

		if (kq != -1) {
			cout << "Tim thay sinh vien tai vi tri: " << kq << endl;
			TieuDe();
			Xuat_SV(a[kq]); cout << endl;
		}
		else {
			cout << "Khong tim thay sinh vien nao co ten phu hop." << endl;
		}
		break; 
	case 5:
		cout << "\n5. Dung thuat giai chon truc tiep sap danh sach tang dan theo nam sinh\n";
		cout << "Truoc khi sap xep danh sach:"; Xuat_DSSV(a, n);
		cout << "\nSau khi sap xep danh sach:"; SXNamSinh_ChonTrucTiep(a, n); Xuat_DSSV(a, n);
		break;
	case 6:
		cout << "\n6. Dung thuat giai Quick sort sap danh sach giam dan theo diem trung binh.\n";
		cout << "Truoc khi sap xep danh sach:"; Xuat_DSSV(a, n);
		cout << "\nSau khi sap xep danh sach:"; SXGiam_TheoDTB(a, n); Xuat_DSSV(a, n); break;
	case 7:
		cout << "\n7. Tim kiem nhi phan: tra ve chi so cuoi cung sinh vien co nam sinh cho truoc.";
		Xuat_DSSV(a, n);
		cout << "\nNhap nam sinh can tim:";
		cin >> nSinh;
		kq= TKNP_TheoNamSinh(a, n, nSinh);
		if (kq != -1) {
			cout << "Tim thay sinh vien tai vi tri: " << kq << endl;
		}
		else {
			cout << "Khong tim thay sinh vien nao co ten phu hop." << endl;
		}
		break;
	case 8:
		cout <<"\n8. Tim kiem nhi phan: tra ve chi so cuoi cung sinh vien co diem trung binh cho truoc.";
		Xuat_DSSV(a, n);
		cout << "\nNhap diem trung binh can tim:";
		cin >> dtb;
		/*kq=TKNP_TheoDTB(a, n, dtb);
		if (kq != -1) {
			cout << "Tim thay sinh vien tai vi tri: " << kq << endl;
		}
		else {
			cout << "Khong tim thay sinh vien nao co ten phu hop." << endl;
		}*/
		break;
	}
} 

