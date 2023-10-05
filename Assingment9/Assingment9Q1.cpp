/*
Q1. Write a user defined function factorial() that calculates factorial of given number and it throws
exception if number entered by user is negative.
*/
#include <iostream>
using namespace std;

class Factorial
{
private:
    int num;

private:
    Factorial()
    {
    }
    Factorial(int num)
    {
        this->num = num;
    }

public:
    static Factorial *acceptNo()
    {
        int nu;
        cout << "Pls Enter the no" << endl;
        cin >> nu;
        if (nu <= 0)
            throw 2;

        return new Factorial(nu); 
    }

public:
    void getFactorial()
    {
        int facto = 1;
        for (int i = 1; i <= this->num; i++)
        {
            facto = facto * i;
        }
        cout << "The factorial of " << this->num << " = " << facto << endl;
    }
};

int main()
{

    try
    {
        Factorial *fptr = Factorial::acceptNo();
        fptr->getFactorial();
    }
    catch (int error)
    {
        cout << "Pls Enter the non-zero and positive value" << endl;
    }
}