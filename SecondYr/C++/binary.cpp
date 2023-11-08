#include<iostream>
using namespace std;
void bin(int);
int main()
{
 int n;
 cout<<"\nEnter no of array";
 cin>>n;
 bin(n);
}
void bin(int n)
{
    int *p,i,j,t,s;
    p=new int[n];
    cout<<"Enter the nos";
    for(i=0;i<n;i++)
    {
        cin>>p[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i]<p[j])
            {
               t=p[i];
               p[i]=p[j];
               p[j]=t;
            }
        }
    }
    cout<<"\nEnter search element";
    cin>>s;
    int u,l,m,c=0;
  /*  up=n-1;
    low=0;
    while(up>low)
    {
       m=(up+low)/2;
       if(p[m]==s)
       {
           cout<<"\nSearch element is present ";
           break;
       }
       else if(s>p[m])
        low=m+1;
       else
         up=m-1;
    }
    delete []p;

}*/
c=0;
l=0;
u=n-1;
m=(l+u)/2;
while(l<=u)
 {
  m=((l+u)/2);
  if(p[m]==s)
   {
    cout<<"The numbber  is present in"<<((2*m)+2);
    c=1;
    break;
   }
  else if(p[m]>s)
     l=m+1;
  else
     u=m-1;
  }
if(c==0)
 cout<<"Element is not present";

}
