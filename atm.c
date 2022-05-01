#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int atm();
int main()
{
    atm();
    return 0;
}
int balance=10000,pin=1234;

int atm()
{
    int withdraw,c,deposit,p;
    char t,s;
    system("cls");
    printf("Enter your secret pin\n");
    scanf("%d",&p);
    if(p!=pin)
    {
        printf("Incorrect pin\n");
        atm();
    }
    printf("1. To check balance\n");
    printf("2. To deposit cash\n");
    printf("3. To withdraw cash\n");
    printf("4. To change pin\n");
    printf("\nEnter your choice\n");
    scanf("%d",&c);
    system("cls");
    switch(c)
    {
        case 1:
            printf("Your current balance is %d\n",balance);
            break;
        case 2:
            printf("Enter the amount you want to deposit\n");
            scanf("%d",&deposit);
            balance+=deposit;
            printf("Your current balance is %d\n",balance);
            break;
        case 3:
            printf("Enter the amount you want to withdraw\n");
            scanf("%d",&withdraw);
            if(withdraw>balance)
            {
                printf("Insufficient balance\n");
                printf("Your current balance is %d\n",balance);
            }
            else{
                if(withdraw%500!=0)
                {
                    printf("Withdrawn amount should be divisible by 500\n");
                }
                else{
                    printf("Collect your cash\n");
                    balance-=withdraw;
                    printf("Do you want slip (y,n)\n");
                    scanf(" %c",&s);
                    if(s=='y' || s=='Y')
                    {
                        printf("Collect you slip\n");
                    }
                    else{
                        printf("You saved a tree\n");
                    }
                    printf("Your current balance is %d\n",balance);
                }
            }
            break;
        case 4:
            pin:
            printf("Enter your current pin\n");
            scanf("%d",&p);
            if(p!=pin)
            {
                printf("Incorrect pin\n");
                goto pin;
            }
            else{
                printf("Enter new pin\n");
                scanf("%d",&p);
                if(p>=1000 && p<=9999)
                {
                    pin=p;
                    printf("Pin successfully changed\n");
                }
                else{
                    printf("Pin should be of 4 digit only\n");
                    pin;
                }
            }
            break;
        default:   
            printf("Incorrect choice\n");
            atm();
    }

    printf("Do you want to do another transaction (y/n)\n");
    scanf(" %c",&t);
    if(t=='y' || t=='Y')
    {
        atm();

    }
    else{
        printf("Thanks for choosing atm service\n");
    }
    return 0;
}
