#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define Max   5
int InsertFirst(struct Node **,int );
int InsertLast(struct Node ** ,int );
void Display(struct Node *, struct Node *);
int CountNode(struct Node *, struct Node *);
int DeleteLast(struct Node *,struct Node *);
int DeleteFirst(struct Node *,struct Node *);
void MakeList(struct Node **,struct Node **,int);
int isDataExits(struct Node *,struct Node *,int);
void DeleteAllNode(struct Node **,struct Node **);
int DeleteAtPosition(struct Node **,struct Node **,int);
int InsertAtPosition(struct Node **,struct Node **,int,int);

struct Node
{
	struct Node *pPrev;
	int iData;
	struct Node *pNext; 
};
int main()
{
	int iCount = 5;
	int iData,iPos,iDelData;
	//printf("Enter the count for LinkedList:\t");
	//scanf_s("&d",iCount);
	struct Node *pFirst = NULL;
	struct Node *pLast = NULL;
	MakeList(&pFirst,&pLast,iCount);
	Display(pFirst,pLast);
	do
	{
		printf("\n\n\n1 Insert \n2 Delete \n3 Exit \n\n");
		printf("Enter Your Choice :-\t");
		scanf_s("%d",&iData);
		switch(iData)
		{
			case 1:

					printf("Enter Data: \t");
					scanf_s("%d",&iData);
					InsertFirst(&pFirst,iData);		
					Display(pFirst,pLast);
					break;
			case 2:
					printf("Enter The Position :-\t");
					scanf("%d",&iPos);
					if(iPos >= 0 && iPos < CountNode(pFirst,pLast))
					{

						iDelData = DeleteAtPosition(&pFirst,&pLast,iPos);
						if(iDelData != 0)
							printf("Deleted Data is %d",iDelData);
						else
							printf("All Ready Deleted\n");
					}
					else
						printf("Invalid Position!!!");

					Display(pFirst,pLast);
					break;
					
			case 3:
					DeleteAllNode(&pFirst,&pLast);
					break;
			default:
					printf("Invalid Choice!!!!");
					break;
		}

	}while(iData != 3);

	 _getch();
	 return 0;
}
void MakeList(struct Node **ppHead,struct Node **ppLast,int iCount)
{
	int iCounter;
	struct Node *pNewNode = NULL;
	for(iCounter = 0; iCounter < iCount; iCounter++)
	{
		pNewNode = (struct Node *)malloc(sizeof(struct Node));
		if(NULL == pNewNode)
		{
			printf("Memory allocation fails\n");
			return;
		}
		pNewNode->iData = 0;
		if(NULL == (*ppHead))
		{
			*ppHead = pNewNode;
			*ppLast = pNewNode;
		}
		else
		{
			pNewNode->pNext = (*ppHead);
			(*ppHead)->pPrev = pNewNode;
			(*ppHead) = pNewNode;
		}
		pNewNode->pPrev = (*ppLast);
		(*ppLast)->pNext = pNewNode;
		
	}
	pNewNode = NULL;
}
void Display(struct Node *pHead, struct Node *pLast)
{    
    if(NULL == pHead)
    {
        printf("LinkedList is Empty");
        return;
    }
    printf("\n****Display LinkedList****\n");
    do
    {
        printf("<-|%d|->",pHead->iData);
        pHead = pHead->pNext;
    }while(pLast->pNext != pHead);           
    pHead = pLast = NULL;
}
int InsertFirst(struct Node **ppHead,int iData)
{
	static int iCount = 0;
	struct Node *pTemp = (*ppHead);
	int iCounter = 0;
	while(iCounter != iCount)
	{
		iCounter++;
		pTemp = pTemp->pNext;
	}
	if(pTemp->iData == 0)
	{
		pTemp->iData = iData;
		iCount++;
		return 1;
	}
	else
		printf("Linked List Full\n");
	return 0;
}

int CountNode(struct Node *pHead, struct Node *pLast)
{
	int iCount=0;
    if(pHead == NULL)
        return 0;
    do
    {
        iCount++;
        pHead = pHead->pNext;
    }while(pLast->pNext != pHead);
    
    pHead = pLast = NULL;       
    return iCount;
}

int DeleteAtPosition(struct Node **ppHead,struct Node **ppLast,int iPos)
{
	int iCount=1;

	struct Node *pTemp = (*ppHead);

	if(iPos <= 1 && iPos >= CountNode(*ppHead,*ppLast))
		return 0;

	while(iCount<iPos)
	{
		pTemp = pTemp->pNext;
		iCount++;
	}
	iCount = 0;
	if(pTemp->iData != 0)
	{
		iCount = pTemp->iData;
		pTemp->iData = 0;
		pTemp = NULL;
	}
	return iCount;
}
void DeleteAllNode(struct Node **ppHead,struct Node **ppLast)
{ 

    if(NULL == *ppHead)
        return;
       
    while(*ppHead != *ppLast)
    {
       (*ppHead)->pNext->pPrev = (*ppLast);
       (*ppLast)->pNext = (*ppHead)->pNext;
       (*ppHead)->pNext = NULL;
       (*ppLast)->pPrev = NULL;
       free(*ppHead);
       (*ppHead) = (*ppLast)->pNext;
    }
    (*ppHead)->pNext = NULL;
    (*ppLast)->pPrev = NULL;
    free(*ppHead);
    *ppHead = NULL;
    *ppLast = NULL;
	printf("Succefully Delete All Node!!!!\n ");
    return;
}