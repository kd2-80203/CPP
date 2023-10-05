/*
Q2. A shop sells book or tapes. The Book class holds id, title, author, and price; whereas Tape class
holds id, title, artist, and price. There is 5% discount on tapes, while 10% discount on books.
Assuming that each user purchase 3 products (either book or tape), calculate final bill. The program
should be menu driven and should not cause memory leakage.
*/
#include<iostream>
using namespace std;

class Product
{
    private:
    int id;
    string title;
    float price;
    string type;
    
    public:
    Product()
    {

    }
    Product(int id,string title,float price,string type)
    {
        this->id=id;
        this->title=title;
        this->price=price;
        this->type=type;
    }
    void setId(int id)
    {
        this->id=id;
    }
     void setTitle(string title)
    {
        this->title=title;
    }
     void setPrice(float price)
    {
        this->price=price;
    }
     void setType(string type)
    {
        this->type=type;
    }
    int getId()
    {
        return this->id;
    }
    string getTitle()
    {
        return this->title;
    }
    float getPrice()
    {
        return this->price;
    }
    string getType()
    {
        return this->type;
    }
};

class Tapes:public Product
{
    private:
    string artist;

    public:
    Tapes()
    {
        setId(1);
        setPrice(540.50);
        setTitle("Old Songs");
        setType("T");
        this->artist="Lata Mangeshkar";

    }
    Tapes(int id,string title,float price,string type,string artist)
    {
        setId(id);
        setPrice(price);
        setTitle(title);
        setType(type);
        this->artist=artist;
    }
    void setArtist(string artist)
    {
        this->artist=artist;
    }
    string getArtist()
    {
        return this->artist;
    }

};



class Book:public Product
{
    string author;

    public:
    Book()
    {
        setId(2);
        setPrice(230.67);
        setTitle("Wings Of Fire");
        setType("B");
        this->author="A.PJ.Kalam";

    }
    Book(int id,string title,float price,string type,string author)
    {
        setId(id);
        setPrice(price);
        setTitle(title);
        setType(type);
        this->author=author;
    }
    void setAuthor(string artist)
    {
       this->author=author;
    }
    string getAuthor()
    {
        return this->author;
    } 

};

void calculateBill(Product **ptr,int INDEX)
{
    float total=0;
    float rTotal=0;
    int noOfBooks=0;
    int noOfTapes=0;
    float Bprice;
    float Tprice;
    
    
     for(int i=0;i<INDEX;i++)
     {
                if(ptr[i]->getType()=="T")
                {  
                   noOfTapes++;
                   Tprice=ptr[i]->getPrice();
                   total=total+(Tprice*0.95);
                   rTotal=rTotal+(Tprice);
                   
                }
                else
                {
                    noOfBooks++;
                    Bprice=ptr[i]->getPrice();
                    total=total+(Bprice*0.90);
                    rTotal=rTotal+(Bprice);
                }
               }
               cout<<"**************************************"<<endl;
               cout<<"Total No Of Book you buy is :"<<noOfBooks<<endl;
               cout<<"Total price of all books is :"<<noOfBooks*(Bprice*0.90)<<endl;
               cout<<"Total No Of Tapes you buy is : "<<noOfTapes<<endl;
               cout<<"Total price of all tapes is :"<<noOfTapes*(Tprice*0.90)<<endl;
               cout<<"Total Discounted price is : "<<total<<endl;
               cout<<"Total Original price is : "<<rTotal<<endl;

}

int main()
{
    Product *arr[3];
    cout<<"Pls Choose the Option Below"<<endl;
    cout<<"1-To buy the Book"<<endl;
    cout<<"2-To buy the Tape "<<endl;
    cout<<"3-To Get your bill"<<endl;
    cout<<"0-EXIT"<<endl;
    int choise;
    cin>>choise;
    int INDEX=0;
    float total=0;
    float rTotal=0;
    int noOfBooks=0;
    int noOfTapes=0;
    float price;

    while (choise!=0)
    {
        switch(choise)
        {
            case 1:
              if(INDEX<3)
              {
              arr[INDEX]=new Book();
              cout<<"Book buy successfully"<<endl;
              INDEX++;
              }
              else
              {
                cout<<"You completed 3 items"<<endl;
                cout<<"Thank you for shoping with us "<<endl;
              }
              break;


            case 2:
                if(INDEX<3)
              {
              arr[INDEX]=new Tapes();
              cout<<"Tape buy successfully"<<endl;
              INDEX++;
              }
              else
              {
                cout<<"You completed 3 items"<<endl;
                cout<<"Thank you for shoping with us "<<endl;
              }
              break;

            case 3:
                  calculateBill(arr,INDEX);
              break;

             default:
                cout<<"Pls Enter the vaild Option"<<endl;
    
        }
    cout<<"**************************************"<<endl;
    cout<<"Pls Choose the Option Below"<<endl;
    cout<<"1-To buy the Book"<<endl;
    cout<<"2-To buy the Tape "<<endl;
    cout<<"3-To Get your bill"<<endl;
    cout<<"0-EXIT"<<endl;
    cin>>choise;
    }
    


}