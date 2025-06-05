#include <stdio.h>
#include <stdlib.h>

typedef struct TNODE
{
	int key;
	TNODE* pLeft;
	TNODE* pRight;
}TNODE;
typedef struct TNODE* TREE;
TREE root;

//tao cay va them nut
void InsertTree(TREE &root , int x);
void CreateTree(TREE &root);

//duyet, in theo dang folder
void NLR(TREE root);
void LNR(TREE root);
void LRN(TREE root);
void Output(TREE Root,int level);

//nhung ham co ban khac
TNODE* searchNode(TREE root,int X);
int delNode(TREE &root,int X);	void searchStandFor(TREE &p, TREE &q);
int insertNode(TREE &root, int X);
void removeTree(TREE &root);
int LeafCount(TREE root);	char Leaf(TNODE*node);
int Tree1NodeCount(TREE root); char Tree1Node(TNODE*node);
int Tree2NodeCount(TREE root);
int NodeSmalXCount(TREE root, int X);
int NodeGreatXCount(TREE root, int X);
int NodeGreatXSmalYCount(TREE root, int X, int Y);
int TreeHeight(TREE root);
void PrintNode(TREE root, int X);

int main()
{
	root=NULL;
	CreateTree(root);
	
	//In cay
	LNR(root);	printf ("\nCay Nhi Phan Tim Kiem\n");
	Output(root,0);
	
	int X,Y;
	
	//Tim nut co khoa X
	printf ("\nNhap vao mot so de tim kiem trong cay: "); scanf("%d",&X);
	if(searchNode(root,X)!=NULL)
		printf ("\nTim thay %d\n",X);
	else
		printf ("\nKhong tim thay %d\n",X);
	PrintNode(root,X);
	
	//Xoa nut co khoa X
	printf ("Nhap phan tu X de tien hanh xoa: "); scanf("%d",&X);
	delNode(root,X);
	printf ("\nCay Nhi Phan sau khi xoa phan tu %d\n",X);
	LNR(root);	printf("\n");
	Output(root,0);

	//So nut la'
	printf("\nSo nut la = %d",LeafCount(root));
	
	//So nut 1 cay con va 2 cay con
	printf("\nSo nut 1 cay con = %d",Tree1NodeCount(root));
	printf("\nSo nut 2 cay con = %d",Tree2NodeCount(root));
	
	//So nut nho hon khoa X
	printf("\nNhap vao so X de dem so nut nho hon: "); scanf("%d",&X);
	printf("So nut nho hon %d = %d",X,NodeSmalXCount(root,X));
	
	//So nut lon hon khoa X
	printf("\nNhap vao X de dem so nut lon hon: "); scanf("%d",&X);
	printf("\nSo nut lon hon %d = %d",X,NodeGreatXCount(root,X));
	
	//So nut lon hon khoa X va nho hon khoa Y
	printf("\nNhap vao X va Y de dem so nut lon hon va nho hon theo thu tu: "); scanf("%d%d",&X,&Y);
	printf("\nSo nut lon hon %d va nho hon %d = %d",X,Y,NodeGreatXSmalYCount(root,X,Y));
	
	//Chieu cao cua cay
	if(TreeHeight(root)==-1)
		printf ("\nChieu cao cua cay = 0");
	else
		printf ("\nChieu cao cua cay = %d",TreeHeight(root));
		
	return 0;
}

void InsertTree(TREE &root , int x)
{
	if(root != NULL)
	{
		if(root->key==x) return;
		if(root->key >x)
		InsertTree(root->pLeft,x);
	else
		InsertTree(root->pRight,x);
	}
	else
	{
		root= new TNODE;
		root->key=x;
		root->pLeft=root->pRight=NULL;
	}
}

void CreateTree(TREE &root)
{
	int x,n;
	printf("Nhap n = "); scanf("%d",&n);
	for(int i=1; i<=n;i++)
	{
		scanf("%d",&x);
		InsertTree(root,x);
	}
}

void NLR(TREE root)
{
	if (root != NULL)
	{
		printf("%d ",root->key);
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}

void LNR(TREE root)
{
	if (root != NULL)
	{
		LNR(root->pLeft);
		printf("%d ",root->key);
		LNR(root->pRight);
	}
}

void LRN(TREE root)
{
	if (root != NULL)
	{
		LRN(root->pLeft);
		LRN(root->pRight);
		printf("%d ",root->key);
	}
}

TNODE * searchNode(TREE root, int x)
{
	TNODE *p = root;
	while (p != NULL)
	{
		if(x == p->key) return p;
	else
		if(x < p->key) p = p->pLeft;
	else
		p = p->pRight;
	}
	return NULL;
}

int delNode(TREE &root,int X)
{
	if(root== NULL)
		return 0;
	if(root->key > X)
		delNode(root->pLeft, X);
	if(root->key < X)
		delNode(root->pRight, X);
	//T->Key == X
	if(root->key==X)
	{
		TNODE* p = root;
	if(root->pLeft == NULL)
		root = root->pRight;
	else
		if(root->pRight == NULL)
			root = root->pLeft;
	else // T có d? 2 con
		searchStandFor(p, root->pLeft);
	delete p;
	}
}

void searchStandFor(TREE &p, TREE &q)
{
	if(q->pRight!=NULL)
		searchStandFor(p, q->pRight);
	else
	{
		p->key = q->key;
		p = q;
		if(q->pLeft!=NULL)
			q = q->pLeft;
		else
			q = q->pRight;
	}
}

int insertNode(TREE &root, int X)
{
	if (root!=NULL) {
		if(root->key == X) return 0; // da co
		if(root->key > X)
		return insertNode(root->pLeft, X);
	else
		return insertNode(root->pRight, X);
	}
	root= (TNODE*)malloc(sizeof(TNODE));
	if (root == NULL) return -1; // thieu bo nho
		root->key = X;
		root->pLeft = root->pRight = NULL;
	return 1; // them vao thanh cong
}

void Output(TREE Root,int level) {
	for(int i=1;i<=level;i++)
		printf("\t");
	if (Root != NULL) {
		printf("%d\n", Root->key);
		Output(Root->pLeft,level+1);
		Output(Root->pRight,level+1);
	}
	else
		printf("NULL\n");
}

void removeTree(TREE &root)
{
	if(root!=NULL)
	{
		removeTree(root->pLeft);
		removeTree(root->pRight);
		delNode(root,root->key);
	}
}

char Leaf(TNODE*node)
{
	return (node->pLeft==NULL) && (node->pRight==NULL);
}

int LeafCount(TREE root)
{
	if (root==NULL)
		return 0;
	else
		if (Leaf(root))
			return  1;
		else
			return (LeafCount(root->pLeft)) + (LeafCount(root->pRight));
}

char Tree1Node(TNODE*node)
{
	return (node->pLeft==NULL) && (node->pRight!=NULL) || (node->pLeft!=NULL) && (node->pRight==NULL);
}

int Tree1NodeCount(TREE root)
{
	if(root==NULL)
		return 0;
	else
		if(Tree1Node(root))
			return 1;
		else
			return (Tree1NodeCount(root->pLeft)) + (Tree1NodeCount(root->pRight));
}


int Tree2NodeCount(TREE root)
{
	if(root==NULL)
		return 0;
	else{
		int LeftCount= Tree2NodeCount(root->pLeft);
		int RightCount= Tree2NodeCount(root->pRight);
		if	((root->pLeft!=NULL) && (root->pRight!=NULL))
			return 1 + LeftCount + RightCount;
		else
			return (Tree2NodeCount(root->pLeft)) + (Tree2NodeCount(root->pRight));
		}
}

int NodeSmalXCount(TREE root, int X)
{
	if(root==NULL)
		return 0;
		
	if(root->key<X)
		return 1 + NodeSmalXCount(root->pLeft,X) + NodeSmalXCount(root->pRight,X);
	else
		return NodeSmalXCount(root->pLeft,X);
}

int NodeGreatXCount(TREE root, int X)
{
	if(root==NULL)
		return 0;
	
	if(root->key>X)
		return 1 + NodeGreatXCount(root->pRight,X) + NodeGreatXCount(root->pLeft,X);
	else
		return NodeGreatXCount(root->pRight,X);
}	

int NodeGreatXSmalYCount(TREE root, int X, int Y)
{
	if(root==NULL)
		return 0;
	
	if(root->key<=X)
		return NodeGreatXSmalYCount(root->pRight,X,Y);
	else
		if(root->key>=Y)
			return NodeGreatXSmalYCount(root->pLeft,X,Y);
		else
			return 1 + NodeGreatXSmalYCount(root->pLeft,X,Y) + NodeGreatXSmalYCount(root->pRight,X,Y);		
}

int TreeHeight(TREE root)
{
	if(root==NULL)
		return -1;
	else
	{
		int LeftHeight = TreeHeight(root->pLeft);
		int RightHeight = TreeHeight(root->pRight);
		return 1 + (LeftHeight > RightHeight ? LeftHeight : RightHeight);
	}
}

void PrintNode(TREE root, int X)
{
	TNODE *p = root;
	printf ("Cac khoa duoc duyet qua sau khi tim nut co khoa %d: \n",X);
	while(p!=NULL)
	{
		printf("%d ",p->key);
		if(p->key==X)
			break;
		else
			if(p->key>X)
				p=p->pLeft;
			else
				p=p->pRight;
	}
	printf("\n");
}
