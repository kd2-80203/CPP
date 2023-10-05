/*
Q2. Write a class to store Account information of Bank customer by using following class diagram.
Use enum to store information of account type. Create an array of 5 Accounts in main() and accept
their details from user. Write Menu driven program to deposit/withdraw amount from the account.
After each transaction display updated account balance. Provide appropriate getters/setters with
necessary validations. Throw exceptions for invalid values. Also implement an exception class
InsufficientFunds. In withdraw() member function, if sufficient balance is not available
in account, throw this exception.
*/
#include<iostream>
using namespace std;

enum Account_type{SAVING,CURRENT,DEMAT};

class Account
{
  private:
  int id;
  Account_type type;
  double balance;
  
  public:
  Account()
  {

  }

  Account(int id,Account_type type,double balance)
  {
    this->id=id;
    this->type=type;
    this->balance=balance;
  }

  void set_Id(int id)
  {
     this->id=id;
  }
  void set_Type(Account_type type)
  {
     this->type=type; 
  }
  void set_Balance(double balance)
  {
    this->balance=balance;
  }
  int get_Id()
  {
    return this->id;
  }
  Account_type get_Type()
  {
    return this->type;
  }
  double get_Balance()
  {
    return this->balance;
  }

  void accept()
  {
    cout<<"Select your account type"<<endl;
    cout<<"0 - SAVING ACCOUNT"<<endl;
    cout<<"1 - CURRENT ACCOUNT"<<endl;
    cout<<"2 - DEMAT ACCOUNT"<<endl;
    int choose;
    cin>>choose;
    this->type=Account_type(choose);
    cout<<"Enter your accout ID"<<endl;
    cin>>this->id;
    cout<<"Pls Enter Acount Balance"<<endl;
    cin>>this->balance;

  }

  void display()
  {
    cout<<"Your accout ID  : "<<this->id<<endl;
    cout<<"Your accout type is : "<<this->type<<endl;
    cout<<"Your accout Balance"<<this->balance<<endl;
  }



};

class Insufficient_Funds
{
  int accid;
  double cur_balance;
  double withdraw_amount;

  public:
  Insufficient_Funds(int accid,double cur_balance,double withdraw_amount)
  {
     this->accid=accid;
     this->cur_balance=cur_balance;
     this->withdraw_amount=withdraw_amount;
  }
  
  void display()
  {
    cout<<"Insufficient balance"<<endl;
    cout<<"Account-ID-"<<this->accid<<endl;
    cout<<"Current available balance is: "<<this->cur_balance<<endl; 
    cout<<"Withdrawal requested amount is: "<<this->withdraw_amount<<endl;
  }

};

void deposite(Account **arr,int INDEX)
{

  int id;
  double balance;
  double amount;

  cout<<"Pls Select the account to DEPOSITE the money"<<endl;

   for(int i=0;i<INDEX;i++)
   {
     cout<<"Accoint ID = "<<arr[i]->get_Id()<<endl;
   }

   cin>>id;

   for(int i=0;i<INDEX;i++)
   {
     if(arr[i]->get_Id()==id)
     {
        cout<<"Enter the amount for deposit : "<<endl;
        cin>>amount;

        balance=arr[i]->get_Balance();
        balance=balance+amount;
        arr[i]->set_Balance(balance);
        cout<<amount<<" deposited successful in account ID-"<<id<<"-balane is :"<<balance<<endl;
        break;
     }
   }

   cout<<"THNAK YOU FOR BANKING WITH US"<<endl;
}

void withdrawal(Account **arr,int INDEX)
{

  int id;
  double balance;
  double amount;

  cout<<"Pls Select the account to WITHDRAWAL the money"<<endl;

   for(int i=0;i<INDEX;i++)
   {
     cout<<"Accoint ID = "<<arr[i]->get_Id()<<endl;
   }

   cin>>id;

   for(int i=0;i<INDEX;i++)
   {
     if(arr[i]->get_Id()==id)
     {
        cout<<"Enter the amount for WITHDRAWAL : "<<endl;
        cin>>amount;
        balance=arr[i]->get_Balance();
        
        if(balance<amount)
          throw Insufficient_Funds(id,balance,amount);
          
          balance=balance-amount;
          arr[i]->set_Balance(balance);
          cout<<amount<<" WITHDRAWAL successful in acount-ID : "<<id<<"-balane is :"<<balance<<endl;
        break;
        
     }
   }
  
   cout<<"THNAK YOU FOR BANKING WITH US"<<endl;
}

void currentBalace(Account **arr,int INDEX)
{
  for(int i=0;i<INDEX;i++)
  {
    cout<<"ID = "<<arr[i]->get_Id()<<" Current Balance is - "<<arr[i]->get_Balance()<<endl;
  }

}



enum Menu{BACK,CURRENT_BAL,DEPOSITE,WITHDRAW};

Menu menu()
{
  int num;
  cout<<"0 - BACK TO MAIN MENU"<<endl;
  cout<<"1 - FOR CURRENT BALANCE"<<endl;
  cout<<"2 - FOR DEPOSITE AMOUNT"<<endl;
  cout<<"3 - FOR WITHDRAW AMOUNT"<<endl;
  cin>>num;
  return Menu(num);
}



int main()
{
    int INDEX=2;
    Account *arr[INDEX];
    Menu choice;

    for(int i=0;i<INDEX;i++)
    {
        arr[i]= new Account();
        cout<<"Enter for details customer "<<i+1<<endl; 
        arr[i]->accept();
        cout<<endl;
    }
  while ((choice=menu())!=BACK)
  {
    switch (choice)
    {
    case WITHDRAW:
      try{
           withdrawal(arr,INDEX); 
         }
      catch (Insufficient_Funds e)
         {
           e.display();
         }
      break;

    case DEPOSITE:
       deposite(arr,INDEX); 
      break;

    case CURRENT_BAL:
       currentBalace(arr,INDEX);
      break;


    default:
      cout<<"PLS ENTER THE VALID OPTION"<<endl;
      break;
    }
   
  }  
}