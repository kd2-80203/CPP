#include <stdio.h>
/*
Write a menu driven program for Date in a C. Declare a structure Date having data members
day, month, year. Implement the following functions.
void initDate(struct Date* ptrDate);
void printDateOnConsole(struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate);
*/
struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrdate)
{
    ptrdate->day=1;
    ptrdate->month=2;
    ptrdate->year=12;
    /* data */
};



 

void acceptDate(struct Date *ptrDate)
{
    printf("Enter the Date");
    scanf("%d", &ptrDate->day);
    printf("Enter the month");
    scanf("%d", &ptrDate->month);
    printf("Enter the year");
    scanf("%d", &ptrDate->year);
}




void printDate(struct Date *ptrDate)
{
    printf("The Date is : %d--%d--%d",ptrDate->day, ptrDate->month, ptrDate->year);
}




int main()
{
    int x=1;
    struct Date date;

 while(x)
      {
         printf("\n 0-Exit" );
        printf("\n1-to initialize default value ");
        printf("\n 2-to insert  value ");
        printf("\n 3-Display date only");
        
        scanf("%d",&x);
        if(x<=3 && x>=0)
        {
         switch(x)
         {
            case 1:
                     initDate(&date);
                     printDate(&date);
                     break;
             case 2:
                    acceptDate(&date);
                    printDate(&date);
                    break;
             case 3 :
                     printDate(&date);
                     break;       
                  
           }
        }
        else
        
            printf("Pls Enter the vailid Option from menu");
        

    }
}
