#include <stdio.h>
/*
Q2. Write a menu driven program for Date in a CPP language using structure and also using class.
Date is having data members day, month, year. Implement the following functions.
void initDate();
void printDateOnConsole();
void acceptDateFromConsole();
bool isLeapYear();
*/
struct Date
{
    int day;
    int month;
    int year;
};

class D1

{
private:
    int day;
    int month;
    int year;
public:
   void setDate(int day,int month,int year)
   {
    this->day=day;
    this->month=month;
    this->year=year;
   }
   int getday()
   {
     
     return day;
   }
   int getmonth()
   {
   
     return month;
   }
   int getyear()
   {
     return year;
   }
};



void initDate(struct Date *ptrdate)
{
    ptrdate->day=1;
    ptrdate->month=2;
    ptrdate->year=12;
    /* data */
}



 

void acceptDate(struct Date *ptrDate)
{
    printf("Enter the Date");
    printf("\n");
    scanf("%d", &ptrDate->day);
    printf("\n");
    printf("Enter the month");
    printf("\n");
    scanf("%d", &ptrDate->month);
    printf("\n");
    printf("Enter the year");
    printf("\n");
    scanf("%d", &ptrDate->year);

}




void printDate(struct Date *ptrDate)
{
    printf("The Date is : %d--%d--%d",ptrDate->day, ptrDate->month, ptrDate->year);
}

bool isLeap(Date d1)
{
    int y=d1.year;
    if((y%400==0)&&(y%100!=0) || (y%4==0))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


int main()
{
    int x=1;
    struct Date date;

 while(x)
      {
         printf("\n 0-Exit" );
         printf("\n");
         printf("\n1-to initialize default value ");
         printf("\n");
         printf("\n 2-to insert  value ");
         printf("\n");
         printf("\n 3-Display date only");
         printf("\n");
         printf("\n 4-Check year is leap or NOT");
         printf("\n");
        
        scanf("%d",&x);
        if(x<=4 && x>=0)
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
             case 4 :
                    
                   // int y1=Date.ptrDate->year;

                   // printf("Pls Enter the year");
                    //int y;
                   // scanf("%d",&y);
                    if (isLeap(date))
                    {
                        printf("\n");
                        printf("Year is leap year");
                    }
                    else
                    {
                        printf("\n");
                        printf("Year IS NOT year");
                    }
                     break;       
           }
        }
        else
        
            printf("Pls Enter the vailid Option from menu");
        

    }

    printf("By Using Classe and Objects/n");
    D1 d1;

    printf("pls enter the day/n");
    int dd;
    scanf("%d",&dd);
    printf("pls enter the month/n");
    int mm;
    scanf("%d",&mm);
    printf("pls enter the year/n");
    int yy;
    scanf("%d",&yy);
//Setting Date Object Value
    d1.setDate(dd,mm,yy);

    dd=d1.getday();
    mm=d1.getmonth();
    yy=d1.getyear();
    printf("The DATE IS :%d--%d--%d",dd,mm,yy);

    
    
}
