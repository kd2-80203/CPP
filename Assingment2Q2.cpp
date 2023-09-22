/*Q2. Write a class Address. Implement constructors, getters, setters, accept(), and display() methods.
Instead of char[] use string datatype
*/
#include <iostream>
#include <string.h>
using namespace std;
namespace NAddress
{
    class Address
{
private:
    // data members
    string building;
    string street;
    string city;
    int pin;

public:
    Address()
    {

    }
    Address(string building,string street,string city,int pin)
    {
       this->building=building;
       this->street=street;
       this->city=city;
       this->pin=pin;
    }

    void acceptAddressFromConsole()
    {
        cout<< "Enter the building Name = ";
        cin >> this->building;
        cout<< "Enter street Name = ";
        cin>> this->street;
        cout<< "Enter the city= ";
        cin >> this->city;
        cout<< "Enter the pin= ";
        cin >> this->pin;

    }
    void printAddressOnConsole()
    {
        cout<< "buildingNameIs= " << this->building<< endl;
        cout<< "StreetNameIs = " << this->street<< endl;
        cout<< "CityNameIS = " << this->city<< endl;
         cout<< "PinCodeIS = " << this->pin<< endl;
    }

    

    string get_building()
    {
        return building;        //returns building
    }
    string get_street()
    {
        return street;      //returns street
    }
    
    string get_city()
    {
        return city;       //returns city
    }
    int get_pin()
        {
            return pin;     //returns pin
        }
 //setters

  void set_building(string building)
  {
    this->building = building;

  }                             //sets building

    void set_street(string street)
  {
    this->street = street;
                                //sets street
  }

    void set_city(string city)
  {
    this->city = city;          //sets city
    
  }

  void set_pin(int pin)
  {
    this->pin= pin;
  }                             //sets pin 




};

}
int main()
{
   NAddress::Address address;

   int x=1;
   while(x)
      {
         printf("\n 0-Exit" );
         printf("\n");
         printf("\n 1-to Insert The Address Details ");
         printf("\n");
         printf("\n 2-Display the Address Details");
        
        scanf("%d",&x);
        if(x<=2 && x>=0)
        {
         switch(x)
         {
            
             case 1:
                    address.acceptAddressFromConsole();
                    break;
             case 2 :
                    address.printAddressOnConsole();
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