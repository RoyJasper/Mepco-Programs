#include<iostream>
#include<string>
using namespace std;
class nextdate
{
int d,m,y;
public:
nextdate(int td=0,int tm=0,int ty=0)
{
d=td;
m=tm;
y=ty;
}
nextdate operator++()
{
if(d==31||d==30||d==29||d==28)
{
if(d==31)
{
if(m==1||m==3||m==5||m==7||m==8||m==10)
{
d=1;
m++;
}
else
{
d=1;
m=1;
y++;
}
}
else if(d==30)
{
if(m==4||m==6||m==9||m==11)
{
d=1;
m++;
}
}
else if(y%4==0 && d==28 && m==2)
{
d=1;
m++;
}
else if(y%4!=0 && d==27 && m==2)
{
d=1;
m++;
}
else
d++;
}
else
d++;
return nextdate(d,m,y);
}
nextdate operator--(int dummy)
{
if(d==1)
{
if(m==5||m==7||m==8||m==10||m==12)
{
d=30;
m--;
}
else if(m==4||m==6||m==9||m==11||m==2)
{
d=31;
m--;
}
else if(m==3)
{
if(y%4==0)
{
d=28;
m--;
}
else
{
d=27;
m--;
}
}
else
{
d=31;
m=12;
y--;
}
}
else
d--;
return nextdate(d,m,y);
}
void display1()
{
cout<<"\nNext date is\t"<<d<<"-"<<m<<"-"<<y<<"\n";;
}
void display()
{
cout<<"\nPrevious date is\t"<<d<<"-"<<m<<"-"<<y<<"\n";
}

};
int main()
{
int da,mo,yr;
cout<<"\nEnter the date,month,year";
cin>>da>>mo>>yr;
nextdate a(da,mo,yr);
++a;
a.display1();
//cout<<"\nEnter the date,month,year";
//cin>>da>>mo>>yr;
nextdate b(da,mo,yr);
b--;
b.display();
}

