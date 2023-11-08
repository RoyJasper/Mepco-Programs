#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
 char ch;
 int count;
 count=0;
 ofstream entryfile("aaa.txt");
 while(true)
 {
  cin.get(ch);
  if(ch=='$')
    break;
  entryfile<<ch;
 }
 entryfile.close();
 ifstream disfile("aaa.txt");
 while(!disfile.eof())
 {
  disfile>>ch;
  if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u'))
    count++;
 }
 cout<<"\n no of vowels in a file :"<<count;
 disfile.close();
}


