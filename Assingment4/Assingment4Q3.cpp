/*
Q3. Write a Matrix class. Allocate memory dynamically in parameterized constructor. Also write
parameter-less constructor. Write accept() and print() functions.
Also provide add(), subtract(), multiply() and transpose() function.
NOTE – Menu driven code not required for all 3 questions
*/
#include<iostream>
using namespace std;
class Matrix
{
    private:
    int m,n;
    int **arr = new int*[m];

    public:
    void setSize()
    {
      cout<<"Enter the no rows"<<endl;
      int m;
      int n;
      cin>>n;
      cout<<"Enter the no columns"<<endl;
      cin>>m;
      this->m=m;
      this->n=n;

    }

    void accept()
    {
     setSize();
     int m=this->m;
     int n=this->n;

     for (int i = 0; i < m; i++) 
       {
         arr[i] = new int[n];
       }

      for (int i = 0; i < m; i++) 
       {
          for (int j = 0; j < n; j++) 
         {
           cout<<"Pls Enter the values for matrix"<<endl;
           int temp;
           cin>>temp; 
           arr[i][j] = temp;
         }
        }

    }
    void printMatrix()
    {
        int m=this->m;
        int n=this->n;
        for (int i = 0; i < m; i++) 
       {
          for (int j = 0; j < n; j++) 
         {
           cout<<"Values"<<i<<"-"<<j<<"="<<arr[i][j]<<endl;
         }
        }

    }

    int getrows()
    {
      return this->m;
    }
    
    int getcolumns()
    {
      return this->n;
    }

   friend void addMatrix(Matrix m1,Matrix m2);
   friend void subMatrix(Matrix m1,Matrix m2);
   friend void multiMatrix(Matrix m1, Matrix m2);
   friend void transMatrix(Matrix m1);

};

void addMatrix(Matrix m1,Matrix m2)
{
 
    int m,n;
    m=m1.getrows();
    n=m1.getcolumns();
    int **arr = new int*[m];

    for (int i = 0; i < m; i++) 
       {
         arr[i] = new int[n];
       }



    for (int i = 0; i < m ; i++) 
       {
          for (int j = 0; j< n; j++) 
          {
           arr[i][j] = m1.arr[i][j]+m2.arr[i][j];
          }
        }

      // Printing the result
        cout << endl
             << "Addition of two matrix is: " << endl;
        for (int i = 0; i <m; i++)
        {
            for (int j = 0; j <n; j++)
                cout << arr[i][j] << "  ";
            cout << endl;
        }

}

void subMatrix(Matrix m1,Matrix m2)
{
 
    int m,n;
    m=m1.getrows();
    n=m1.getcolumns();
    int **arr = new int*[m];

    for (int i = 0; i < m; i++) 
       {
         arr[i] = new int[n];
       }



    for (int i = 0; i < m ; i++) 
       {
          for (int j = 0; j< n; j++) 
          {
           arr[i][j] = m1.arr[i][j]-m2.arr[i][j];
          }
        }

     // Printing the result
        cout << endl
             << "Substraction of two matrix is: " << endl;
        for (int i = 0; i <m; i++)
        {
            for (int j = 0; j <n; j++)
                cout << arr[i][j] << "  ";
            cout << endl;
        }

}

void multiMatrix(Matrix m1, Matrix m2)
    {
       int m,n;
       m=m1.getrows();
       n=m1.getcolumns();
       int **arr = new int*[m];

       for (int i = 0; i < m; i++) 
       {
         arr[i] = new int[n];
       }


        for (int i = 0; i <m; i++)
        {
            for (int j = 0; j <n; j++)
            {
                arr[i][j] = 0;

                for (int k = 0; k < n; k++)
                    arr[i][j] += m1.arr[i][k] * m2.arr[k][j];
            }
        }

        // Printing the result
        cout << endl
             << "Multiplication of two matrix is: " << endl;
        for (int i = 0; i <m; i++)
        {
            for (int j = 0; j <n; j++)
                cout << arr[i][j] << "  ";
            cout << endl;
        }
    }


    //Transpose of a matrix
    void transMatrix(Matrix m1)
    {
        int m,n;
        m=m1.getrows();
        n=m1.getcolumns();
        int **arr = new int*[m];

       for (int i = 0; i < m; i++) 
       {
         arr[i] = new int[n];
       }


        //Calculating the Transpose 
        for (int i = 0; i <m; i++)
        for (int j = 0; j <n; j++)
            arr[i][j] = m1.arr[j][i];

        // Printing the result
        cout << endl
             << "Transpose of the matrix is: " << endl;
        for (int i = 0; i <m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << arr[i][j] << "  ";
            cout << endl;
        }
    }


int main()
{
    Matrix m1;
    Matrix m2;

    cout <<"Pls enter the values for frist matrix"<<endl;
    m1.accept();
    cout <<"Pls enter the values for second matrix"<<endl;
    m2.accept();

    addMatrix(m1,m2);
    subMatrix(m1,m2);
    multiMatrix(m1,m2);
    transMatrix(m1);


  return 0;

}

