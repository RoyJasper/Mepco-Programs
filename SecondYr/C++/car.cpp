#include<iostream>
#include<string>
using namespace std;
class car
{
 public:
   static int bmw;
   static int audi;
   static int jaquar;
   static int bugati;
 private:
   int no,yr;
   string name,manifacturer,col;
 public:
   static void totbmw();
   static void totaudi();
   static void totjaquar();
   static void totbugati();
   void read();
};
void car::read()
{
 cout<<"\nEnter model no:";
 cin>>no;
 cout<<"\nEnter colour";
 cin>>col;
 cout<<"\nEnter name";
 cin>>name;
 cout<<"\nEnter company";
 cin>>manifacturer;
 if(name=="bmw")
   bmw++;
 if(name=="audi")
   audi++;
 if(name=="jaquar")
   jaquar++;
 if(name=="bugati")
  bugati++;
}
int car::bmw;
int car::audi;
int car::bugati;
int car::jaquar;
void car::totbmw()
{
 cout<<"\nno of bmw cars are "<<car::bmw;
}
void car::totaudi()
{
 cout<<"\nno of audi cars are "<<car::audi;
}
void car::totbugati()
{
 cout<<"\ntotal no of bugatti "<<car::bugati;
}
void car::totjaquar()
{
 cout<<"\nTotal no of jaquar cars are "<<car::jaquar; 
}
int main()
{
 int i,n;
 cout<<"Enter no of cars";
 cin>>n;
 car b[20];
 for(i=0;i<n;i++)
  {
   cout<<"\n Enter car no"<<i+1;
   b[i].read();
  }
 car::totbmw();
 car::totaudi();
 car::totbugati();
 car::totjaquar(); 
}

