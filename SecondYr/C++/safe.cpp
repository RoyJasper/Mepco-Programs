#include<iostream>
using namespace std;
class comple
{
 public:
 int real,img;
 public:
 comple()
 {
  real=0;
  img=0;
 }
 void set(int treal,int timg)
 {
     real=treal;
     img=timg;
 }
 void operator [] (int ind)
 {
  if((ind<0)||(ind>4))
  {
    cout<<"\n number-> "<<ind<<" array element is out of boundary";
}
  else
  {
   cout<<"\n for number->"<<ind;
   cout<<"\n the real part is"<<real;
   cout<<"\n the imaginary part is"<<img;
  }
 }
};
int main()
{
 int r,i,b;
 char ch;
 comple a;
 /*a.set(2,3);
 a[0];
 a.set(1,4);
 a[-3];
 a.set(5,6);
 a[4];
 a.set(2,3);
 a[9];*/
 while(ch!='n')
 {
 cout<<"\nEnter the real and imaginary part of a complex no ";
 cin>>r>>i;
 cout<<"\nEnter the index";
 cin>>b;
 a.set(r,i);
 a[b];
 cout<<"\nDo u want to continue y/n?";
 cin>>ch;
 if(ch=='n')
    goto roy;
 }
 roy:
 return 0;
}
