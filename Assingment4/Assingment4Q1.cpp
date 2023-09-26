/*Assignment 4
Q1. Write a class for Time and provide the functionality
Time()
Time(int h,int m,int s)
getHour()
getMinute()
getSeconds()
printTime()
setHour()
setMinute()
setSeconds()
In main create array of objects of Time.
Allocate the memory for the array and the object dynamically.
 */

#include<iostream>
using namespace std;
class Time
{
    private:
    int h;
    int m;
    int s;

public:
Time()
{

}
Time(int h,int m,int s)
{
    this->h=h;
    this->m=m;
    this->s=s;
}
int getHour()
{
     return this->h;
}
int getMinute()
{
    return this->m;

}
int getSeconds()
{
    return this->s;

}
void printTime()
{
    cout<<"TIME IS --- "<<this->h<<" : "<<this->m<<" : "<<this->s<<endl;
}
void setHour(int h)
{
    this->h=h;
}
void setMinute(int m)
{
    this->m=m;
}
void setSeconds(int s)
{
    this->s=s;
}
};

int main()
{
//  Dynamic Array declaration  
    Time  **arr=new Time *[5];

// Array allocation to objects
    for(int i=0;i<5;i++)
    {
        arr[i]=new Time();
    }
// Adding information in objects
    for (int i = 0; i < 5; i++)
    {
        int h,m,s;
        cout << "Enter the values for hours"<< endl;
        cin>>h;
        arr[i]->setHour(h);
        cout << "Enter the values for minutes"<< endl;
        cin>>m;
        arr[i]->setMinute(m);
        cout << "Enter the values for seconds"<< endl;
        cin>>s;
        arr[i]->setSeconds(s);
    }

    for(int i=0;i<5;i++)
    {
        arr[i]->printTime();
    }

    /// deallocating the objects memory
    for (int i = 0; i < 5; i++)
        delete arr[i];

    delete[] arr;
    
    return 0;
}