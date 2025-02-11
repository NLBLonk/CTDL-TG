﻿//Kiểu dữ liệu list: LL
//Kiểu sinh viên
struct LLSinhVien
{
	char maSV[8];
	char ho[15];
	char ten[10];
	int namSinh;
	char nguyenQuan[15];
};

struct tagNodeLL
{
	LLSinhVien info;
	tagNodeLL* pNext;
};

typedef tagNodeLL NODELL;
struct LL
{
	NODELL* pHead;
	NODELL* pTail;
};

//=========================
struct DiemTP
{
	char maSV[8];
	double dBT1;
	double dBT2;
	double dGK;
	double dQT;

};

struct tagNodeDiem
{
	DiemTP info;
	tagNodeDiem* pNext;
};

typedef tagNodeDiem NODEBD;

struct BD
{
	NODEBD* pHead;
	NODEBD* pTail;
};

//================


//================

//Tạo nút mới LL
NODELL* GetNode_LL(LLSinhVien x)
{
	NODELL* p;
	p = new NODELL;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

//Khởi tao ds lket đơn LL rỗng
void CreatList_LL(LL& l)
{
	l.pHead = l.pTail = NULL;
}

//Chèn x vào cuối danh sách 
void InsertTail_LL(LL& l, LLSinhVien x)
{
	NODELL* new_ele = GetNode_LL(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		_getch();
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

//Chuyen du lieu tap tin sinh vien sang list 1
int TapTin_List_LL(char* filename, LL& l)
{
	ifstream in(filename);
	if (!in)
		return 0;
	LLSinhVien x;
	CreatList_LL(l);

	while (!in.eof())
	{
		in >> x.maSV;
		in >> x.ho;
		in >> x.ten;
		in >> x.namSinh;
		in >> x.nguyenQuan;
		InsertTail_LL(l, x);

	}
	in.close();
	return 1;
}
//==========
//Bang diem
//Tao nut moi bang diem
NODEBD* GetNode_BD(DiemTP x)
{
	NODEBD* p;
	p = new NODEBD;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

//Khoi tao DSLK don bang diem rong 
void CreatList_BD(BD& l)
{
	l.pHead = l.pTail = NULL;
}

//Chen x vao cuoi ds
void InsertTail_BD(BD& l, DiemTP x)
{
	NODEBD* new_ele = GetNode_BD(x);
	if (new_ele == NULL)
	{
		cout << "\nKhonf du bo nho";
		_getch();
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

//Chuyen du lieu tap tin diem thanh phan sang list BD 
int TapTin_List_BD(char* filename, BD& l)
{
	ifstream in(filename);
	if (!in)
		return 0;
	DiemTP x;
	CreatList_BD(l);
	while (!in.eof())
	{
		in >> x.maSV;
		in >> x.dBT1;
		in >> x.dBT2;
		in >> x.dGK;
		x.dQT = x.dBT1 + x.dBT2 + x.dGK;

		InsertTail_BD(l, x);
	}
	in.close();
	return 1;
}

//======================
void TieuDe()
{
	int i;
	cout << endl;
	cout << ':';
	for (i = 1; i <= 54; i++)
		cout << '=';
	cout << ':' << endl;
	cout << setiosflags(ios::left);
	cout << ':';
	cout << setw(10) << "Ma SV"
		<< ':'
		<< setw(16) << "Ho"
		<< setw(11) << "Ten"
		<< ':'
		<< setw(6) << "NSinh"
		<< ':'
		<< setw(8) << "DiemGK"
		<< ':';
	cout << endl;
	cout << ':';
	for (i = 1; i <= 54; i++)
		cout << '=';
	cout << ':';
}
void XuatBangDiem(LL l, BD g)
{
	TieuDe();
	NODELL* p = l.pHead;
	NODEBD* q = g.pHead;
	while (p != NULL && q != NULL)
	{
		cout << endl << ':';
		cout << setiosflags(ios::left)
			<< setw(10) << p->info.maSV
			<< ':'
			<< setw(16) << p->info.ho
			<< setw(11) << p->info.ten
			<< ':'
			<< setw(6) << p->info.namSinh
			<< ':'
			<< setw(8) << setprecision(2) << setiosflags(ios::fixed) << q->info.dQT
			<< ':';
		p = p->pNext;
		q = q->pNext;
	}
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 54; i++)
		cout << '=';
	cout << ':' << endl;
}
