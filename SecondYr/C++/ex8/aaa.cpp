#include<iostream>
#include<string>
using namespace std;
class integer
{
private:
int lb;
int ub;
int value;
public:
void validate()
{
cout<<value;
if((value>=lb)&&(value<=ub))
cout<<"\n value is present in the given limit 0-100\n";
else
cout<<"\n  value is not present in the given limit 0-100\n";
}
integer(int x=0,int y=100,int z=0  )
{
value=x;
ub=y;
lb=z;
}
integer operator () (int k)
{
cout<<k;
cout<<"\n**********************************************\n";
value=k;
return integer (value);
}
};
int main()
{
int x;
cout<<"\n  enter the value to be checked    :";
cin>>x;
integer il=x;
integer (x).validate();
return 0;
}

