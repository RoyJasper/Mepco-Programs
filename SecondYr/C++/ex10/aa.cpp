#include<iostream>
#include<string>
using namespace std;
class student
{
 int rno;
 string name,dept;
 int mark[6];
 public:
    student()
    {
     rno=0;
     name="";
     dept="";
     for(int i=0;i<6;i++)
      mark[i]=0;
    }
    void getdetails()
    {
     cout<<"\nenter rollno";
     cin>>rno;
     cout<<"\nenter name";
     cin>>name;
     cout<<"\nenter department";
     cin>>dept;
     cout<<"\nenter marks";
     for(int i=0;i<6;i++)
      cin>>mark[i];
    }
    void printdetails()
    {
     cout<<"\nrollno:\t"<<rno;
     cout<<"\nname  :\t"<<name;
     cout<<"\ndepart:\t"<<dept;
     cout<<"\nmarks :\t";
     for(int i=0;i<6;i++)
      cout<<"\n"<<mark[i];
    }
};
template<typename type>
class queue
{
private:
      int front,rear;
      type s[10];
      public :
      queue()
      {
       front=0;
       rear=-1;
      }
      void enqueue(type);
      type dequeue();
};
template<typename type>
void queue<type>::enqueue(type value)
{
 if(rear==9)
  cout<<"\nqueue is full";
 else
  rear++;
  s[rear]=value;
}
template<typename type>
type queue<type>::dequeue()
{
 type x;
 if(front==(rear+1))
  cout<<"\nqueue empty";
 else
 { 
  x=s[front];
  front++;
  return x;
 }
}
int main()
{
 int a[10],m,n,t,k,o,ch,f;
 char c[20],e;
 student s[20],d;
 cout<<"hai";
 queue<int>qi;
 queue<char>qc;
 queue<student>qo;
 while(1)
 {
  
  cout<<"\nenter your choice\n1.integer\n2.character\n3.object\n4.exit";
  cin>>ch;
  switch(ch)
  {
   case 1: 

      l1: 
       cout<<"\nenter your choice\n1.enqueue\n2.dequeue\n3.exit";
       cin>>k;
       if(k==1)
       {
        cout<<"\nenter no of elements";
        cin>>n;
        for(int i=0;i<n;i++)
        {
         cin>>a[i];
         qi.enqueue(a[i]);
        }
        goto l1;
       }
       else if(k==2)
       {
        f= qi.dequeue();
        cout<<"\n deleted element is"<<f; 
        goto l1;
       }
       else
         goto l2;        
       l2:break;
   case 2:
       b1:
       cout<<"\nenter your choice\n1.enqueue\n2.dequeue\n3.exit";
       cin>>o;
       if(o==1)
       {
        cout<<"\nenter no of elements";
        cin>>m;
        for(int i=0;i<m;i++)
        {
         cin>>c[i];
         qc.enqueue(c[i]);
        }
        goto b1;
       }
       else if(o==2)
       {  e=qc.dequeue();
          cout<<"\n the deleted element is"<<e;
          goto b1;
       }
       else
         goto b2;
       b2:
       break;
    case 3:
      c1:
       cout<<"\nenter your choice\n1.enqueue\n2.dequeue\n3.exit";
       cin>>t;
       if(t==1)
       {
        cout<<"\nenter no of elements";
        cin>>n;
        for(int i=0;i<n;i++)
        {
         s[i].getdetails();;
         qo.enqueue(s[i]);
        }
        goto c1;
       }
       else if(t==2)
       { d= qo.dequeue();
        d.printdetails();
        goto c1;
       }
       else
         goto c2;
       c2:
        break;
   case 4:
       exit(0);
       break;
   default:
       cout<<"\n invalid choice";
       break;
  }
 }
}
