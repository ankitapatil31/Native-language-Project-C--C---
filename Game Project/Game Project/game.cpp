#include<iostream>
using namespace std;
char arr[9]={' '};
int iCounter1,iCounter2;
int User(char *);
void display();
int main()
{
	
	int iTemp;
	char chChar;
	if(User(&chChar))
		cout<<"win\n";
	else
		cout<<"\fail";
	cin>>iTemp;
	cin.get();
	return 0;
}
void display()
{
	 printf("\n\n");
        printf("\t\t\t  %c | %c  | %c  \n", arr[0], arr[1], arr[2]);
        printf("\t\t\t----+----+----\n");
        printf("\t\t\t  %c | %c  | %c  \n", arr[3], arr[4], arr[5]);
        printf("\t\t\t----+----+---\n");
        printf("\t\t\t  %c | %c  | %c  \n\n", arr[6], arr[7], arr[8]);
}
int User(char * chChar)
{
		int iPos,iCount = 0;
		while(iCount <= 8)
		{
			
			User1:
			cout<<"user 1 :  enter position :- \t"<<endl;
			cin>>iPos;
			if(arr[iPos - 1] == 'X' || arr[iPos-1] == 'Y')
			{
				printf("all ready occupied\n");
				goto User1;
			}
			else 
			{
				iCount++;
				arr[iPos-1] = 'X';
				
			}
			display();
			if(iCount == 9)
				break;
			iPos = 0;
			User2:
			cout<<"user 2 : enter position :- \t"<<endl;
			cin>>iPos;
			if(arr[iPos-1] == 'X' || arr[iPos-1] == 'Y')
			{
				printf("all ready occupied\n");
				goto User2;
			}
			else 
			{
				iCount++;
				arr[iPos-1] = 'Y';	
			}
		
			display();
			if(iCount == 9)
				break;
			printf("iCount %d",iCount);
			
			
		}
		if(arr[0]==arr[1]==arr[2] || arr[3]==arr[4]==arr[5] || arr[6]==arr[7]==arr[8] || arr[0]==arr[3]==arr[7] || arr[1]==arr[5]==arr[8] || arr[2]==arr[6]==arr[9] || arr[0]==arr[5]==arr[9] || arr[2]==arr[5]==arr[7])
		{
			return 1;
		}
		else 
			return 0;
}



/*

#include <stdio.h>
  int main() {
        int winner = 0, count = 0;
        int arr[9], index, sign, player, flag, i, k, j;

        for (i = 0; i < 9; i++)
                arr[i] = ' ';

        while (count < 9) {
                flag = 0;
                system("clear");
                printf("\n\n");
                printf("\t\t\t  %c | %c  | %c  \n", arr[0], arr[1], arr[2]);
                printf("\t\t\t----+----+----\n");
                printf("\t\t\t  %c | %c  | %c  \n", arr[3], arr[4], arr[5]);
                printf("\t\t\t----+----+---\n");
                printf("\t\t\t  %c | %c  | %c  \n", arr[6], arr[7], arr[8]);
                if (count % 2 == 0) {
                        sign = 'X';
                        player = 1;
                } else {
                        sign = 'Y';
                        player = 2;
                }
                printf("Move for player%d(1-9):", player);
                scanf("%d", &index);
                if (index < 1 || index > 9) {
                        printf("Allowed index is 1 to 9!!\n");
                        continue;
                }
                if (arr[index - 1] == 'X' || arr[index - 1] == 'Y') {
                        printf("Position Already occupied!!\n");
                        sleep(1);
                        continue;
                }
                arr[index - 1] = sign;
                count++;

                for (i = 0; i < 9; i++) {
                        if (i % 3 == 0)
                                flag = 0;

                        if (arr[i] == sign)
                                flag++;

                        if (flag == 3) {
                                winner = 1;
                                goto win;
                        }
                }

                flag = 0;
                for (i = 0; i < 3; i++) {
                        for (k = i; k <= i + 6; k = k + 3) {
                                if (arr[k] == sign)
                                        flag++;
                        }
                        if (flag == 3) {
                                winner = 1;
                                goto win;
                        }
                        flag = 0;
                }
                if ((arr[0] == sign && arr[4] == sign && arr[8] == sign) ||
                        (arr[2] == sign && arr[4] == sign && arr[6] ==  sign)) {
                        winner = 1;
                        goto win;
                }
        }
  win:
        system("clear");
        printf("\n\n");
        printf("\t\t\t  %c | %c  | %c  \n", arr[0], arr[1], arr[2]);
        printf("\t\t\t----+----+----\n");
        printf("\t\t\t  %c | %c  | %c  \n", arr[3], arr[4], arr[5]);
        printf("\t\t\t----+----+---\n");
        printf("\t\t\t  %c | %c  | %c  \n\n", arr[6], arr[7], arr[8]);
        if (winner) {
                printf("Player %d is the winner. Congrats!!\n", player);
        } else {
                printf("Match draw.. Best of luck for both\n");
        }
        return 0;
  }

  */