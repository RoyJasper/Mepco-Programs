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
      cin>>mark[i];
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
     cout<<"\nmarks :\t"
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
  cout<<"queue is full";
 else
  rear++;
  s[rear]=value;
}
template<typename type>

      
