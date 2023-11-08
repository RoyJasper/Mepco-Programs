#include<iostream>
#include<string>
using namespace std;
class matrix
{
int ele[3][3];
public:
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
void display()
{
cout<<"\nThe elements in matrix are\n";
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
cout<<"\t"<<ele[i][j];
}
cout<<"\n";
}
}
matrix operator+(matrix m1)
{
matrix temp;
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
temp.ele[i][j]=ele[i][j]+m1.ele[i][j];
}
cout<<"\n";
}
return temp;
}
matrix operator-(matrix m1)
{
matrix temp;
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
temp.ele[i][j]=ele[i][j]-m1.ele[i][j];
}
cout<<"\n";
}
return temp;
}
matrix operator*(matrix m1)
{
matrix temp;
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
temp.ele[i][j]=0;
for(int k=0;k<3;k++)
{
temp.ele[i][j]=temp.ele[i][j]+(ele[i][k]*m1.ele[k][j]);
}
}
}
return temp;
}
};
main()
{
int a[3][3],b[3][3],n;
cout<<"\nEnter the matrix elements";
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
cin>>a[i][j];
}
}
cout<<"\nEnter the 2nd matrix elements";
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
cin>>b[i][j];
}
}
matrix m(a);
matrix m1(b);
matrix m2;
while(1)
{
cout<<"\nEnter your choice::\n1.Addition\n2.Subtraction\n3.Multiplication\n4.To exit\n";
cin>>n;
switch(n)
{
case 1:
m2=m+m1;
m2.display();
break;
case 2:
m2=m-m1;
m2.display();
break;
case 3:
m2=m*m1;
m2.display();
break;
case 4:
 cout<<"invalid";
}
}
}

