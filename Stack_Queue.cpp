#include <stdio.h>
#include <string.h>

typedef struct Node
{
	char Info;
	Node * pNext;
}Node;

typedef struct stack
{
	Node *top;
}stack;

void Init (stack &s);
int Empty(stack s);
void Push(stack &s, char x);
char Pop(stack &s);

int main()
{
	stack S;
	char thaotac[150];
	fflush(stdin);
	gets(thaotac);
	Init (S);
	for (int i=0; i<strlen(thaotac);i++)
		if (thaotac[i]!='*')
			Push(S,thaotac[i]);
		else
			printf("%c",Pop(S));
	return 0;
}

void Init (stack &s)
{
	s.top=NULL;
}

int Empty(stack s)
{
	return s.top == NULL ? 1 : 0; // stack r?ng
}

void Push(stack &s, char x)
{
	Node * p;
	p=new Node;
	if(p!=NULL)
	{
		p->Info=x;
		p->pNext=s.top;
		s.top=p;
	}
}

char Pop(stack &s)
{
	char x;
	if(!Empty(s))
	{
		Node * p=s.top;
		x=p->Info;
		s.top=p->pNext;
		delete(p);
		return x;
	}
}


