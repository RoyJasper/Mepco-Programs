#include<iostream>
#include<string>
using namespace std;
class employee
{
 int id;
 string name,dept;
 float bp;
 public:
  void getdetails()
  {
   cout<<"\nenter employee id";
   cin>>id;
   cout<<"\n enter ename";
   cin>>name;
   cout<<"\n enter department";
   cin>>dept;
   cout<<"\n enter basic pay";
   cin>>bp;
  }
  void printdetails()
  {
   cout<<"\n employee id"<<id;
   cout<<"\n employee name:"<<name;
   cout<<"\n department:"<<dept;
   cout<<"\nbasic pay:"<<bp;
  }
};
template<>
class tqueue<employee>
{
int front,rear;
employee d[10];
public: 
 tqueue()
 {
  front=0;
  rear=-1;
 }
 void enqueue(employee &e)
 {
  if(rear==9)
    cout<<"\nqueue is full";
  else
    rear++;
    d[rear]=e;
 }
 employee dequeue()
 {
  employee x;
  if(front==(rear+1))      
  {
   cout<<"\n queue is empty";
   return x; 
  }
  else
  {
   x=d[front];
   front++;
   return x;
  }
 }
};
template <typename type>
class tqueue
{
 int front,rear;
 type a[10];
 public:
  tqueue()
  {
   front=0;
   rear=-1;
  }
  void enqueue(type);
  type dequeue();
};
  template<typename type>
  void tqueue<type>::enqueue(type val)
  {
   if(rear==9)
    cout<<"\n queue is full";
   else
   { 
    rear++;
    a[rear]=val;
   }
  }
  template<typename type>
  type tqueue<type>::dequeue()
  {
   type k;
   if(front==(rear+1))
   { 
    cout<<"\n queue is empty";
    return k;
   }
   else
   { 
    k=a[front];
    front++;
    return k;
   }
  }

int main()
{
 int li[10],i,j,n,ch,u,v,w,x,z,lo;
 char c[20],f;
 employee s,vo[10],r[10],p;
 tqueue<int>qi;
 tqueue<char>qc;
 tqueue<employee>qo;
 cout<<"\nexplicit specialisation template class for object\n";
 cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
 l1: 
 cout<<"\nenter your choice\n1.enqueue\n2.dequeue\n3.exit";
 cin>>ch;
 if(ch==1)
 {
  cout<<"\n enter no of students";
  cin>>n;
  for(i=0;i<n;i++)
  {
   vo[i].getdetails();
   qo.enqueue(vo[i]);
  }
  goto l1;
 }
 else if(ch==2)
 {
  s=qo.dequeue();
  s.printdetails();
  goto l1;
 }
 else
 {
  cout<<"";
 }
 cout<<"\n normal template class";
 while(1)
 {
  cout<<"\n enter ur choice\n1.integer\n2.character\n3.object\n4.exit";
  cin>>j; 
  switch(j)
  {
   case 1:
       a1: 
       cout<<"\nenter your choice\n1.enqueue\n2.dequeue\n3.exit";
       cin>>u;
       if(u==1)
       {
       cout<<"enter no of elements";
       cin>>n; 
        for(i=0;i<n;i++)
        { 
         cin>>li[i];
         qi.enqueue(li[i]);
        }
        goto a1;
       }
       else if(u==2)
       {
        x=qi.dequeue();
        cout<<"\n the deleted element is"<<x;
        goto a1;
       }
       else
        goto a2;
       a2:
        break;
   case 2: 
       b1:
       cout<<"\nenter your choice\n1.enqueue\n2.dequeue\n3.exit";
       cin>>v;
       if(v==1)
       { 
        cout<<"\n enter no of characters";
        cin>>z;
        for(i=0;i<z;i++)
        {
         cin>>c[i];
         qc.enqueue(c[i]);
        }
        goto b1;
       }
       else if(v==2)
       {
        f=qc.dequeue();
        cout<<"\n the deleted character is"<<f;
        goto b1;
       }
       else
       {
        goto b2;
       }
       b2:
        break;
   case 3:
       c1:
       cout<<"\nenter your choice\n1.enqueue\n2.dequeue\n3.exit";
       cin>>w;
       if(w==1)
       {
        cout<<"\n enter no of elements";
        cin>>lo;
        for(i=0;i<lo;i++)
        {
         r[i].getdetails();
         qo.enqueue(r[i]);
        }
        goto c1;
       }
       else if(w==2)
       {
        p=qo.dequeue();
        p.printdetails();
        goto c1;
       }
       else
        goto c2;
       c2:
        break;
   case 4:
       exit(0);
       break;
   default :
       cout<<"\n invalid choice";
  }
 }
}

       

      
