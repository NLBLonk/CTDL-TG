#define MAXCOT 100
typedef char KeyType[10];
typedef char KeyTypeKH[8];

struct dungcu
{
	KeyType maDC;
	char tenDC[30];
	char theLoai[30];
	int soLuong;
	int donGia;

};

struct BSNode
{
	dungcu info;
	BSNode* left;
	BSNode* right;
};

struct nts
{
	unsigned ngay;
	unsigned thang;
	unsigned nam;
};

struct KhachHang
{
	KeyTypeKH maKH;
	char hoTen[20];
	char diaChi[30];
	char sdt[11];
	nts ngayMua;
};

struct BSNodeKH
{
	KhachHang info;
	BSNodeKH* left;
	BSNodeKH* right;
};

struct HoaDon
{
	char tenKH[20];  // Tên khách hàng
	struct SanPham
	{
		char tenDC[30]; // Tên d?ng c?
		int soLuong;    // S? l??ng
		int donGia;     // ??n giá
	} sanPham[100];     // Danh sách s?n ph?m
	int soSP;           // S? l??ng s?n ph?m
	int tongTien;       // T?ng ti?n hóa ??n
};


//Cay nhi phan tim kiem
typedef BSNode* BSTDungCu;
typedef BSNodeKH* BSTCustomer;

//Khai bao nguyen mau
//***********************DUNG CU**************************
BSNode* CreateNode(dungcu x);
void CreateBST(BSTDungCu& root);
int InsertNode(BSTDungCu& root, dungcu x);
int FileBST_DCu(BSTDungCu& root, char* filename);
void TieuDe();
void KeNgang();
void Xuat_DC(dungcu p);
//===============================
void PreOrder(BSTDungCu root);
void InOrder(BSTDungCu root);
void PosOrder(BSTDungCu root);
//===============================
//***********************KHACH HANG**************************
BSNodeKH* CreateNodeKH(KhachHang kh);
void CreateBST_KH(BSTCustomer& root2);
int InsertNode_KH(BSTCustomer& root2, KhachHang kh);
int FileBST_KH(BSTCustomer& root2, char* filename2);
void Xuat_KH(KhachHang kh);
//===================================
void PreOrder_KH(BSTCustomer root2);
void InOrder_KH(BSTCustomer root2);
void PosOrder_KH(BSTCustomer root2);


//Tao nut voi x cho truoc
BSNode* CreateNode(dungcu x)
{
	BSNode* p = new BSNode;
	if (p != NULL)
	{
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

//Khoi tao vao cay BST rong 
void CreateBST(BSTDungCu& root)
{
	root = NULL;
}

//Them x vao cay BST
int InsertNode(BSTDungCu& root, dungcu x)
{
	if (root != NULL)
	{
		if (strcmp(root->info.maDC, x.maDC) == 0)

			return 0;
		if (strcmp(root->info.maDC, x.maDC) > 0)
			return InsertNode(root->left, x);
		else
			return InsertNode(root->right, x);
	}
	root = CreateNode(x);
	if (root == NULL)
		return -1;
	return 1;
}

//Tao cay BST tu file
int FileBST_DCu(BSTDungCu& root, char* filename)
{
	ifstream in(filename);
	if (!in)
		return 0;
	KeyType maDC;
	char tenDC[30];
	char theLoai[30];
	int soLuong;
	int donGia;

	int kq;
	CreateBST(root);
	dungcu x;
	while (!in.eof())
	{
		in >> x.maDC; 
		in >> x.tenDC;
		in >> x.theLoai;
		in >> x.soLuong; 
		in >> x.donGia; 
		kq = InsertNode(root, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}

//========================================================
//Xuat tieu de
void TieuDe()
{
	int i;
	cout << "\n";
	for (i = 1; i <= MAXCOT; i++)
		cout << "-";
	cout << endl;
	cout << setiosflags(ios::left);
	cout << ":"
		<< setw(8) << "MaDC"
		<< ":"
		<< setw(30) << "Ten dung cu"
		<< ":"
		<< setw(25) << "The loai"
		<< ':'
		<< setw(10) << "So luong"
		<< ":"
		<< setw(20) << "Don gia"
		<< ":";
	cout << "\n";
	for (i = 0; i < MAXCOT; i++)
		cout << "-";
	cout << ":";
}
void TieuDe_KH()
{

	int i;
	cout << "\n";
	for (i = 1; i <= MAXCOT; i++)
		cout << "-";
	cout << endl;
	cout << setiosflags(ios::left);
	cout << ":"
		<< setw(10) << "MaKH"
		<< ":"
		<< setw(25) << "Ho va ten"
		<< ":"
		<< setw(30) << "Dia Chi"
		<< ":"
		<< setw(15) << "SDT"
		<< ":"
		<< setw(15) << "Ngay mua" << ":";
	cout << "\n";
	for (i = 0; i < MAXCOT; i++)
		cout << "-";
	cout << ":";
}

void KeNgang()
{
	cout << endl;
	for (int i = 1; i <= MAXCOT; i++)
		cout << "-";
	cout << ":";
	cout << endl;
}
//========================================================

//Xuat 1 dung cu
void Xuat_DC(dungcu p)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ":"
		<< setw(8) << p.maDC
		<< ":"
		<< setw(30) << p.tenDC
		<< ":"
		<< setw(25) << p.theLoai
		<< ":"
		<< setw(10) << p.soLuong
		<< ":"
		<< setw(20) << p.donGia
		<< ":";
		
}

//NLR 
void PreOrder(BSTDungCu root)
{
	if (root != NULL)
	{
		Xuat_DC(root->info);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//LNR
void InOrder(BSTDungCu root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		Xuat_DC(root->info);
		InOrder(root->right);
	}
}
//LRN
void PosOrder(BSTDungCu root)
{
	if (root != NULL)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		Xuat_DC(root->info);
	}
}

//***********************************KHACH HANG************************************
BSNodeKH* CreateNodeKH(KhachHang kh)
{
	BSNodeKH* cus = new BSNodeKH;
	if (cus != NULL)
	{
		cus->info = kh;
		cus->left = NULL;
		cus->right = NULL;
	}
	return cus;
}

void CreateBST_KH(BSTCustomer& root2)
{
	root2 = NULL;
}

int InsertNode_KH(BSTCustomer& root2, KhachHang kh)
{
	if (root2 != NULL)
	{
		if (strcmp(root2->info.maKH, kh.maKH) == 0)

			return 0;
		if (strcmp(root2->info.maKH, kh.maKH) > 0)
			return InsertNode_KH(root2->left, kh);
		else
			return InsertNode_KH(root2->right, kh);
	}
	root2 = CreateNodeKH(kh);
	if (root2 == NULL)
		return -1;
	return 1;
}

int FileBST_KH(BSTCustomer& root2, char* filename2)
{
	ifstream in(filename2);
	if (!in)
		return 0;
	KeyTypeKH maKH;

	int kq;
	CreateBST_KH(root2);
	KhachHang x;

	while (!in.eof())
	{
		in >> x.maKH; 
		in >> x.hoTen;
		in >> x.diaChi; 
		in >> x.sdt; 
		in >> x.ngayMua.ngay;
		in >> x.ngayMua.thang;
		in >> x.ngayMua.nam;
		kq = InsertNode_KH(root2, x);
		if (kq == 0 || kq == -1)
			return 0;
	}
	in.close();
	return 1;
}

void Xuat_KH(KhachHang kh)
{
	cout << endl;
	cout << setiosflags(ios::left)
		<< ":"
		<< setw(10) << kh.maKH
		<< ":"
		<< setw(25) << kh.hoTen
		<< ":"
		<< setw(30) << kh.diaChi
		<< ":"
		<< setw(15) << kh.sdt
		<< ":"
		<< setw(2) << kh.ngayMua.ngay << "/" << setw(2) << kh.ngayMua.thang << "/"
		<< setw(9) << kh.ngayMua.nam << ":";
}

void PreOrder_KH(BSTCustomer root2)
{
	if (root2 != NULL)
	{
		Xuat_KH(root2->info);
		PreOrder_KH(root2->left);
		PreOrder_KH(root2->right);
	}
}

void InOrder_KH(BSTCustomer root2)
{
	if (root2 != NULL)
	{
		InOrder_KH(root2->left);
		Xuat_KH(root2->info);
		InOrder_KH(root2->right);
	}
}

void PosOrder_KH(BSTCustomer root2)
{
	if (root2 != NULL)
	{
		PosOrder_KH(root2->left);
		PosOrder_KH(root2->right);
		Xuat_KH(root2->info);
	}
}
//========================================================================