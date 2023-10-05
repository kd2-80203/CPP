#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->day = month;
        this->year = year;
    }

    void setDay(int day)
    {
        this->day = day;
    }

    void setMonth(int month)
    {
        this->month = month;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    int getDay()
    {
        return this->day;
    }

    int getMonth()
    {
        return this->month;
    }

    int getYear()
    {
        return this->year;
    }

    void acceptDate()
    {
        cout << "Enter the day = " << endl;
        cin >> this->day;
        cout << "Enter the Month = " << endl;
        cin >> this->month;
        cout << "Enter the Year = " << endl;
        cin >> this->year;
    }

    void displayDate()
    {
        cout << this->day << "/" << this->month << "/" << this->year << endl;
    }
};

class Person
{
private:
    string name;
    string address;
    Date dob;

public:
    Person()
    {
    }

    Person(string name, string address, int day, int month, int year) : dob(day, month, year)
    {
        this->name = name;
        this->address = address;
    }

    void setName(string name)
    {
        this->name = name;
    }
    void setAddress(string address)
    {
        this->address = address;
    }
    void setBirthDate(int day, int month, int year)
    {
        Date(day, month, year);
    }
    string getName()
    {
        return this->name;
    }

    string getAddress()
    {
         return this->address;
    }
    Date getBirthDate()
    {
        return dob;
    }

     void accept()
    {
        cout << "Enter name = ";
        cin >> this->name;
        cout << "Enter Address = ";
        cin >> this->address;
        cout << "Enter Date Of Birth is : ";
        dob.acceptDate();
    }


    void display()
    {
        cout << "Name = ";
        cout << this->name << endl;
        cout << "Address = ";
        cout << this->address << endl;
        cout << "Date of Birth is :";
        dob.displayDate();
    }
};

class Employee : public Person
{

    int id;
    float salary;
    string department;
    Date joing_date;

public:
    Employee()
    {
    }
    Employee(string name, string address, int day, int month, int year, int id, float salary, string department, int d, int m, int y):joing_date(d, m, y)
    {
        this->setName(name);
        this->setAddress(address);
        this->setBirthDate(day, month, year);
        this->id = id;
        this->salary = salary;
        this->department = department;
    }

    void setId(int id)
    {
        this->id = id;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }

    void setDepartment(string department)
    {
        this->department = department;
    }

    void setDateOfJoining(int day, int month, int year)
    {
        Date(day, month, year);
    }

    int getId()
    {
        return this->id;
    }
    float getSalary()
    {
        return this->salary;
    }
    string getDepartment()
    {
        return this->department;
    }
    Date getJoinDate()
    {
        return this->joing_date;
    }

    void accept()
    {
        Person::accept();
        cout << "Pls Enter Your Employee-ID" << endl;
        cin >> this->id;
        cout << "Pls Enter Your Salary" << endl;
        cin >> this->salary;
        cout << "Pls Enter Your Department" << endl;
        cin >> this->department;
        cout << "Pls Enter Your Date of Joing" << endl;
        joing_date.acceptDate();
    }

    void display()
    {
        Person::display();
        cout << "Employee-ID = ";
        cout << this->id << endl;
        cout << "Employee Salary is = ";
        cout << this->salary << endl;
        cout << "Employee Department is = ";
        cout<< this->department << endl;
        cout << "Joing Date is = ";
        joing_date.displayDate();
    }
};

int main()
{
    Employee emlpoyee;

    // emlpoyee.accept();
    // cout << "*********************************" << endl;
    // emlpoyee.display();

    Person *pter=new Employee();
    // pter->accept();

    
    Employee *epter=(Employee *)pter;
    epter->accept();



    // Person p;
    // p.accept();
    // p.display();
}
