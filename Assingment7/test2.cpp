#include <iostream>
using namespace std;

class Student
{
    int id;
    string name;
    float per;

    public:
    Student()
    {
      this->id=10;
      this->name="Ram";
      this->per=90.06;
    }

    void display()
    {
        cout<<"ID IS "<<this->id<<endl;
        cout<<"Name IS "<<this->name<<endl;
        cout<<"Percntage IS "<<this->per<<endl;
    }

};

int main()
{

    Student *arr[2];

    for(int i=0;i<2;i++)
    {
        arr[i]=new Student();
    }

        arr[i]->display();
        arr[5]->display();
}