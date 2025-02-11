#define MAX 100

struct sinhvien
{
	char maSV[8];
	char hoSV[10];
	char tenLot[10];
	char ten[10];
	int namSinh;
	double dtb;
};
//=============================================================
int File_MangCT(char* filename, sinhvien a[MAX], int& n);
void TieuDe();
void Xuat_SV(sinhvien p);
void Xuat_DSSV(sinhvien a[MAX], int n);
//=============================================================
int File_MangCT(char* filename, sinhvien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n].maSV;
		in >> a[n].hoSV;
		in >> a[n].tenLot;
		in >> a[n].ten;
		in >> a[n].namSinh;
		in >> a[n].dtb;
		n++;
	}
	in.close();
	return 1;
}

void TieuDe()
{
	int i;
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << ':';
	cout << setw(9) << "Ma SV"
		<< ':'
		<< setw(10) << " Ho "
		<< ':'
		<< setw(10) << " Ten Lot"
		<< ':'
		<< setw(10) << " Ten "
		<< ':'
		<< setw(6) << "NS"
		<< ':'
		<< setw(6) << "DTB"
		<< ':';
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void Xuat_SV(sinhvien p)
{
	cout << ':';
	cout << setiosflags(ios::left)
		<< setw(9) << p.maSV
		<< ':'
		<< setw(10) << p.hoSV
		<< setw(10) << p.tenLot
		<< setw(10) << p.ten
		<< ':'
		<< setw(6) << p.namSinh
		<< ':'
		<< setw(6) << setiosflags(ios::fixed) << setprecision(2) << p.dtb
		<< ':';
	cout << endl;
}

void Xuat_DSSV(sinhvien a[MAX], int n)
{
	int i;
	TieuDe();
	for (i = 0; i < n - 1; i++)
	{
		Xuat_SV(a[i]);
		cout << '\n';
	}
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void Tim_Ho_Ten_NamSinh(sinhvien a[MAX], int n, char ho[10], char ten[10], int nSinh)
{
	int kq = -1;
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(a[i].hoSV, ho) == 0 && _stricmp(a[i].ten, ten) == 0 && a[i].namSinh < nSinh)
		{
			kq = 1;
			break;
		}
	}
	if (kq == -1)
		cout << "\nKhong tim thay sinh vien co ho '" << ho << "' va ten '" << ten << "'"
		<< "\n va nam sinh < " << nSinh << " trong danh sach";
	else
	{
		cout << "\nDanh sach nhung sien vien co ho '" << ho << "' va ten '" << ten << "'"
			<< "\n va nam sinh < " << nSinh << " trong danh sach : \n";
		TieuDe();
		for (int i = 0; i < n; i++)
			if (_stricmp(a[i].hoSV, ho) == 0 && _stricmp(a[i].ten, ten) == 0 && a[i].namSinh < nSinh)
				Xuat_SV(a[i]); cout << endl;
		
	}
}

int TimKiem_Ten_CoLinhCanh(sinhvien a[MAX], int n, char ten[10])
{
	sinhvien x;
	strcpy_s(x.ten, ten);
	int i = 0; a[n] = x;
	while (strcpy_s(a[i].ten, x.ten) != 0) i++;
	if (i == n) return -1;
	return i;
}

void SXNamSinh_ChonTrucTiep(sinhvien a[MAX], int n)
{
	int cs_min;
	for (int i = 0; i < n - 1; i++)
	{
		cs_min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j].namSinh < a[cs_min].namSinh)
				cs_min = j;
		swap(a[i], a[cs_min]);
	}
}

void Partition(sinhvien a[MAX], int l, int r) {
	int i = l, j = r;
	sinhvien x = a[(l + r) / 2];
	do {
		while (a[i].dtb > x.dtb)
			i++;
		while (a[j].dtb < x.dtb)
			j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (l < j)
		Partition(a, l, j);
	if (i < r)
		Partition(a, i, r);
}

void SXGiam_TheoDTB(sinhvien a[MAX], int n) {
	Partition(a, 0, n - 1);
}

void HoanVi(sinhvien a[], int& i, int& j) {
	sinhvien temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void SapXepDSTangNamSinh(sinhvien a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min].namSinh > a[j].namSinh) {
				min = j;
			}
		}
		HoanVi(a, min, i);
	}
}

int TKNP_TheoNamSinh(sinhvien a[MAX], int n, int nSinh) {
	int l = 0;
	int r = n - 1;
	SapXepDSTangNamSinh(a, n);
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid].namSinh == nSinh && a[mid + 1].namSinh == nSinh)
			return mid + 1;
		else if (a[mid].namSinh > nSinh) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return -1;
}

int TKNP_TheoDTB(sinhvien a[MAX], int n, double diemTB) {
	int l = 0;
	int r = n - 1;
	SXGiam_TheoDTB(a, n);
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid].dtb == diemTB && a[mid + 1].dtb == diemTB)
			return mid + 1;
		else if (a[mid].dtb > diemTB) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return -1;
}
