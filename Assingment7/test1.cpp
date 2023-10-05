#include <iostream>
using namespace std;

// abstract implementation

class Shape
{
private:
    double area;

protected:
    void setArea(double area)
    {
        this->area = area;
    }

public:
    virtual void displayArea()
    {
        cout << "Area = " << this->area << endl;
    }

    virtual void acceptData() = 0;

    virtual void calculateArea() = 0;
};

class Circle : public Shape
{
private:
    int radius;

public:
    void acceptData()
    {
        cout << "Enter the radius = ";
        cin >> this->radius;
    }
    void calculateArea()
    {
        // this->area = 3.14 * this->radius * this->radius;
        this->setArea(3.14 * this->radius * this->radius);
    }
};

class Rectangle : public Shape
{
private:
    int length;
    int breadth;

public:
    void acceptData()
    {
        cout << "Enter the length = ";
        cin >> this->length;
        cout << "Enter the breadth = ";
        cin >> this->breadth;
    }

    void calculateArea()
    {
        this->setArea(this->length * this->breadth);
    }

    void displayArea()
    {
        cout << "Rectangle ";
        Shape::displayArea();
    }
};

class Square : public Shape
{
private:
    int side;

public:
    void acceptData()
    {
        cout << "Enter the side = ";
        cin >> this->side;
    }
    void calculateArea()
    {
        this->setArea(this->side * this->side);
    }
    void displayArea()
    {
        cout << "Square ";
        Shape::displayArea();
    }
};

int menu()
{
    int choice;
    cout << "--------------------" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Add Circle" << endl;
    cout << "2. Add Rectangle" << endl;
    cout << "3. Add Square" << endl;
    cout << "4. Display All Area" << endl;
    cout << "Enter Your Chocie = ";
    cin >> choice;
    cout << "--------------------" << endl;
    return choice;
}

int main()
{
    int choice;
    Shape *arr[5];
    int index = 0;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (index < 5)
            {
                arr[index] = new Circle();
                arr[index]->acceptData();
                arr[index]->calculateArea();
                index++;
            }
            else
                cout << "Array is Full, Cannot add the Circle Object.." << endl;
            break;
        case 2:
            if (index < 5)
            {
                arr[index] = new Rectangle();
                arr[index]->acceptData();
                arr[index]->calculateArea();
                index++;
            }
            else
                cout << "Array is Full, Cannot add the Rectangle Object.." << endl;

            break;
        case 3:
            if (index < 5)
            {
                arr[index] = new Square();
                arr[index]->acceptData();
                arr[index]->calculateArea();
                index++;
            }
            else
                cout << "Array is Full, Cannot add the Square Object.." << endl;

            break;

        case 4:
            for (int i = 0; i < index; i++)
                arr[i]->displayArea
            break;
        default:
            cout << "Wrong Choice ..." << endl;
            break;
        }
    }
    for (int i = 0; i < index; i++)
        delete arr[i];

    cout << "Thank you for using our app..." << endl;
    return 0;
}