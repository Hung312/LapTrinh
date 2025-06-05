#include <stdio.h>
#define MAX 255
void nhapMang(int a[],int n);
void xuatMang(int a[],int n);
//SelectionSort
void SelectionSort(int a[],int N);
//InsertionSort
void InsertionSort(int a[], int N);
//InterchangeSort
void InterchangeSort(int a[], int N);
//Bubble Sort
void BubbleSort(int a[],int N);
//HeapSort
void Shift (int a[], int left, int right);
void CreateHeap(int a[], int N);
void HeapSort (int a[], int N);
//QuickSort
void QuickSort(int a[], int left, int right);
//HoanVi
void Swap(int *n, int *m);
int main()
{
	int n,A[MAX]; 
	scanf ("%d",&n);
	nhapMang(A,n);
	xuatMang(A,n);
	//SelectionSort(A,n);
	//InsertionSort(A,n);
	//InterchangeSort(A,n);
	//BubbleSort(A,n);
	//HeapSort(A,n);
	//QuickSort(A,1,n);
	//xuatMang(A,n);
	return 0;
}

void nhapMang(int a[],int n)
{
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
}

void xuatMang(int a[],int n)
{
	for (int i=1; i<=n; i++)
		printf ("%2d ",a[i]);
	printf ("\n");
}

void Swap(int *n,int *m)
{
	int temp= *n;
	*n = *m;
	*m= temp;
}


void SelectionSort(int a[],int N )
{
int min; // chæ soá phaàn töû nhoû nhaát trong daõy hieän haønh
for (int i=1; i<=N ; i++)
	{
	min = i;
	for(int j = i+1; j <= N ; j++)
 		if (a[j] < a[min])
 			min = j; // ghi nhaän vò trí phaàn töû nhoû nhaát
	if (min != i)
 	Swap(&a[min], &a[i]);
	}
}

void InsertionSort(int a[], int N )
	{ 
	int pos;
	int x; //löu tröõ a[i] traùnh bò ghi ñeø khi dôøi choã caùc phaàn töû.
	for(int i=2 ; i<=N ; i++) //ñoaïn a[1] ñaõ saép
	{
	x = a[i];
	for(pos=i-1;(pos>=1)&&(a[pos]>x);pos--)
		a[pos+1] = a[pos];
	a[pos+1] = x;// cheøn x vaøo daõy
	}	
}

void InterchangeSort(int a[], int N)
{
	int i, j;
	for (i = 1 ; i<N ; i++)
		for (j =i+1; j <= N ; j++)
 			if(a[j]< a[i]) //neáu coù nghòch theá thì ñoåi choã
				Swap(&a[i],&a[j]);
}

//Dua phan tu nho nhat ve dau day
void BubbleSort(int a[], int N)
{
	int i, j;
	for (i = 1 ; i<N ; i++)
	for (j =N; j>i ; j --)
 	if(a[j]< a[j-1])
		Swap(&a[j], &a[j-1]);
}

void Shift (int a[], int left, int right)
{
	int x, curr, joint;
 	curr = left; joint =2*curr;// ajoint: phaàn töû lieân ñôùi
 	x = a[curr];
	while (joint <= right)
	{
		if (joint < right) // neáu coù ñuû 2 phaàn töû lieân ñôùi
 			if (a[joint] < a[joint+1])
				joint = joint+1;
 		if (a[joint]<x) break; //thoaû quan heä lieân ñôùi
	else
	{
		a[curr] = a[joint];
 		curr = joint; // xeùt tieáp khaû naêng hieäu chænh lan truyeàn
 		joint = 2*curr;
	}
	a[curr] = x; // c?i ti?n
	}
}

void CreateHeap(int a[], int N)
{
 int left;
//left: v? trí ph?n t? c?n ghép thêm
 	for (left = (N)/2; left >= 1; left --)
		Shift(a, left, N);
}

void HeapSort (int a[], int N)
{
 	int right;
 	CreateHeap(a, N); //saép xeáp daõy a thanh hea
 	right = N; // right laø vò trí ñuùng cho phaàn töû lôùn nhaát
 	while (right > 1)
 	{
 		Swap(&a[1],&a[right]);
 		right --;
 		Shift(a,1,right);
 	}
}

void QuickSort(int a[], int left, int right)
{
	int i, j, x;
	if (left >= right) return;
 		x = a[(left+right)/2]; // choïn phaàn töû giöõa laøm giaù trò moác
 	i = left; j = right;
 while(i <= j)
{
 	while(a[i] < x) i++;
 	while(a[j] > x) j--;
 	if(i <= j)
	{
		Swap(&a[i], &a[j]);
 		i++ ; j--;
	}
}
	QuickSort(a, left, j);
	QuickSort(a, i, right);
}

