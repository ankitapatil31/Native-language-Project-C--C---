/*#include<stdio.h>
#include<malloc.h>
struct Node
{
	struct Node* pPrev;
	int iData;
	struct Node* pNext;
};

void phyRev(struct Node **ppHead, struct Node **ppTail);
void Display(struct Node *pHead, struct Node *pTail);
void InsertFirst(struct Node **ppHead, struct Node **ppTail, int iNo);

int main(void)
{
	struct Node *pFirst = NULL;
	struct Node *pLast = NULL;
	InsertFirst(&pFirst,&pLast,20);
	InsertFirst(&pFirst,&pLast,10);
	InsertFirst(&pFirst,&pLast,30);
	Display(pFirst,pLast);
	phyRev(&pFirst,&pLast);
	printf("\n rev display\n");
	Display(pFirst,pLast);
	getch();
	return 0;
}
void Display(struct Node *pHead, struct Node *pTail)
{
	while(pHead != NULL)
	{
		
		printf("<-| %d |->",pHead->iData);
		pHead = pHead->pNext;
	}
}
void InsertFirst(struct Node **ppHead, struct Node **ppTail, int iNo)
{
	struct Node * pNewNode = (struct Node*)malloc(sizeof(struct Node));
	if(NULL == pNewNode)
	{
		printf("Memory Allocation fail");
		return;
	}
	pNewNode->iData = iNo;
	pNewNode->pPrev = NULL;
	if(NULL == *ppHead )
	{
		pNewNode->pNext = NULL;
		*ppHead = pNewNode;
		*ppTail = pNewNode;	
	}
	else
	{
		pNewNode->pNext = *ppHead;
		(*ppHead)->pPrev = pNewNode;
		*ppHead = pNewNode;
	}

}
void phyRev(struct Node **ppHead, struct Node **ppTail)
{
	struct Node *pCurrent = *ppHead;
	 struct Node *pNext = NULL;

	 while(pCurrent != NULL)
	 {
		 pNext = pCurrent->pNext;
		 pCurrent->pNext = pCurrent->pPrev;
		 pCurrent->pPrev = pNext;
		 pCurrent = pNext;
		 printf("\nhi");
	 }
	 pCurrent = *ppHead;
	 *ppHead = *ppTail;
	 *ppTail = pCurrent;
		 printf("\n%d",(*ppHead)->iData);
		 printf("\n%d",(*ppTail)->iData);

}

*/



/*
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct Node
{
	struct Node* pPrev;
	int iData;
	struct Node* pNext;
};

void phyRev(struct Node **ppHead, struct Node **ppTail);
void Display(struct Node *pHead, struct Node *pTail);
void InsertFirst(struct Node **ppHead, struct Node **ppTail, int iNo);

int main(void)
{
	struct Node *pFirst = NULL;
	struct Node *pLast = NULL;
	InsertFirst(&pFirst,&pLast,10);
	InsertFirst(&pFirst,&pLast,20);
	InsertFirst(&pFirst,&pLast,30);
	InsertFirst(&pFirst,&pLast,40);
	InsertFirst(&pFirst,&pLast,50);
	Display(pFirst,pLast);
	
	_getch();
	return 0;
}
void Display(struct Node *pHead, struct Node *pTail)
{
	while(pHead != NULL)
	{
		
		printf("<-| %d |->",pHead->iData);
		pHead = pHead->pNext;
	}
}
void InsertFirst(struct Node **ppHead, struct Node **ppTail, int iNo)
{
	struct Node * pNewNode = (struct Node*)malloc(sizeof(struct Node));
	if(NULL == pNewNode)
	{
		printf("Memory Allocation fail");
		return;
	}
	pNewNode->iData = iNo;
	pNewNode->pPrev = NULL;
	if(NULL == *ppHead )
	{
		pNewNode->pNext = NULL;
		*ppHead = pNewNode;
		*ppTail = pNewNode;	
	}
	else
	{
		pNewNode->pNext = *ppHead;
		(*ppHead)->pPrev = pNewNode;
		*ppHead = pNewNode;
	}

}
void phyRev(struct Node **ppHead, struct Node **ppTail)
{
	struct Node *pCurrent = *ppHead;
	 struct Node *pNext = NULL;

	 while(pCurrent != NULL)
	 {
		 pNext = pCurrent->pNext;
		 pCurrent->pNext = pCurrent->pPrev;
		 pCurrent->pPrev = pNext;
		 pCurrent = pNext;
		 printf("\nhi");
	 }
	 pCurrent = *ppHead;
	 *ppHead = *ppTail;
	 *ppTail = pCurrent;
		 printf("\n%d",(*ppHead)->iData);
		 printf("\n%d",(*ppTail)->iData);

}



*/