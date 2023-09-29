/* Q1. Implement following classes. Test all functionalities in main().Insted of char[] use string
datatype */

#include<iostream>
using namespace std;

class Date
{
    public:
    int day;
    int month;
    int year;

    public:
    Date()
    {
        this->day=0;
        this->month=0;
        this->year=0;

    }

    Date(int day,int month,int year)
    {
      this->day=day;
      this->day=month;
      this->year=year;
    }

     void acceptDate()
    {
        cout << "Enter the day = "<<endl;
        cin>>this->day;
        cout << "Enter the Month = "<<endl;
        cin>>this->month;
        cout << "Enter the Year = "<<endl;
        cin>>this->year;

    }

     void displayDate()
    {
     cout<<this->day<<"/"<<this->month<<"/"<<this->year<<endl;
    }

};

class Person
{
    public:
    string name;
    string address;
    Date dob;

    public:
    Person()
    {

    }
    
    Person(string name,string address,int day,int month,int year) : dob(day,month,year)
    {
        this->name = name;
        this->address = address;
    }

    void PersonalDetails()
    {
        cout << "Enter name = ";
        cin >> this->name;
        cout << "Enter Address = ";
        cin >> this->address;
        cout << "Enter Date Of Birth is : ";
        dob.acceptDate();

    }

    void displayPerson()
    {
        cout << "Name = " << this->name << endl;
        cout << "Address = " << this->address<< endl;
        cout<<"Date of Birth is :";
        dob.displayDate();
    }


};


class Employee
{
    public:
    int id;
    float salary;
    string department;
    Person person;
    Date jdate;

    public:
    Employee()
    {

    }

    Employee(int id,float salary,string department,string name,string address,int day,int month,int year,int d,int m, int y ) :person(name,address,day,month,year),jdate(d,m,y)
    {
     
        this->id=id;
        this->salary=salary;
        this->department=department;
    }

    void EmployeeDetails()
    {
        person.PersonalDetails();
        cout << "Enter empid = ";
        cin >> this->id;
        cout << "Enter your Salary = ";
        cin >> this->salary;
        cout << "Enter Department = ";
        cin >> this->department;
        cout << "Enter Date Of joining = " << endl;
        jdate.acceptDate();
    }

    void displayEmployee()
    {
        person.displayPerson();
        cout << "Employee-ID = " << this->id<< endl;
        cout << "Department = " << this->department << endl;
        cout << "Salary = " << this->salary << endl;
        cout << "Date Of joining = ";
        jdate.displayDate();
    }


};

int main()
{

    Employee e1;

    e1.EmployeeDetails();
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    e1.displayEmployee();
 

    return 0;
}



