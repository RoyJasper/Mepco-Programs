#include<iostream>
using namespace std;
class matrix
{
 public:
 int ele[3][3];
 matrix()
 { 
 }
 matrix(int tm[3][3])
 {
  for(int i=0;i<3;i++)
  {
   for(int j=0;j<3;j++)
   {
    ele[i][j]=tm[i][j];
   }
  }
 }
 matrix operator+(matrix tm)
 {
  matrix c;
  for(int i=0;i<3;i++)
  {
   for(int j=0;j<3;j++)
   {
    c.ele[i][j]=ele[i][j]+tm.ele[i][j];
   }
  }
  return c;
 }
  matrix operator-(matrix tm)
 {
  matrix c;
  for(int i=0;i<3;i++)
  {
   for(int j=0;j<3;j++)
   {
    c.ele[i][j]=ele[i][j]-tm.ele[i][j];
 }

  }
  return c;
 }
 matrix operator*(matrix tm)
 {
  matrix c;
  for(int i=0;i<3;i++)
  {
   for(int j=0;j<3;j++)
   {
    c.ele[i][j]=0;
    for(int k=0;k<3;k++)
    {
     c.ele[i][j]=c.ele[i][j]+ele[i][k]*tm.ele[k][j];
    }
   }
  }
 return c;
 }
 void display()
 {
  cout<<"the resultant matrix is\n";
  for(int i=0;i<3;i++)
  {
   for(int j=0;j<3;j++)
   {
    cout<<ele[i][j];
cout<<"\t";
   }
   cout<<"\n";
  }
 }
};
 int main()
 {
  int i,j,a[3][3],b[3][3],n;
  cout<<"enter the elements of A matrix\n";
  for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
   cin>>a[i][j];
  }
  cout<<"enter the elements of B matrix\n";
  for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
   cin>>b[i][j];
  }
  matrix x(a);
  matrix y(b);
  matrix z;
  while(1)
  {
   cout<<"\n************* welcome to matrix operation  *************\n";
   cout<<"\nenter your choice\n1.addition\n2.subtraction\n3.multiplication\n";
   cout<<"4.exit\n";
	 cin>>n;
   switch(n)
   {
    case 1:
           z=x+y;
           z.display();
           break;
    case 2:
           z=x-y;
           z.display();
           break;
    case 3:
           z=x*y;
           z.display();
           break;
   case 4: exit(0);
    default:
           cout<<"\ninvalid input";
           break;
   }
  }
 }
