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
    cout << "0. Exit" << endl;
    cout << "1. Area of Circle" << endl;
    cout << "2. Area of Rectangle" << endl;
    cout << "3. Area of Square" << endl;
    cout << "Enter Your Chocie = ";
    cin >> choice;
    return choice;
}

int main()
{
    int choice;
    Shape *shape = NULL;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            shape = new Circle(); // upcasting
            break;
        case 2:
            shape = new Rectangle(); // upcasting
            break;
        case 3:
            shape = new Square(); // upcasting
            break;
        default:
            cout << "Wrong Choice ..." << endl;
            break;
        }
        if (shape != NULL)
        {
            shape->acceptData();
            shape->calculateArea();
            shape->displayArea();
            delete shape;
            shape = NULL;
        }
    }
    cout << "Thank you for using our app..." << endl;
    return 0;
}