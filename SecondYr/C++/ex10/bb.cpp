#include<iostream>
#include<string>
using namespace std;
class employee
{
int empno;
string empname;
public:
employee(int tempno=0,string tempname="\0")
{
empno=tempno;
empname=tempname;
}
friend ostream& operator << (ostream&,employee&);
void operator=(employee c)
{
empno=c.empno;
empname=c.empname;
}
};
template <typename type>
class queue
{
int a[10];
int front,rear;
public:
queue()
{
front=0;
rear=-1;
}
void dequeue()
{
if(front-1==rear)
{
cout<<"\n not possible empty ";
}
else
{
cout<<a[front]<<" is deleted\n";
front++;
}
}
void enqueue(int b)
{
if(rear==10) 
cout<<"\n Queue overflow!! ";
else
{
rear++;
a[rear]=b;
}
}
};
template <typename t>
class queue1
{
t a[10];
int front,rear;
public:
queue1()
{
front=0;
rear=-1;
}
void dequeue()
{
if(front-1==rear)
{
cout<<"\nNot possible";
}
else
{
cout<<a[front]<<" Is deleted ";
front++;
}
}
void enqueue(t b)
{
if(rear==10)
cout<<"\n Queue overflow!! ";
else
{
rear++;
a[rear]=b;
}
}
};

int main()
{
int s,f,choice,n,sid;
char c;
string sname;
queue1 <int> q1;
queue1 <char> q2;
queue <employee> q3;
employee s1;
while(true)
{
start:
cout<<"1.Integer \n2.character \n 3.Class \n4.Exit \n Enter choice ";
cin>>s;
switch(s)
{
case 1:
while(true)
{
cout<<"\n1.Enqueue \n2.Dequeue \n 3.Exit \n Enter choice ";
cin>>choice;
switch(choice)
{
case 1: cout<<"\nEnter element ";
cin>>f;
q1.enqueue(f);
break;
case 2: q1.dequeue();
break;
case 3: goto start;
}
}
break;
case 2:
while(true)
{
cout<<"\n1.Enqueue \n2.Dequeue \n 3.Exit \n Enter choice" ;
cin>>choice;
switch(choice)
{
case 1: cout<<"\nEnter element ";
cin>>c;
q2.enqueue(c);
break;
case 2: q2.dequeue();
break;
case 3: goto start;
}
}
break;
case 3:
while(true)
{
cout<<"\n1.Enqueue \n2.Dequeue \n 3.Exit \n Enter choice ";
cin>>choice;
switch(choice)
{
case 1: cout<<"\n Enter id";
cin>>sid;
cout<<"\n Enter name ";
cin>>sname;
s1=employee(sid,sname);
q3.enqueue(sid);
break;
case 2: q3.dequeue();
break;
case 3:
goto start;
}
}
break;
case 4: exit(0);
break;
}
}
return 0;
}

