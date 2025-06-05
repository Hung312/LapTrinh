#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NGAY
{//cau truc ngay thang nam sinh
    int ngay,thang,nam;
}ngay;

typedef struct SINH_VIEN
{//cau truc SINH_VIEN
    char mssv[10],hoten[45],diachi[100];
    int somon;
    ngay ngaysinh;
    float *diem;
}SV;

void nhapSV(SV *a);
void xuatSV(SV a);
void nhapNgay(ngay *a);
void xuatNgay(ngay a);
void nhapDSSV(SV a[],int n);
int kiemtraSV(SV a[],int n);
void xuatDSSV(SV a[],int n);

int main()
{//chuong trinh chinh
    SV a;
    SV A[10];
    int n;
    printf ("Nhap so sinh vien: ");scanf ("%d",&n);
    nhapDSSV(A,n);
    xuatDSSV(A,n);
    if (kiemtraSV(A,n)==1)
        printf ("co ton tai sinh vien trong danh sach");
    else
        printf ("khong ton tai sinh vien");
	return 0;
}

void nhapNgay(ngay *a)
{//nhap ngay thang nam sinh
    do
    {
        printf ("Nhap vao ngay sinh: "); scanf("%d",&a->ngay);
        printf ("Nhap vao thang sinh: "); scanf("%d",&a->thang);
        printf ("Nhap vao nam sinh: ");scanf ("%d",&a->nam);
    } while (a->ngay > 31||a->ngay<=0||a->thang >12||a->thang<=0);
}

void xuatNgay(ngay a)
{//xuat ngay thang nam sinh
    printf ("Ngay thang nam sinh: %d/%d/%d\n",a.ngay,a.thang,a.nam);
}

void nhapSV(SV *a)
{//nhap thong tin SV
    printf ("Nhap ma so sinh vien (toi da 9 so): ");
    fflush(stdin);
    scanf ("%s",a->mssv);
    
    printf ("Nhap ho va ten(VD: Nguyen Van A): ");
    fflush(stdin);
    gets(a->hoten);

    nhapNgay(&a->ngaysinh);

    printf ("Nhap dia chi: ");
    fflush(stdin);
    gets(a->diachi);

    do
    {
        printf ("Nhap so mon dau vao(toi da 3 mon): "); scanf("%d",&a->somon);
    } while (a->somon>3);

    a->diem = (float *) malloc(a->somon * sizeof(float));

    for (int i=0; i<a->somon;i++)
    {
        printf ("Nhap mon thu %d= ",i+1); scanf("%f",&a->diem[i]);
    }
}

void xuatSV(SV a)
{//xuat ra thong tin SV
    printf ("\nMSSV: %s\n",a.mssv);
    printf ("Ho va ten: %s\n",a.hoten);
    xuatNgay(a.ngaysinh);
    printf ("Dia chi: %s\n",a.diachi);
    printf ("Danh sach diem:\n");
    for (int i=0;i<a.somon;i++)
        printf ("Mon %d= %.1f\n",i+1,a.diem[i]);
}

void nhapDSSV(SV a[],int n)
{//nhap vao danh sach sinh vien
    for (int i=0;i<n;i++)
    {
        printf ("Sinh vien thu %d:\n",i+1);
        nhapSV(&a[i]);
    }
}

int kiemtraSV(SV a[],int n)
{//kiem tra xem co ton tai sinh vien khong
    char mssv[10];
    printf ("Nhap ma so de kiem tra: ");scanf ("%s",mssv);
    for (int i=0;i<n;i++)
    {
        if (strcmp(a[i].mssv,mssv)==0)
            return 1;
    }
    return 0;
}

void xuatDSSV(SV a[],int n)
{//xuat ra danh sach sinh vien
    for (int i=0;i<n;i++)
    {
        xuatSV(a[i]);
    }
}




