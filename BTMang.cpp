#include <stdio.h>
#define day 31

void nhapchitieu(float a[], int n);
void hienthichitieu(float a[], int n);
void Tinhtoan_va_Thongke(float a[], int n);
float tongchitieu(float a[], int n);
float trungbinhchitieu(float a[], int n);
int timngaymax(float a[], int n);
int timngaymin(float a[], int n);
void phantichChitieu(float a[], int n);
int demngayvuotmucX(float a[], int n, float X);
int demngaythapbangX(float a[], int n, float X);
void sapxep(float n, float m);
void sapxeptangdan(float a[], int n);
void sapxepChitieu(float a[], int n);

int main()
{
	int n;
	float A[day];
	do
	{
		printf ("Nhap vao so ngay chi tieu (28<=n<=31): "); scanf ("%d",&n);
	}while (n<28||n>day);
	//Goi ham
	nhapchitieu(A,n);	printf ("\n");
	hienthichitieu(A,n);	printf ("\n");
	printf ("Tinh toan va thong ke:\n");
	Tinhtoan_va_Thongke(A,n);	printf ("\n");
	printf ("Phan tich chi tieu:\n");
	phantichChitieu(A,n);	printf ("\n");
	printf ("Sap xep chi tieu: \n");
	sapxepChitieu(A,n);	printf ("\n");
	
	return 0;
}

void nhapchitieu(float a[], int n)
{
	for (int i=0; i<n; i++)
	{
		printf ("Ngay %d: ",i+1); scanf ("%f",&a[i]);
	}
}

void hienthichitieu(float a[], int n)
{
	printf ("Hien thi chi tieu tung ngay: \n");
	for (int i=0; i<n; i++)
	{
		printf ("Ngay %d: %.1f dong\n",i+1,a[i]);
	}
}

void Tinhtoan_va_Thongke(float a[], int n)
{
	printf ("Tong chi tieu trong thang: %.1f dong",tongchitieu(a,n));	printf ("\n");
	printf ("Trung binh chi tieu moi ngay: %.1f dong",trungbinhchitieu(a,n));	printf ("\n");
	printf ("Ngay co chi tieu lon nhat: Ngay %d\n",timngaymax(a,n));
	printf ("Ngay co chi tieu thap nhat: Ngay %d\n",timngaymin(a,n));
}

float tongchitieu(float a[], int n)
{
	float S=0;
	for (int i=0; i<n; i++)
		S+=a[i];
	return S;
}

float trungbinhchitieu(float a[], int n)
{
	float TB=0;
	for (int i=0; i<n; i++)
		TB+=a[i];
	return TB/n;
}

int timngaymax(float a[], int n)
{
	float max=a[0];
	int x=1;
	for (int i=0; i<n; i++)
	{
		if (max<a[i])
		{
			max=a[i];
			x=i+1;
		}
	}
	return x;
}

int timngaymin(float a[], int n)
{
	float min=a[0];
	int y=1;
	for (int j=0; j<n; j++)
	{
		if (min>a[j])
		{
			min=a[j];
			y=j+1;
		}
	}
	return y;
}

void phantichChitieu(float a[], int n)
{
	float X;
	printf ("Nhap vao mot so de phan tich chi tieu: "); scanf ("%f",&X);
	printf ("So ngay vuot muc chi tieu %.1f: %d ngay\n",X,demngayvuotmucX(a,n,X));
	printf ("So ngay thap hoac bang chi tieu %.1f: %d ngay\n",X,demngaythapbangX(a,n,X));
}

int demngayvuotmucX(float a[], int n, float X)
{
	int dem=0;
	for (int i=0; i<n; i++)
	{
		if (a[i]>X)
			dem++;
	}
	return dem;
}

int demngaythapbangX(float a[], int n, float X)
{
	int dem=0;
	for (int i=0; i<n; i++)
	{
		if (a[i]<=X)
			dem++;
	}
	return dem;
}

void sapxepChitieu(float a[], int n)
{
	sapxeptangdan(a,n);	printf ("\n");
}

void sapxep(float *n, float *m)
{
	int temp=*n;
	*n=*m;
	*m=temp;
}

void sapxeptangdan(float a[], int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (a[i]>a[j])
				sapxep(&a[i],&a[j]);
		}
	}
	for (int i=0; i<n; i++)
	{
		printf ("Ngay %d: %.1f dong\n",i+1,a[i]);
	}
}
