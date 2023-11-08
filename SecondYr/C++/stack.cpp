#include<iostream>
#include<string>
using namespace std;
class stack
{
 private:
 int top;
 int a[10];
 public:
 stack()
 {
  top=0;
 }
 void operator + (int data)
 {
  if(top==10)
  {
   cout<<"stack is overflow\n"<<data<<"CANNOT BE INSERTED";
  }
  else
  {
  a[top]=data;
  top++;
  }
 }
 void operator - ()
 {
  if(top==0)
  cout<<"stack empty";
  else
  {
   top--;
   cout<<"\nPOP Element is"<<a[top];
  }
}
};
int main()
{
 int x,z,c;
 stack s;
 while(1)
{
 cout<<"\nenter your choice\n1.push\n2.pop\n3.exit";
 cin>>x;
 switch(x)
 {
  case 1:
        cout<<"enter the character to push";
        cin>>z;
        s+z;
        break;
  case 2:
        -s;
        //cout<<"the poped element is"<<c;
        break;
  case 3:
        goto roy;
        break;
  default:
        cout<<"invalid choice";
        break;
  }
 }
 roy:
     cout<<"";
}
