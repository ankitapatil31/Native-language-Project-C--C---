/*
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void Display(struct node *, struct node *);
int CountNode(struct node *, struct node *);
int DeleteLast(struct node **, struct node **);
int DeleteFirst(struct node **, struct node **);
void DisplayReverse(struct node *,struct node *);
void DeleteAllNode(struct node **,struct node **);
void PhysicalReverse(struct node **,struct node **);
void InsertLast(struct node **, struct node **, int );
void InsertFirst(struct node **, struct node **, int );
int DeleteAtPosition(struct node **, struct node **, int );
int SearchAllOccurrence(struct node *, struct node *, int );
int SearchFirstOccurrence(struct node *, struct node *,int );
int SearchLastOccurrence(struct node *, struct node *, int );
void InsertAtPossition(struct node **, struct node **, int iPos, int );
void ConcateList(struct node **,struct node **,struct node **,struct node **);
void ConcateAtPosition(struct node **,struct node **,struct node **,struct node **,int );
int main()
{
    int iCase,iNo,iPos,iDel;
    char ch;
    struct node *pFirst = NULL;
    struct node *pLast = NULL;
    struct node *pFirst2 = NULL;
    struct node *pLast2 = NULL;
    while(1)
    {
        printf("\n****************************\n");
        printf("****Main Menu****");
        printf("\n****************************\n");
        printf("\n1 Insert\n2 Delete\n3 Search\n4 Count\n5 Concate\n6 Reverse\n7 Exit\n");
        printf("\nEnter Your Choice ");
        scanf("%d",&iCase);
        switch(iCase)
        {
            case 1:
                    do
                    {
                        printf("\n****************************\n");
                        printf("\n1 Insert First\n2 Insert Last\n3 Insert At Possition\n4 Back\n");
                        printf("****************************");
                        printf("\nEnter Your Choice:- ");
                        scanf("%d",&iCase);
                        switch(iCase)
                        {
                            case 1: 
                                    printf("\nEnter Data Which You Want To Insert in LinkList:- ");
                                    scanf("%d",&iNo);
                                    InsertFirst(&pFirst,&pLast,iNo);
                                    Display(pFirst,pLast);
                                      
                                    break;
                            case 2:
                                    printf("\nEnter Data Which You Want To Insert in LinkList:- ");
                                    scanf("%d",&iNo);
                                    InsertLast(&pFirst,&pLast,iNo); 
                                   
                                    Display(pFirst,pLast);
                                            
                                    break;
                            case 3:
                                    printf("\nEnter Position:-");
                                    scanf("%d",&iPos);
                                    // printf("%d",Count(pFirst,pLast));
                                    if(iPos>=1&&iPos<=CountNode(pFirst,pLast)+1)
                                    {
                                        printf("Enter the Date:-");
                                        scanf("%d",&iNo);
                                        InsertAtPossition(&pFirst,&pLast,iPos,iNo);
                                        Display(pFirst,pLast);
                                    }
                                    else
                                    {
                                        printf("\nInvalid Position\n");
                                    }
                                    break;
                            case 4:
                                 
                                    break;
                            default:
                                        printf("\nInvalid Input!!!\n");
                                    break;
                        }
                    }while(iCase != 4);
                    break;
            case 2:
                    if(NULL==pFirst)
                    {    
                        printf("\nLinkedList Is All Ready Empty\n");
                        break; 
                    } 
                    do
                    {
                        printf("****************************");
                        printf("\n1 Delete Frist\n2 Delete Last\n3 Delete At Possition\n4 Back\n");
                        printf("****************************");
                        printf("\nEnter Your Choice:- ");
                        scanf("%d",&iCase);
                        switch(iCase)
                        {
                            case 1:
                                    if(NULL==pFirst)
                                    {    
                                        printf("\nLinkedList Is All Ready Empty\n");
                                        break; 
                                    } 
                                    else
                                    {   
                                        iDel=DeleteFirst(&pFirst,&pLast);
                                        printf("\nDeleted Value is :- %d\n",iDel);
                                        Display(pFirst,pLast);
                                        break;
                                    }   
                            case 2:
                                    if(NULL==pFirst)
                                    {    
                                        printf("\nLinkedList Is All Ready Empty\n");
                                        break; 
                                    } 
                                    else
                                    {  
                                        iDel=DeleteLast(&pFirst,&pLast);
                                        printf("\nDeleted Value is :- %d\n",iDel);
                                        Display(pFirst,pLast);
                                        break;
                                    }    
                            case 3:
                                    if(NULL==pFirst)
                                    {    
                                        printf("\nLinkedList Is All Ready Empty\n");
                                        break; 
                                    } 
                                    printf("\nEnter Position:- ");
                                    scanf("%d",&iPos);

                                    if(iPos>=1&&iPos<=CountNode(pFirst,pLast))
                                    {
                                        iDel=DeleteAtPosition(&pFirst,&pLast,iPos);
                                        printf("\nDeleted value %d\n",iDel);
                                        Display(pFirst,pLast);
                                    }
                                    else
                                    {
                                        printf("\nInvalid Possition\n");
                                    }
                                    break;
                            case 4:
                                    break;
                            default:
                                    printf("\nInvalid Input!!!\n");
                                    break;
                        }
                    }while(iCase != 4);
          
                    break;
            case 3:
                    if(NULL==pFirst)
                    {    
                        printf("\nLinkedList Is All Ready Empty\n");
                        break; 
                    }             
                    do
                    {
                        printf("\n1 Search Frist Occourence\n2 Search Last Occourence\n3 Search All Occourence\n4 Back\n");
                        printf("\nEnter Your Choice:- ");
                        scanf("%d",&iCase);
                        switch(iCase)
                        {
                            case 1:
                                    printf("\nEnter a Key value for Search :- ");
                                    scanf("%d",&iNo);   
                                    iPos=SearchFirstOccurrence(pFirst,pLast,iNo);
                                    if(iPos==0)
                                        printf("\nKey Not Found In LinkedList\n");
                                    else
                                        printf("\nKey value found at %d positionin",iPos);
                                   
                                    Display(pFirst,pLast);
                                            
                                    break;
                            case 2:
                                    printf("\nEnter a Key value for Search :- ");
                                    scanf("%d",&iNo);   
                                    iPos=SearchLastOccurrence(pFirst,pLast,iNo);
                                    if(iPos==0)
                                        printf("\nKey Value Not Found In LinkedList\n");
                                    else
                                          printf("\nKey value found at %d positionin",iPos);
                                 
                                    Display(pFirst,pLast);
                                                        
                                    break;
                            case 3: 
                                    printf("\nEnter a Key value for Search :- ");
                                    scanf("%d",&iNo);   
                                    iPos=SearchAllOccurrence(pFirst,pLast,iNo);
                                    if(iPos==0)
                                        printf("Key Value Not Found In LinkedList");
                                    else
                                        printf("Possition of Key in LinkedList:- %d",iPos);
                                    Display(pFirst,pLast);
                 
                                    break;
                            case 4:
                                    break;
                            default:
                                    printf("\n Invalid Input!!!");
                                    break;
                        }
                    }while(iCase != 4);
                    break;
            case 4:
                    iNo=CountNode(pFirst,pLast);
                    printf("\nTotal Count Of LinkList :-%d\n\n",iNo);
                    printf("\nDisplay Of LinkedList:- \n");
                    Display(pFirst,pLast);
          
                    break;
            case 5:
					
					
                    if(NULL == pFirst2)
                    {
                        printf("Second LinkedList is Empty!!\nDo you want to add Data? ");
						printf("[ Note: \"If Yes,Enter Y||y\"]\n");
                        scanf(" %c",&ch);
                        if(ch == 'y'||ch == 'Y')
                        {
                            do
                            {
                                printf("\n1 Insert First\n2 Insert Last\n3 Insert At Possition\n4 Back\n");
                                printf("\nEnter Your Choice ");
                                scanf("%d",&iCase);
                                switch(iCase)
                                {
                                    case 1: 
                                        printf("\nEnter Data Which You Want To Insert in LinkList\n");
                                        scanf("%d",&iNo);
                                        InsertFirst(&pFirst2,&pLast2,iNo);
                                        printf("\nDisplay Second LinkedList:- \n");
                                        Display(pFirst2,pLast2);
                                   
                                        break;
                                    case 2:
                                        printf("\nEnter Data Which You Want To Insert in LinkList\n");
                                        scanf("%d",&iNo);
                                        InsertLast(&pFirst2,&pLast2,iNo); 
                                        printf("\nDisplay Second LinkedList:- \n");
                                        Display(pFirst2,pLast2);
                                    //printf("\ninsert successfully\n");              
                                    break;
                                    case 3:
                                        printf("\nEnter Position \n");
                                        scanf("%d",&iPos);
                                    // printf("%d",Count(pFirst,pLast));
                                        if(iPos>=1&&iPos<=CountNode(pFirst,pLast)+1)
                                        {
                                            printf("Enter the Date");
                                            scanf("%d",&iNo);
                                            InsertAtPossition(&pFirst2,&pLast2,iPos,iNo);
                                            printf("\nDisplay Second LinkedList:- \n");
                                            Display(pFirst2,pLast2);
                                        }
                                        else
											printf("\nEnter valid Possition");
                                        
                                        break;
                                    case 4:
                                         ch='0';
                                        break;
                                    default:
                                        printf("\nInvalid Input!!!");
                                    break;
                                }
                            }while(ch != '0');
                            
                        }
                    }
					do
					{
						printf("\n1 Concate List \n2 Concate At Position\n3 Back\n");
						printf("\nEnter Your Choice :-");
						scanf("%d",&iCase);
						switch(iCase)
						{
							case 1:
									ConcateList(&pFirst,&pLast,&pFirst2,&pLast2);
									Display(pFirst,pLast);
									break;
							case 2:
                                
									iNo = CountNode(pFirst,pLast);
									printf("\nEnter Your poSition:- \t");
									scanf("%d",&iPos);
            
									if(iPos>=1&&iPos<=CountNode(pFirst,pLast)+1)
									{             
										ConcateAtPosition(&pFirst,&pLast,&pFirst2,&pLast2,iPos);
										Display(pFirst,pLast);
										break;
									}
									else
										printf("\nInvalid Position\n");
                               
									break;
							case 3: 
									break;
							default:
									printf("\nInvalid Input!!!!\n");
						}
					}while(iCase != 3);
                    break;
            case 6:
                    if(pFirst == NULL)
                        break;
                    do
                    {
                        printf("\n1 Dispaly Reverse \n2 Physical Reverse\n3 Back\n");
                        printf("Enter Your Choice :- ");
                        scanf("%d",&iCase);
                        switch(iCase)
                        {
                            case 1:    
                                DisplayReverse(pFirst,pLast);
                                break;
                            case 2:
                                PhysicalReverse(&pFirst,&pLast);
                                Display(pFirst,pLast);
                                break;
                            case 3:
                                break;
                            default:
                                printf("\nInvalid Input\n");
                                break;
                        }
                    }while(iCase != 3);
                    break;
            case 7:
                    printf("\nDo You Really Want To Exit?\n");
                    printf("[ Note: \"If Yes,Enter Y||y\"]\n");
                    scanf("%d");
                    scanf("%c",&ch);
                    if(ch=='y'||ch=='Y')
                    {
                        DeleteAllNode(&pFirst,&pLast);
                        exit(0);
                    }               
                    break;
            default:
                    printf("Invalid Input!!!");
                    break;
        }
    }
	if(pFirst != NULL)
		DeleteAllNode(&pFirst,&pLast);
    return 0;
}
void InsertFirst(struct node **ppHead, struct node **ppLast, int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("memory allocation fail");
        return;
    }
    pNewNode->iData = iNo;
    
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
    pNewNode = NULL;
    return;
}

int DeleteFirst(struct node **ppHead, struct node **ppLast)
{
   
    int iDel; 
    if(NULL == (*ppHead))
    {
        return 0;
    }
    iDel = (*ppHead)->iData;
    if((*ppHead) == (*ppLast))
    {
        (*ppHead)->pPrev = NULL;
        (*ppHead)->pNext = NULL;
        free(*ppHead);
        (*ppHead) = NULL;
        (*ppLast) = NULL;
        
        return iDel;
    }
    else
    {
        (*ppLast)->pNext = (*ppHead)->pNext;
        (*ppHead)->pNext->pPrev = (*ppLast);
        (*ppHead)->pPrev = NULL;
        (*ppHead)->pNext = NULL;
        free(*ppHead);
        (*ppHead) = (*ppLast)->pNext;
        return iDel;
    }
}

int DeleteLast(struct node **ppHead, struct node **ppLast)
{
    int iDel;
    if(NULL == *ppHead)
    {
        return -1;
    }
    iDel = (*ppLast)->iData;
    if((*ppHead) == (*ppLast))
    {
        (*ppHead)->pPrev = NULL;
        (*ppHead)->pNext = NULL;
        free(*ppHead);
        (*ppHead) = NULL;
        (*ppLast) = NULL;
      
        return iDel;
    }
    else
    {
        *ppLast = (*ppLast)->pPrev;
        (*ppLast)->pNext->pPrev = NULL;
        (*ppLast)->pNext->pNext = NULL;
        free((*ppLast)->pNext);
        (*ppLast)->pNext = *ppHead;
        (*ppHead)->pPrev = *ppLast;
        return iDel;
    }
}

void InsertLast(struct node **ppHead, struct node **ppLast, int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(NULL == pNewNode)
    {
        printf("memory allocation fail");
        return;
    }
    pNewNode->iData = iNo;
    if(NULL == (*ppHead))
    {
        *ppHead = pNewNode;
        *ppLast = pNewNode;
    }
    else
    {
        pNewNode->pPrev = (*ppLast);
        (*ppLast)->pNext = pNewNode;
        (*ppLast) = pNewNode;
    }
    pNewNode->pNext = (*ppHead);
    (*ppHead)->pPrev = (*ppLast);
    pNewNode = NULL;
    return;
}

void Display(struct node *pHead, struct node *pLast)
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

void InsertAtPossition(struct node **ppHead, struct node **ppLast, int iPos, int iNo)
{   
    if(iPos <= 1)
    {
        InsertFirst(ppHead,ppLast,iNo);
        return;
    }
    else if(iPos == CountNode((*ppHead),(*ppLast))+1)
    {
        InsertLast(ppHead,ppLast,iNo);
        return;
    }
    else
    {
        
        struct node *pNewNode = NULL;
        struct node *pTemp = NULL;
        int iCount;
        pNewNode = (struct node*)malloc(sizeof(struct node));

        if(NULL == pNewNode)
        {
        
            printf("memory allocation fail");
            return;
        }
        pNewNode->iData = iNo;
        pTemp = (*ppHead);
        iCount = 1;
        while(iCount != iPos-1)
        {
            iCount++;
            pTemp = pTemp->pNext;
        }
        pNewNode->pNext = pTemp->pNext;
        pNewNode->pNext->pPrev = pNewNode;
        pNewNode->pPrev = pTemp;
        pTemp->pNext = pNewNode;
        pNewNode = NULL;
		pTemp = NULL;
        return;
    }
}

int DeleteAtPosition(struct node **ppHead, struct node **ppLast, int iPos)
{   
    int iDel;
    if(iPos <= 1)
    {
        return DeleteFirst(ppHead,ppLast); 
    }
    else if(iPos==CountNode((*ppHead),(*ppLast)))
    {
        return DeleteLast(ppHead,ppLast);
    }
    else
    {  
        struct node *pTemp = NULL;
        int iCount,iDel;
        pTemp = (*ppHead);
        iCount = 1;
      
        while(iCount != iPos)
        {
            iCount++;
            pTemp = pTemp->pNext;
        }
       
        pTemp->pPrev->pNext = pTemp->pNext;
        pTemp->pNext->pPrev = pTemp->pPrev;
        pTemp->pNext = NULL;
        pTemp->pPrev = NULL;
        iDel = pTemp->iData;
        free(pTemp);
        pTemp = NULL;
        return iDel;
    }
}

int CountNode(struct node *pHead, struct node *pLast)
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

int SearchFirstOccurrence(struct node *pHead, struct node *pLast, int iKey)
{
    int iCount = 1;
    if(pHead == NULL)
        return 0;
    do
    {
        if(iKey == pHead->iData)
            break;
        iCount++;
        pHead = pHead->pNext;
    }while(pLast->pNext != pHead);
    
    pHead = pLast = NULL;    
    return iCount;
}

int SearchLastOccurrence(struct node *pHead, struct node *pLast, int iKey)
{
            int iCount = 0,iPos = 0;
            if(pHead == NULL)
                return 0;
            do
            {
                iCount++;
                if(iKey == pHead->iData)
                    iPos = iCount;
                
                pHead = pHead->pNext;
            }while(pLast->pNext != pHead);
            
            pHead = pLast = NULL;
                return iPos;   
}

int SearchAllOccurrence(struct node *pHead, struct node *pLast, int iKey)
{
    int iCount = 0;
        do
        {
            if(iKey == pHead->iData)
                iCount++;  
            pHead = pHead->pNext;
        }while(pLast->pNext!= pHead);
        
        if(pHead == pLast)
            return 0;
        else
            return iCount;
}
void ConcateList(struct node **ppHead1,
        struct node **ppLast1,
        struct node **ppHead2,
        struct node **ppLast2)
{
  
    if(NULL == *ppHead1 && NULL == *ppHead2)
    {
        printf("\nLinkedList is Empty\n");
        return;
    }
    else if(NULL == *ppHead2)
    {
        return;
    }
    else if(NULL == *ppHead1)
    {
        *ppHead1 = *ppHead2;
        *ppLast1 = *ppLast2;
        *ppHead2 = *ppLast2 = NULL;
    }
    else
    {
        (*ppLast1)->pNext = *ppHead2;
        (*ppHead2)->pPrev = *ppLast1;
        (*ppLast2)->pNext = *ppHead1;
        (*ppHead1)->pPrev = *ppLast2;
        *ppLast1 = *ppLast2;
        *ppLast2 = *ppHead2 = NULL;
    }
}

void ConcateAtPosition(struct node **ppHead1,
        struct node **ppLast1,
        struct node **ppHead2,
        struct node **ppLast2,
        int iPos)
{
    int iCount;
    struct node *pTemp1 = NULL;
    if(NULL == *ppHead2)
    {
        return;
    }
    else if(1 == iPos)
    {
        ConcateList(ppHead2,ppLast2,ppHead1,ppLast1);
        *ppHead1 = *ppHead2;
        *ppLast1 = *ppLast2;
        *ppHead2 = *ppLast2 = NULL;
    }
    /*else if(iPos ==  CountNode(*ppHead1,*ppTail1)+1)
    {
        ConcateList(ppHead1,ppTail1,ppHead2,ppTail2);
    }*/
 /*   else
    {
        pTemp1 = *ppHead1;
        iCount = 1;
        while(iCount != iPos-1)
        {
            iCount++;
            pTemp1 = pTemp1->pNext;
        }
        iCount = CountNode(*ppHead1,*ppLast1);
        (*ppLast2)->pNext = pTemp1->pNext;
        pTemp1->pNext->pPrev = *ppLast2;
        
        pTemp1->pNext = *ppHead2;
        (*ppHead2)->pPrev = pTemp1;
         
        if(iPos == iCount+1)
        {
            *ppLast1 = *ppLast2;
        }
        *ppLast2 = *ppHead2 = NULL;
        pTemp1 = NULL;
    }
}
void DisplayReverse(struct node *pHead, struct node *pLast)
{
    do
    {
        printf("<-|%d|->",pLast->iData);
        pLast = pLast->pPrev;
    }while(pLast != pHead->pPrev);
}
void PhysicalReverse(struct node **ppHead,struct node **ppTail)
{
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;
    while(pNext != *ppHead)
    {
        pNext = pCurrent->pNext;
        pCurrent->pNext = pCurrent->pPrev;
        pCurrent->pPrev = pNext;
        pCurrent = pNext;
    }
    *ppTail=*ppHead;
    *ppHead = pCurrent->pNext;
	pCurrent = pNext = NULL;
}
void DeleteAllNode(struct node **ppHead,struct node **ppLast)
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
    return;
}
*/