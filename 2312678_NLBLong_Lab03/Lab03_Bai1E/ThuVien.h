#define MAX 100
//Dinh nghia kieu du lieu

//Khai bao nguyen mau cac ham
void HoanVi(int& a, int& b);
void Copy(int b[MAX], int a[MAX], int n);
void Selection_R(int a[MAX], int n);
void Selection_R_L(int a[MAX], int n);
void Insertion_R(int a[MAX], int n);
void Interchange_R(int a[MAX], int n);
void Bubble_R(int a[MAX], int n);
void Shaker(int a[MAX], int n);
void HoanVi(int& a, int& b);
void Selection_L(int a[MAX], int n);
void Copy(int b[MAX], int a[MAX], int n);
void Insertion_L(int a[MAX], int n);
void Interchange_L(int a[MAX], int n);
void Bubble_L(int a[MAX], int n);
void Binary_Insertion(int a[MAX], int n);

//Dinh nghia cac ham
int TapTin_mang1c(char* filename, int a[MAX], int& n)
{
	ifstream in(filename);
	if (!in) return 0;
	n = 0;  in >> a[0];
	while (!in.eof())
	{
		n++;
		in >> a[n];
	}
	n++;
	in.close();
	return 1;
}

void Xuat_Mang(int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
}

//Hàm hoán vi
void HoanVi(int& a, int& b)
{
	int tam = a;
	a = b;
	b = tam;
}
//Copy a sang b
void Copy(int b[MAX], int a[MAX], int n)
{

	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
// Tai moi buoc dua gia tri nho nhat ve dau mang
void Selection_L(int a[MAX], int n)
{
	int b[MAX];
	Copy(b, a, n);
	int i, j, cs_min;
	for (i = 0; i < n - 1; i++)
	{
		cs_min = i;
		for (j = i + 1; j < n; j++)
			if (b[j] < b[cs_min])
				cs_min = j;
		HoanVi(b[i], b[cs_min]);
	}
	cout << "\nMang sau khi sap xep : \n";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << '\t';
	}
}
//Tai moi buoc, chen PT hien hanh vao mang con ben trai tang dan
void Insertion_L(int a[MAX], int n)
{
	int b[MAX];
	Copy(b, a, n);
	int i, x, pos;
	for (i = 1; i < n; i++)
	{
		x = b[i];
		for (pos = i - 1; (pos >= 0) && (b[pos] > x); pos--)
			b[pos + 1] = b[pos];
		b[pos + 1] = x;
	}
	cout << "\nMang sau khi sap xep : \n";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << '\t';
	}
}
// Doi cho truc tiep :Tai moi buoc dua gia tri nho nhat ve dau mang
void Interchange_L(int a[MAX], int n)
{
	int b[MAX];
	Copy(b, a, n);
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
			if (b[j] < b[i])
				HoanVi(b[i], b[j]);
	}
	cout << "\nMang sau khi sap xep : \n";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << '\t';
	}
}
//Buble: Tai moi buoc dua GTNN ve dau mang
void Bubble_L(int a[MAX], int n)
{
	int b[MAX];
	Copy(b, a, n);
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
			if (b[j] < b[j - 1])
				HoanVi(b[j - 1], b[j]);
	}
	cout << "\nMang sau khi sap xep : \n";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << '\t';
	}
}
//Chen nhi phan
void Binary_Insertion(int a[MAX], int n)
{
	int b[MAX];
	Copy(b, a, n);
	int l, r, m;
	int i, j;
	int x;
	for (i = 1; i < n; i++)
	{
		x = b[i]; l = 0; r = i - 1;
		while (l <= r)
		{
			m = (l + r) / 2;
			if (x < b[m])
				r = m - 1;
			else
				l = m + 1;
		}
		for (j = i - 1; j >= l; j--)
			b[j + 1] = b[j];
		b[l] = x;
	}
	cout << "\nMang sau khi sap xep : \n";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << '\t';
	}
}
//Tai moi buoc dua gia tri lon nhat ve cuoi mang
void Selection_R(int a[MAX], int n)
{
	int b[MAX];
	Copy(b, a, n);
	int i, j, cs_max;
	for (i = 0; i < n - 1; i++)
	{
		cs_max = n - 1 - i;
		for (j = n - 2 - i; j >= 0; j--)
			if (b[j] > b[cs_max])
				cs_max = j;
		HoanVi(b[n - 1 - i], b[cs_max]);
	}
	cout << "\nMang sau khi sap xep : \n";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << '\t';
	}
}

//Tai moi buoc dua GTLN ve cuoi mang, dua GTNN ve dau mang
void Selection_R_L(int a[MAX], int n)
{
	int b[MAX];
	Copy(b, a, n);
	int i, j, cs_min, cs_max;
	for (i = 0; i < n / 2; i++)
	{
		cs_min = i;
		cs_max = n - 1 - i;
		for (j = i; j <= n - 1 - i; j++)
		{
			if (b[j] < b[cs_min])
				cs_min = j;
			if (b[j] > b[cs_max])
				cs_max = j;
		}
		if (cs_min == n - i - 1)
		{
			HoanVi(b[i], b[cs_min]);
			if (cs_max != i) //?
				HoanVi(b[cs_max], b[n - i - 1]);
		}
		else
		{
			HoanVi(b[cs_max], b[n - i - 1]);
			HoanVi(b[i], b[cs_min]);
		}
	}
	cout << "\nMang sau khi sap xep : \n";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << '\t';
	}
}

//Insertion_R : Tai moi buoc, chen PT hien hanh vao mang con ben phai tang dan
void Insertion_R(int a[MAX], int n)
{
	int b[MAX];
	Copy(b, a, n);
	int i, x, pos;
	for (i = n - 2; i >= 0; i--)
	{
		x = b[i];
		for (pos = i + 1; (pos < n) && (b[pos] < x); pos++)
			b[pos - 1] = b[pos];
		b[pos - 1] = x;
	}
	cout << "\nMang sau khi sap xep : \n";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << '\t';
	}
}

//Interchange_R: Tai moi buoc dua gia tri lon nhat ve cuoi mang
void Interchange_R(int a[MAX], int n)
{
	int b[MAX];
	Copy(b, a, n);
	int i, j;
	for (j = n - 1; j > 0; j--)
	{
		for (i = 0; i < j; i++)
			if (b[i] > b[j])
				HoanVi(b[i], b[j]);
	}
	cout << "\nMang sau khi sap xep : \n";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << '\t';
	}
}

//Bubble_R : Tai moi buoc dua GTLN ve cuoi mang
void Bubble_R(int a[MAX], int n)
{
	int b[MAX];
	Copy(b, a, n);
	int i, j;
	for (j = n - 1; j > 0; j--)
	{
		for (i = 0; i < n - 1; i++)
			if (b[i] > b[i + 1])
				HoanVi(b[i + 1], b[i]);
		cout << "\nBuoc " << n - j << " : ";
		Xuat_Mang(b, n);
		cout << "\n";
	}
	cout << "\nCo " << n - 1 << " buoc thuc hien thuat giai.\n";
	cout << "\nMang sau khi sap xep : \n";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << '\t';
	}
}

//Shaker :
void Shaker(int a[MAX], int n)
{
	int b[MAX];
	Copy(b, a, n);
	int l = 0, r = n - 1;
	int k = n - 1;
	int j;
	while (l < r)
	{
		j = r;//Khoi tao j tu bien phai
		while (j > l)
		{
			if (b[j] < b[j - 1])
			{
				HoanVi(b[j], b[j - 1]);
				k = j;
				cout << "\nk = " << k;
			}
			j = j - 1;
		}
		l = k;//xac dinh lai bien trai l
		j = l; //khoi tao j tu bien trai
		while (j < r)
		{
			if (b[j] > b[j + 1])
			{
				HoanVi(b[j], b[j + 1]);
				k = j;
			}
			j = j + 1;
		}
		r = k;//xac dinh lai bien phai l
	}
	cout << "\nMang sau khi sap xep : \n";
	for (int i = 0; i < n; i++)
	{
		cout << b[i] << '\t';
	}
}
