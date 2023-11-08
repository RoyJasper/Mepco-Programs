#include<iostream>
#include<string>
using namespace std;
class queue
{
 private:
 int a[20];
 int front,rear;
 public:
 queue()
 {
  front=0;
  rear=0;
 }
 void enqueue(int x)
 {
  if(rear==20)
  cout<<"queue is full";
  else
  a[rear]=x;
  rear++;
 }
 int dequeue()
 {
  int y;
  if(rear==front)
  cout<<"queue is empty";
  else
  {
   y=a[front];
   a[front]='\0';
   front++;
   cout<<"deleted element is"<<y;
  }
 }
};
int main()
{
 queue q;
 int choice,x;
 while(1)
 {
  cout<<"enter your choice\n1.queue\n2.dequeue\n3.exit";
  cin>>choice;
  switch(choice)
  {
   case 1:
          cout<<"enter the value";
          cin>>x;
          q.enqueue(x);
          break;
   case 2:
          q.dequeue();
          break;
   case 3:
          exit(0);
  }
 }
}

