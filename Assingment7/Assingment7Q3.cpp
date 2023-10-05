/*
Q3. Using the Q1 from assignment 6. Create an array of 10 employees. Provide menu driven code
for the functionalities: Insted of char[] use string datatype
1. Accept Employee
2. Display the count of all employees with respect to
designation
3. Display respective designation employees
*/

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
    string designation;

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
    
    string getDesignation()
    {
        return this->designation;
    }


    void virtual accept()
    {
        cout<<"Enter the Emp-ID : "<<endl;
        cin>>this->empid;
        cout<<"Enter The Your Salary : "<<endl;
        cin>>this->salary;
    }
    void virtual display()
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
      this->designation="SALESMAN";
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
        this->designation="MANAGER";
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
       this->designation="SALES_MANAGER";
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

enum emenu {EXIT,ADD_EMPLOYEE,GET_THE_NO_OF_EMPLOYEE,SHOW_EMPLOYEE};
enum EmpOption{BACK_TO_MENU,MANAGER,SALESMAN,SALESMANAGER};


emenu Menu()
{
    cout<<"PRESS 0 TO EXIT"<<endl;
    cout<<"PRESS 1 TO ADD EMPLOYEE"<<endl;
    cout<<"PRESS 2 TO GET THE NO OF EMPLOYEE"<<endl;
    cout<<"PRESS 3 TO SHOW_EMPLOYEE"<<endl;
    int a;
    cin>>a;
  
    return emenu(a);
}

EmpOption empOption()
{
    cout<<"PRESS 0 BACK TO MENU"<<endl;
    cout<<"PRESS 1 TO ADD MANAGER"<<endl;
    cout<<"PRESS 2 TO ADD SALESMAN"<<endl;
    cout<<"PRESS 3 TO ADD SALESMANAGER"<<endl;
    int a;
    cin>>a;
  
    return EmpOption(a);
}

void coutOfEmployee(Employee **arr,int index)
{
    int countManger=0;
    int countSalesMan=0;
    int coutSalesManager=0; 

  for(int i=0;i<index;i++)
  {
    if("MANAGER"==(arr[i]->getDesignation()))
    {
       //arr[i]->display();
       countManger++;  
    }
    else if ("SALESMAN"==(arr[i]->getDesignation()))
    {
       //arr[i]->display();
       countSalesMan++;
    }
    else if ("SALES_MANAGER"==(arr[i]->getDesignation()))
    {
       //arr[i]->display(); 
       coutSalesManager++;
    }  
  }
  cout<<"No of Mangers is : "<<countManger<<endl;
  cout<<"No of SalesMan is : "<<countSalesMan<<endl;
  cout<<"No of Sale-Manager is : "<<coutSalesManager<<endl;
}

void showOfEmployee(Employee **arr,int index)
{
  int option=10;

  while(option!=0)
  {
    cout<<"PRESS 0 BACK TO MENU"<<endl;
    cout<<"PRESS 1 TO GET ALL MANAGER"<<endl;
    cout<<"PRESS 2 TO GET ALL SALESMAN"<<endl;
    cout<<"PRESS 3 TO GET ALL SALESMANAGER"<<endl;
    string temp;
    cin>>option;
    
    if(option==1)
    {
        temp="MANAGER";
    }
    else if (option==2)
    {
        temp="SALESMAN";
    }
    else if (option==3)
    {
       temp="SALES_MANAGER";
    }
     for(int i=0;i<index;i++)
    {
      if(temp==(arr[i]->getDesignation()))
      {
         arr[i]->display();
         
      }
    } 
  } 

}

int main()
{
    Employee *arr[10];
    int index=0;
    
    emenu choise;
    EmpOption echoise;


    while ((choise=Menu())!=EXIT)
    {
        switch (choise)
        {
        case ADD_EMPLOYEE:
           
           while ((echoise=empOption())!=BACK_TO_MENU)
           {
            switch (echoise)
            {
            case MANAGER:
               if(index<10)
               {
                  arr[index]=new Manager();
                  arr[index]->accept();
                  index++;
               }
               else
               {
                cout<<"You are completed the 10 entry the array is full"<<endl;
               }
                break;


            case SALESMAN:
                if(index<10)
               {
                  arr[index]=new Salesman();
                  arr[index]->accept();
                  index++;
               }
               else
               {
                cout<<"You are completed the 10 entry the array is full"<<endl;
               }
                break;


            case SALESMANAGER:
                if(index<10)
               {
                  arr[index]=new Sales_Manager();
                  arr[index]->accept();
                  index++;
               }
               else
               {
                cout<<"You are completed the 10 entry the array is full"<<endl;
               }
                break;
            default:
               cout<<"Pls Enter the vaild choise"<<endl;
                break;
            }
           }
            break;


        case GET_THE_NO_OF_EMPLOYEE:
            coutOfEmployee(arr,index);
            break;

        case SHOW_EMPLOYEE :
            showOfEmployee(arr,index);
            break;
        
        default:
            break;
        }
    }
    
   
   

}