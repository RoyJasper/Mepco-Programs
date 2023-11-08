#include<iostream>
#include<string.h>
using namespace std;
class loan
{
public:
     string ltype;
     int lno;
     void getdetails()
{
cout<<"enter the loan no ";
cin>>lno;
cout<<"enter the loan type ";
cin>>ltype;
}
bool operator < (loan &e)
{
 if(ltype<e.ltype)
 return true;
 else
 return false;
}
bool operator == (loan &e)
{
 if(ltype==e.ltype)
 return true;
 else
 return false;
}};
//template<>
//void bubblesort(loan [],int n);
//template<>
 //void search(loan [],int n,type);

template<typename type>
void bubblesort(type b[],int n)
{
 loan t;
 int i,j;
 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(b[i].ltype>b[j].ltype)
   {
    t=b[i];
    b[i]=b[j];
    b[j]=t;
   }
   if(b[i].ltype==b[j].ltype)
   {
    if(b[i].lno>b[j].lno)
    {
        t=b[i];
    b[i]=b[j];
    b[j]=t;
    }
   }

 }}
 for(i=0;i<n;i++)
 {
 cout<<"  "<<b[i].ltype;
 cout<<"  "<<b[i].lno<<"\n";
 }

 }
template<typename type>
void searched(type b[],int n,type a)
{

 int mid,low=0,up=n-1;
 while(up>=low)
 {
  mid=(low+up)/2;
  if((b[mid].ltype==a.ltype)&&(b[mid].lno==a.lno))
  {
  cout<<"The search loan present in "<<mid+1;
  break;
  }
  else if((b[mid].ltype<a.ltype)&&(b[mid].lno<a.lno))
  low=mid+1;
  else /*((b[mid].ltype>a.ltype)&&(b[mid].lno>a.lno))*/
  up=mid-1;
 }
  if(low>up)
    cout<<"not present";
 }

int main()
{
 loan b[20],a;
 int i,n,z;
 cout<<"enter the no of customer";
 cin>>n;
 for(i=0;i<n;i++)
 b[i].getdetails();
 bubblesort(b,n);
 cout<<"enter the search details\n";
 a.getdetails();
 searched<loan>(b,n,a);
}
