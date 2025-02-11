BSTDungCu SearchByID(BSTDungCu root, KeyType x);
dungcu DeleteMin_DC(BSTDungCu& root);
int DeleteNode(BSTDungCu& root, KeyType maDC);
void SearchByCategory(BSTDungCu root, char theLoai[30]);
//===========================================================
KhachHang DeleteMin_KH(BSTCustomer& root2);
int DeleteNode_KH(BSTCustomer& root2, KeyType maKH);
//===========================================================
BSTCustomer SearchByCustomerID(BSTCustomer root2, KeyTypeKH maKH);
BSTCustomer SearchByCustomerName(BSTCustomer root2, char hoTen[30]);
BSTCustomer SearchByPhone(BSTCustomer root2, char sdt[11]);


//Tim dung cu the thao khi biet ma dung cu
BSTDungCu SearchByID(BSTDungCu root, KeyType x)
{
	if (root != NULL)
	{
		if (strcmp(root->info.maDC, x) == 0)
			return root;
		else
			if (strcmp(root->info.maDC, x) < 0)
				return SearchByID(root->right, x);
			else
				return SearchByID(root->left, x);
	}
	return NULL;
}
//Tim dung cu the thao theo ten
BSTDungCu SearchByName(BSTDungCu root, char tenDC[30])
{
	if (root != NULL)
	{
		if (strcmp(root->info.tenDC, tenDC) == 0)
			return root;
		BSTDungCu found = SearchByName(root->left, tenDC);
		if (found != NULL) return found;
		return SearchByName(root->right, tenDC);
	}
	return NULL;
}
//Tim dung cu the thao khi biet the loai
void SearchByCategory(BSTDungCu root, char theLoai[30]) {
	if (root == NULL) {
		return;  
	}

	//Kiem tra neu the loai cua node hien tai khop voi the loai tim kiem
	if (strcmp(root->info.theLoai, theLoai) == 0) {
		Xuat_DC(root->info);
	}

	//Duyet cay con trai va phai de tim cac dung cu khac cung the loai
	SearchByCategory(root->left, theLoai);
	SearchByCategory(root->right, theLoai);
}


//Tim kiem thong tin khach hang theo ma khach hang
BSTCustomer SearchByCustomerID(BSTCustomer root2, KeyTypeKH maKH)
{
	if (root2 != NULL)
	{
		if (strcmp(root2->info.maKH, maKH) == 0)
			return root2;
		else
			if (strcmp(root2->info.maKH, maKH) < 0)
				return SearchByCustomerID(root2->right, maKH);
			else
				return SearchByCustomerID(root2->left, maKH);
	}
	return NULL;
}
//Tim kiem thong tin theo ten khach hang
BSTCustomer SearchByCustomerName(BSTCustomer root2, char hoTen[30])
{
	if (root2 != NULL)
	{
		if (strcmp(root2->info.hoTen, hoTen) == 0)
			return root2;
		BSTCustomer found = SearchByCustomerName(root2->left, hoTen);
		if (found != NULL) return found;
		return SearchByCustomerName(root2->right, hoTen);
	}
	return NULL;
}
//Tim kiem thong tin theo so dien thoai
BSTCustomer SearchByPhone(BSTCustomer root2, char sdt[11])
{
	if (root2 != NULL)
	{
		if (strcmp(root2->info.sdt, sdt) == 0)  
			return root2;
		BSTCustomer found = SearchByPhone(root2->left, sdt);  
		if (found != NULL) return found;
		return SearchByPhone(root2->right, sdt);  
	}
	return NULL;
}

//Ham xoa nut nho nhat (nam ngoài cùng bên trái) tai vi tri root va thay the bang nut ben phai
dungcu DeleteMin_DC(BSTDungCu& root)
{
	if (root->left == NULL)
	{
		dungcu x = root->info;
		root = root->right;
		return x;
	}
	else return DeleteMin_DC(root->left);
}
//Ham xoa thong tin dung cu the thao theo ma dung cu
int DeleteNode(BSTDungCu& root, KeyType maDC)
{
	if (root != NULL)
	{
		if (_strcmpi(root->info.maDC, maDC) == 0)
		{
			if (root->left == NULL && root->right == NULL)
				root = NULL;
			else if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;
			else root->info = DeleteMin_DC(root->right);
			return 1;
		}
		else if (_strcmpi(root->info.maDC, maDC) > 0)
			return DeleteNode(root->left, maDC);
		else return DeleteNode(root->right, maDC);
	}
	return 0;
}

KhachHang DeleteMin_KH(BSTCustomer& root2)
{
	if (root2->left == NULL)
	{
		KhachHang x = root2->info;
		root2 = root2->right;
		return x;
	}
	else return DeleteMin_KH(root2->left);
}
//Ham xoa thong tin khach hang theo ma khach hang
int DeleteNode_KH(BSTCustomer& root2, KeyType maKH)
{
	if (root2 != NULL)
	{
		if (_strcmpi(root2->info.maKH, maKH) == 0)
		{
			if (root2->left == NULL && root2->right == NULL)
				root2 = NULL;
			else if (root2->left == NULL)
				root2 = root2->right;
			else if (root2->right == NULL)
				root2 = root2->left;
			else root2->info = DeleteMin_KH(root2->right);
			return 1;
		}
		else if (_strcmpi(root2->info.maKH, maKH) > 0)
			return DeleteNode_KH(root2->left, maKH);
		else return DeleteNode_KH(root2->right, maKH);
	}
	return 0;
}

//Nhap thong thong tin khach hang
void NhapKhachHang(HoaDon& hoaDon, BSTCustomer rootKH) 
{
	cout << "Nhap ten khach hang: ";
	cin.ignore();
	cin.getline(hoaDon.tenKH, 20);

	// Tim khach hang trong BST
	BSTCustomer khNode = SearchByCustomerName(rootKH, hoaDon.tenKH);
	if (khNode == NULL) {
		cout << "Khong tim thay khach hang voi ten: " << hoaDon.tenKH << ". Hoa don se duoc tao voi thong tin da nhap.\n";
	}
}

// Nhap thong tin san pham
void NhapSanPham(HoaDon& hoaDon, BSTDungCu rootDC) 
{
	hoaDon.tongTien = 0;

	for (int j = 0; j < hoaDon.soSP; j++) {
		cout << "\nNhap thong tin san pham thu " << j + 1 << ":\n";

		cout << "Nhap ten dung cu: ";
		cin.ignore();
		cin.getline(hoaDon.sanPham[j].tenDC, 30);

		// Tim dung cu trong BST
		BSTDungCu dcNode = SearchByName(rootDC, hoaDon.sanPham[j].tenDC);
		if (dcNode == NULL) {
			cout << "Khong tim thay dung cu voi ten: " << hoaDon.sanPham[j].tenDC << ". Bo qua san pham nay.\n";
			hoaDon.sanPham[j].soLuong = 0;
			hoaDon.sanPham[j].donGia = 0;
			continue;
		}

		cout << "Nhap so luong: ";
		cin >> hoaDon.sanPham[j].soLuong;

		hoaDon.sanPham[j].donGia = dcNode->info.donGia;

		// Tinh tong tien san pham
		int thanhTien = hoaDon.sanPham[j].soLuong * hoaDon.sanPham[j].donGia;
		hoaDon.tongTien += thanhTien;
	}
}

// Xuat hoa don
void XuatHoaDon(HoaDon& hoaDon, BSTCustomer rootKH) 
{
	cout << "\n=============================================================================";
	cout << "\n \t \t \tHOA DON\n";
	cout << "Ten khach hang:  " << hoaDon.tenKH << "\n";
	BSTCustomer khNode = SearchByCustomerName(rootKH, hoaDon.tenKH);
	if (khNode != NULL) {
		cout << "Dia chi: \t" << khNode->info.diaChi << "\n";
		cout << "So dien thoai: \t" << khNode->info.sdt << "\n";
	}
	else {
		cout << "Dia chi: Khong co thong tin\n";
		cout << "So dien thoai: Khong co thong tin\n";
	}

	cout << setw(25)<<"\nTen dung cu" << setw(20) << "So luong" << setw(20) << "Don Gia" << setw(20) << "Thanh tien";
	cout << "\n-----------------------------------------------------------------------------";

	for (int j = 0; j < hoaDon.soSP; j++) {
		cout << "\n"
			<< setw(25) << left << hoaDon.sanPham[j].tenDC
			<< setw(20) << left << hoaDon.sanPham[j].soLuong
			<< setw(20) << left << hoaDon.sanPham[j].donGia
			<< setw(20) << left << hoaDon.sanPham[j].soLuong * hoaDon.sanPham[j].donGia;
	}
	cout << "\n-----------------------------------------------------------------------------";
	cout << "\nTong tien: \t" << hoaDon.tongTien;
	cout << "\n-----------------------------------------------------------------------------";
}

// Ham xu ly hoa don
void XuLyHD(BSTCustomer rootKH, BSTDungCu rootDC, int soHoaDon) 
{
	HoaDon dsHoaDon[100]; // Danh sach hoa don

	for (int i = 0; i < soHoaDon; i++) {
		cout << "\nNhap thong tin hoa don thu " << i + 1 << ":\n";

		// Nhap thong tin hoa don
		NhapKhachHang(dsHoaDon[i], rootKH);

		// Nhap so dung cu khach hang mua
		cout << "Nhap so dung cu mua: ";
		cin >> dsHoaDon[i].soSP;

		// Nhap thong tin san pham
		NhapSanPham(dsHoaDon[i], rootDC);
	}

	// Xuat hoa don
	for (int i = 0; i < soHoaDon; i++) {
		XuatHoaDon(dsHoaDon[i], rootKH);
	}
}
