/*
Q2. Implement following classes. Test all functionalities in main() of each created class. Note that
employee is inherited into manager and salesman. Insted of char[] use string datatype.
*/

#include<iostream>
using namespace std;

class Employee
{
    protected:
    int empid;
    float salary;

    public:
    Employee()
    {
        this->empid=0;
        this->salary=0;
    }
    
    Employee(int empid,float salary)
    {
        this->empid=empid;
        this->salary=salary;
    }

    void set_empid(int empid)
    {
        this->empid=empid;
    }

    void set_salary(int salary)
    {
        this->salary=salary;
    }

    int get_empid()
    {
       return this->empid;
    }

    int get_salary()
    {
        return this->salary;
    }
    
    void accept()
    {
        cout<<"Enter the Emp-ID : "<<endl;
        cin>>this->empid;
        cout<<"Enter The Your Salary : "<<endl;
        cin>>this->salary;
    }
    void display()
    {
        cout<<"Emp-ID is = "<<this->empid<<endl;
        cout<<"Your Salary is = "<<this->salary<<endl;
    }



};

class Salesman:virtual public Employee
{
    protected:
    float commission;

    public:
    Salesman()
    {
      this->commission=0;
    }

    Salesman(int empid,int salary,float commission)
    {
        Employee::set_empid(empid);
        Employee::set_salary(salary);
        this->commission=commission;
    }
    
    void set_Commission(float commission)
    {
        this->commission=commission;
    }

    float get_Commission()
    {
        return this->commission;
    }
    
    void accept()
    {
        Employee::accept();
         cout<<"Enter your commission : "<<endl;
        cin>>this->commission;
      
    }

    void display()
    {
        Employee::display();
        cout<<"Commission is : "<<this->commission<<endl;
    }

    protected:
    void acceptSalesMan()
    {
        cout<<"Enter your commission : "<<endl;
        cin>>this->commission;
    }

     void displayManager()
    {
        cout<<"Commission is : "<<this->commission<<endl;
    }

};

class Manager:virtual public Employee
{
    protected:
    float bonus;

    public:
    Manager()
    {
        this->bonus=0;
    }

    Manager(int empid,float salary,float bonus)
    {
       Employee::set_empid(empid);
       Employee::set_salary(salary);
       this->bonus=bonus;
    }
    
    void set_Bonus(float bonus)
    {
        this->bonus=bonus;
    }

    float get_Bonus()
    {
        return this->bonus;
    }

    void accept()
    {
        Employee::accept();
         cout<<"Enter your Bonus : "<<endl;
         cin>>this->bonus;
       
    }



    void display()
    {
        Employee::display();
        cout<<"Bonus is : "<<this->bonus<<endl;
    }

    protected:
    void  acceptManager()
    {
         cout<<"Enter your Bonus : "<<endl;
         cin>>this->bonus;
    }

    void displayManager()
    {
        cout<<"Bonus is : "<<this->bonus<<endl;
    }



};

class Sales_Manager:public Manager,public Salesman
{
    public:
    Sales_Manager()
    {

    }

    Sales_Manager(int empid,float salary,float commission,float bonus)
    {
       Employee::set_empid(empid);
       Employee::set_salary(salary);
       Salesman::set_Commission(commission);
       Manager::set_Bonus(bonus);
    }
    void accept()
    {
       Employee::accept();
       Manager::acceptManager();
       Salesman::acceptSalesMan();

    }

     void display()
     {
       Employee::display();
       Manager::displayManager();
       Salesman::displayManager();
       
       
     }

};

int main()
{
   Employee employee;
   Manager manager;
   Salesman salesman;
   Sales_Manager sales_Manager;

cout<<"Enter the Information of Employee"<<endl;
cout<<"********************************************"<<endl;
   employee.accept();
cout<<"----------------------------------------------"<<endl;
   employee.display();




cout<<"Enter the Information of Manaager"<<endl;
cout<<"********************************************"<<endl;
   manager.accept();
cout<<"----------------------------------------------"<<endl;
   manager.display();




cout<<"Enter the Information of Sales-Man "<<endl;
cout<<"********************************************"<<endl;
   salesman.accept();
cout<<"----------------------------------------------"<<endl;
   salesman.display();



cout<<"Enter the Information of Sales-Manager"<<endl;
cout<<"********************************************"<<endl;
   sales_Manager.accept();
cout<<"----------------------------------------------"<<endl;
   sales_Manager.display();

}