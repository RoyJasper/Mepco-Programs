#include<iostream>
using namespace std;
void po(float *,float *,float *);
void rv(float &,float &,float &);
int main()
{
 float p,n,r;
 cout<<"Enter principle amount\n";
 cin>>p;
 cout<<"Enter no of years\n";
 cin>>n;
 cout<<"Enter rate\n";
 cin>>r;
 po(&p,&n,&r);
 rv(p,n,r);
 return 0;
}
void po(float *p,float *n,float *r)
{
 float si;
 si=((*p)*(*n)*(*r))/100;
 cout<<"\nSI using pointer is"<<si;
}
void rv(float &p,float &n,float &r)
{
  float si;
 si=(p*n*r)/100;
 cout<<"\nSI using address is"<<si;
}

