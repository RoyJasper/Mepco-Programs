#include<iostream>
#include<string>
using namespace std;
class day
{
 private:
 int d,m,y;
 public:
 day()
 {
  d=0;
  m=0;
  y=0;
 }
day(int td,int tm,int ty)
{
 d=td;
 m=tm;
 y=ty;
}
void calculate(day);
int years(int);
int months(int,int);
};
int day::years(int tty)
{
 if(tty%4==0)
 return 366;
 else
 return 365;
}
int day::months(int ttm,int tty)
{
 if((ttm==4)||(ttm==6)||(ttm==9)||(ttm==11))
 return 30;
 else if((ttm==2)&&(tty%4==0))
 return 29;
 else if((ttm==2)&&(tty%4!=0))
 return 28;
 else
 return 31;
}
void day::calculate(day d2)
{
 int a,b,c,e=0,f,g=0,h,i,j,k,l,p=0,q=0;
 if((m==d2.m)&&(y==d2.y))
 {
  if(d>d2.d)
   a=d-d2.d;
   else
   a=d2.d-d;
   cout<<"total number of days between them is"<<a<<"days";
 }
  else if((d==d2.d)&&(m==d2.m))
  {
   a=0;
   while(y!=d2.y)
   {
    a=years(y+1)+a;
    y++;
   }
   cout<<"total number of days between them is"<<a<<"days";
  }
  else if((d==d2.d)&&(y==d2.y))
  {
   b=months(m,y);
   c=b-d;
   m++;
   while(m!=d2.m)
   {
     e=e+months(m,y);
     m++;
   }
    a=c+e+d2.d;
    cout<<"total number of days between them is"<<a<<"days";
  }
else if(y==d2.y)
{
 p=months(m,y);
 p=p-d;
 m++;
 while(m!=d2.m)
{
 q=q+months(m,y);
 m++;
}
a=p+q+d2.d-1;
cout<<"total number of days between them is"<<a<<"days";
}
else
{
 f=months(m,y);
 g=f-d;
 m++;
// cout<<g<<"\n";
 h=0;
 while(m!=13)
 {
  h=h+months(m,y);
  m++;
 }
// cout<<h<<"\n";
 i=0;
 y++;
 while(y!=d2.y)
 {
  i=i+years(y);
  y++;
 }
 // cout<<i<<"\n";
  j=1;
  k=0;
   while(j!=d2.m)
     {
      k=k+months(j,d2.y);
      j++;
     }
   //  cout<<k<<"\n";
     a=h+i+k+d2.d+g-1;
     cout<<"total number of days between them is:"<<a<<"days";
    }
}
    int main()
    {
    int td,tm,ty;
    cout<<"enter the first date";
    cin>>td>>tm>>ty;
    day d1(td,tm,ty);
    cout<<"enter the second date";
    cin>>td>>tm>>ty;
    day d2(td,tm,ty);
    d1.calculate(d2);
    }
