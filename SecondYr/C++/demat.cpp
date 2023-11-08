#include<iostream>
using namespace std;
class matrix
{
 int e[3][3];
 public:
  matrix()
  {
   e[3][3]=0;
  }
 matrix(int tm[3][3])
  {
   for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      e[i][j]=tm[i][j];
  }
 void display()
 {
  cout<<"\nResultant elements are";
   for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      cout<<e[i][j];
 }
 matrix operator + (matrix b)
 {
  matrix c;
   for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
     c.e[i][j]=e[i][j]+b.e[i][j];
  return c;
 }
 matrix operator - (matrix b)
 {
  matrix c;
   for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
     c.e[i][j]=e[i][j]-b.e[i][j];
  return c;
 }
 matrix operator * (matrix b)
 {
  matrix c;
   for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
     {
      c.e[i][j]=0;
      for(int k=0;k<3;k++)
        c.e[i][j]= c.e[i][j]+e[i][k]*b.e[k][j];
     }
  return c;
 }
};
int main()
{
 matrix x,y,p,q,r;
 int i,j,n,a[3][3],b[3][3];
 cout<<"\nEnter elements of Matrix A";
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      cin>>a[i][j];
  cout<<"\nEnter elements of Matrix B";
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      cin>>b[i][j];
 x(a);
 y(b);
 cout<<"\nEnter choice\n1.Add\n2.Sub\n3.Mul";
 cin>>n;
 switch(n)
  {
   case 1:
        p=x+y;
        p.display(); 
        break;
   case 2:
        q=x-y;
        q.display();
        break;
   case 3:
        r=x*y;
        r.display();
        break;
   default:
       cout<<"\nInvalid input"; 
  }
return 0;
}
