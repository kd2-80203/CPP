/*Q1. Create a namespace NStudent. Create the Student class(created as per assignment-1 Q3) inside
namespace. Test the functionalities.
*/
#include <iostream>
#include <string.h>
using namespace std;
namespace NStudent
{
    class Student
{
private:
    // data members
    int rollno;
    string name;
    int marks;

public:
    void initStudent()
    {
        this->rollno = 10;
        this->name ="Ram";
        this->marks = 36;
    }

    void acceptStudentFromConsole()
    {
        cout<< "Enter the RollNo = ";
        cin >> this->rollno;
        cout<< "Enter the Name = ";
        cin>> this->name;
        cout<< "Enter the Marks= ";
        cin >> this->marks;
    }
    void printStudentOnConsole()
    {
        cout<< "Roll No = " << this->rollno << endl;
        cout<< "Name Of Student = " << this->name << endl;
        cout<< "Marks of Student = " << this->marks << endl;
    }
};

}
int main()
{
   NStudent::Student student;

   int x=1;
   while(x)
      {
         printf("\n 0-Exit" );
         printf("\n");
         printf("\n 1-to insert the student  ");
         printf("\n");
         printf("\n 2-Display student display");
        
        scanf("%d",&x);
        if(x<=2 && x>=0)
        {
         switch(x)
         {
            
             case 1:
                    student.acceptStudentFromConsole();
                    break;
             case 2 :
                    student.printStudentOnConsole();
                     break;       
            
           }
        }
        else
        
            printf("Pls Enter the vailid Option from menu");
        

    }

   // NStudent::student.acceptStudentFromConsole();
    //NStudent::student.printStudentOnConsole();
    
    return 0;
}