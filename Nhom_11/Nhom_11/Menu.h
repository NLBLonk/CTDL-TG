void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, BSTDungCu& root, BSTCustomer& root2);

void XuatMenu()
{
	cout << "\t \t~~~~~~~~~~~~~~~~~~~~~~~~~~~~ HE THONG CHUC NANG ~~~~~~~~~~~~~~~~~~~~~~~~~~~~"; cout << endl;
	cout << "\n==================== NHAP XUAT =======================";
	cout << "\n 0.Thoat chuong trinh"; 
	cout << "\n 1.Nhap du lieu DO DUNG CU THE THAO tu file (Tao cay)";
	cout << "\n 2.Xuat thong tin DO DUNG CU THE THAO";
	cout << "\n 3.Nhap du lieu KHACH HANG tu file (Tao cay)";
	cout << "\n 4.Xuat thong tin KHACH HANG";
	cout << "\n======================================================\n";

	cout << "\n============TIM KIEM, THEM, CHINH SUA & XOA===========";
	cout << "\n 5. Them DO DUNG CU THE THAO vao danh sach";
	cout << "\n 6. Them KHACH HANG vao danh sach";
	cout << "\n 7. Tim DO DUNG CU THE THAO theo MA DUNG CU";
	cout << "\n 8. Tim DO DUNG CU THE THAO theo THE LOAI";
	cout << "\n 9. Tim kiem thong tin KHACH HANG theo MA KHACH HANG";
	cout << "\n 10.Tim kiem thong tin KHACH HANG theo SDT";
	cout << "\n 11.Chinh sua DON GIA cua DUNG CU";
	cout << "\n 12.Chinh sua TEN KHACH HANG";
	cout << "\n 13.Xoa thong tin DO DUNG CU THE THAO theo MA DUNG CU";
	cout << "\n 14.Xoa thong tin KHACH HANG theo MA KHACH HANG";
	cout << "\n======================================================\n";

	cout << "\n \t====================TAO HOA DON=========================";
	cout << "\n \t|	15.Tao hoa don khach hang mua hang             |";
	cout << "\n \t========================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\n Vui long chon menu [0 -> " << soMenu << "], stt= ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, BSTDungCu& root, BSTCustomer& root2)
{
	char theLoai[30], hoten[30], sdt[11];
	char* filename;
	int kq, dongia;
	KeyType x, maDC;
	KeyTypeKH maKH;
	BSTDungCu p; 
	BSTCustomer cus;
	dungcu themdc;
	KhachHang themkh;
	switch (menu)
	{
	case 1:
		cout << "\n1.NHAP DU LIEU DO DUNG CU THE THAO TU FILE (TAO CAY) ";
		filename = new char[50];
		do
		{
			cout << "\nfilename = ";
			cin >> filename;
			kq = FileBST_DCu(root, filename);
		} while (kq == 0);
		cout << "Da chuyen du lieu tap tin " << filename << " vao cay BST thanh cong";
		cout << endl;
		delete[]filename;
		break;
	case 2:
		system("cls");
		cout << "\t \t~~~~~~~~~~~~~~~~~~~2.XUAT THONG TIN DO DUNG CU THE THAO~~~~~~~~~~~~~~~~~~~\n";
		cout << "\nCay BST hien hanh, xuat theo thu tu truoc(NLR): \n";
		TieuDe();
		PreOrder(root);
		KeNgang();
		//system("PAUSE"); cout << endl;

		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR): \n";
		TieuDe();
		InOrder(root);
		KeNgang();
		//system("PAUSE"); cout << endl;

		cout << "\n\nCay BST hien hanh, xuat theo thu tu cuoi (LRN): \n";
		TieuDe();
		PosOrder(root);
		KeNgang();
		cout << endl;
		break;
	case 3:
		cout << "\n3.NHAP DU LIEU KHACH HANG TU FILE (TAO CAY) ";
		filename = new char[50];
		do
		{
			cout << "\nfilename = ";
			cin >> filename;
			kq = FileBST_KH(root2, filename);
		} while (kq == 0);
		cout << "Da chuyen du lieu tap tin " << filename << " vao cay BST thanh cong";
		cout << endl;
		delete[]filename;
		break;
	case 4:
		system("cls");
		cout << "\t \t~~~~~~~~~~~~~~~~~~~4.XUAT THONG TIN KHACH HANG~~~~~~~~~~~~~~~~~~~\n";
		cout << "\ncay BST hien hanh, xuat theo thu tu truoc(NLR): \n";
		TieuDe_KH();
		PreOrder_KH(root2);
		KeNgang();
		//system("PAUSE"); cout << endl;

		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR): \n";
		TieuDe_KH();
		InOrder_KH(root2);
		KeNgang();
		//system("PAUSE"); cout << endl;

		cout << "\n\nCay BST hien hanh, xuat theo thu tu cuoi (LRN): \n";
		TieuDe_KH();
		PosOrder_KH(root2);
		KeNgang();
		cout << endl;
		break;
	case 5:
		system("cls");
		cout << "\n~~~~~~~~~~~~~~~~~~~5.THEM DUNG CU DANH SACH VAO DANH SACH~~~~~~~~~~~~~~~~~~~\n";
		cout << "\nDanh sach truoc khi chen them, xuat theo thu tu giua (LNR): \n";
		TieuDe();
		InOrder(root);
		KeNgang(); cout << endl;
		cout << "Hay nhap ma dung cu: "; cin >> themdc.maDC; 
		cout << "Nhap ten dung cu: "; cin >> themdc.tenDC;
		cout << "Nhap the loai dung cu:"; cin >> themdc.theLoai;
		cout << "Nhap so luong: "; cin >> themdc.soLuong;
		cout << "Nhap don gia: "; cin >> themdc.donGia;
		kq = InsertNode(root, themdc);
		cout << "\nDanh sach sau khi chen them, xuat theo thu tu giua (LNR): \n";
		TieuDe();
		InOrder(root);
		KeNgang();
		break;
	case 6:
		system("cls");
		cout << "\n~~~~~~~~~~~~~~~~~~~6.THEM KHACH HANG VAO DANH SACH~~~~~~~~~~~~~~~~~~~\n";
		cout << "\nDanh sach truoc khi chen them, xuat theo thu tu giua (LNR): \n";
		TieuDe_KH();
		InOrder_KH(root2);
		KeNgang(); cout << endl;
		cout << "Hay nhap ma khach hang: "; cin >> themkh.maKH;
		cout << "Nhap ten khach hang: "; cin >> themkh.hoTen;
		cout << "Nhap dia chi khach hang: "; cin >> themkh.diaChi;
		cout << "Nhap sdt: "; cin >> themkh.sdt;
		cout << "Nhap ngay: "; cin >> themkh.ngayMua.ngay;
		cout << "Nhap thang: "; cin >> themkh.ngayMua.thang;
		cout << "Nhap nam: "; cin >> themkh.ngayMua.nam;
		kq = InsertNode_KH(root2, themkh);
		cout << "\nDanh sach sau khi chen them, xuat theo thu tu giua (LNR): \n";
		TieuDe_KH();
		InOrder_KH(root2);
		KeNgang();
		break;
	case 7:
		system("cls");
		cout << "\n~~~~~~~~~~~~~~~~~~~7.TIM DO DUNG CU THE THAO THEO MA DUNG CU~~~~~~~~~~~~~~~~~~~\n"; 
		cout << "\nCay BST hien hanh theo thu tu LNR: \n";
		TieuDe();
		InOrder(root);
		KeNgang();

		cout << "\nNhap ma dung cu the thao \nmaDC="; cin >> x;
		p = SearchByID(root, x);
		if (p == NULL)
			cout << "\nKhong tim thay thong tin dung cu the thao co ma " << x;
		else
		{
			cout << "\nThong tin dung cu the thao co ma " << x << ":\n";
			TieuDe();
			Xuat_DC(p->info);
			KeNgang();
		}
		break;
	case 8:
		system("cls");
		cout << "\n~~~~~~~~~~~~~~~~~~~8.TIM DO DUNG CU THE THAO THEO THE LOAI~~~~~~~~~~~~~~~~~~~";
		cout << "\nCay BST hien hanh theo thu tu LNR: \n";
		TieuDe();
		InOrder(root);
		KeNgang();

		cout << "\nNhap the loai can tim: "; cin >> theLoai;
		cout << "\nThong tin dung cu the thao co the loai " << theLoai << ":\n";
		TieuDe();
		SearchByCategory(root, theLoai);
		KeNgang();
		break;
	case 9:
		system("cls");
		cout << "\n~~~~~~~~~~~~~~~~~~~9.TIM KIEM THONG TIN KHACH HANG THEO MA KHACH HANG~~~~~~~~~~~~~~~~~~~\n";
		cout << "\nCay BST hien hanh theo thu tu LNR: \n";
		TieuDe_KH();
		InOrder_KH(root2);
		KeNgang();
		cout << "\nNhap ma khach hang can tim: "; cin >> maKH;
		cus = SearchByCustomerID(root2, maKH);
		if (cus == NULL)
			cout << "\nKhong tim thay thong tin khach hang co ma " << maKH;
		else
		{
			cout << "\nThong tin khach hang ten co ma " << maKH << ":\n";
			TieuDe_KH();
			Xuat_KH(cus->info);
			KeNgang();
		}
		break;
	case 10:
		system("cls");
		cout << "\n~~~~~~~~~~~~~~~~~~~10.TIM KIEM THONG TIN KHACH HANG THEO SDT~~~~~~~~~~~~~~~~~~~\n";
		cout << "\nCay BST hien hanh theo thu tu LNR: \n";
		TieuDe_KH();
		InOrder_KH(root2);
		KeNgang();
		cout << "\nNhap sdt khach hang can tim: "; cin >> sdt;
		cus = SearchByPhone(root2, sdt);
		if (cus == NULL)
			cout << "\nKhong tim thay thong tin khach hang co sdt " << sdt;
		else
		{
			cout << "\nThong tin khach hang ten co sdt " << sdt << ":\n";
			TieuDe_KH();
			Xuat_KH(cus->info);
			KeNgang();
		}
		break;
	case 11:
		system("cls");
		cout << "\n~~~~~~~~~~~~~~~~~~~11.CHINH SUA DON GIA CUA DUNG CU~~~~~~~~~~~~~~~~~~~\n";
		cout << "\nCay BST hien hanh theo thu tu LNR: \n";
		TieuDe();
		InOrder(root);
		KeNgang();

		cout << "\nNhap ma dung cu can tim:\nmaDC= ";
		cin >> x;
		p = SearchByID(root, x);
		if (p == NULL)
			cout << "\nKhong tim thay thong tin dung cu the thao co ma" << x;
		else
		{
			cout << "\nThong tin dung cu co ma " << x << " :\n";
			TieuDe();
			Xuat_DC(p->info);
			KeNgang();

			cout << "\n\nNhap DON GIA MOI cua dung cu, dongia = ";
			cin >> dongia;
			p->info.donGia = dongia;
			cout << "\nThong tin dung cu co ma " << x << " :\n";
			TieuDe();
			Xuat_DC(p->info);
			KeNgang();
		}
		break;
	case 12:
		system("cls");
		cout << "\n~~~~~~~~~~~~~~~~~~~12.CHINH SUA TEN KHACH HANG~~~~~~~~~~~~~~~~~~~\n";
		cout << "\nCay BST hien hanh theo thu tu LNR: \n";
		TieuDe_KH();
		InOrder_KH(root2);
		KeNgang();
		cout << "\nNhap ma khach hang can tim:\n maKH= ";
		cin >> maKH;
		cus = SearchByCustomerID(root2, maKH);
		if (cus == NULL)
			cout << "\nKhong tim thay thong tin dung cu the thao co ma" << maKH;
		else
		{
			cout << "\nThong tin dung cu co ma " << maKH << " :\n";
			TieuDe_KH();
			Xuat_KH(cus->info);
			KeNgang();

			cout << "\n\nNhap ten khach hang can chinh sua: ";
			cin >> hoten;
			strcpy_s(cus->info.hoTen ,hoten);
			cout << "\nThong tin khach hang co ten  " << hoten << " ma " << maKH << ":\n";
			TieuDe_KH();
			Xuat_KH(cus->info);
			KeNgang();
		}
		break;
	case 13:
		system("cls");
		cout << "\n~~~~~~~~~~~~~~~~~~~13.XOA THONG TIN KHACH HANG THEO MA DUNG CU~~~~~~~~~~~~~~~~~~~\n";
		cout << "\nCay BST hien hanh theo thu tu LNR: \n";
		TieuDe();
		InOrder(root);
		KeNgang();
		if (root == NULL)
			cout << "\nBST rong!";
		else
		{
			cout << "\n\nNhap ma dung cu can xoa : "; cin >> maDC;
			kq = DeleteNode(root, maDC);
			if (kq)
			{
				cout << "\nDa xoa thanh cong";
				cout << "\nDanh sach moi theo thu tu giua (LNR):\n\n";
				TieuDe();
				PreOrder(root);
				KeNgang();
			}
			else cout << "\nKhong tim thay ma dung cu co ma la " << maDC;
		}
		break;
	case 14:
		system("cls");
		cout << "\n~~~~~~~~~~~~~~~~~~~14.XOA THONG TIN KHACH HANG THEO MA KHACH HANG~~~~~~~~~~~~~~~~~~~\n";
		cout << "\nCay BST hien hanh theo thu tu LNR: \n";
		TieuDe_KH();
		InOrder_KH(root2);
		KeNgang();
		if (root == NULL)
			cout << "\nBST rong!";
		else
		{
			cout << "\n\nNhap ma dung cu can xoa : "; cin >> maKH;
			kq = DeleteNode_KH(root2, maKH);
			if (kq)
			{
				cout << "\nDa xoa thanh cong";
				cout << "\nDanh sach moi theo thu tu giua (LNR):\n\n";
				TieuDe_KH();
				PreOrder_KH(root2);
				KeNgang();
			}
			else cout << "\nKhong tim thay ma khach hang co ma la " << maKH;
		}
		break;
	case 15:
		system("cls");
		cout << "\n~~~~~~~~~~~~~~~~~~~15.TAO HOA DON KHACH HANG MUA HANG~~~~~~~~~~~~~~~~~~~\n";
		int soHoaDon;
		cout << "\nDanh sach dung cu the thao:";
		TieuDe();
		InOrder(root);
		KeNgang();
		cout << "\nDanh sach khach hang:";
		TieuDe_KH();
		InOrder_KH(root2);
		KeNgang();
		cout << "\nNhap so hoa don: ";
		cin >> soHoaDon;
		XuLyHD(root2, root, soHoaDon);
		break;
	case 0:
		cout << "\n0.Thoat chuong trinh!"; 
		cout << "\n \tHAVE A NICE DAY!\n";
		exit(0);
		break;
	}
	_getch();
}
