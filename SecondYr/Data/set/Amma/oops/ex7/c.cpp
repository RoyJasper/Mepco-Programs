#include<iostream>
#include<string>
using namespace std;
class vector
{
int v[3];
public:
	vector operator +()
	{
	for(int i=0;i<3;i++)
	v[i]=+v[i];
	}
	vector operator -()
	{	
	for(int i=0;i<3;i++)
	v[i]=-v[i];
	}
  vector operator ++()
  {
  for(int i=0;i<3;i++)
  v[i]=++v[i];
  }
	vector operator ++(int dum)
	{
	for(int i=0;i<3;i++)
	v[i]=v[i]++;
	}
  vector(int tv[3])
  {
  for(int i=0;i<3;i++)
  v[i]=tv[i];
  }
void display()
 {
cout<<"\n resultant values  are\n   ";
for(int i=0;i<3;i++)
{
cout<<v[i];
cout<<"\t";
}
cout<<"\n ";
}
};
int main()
{
int t[3];
cout<<"\n enter the 3 elements\n     ";
for(int i=0;i<3;i++)
cin>>t[i];
vector vo(t);
+vo;
cout<<"\n over loading + operator \n";
vo.display();
-vo;
cout<<"\n over loading - operator  \n";
vo.display();
++vo;
cout<<"\n over loading ++ operator  \n";
vo.display();
cout<<"\n over loading operator ++\n";
vo++;
vo.display();
return 0;
}

