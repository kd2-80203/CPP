/*
Q3. Write a menu driven program for Student in CPP language. Create a class student with data
members roll no, name and marks. Implement the following functions
void initStudent();
void printStudentOnConsole();
void acceptStudentFromConsole();
*/
#include <iostream>
//#include <string.h>
using namespace std;
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

int main()
{
    Student student1;
    student1.initStudent();
    student1.acceptStudentFromConsole();
    student1.printStudentOnConsole();
    return 0;
}