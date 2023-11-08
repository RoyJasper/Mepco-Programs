#include<iostream>
#include<string>
using namespace std;
class queue
{
 private:
  int m[10];
  int front,rear;
 public:
  queue()
   {
    front=0;
    rear=0;
   }
 void enqueue(int x)
  {
   if(rear=='\0')
    cout<<"\nQueue is completed";
   else
    {
     m[rear]=x;
     rear++;
    }	
  }
 void dequeue()
 {
  int x;
  if(rear=front)
   cout<<"\nEmpty";
  else
   {
    x=m[front];
    front++;
    cout<<"\nPOP value is"<<x;
   }
  }
};
int main()
{
 int choice,x;
 queue q;
 while (true)
  {
   cout<<"\n Enter choice:\n1.Enqueue\n2.Dequeue\n3.Exit ";
   cin>>choice;
    switch(choice)
    {
     case 1:
       cout<<"\nEnter data";
       cin>>x;
       q.enqueue(x);
       break;
     case 2:
       q.dequeue();
       break;
     case 3:
       exit(0);
     default:
       cout<<"\nInvalid entery";
       break;
    } 
  }
 return 0;
}
