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
int min; // ch� so� pha�n t�� nho� nha�t trong da�y hie�n ha�nh
for (int i=1; i<=N ; i++)
	{
	min = i;
	for(int j = i+1; j <= N ; j++)
 		if (a[j] < a[min])
 			min = j; // ghi nha�n v� tr� pha�n t�� nho� nha�t
	if (min != i)
 	Swap(&a[min], &a[i]);
	}
}

void InsertionSort(int a[], int N )
	{ 
	int pos;
	int x; //l�u tr�� a[i] tra�nh b� ghi �e� khi d��i cho� ca�c pha�n t��.
	for(int i=2 ; i<=N ; i++) //�oa�n a[1] �a� sa�p
	{
	x = a[i];
	for(pos=i-1;(pos>=1)&&(a[pos]>x);pos--)
		a[pos+1] = a[pos];
	a[pos+1] = x;// che�n x va�o da�y
	}	
}

void InterchangeSort(int a[], int N)
{
	int i, j;
	for (i = 1 ; i<N ; i++)
		for (j =i+1; j <= N ; j++)
 			if(a[j]< a[i]) //ne�u co� ngh�ch the� th� �o�i cho�
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
 	curr = left; joint =2*curr;// ajoint: pha�n t�� lie�n ���i
 	x = a[curr];
	while (joint <= right)
	{
		if (joint < right) // ne�u co� �u� 2 pha�n t�� lie�n ���i
 			if (a[joint] < a[joint+1])
				joint = joint+1;
 		if (a[joint]<x) break; //thoa� quan he� lie�n ���i
	else
	{
		a[curr] = a[joint];
 		curr = joint; // xe�t tie�p kha� na�ng hie�u ch�nh lan truye�n
 		joint = 2*curr;
	}
	a[curr] = x; // c?i ti?n
	}
}

void CreateHeap(int a[], int N)
{
 int left;
//left: v? tr� ph?n t? c?n gh�p th�m
 	for (left = (N)/2; left >= 1; left --)
		Shift(a, left, N);
}

void HeapSort (int a[], int N)
{
 	int right;
 	CreateHeap(a, N); //sa�p xe�p da�y a thanh hea
 	right = N; // right la� v� tr� �u�ng cho pha�n t�� l��n nha�t
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
 		x = a[(left+right)/2]; // cho�n pha�n t�� gi��a la�m gia� tr� mo�c
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

