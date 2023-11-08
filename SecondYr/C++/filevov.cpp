#include<fstream>
#include<iostream>
using namespace std;
main()
{
 char ch;
 int c=0;
 ofstream entryfile("roy.txt");
 cout<<"\n Enter Data to file ....\n";
 while(true)
 {
  cin.get(ch);
  if(ch=='#')
   break;
  else
   entryfile<<ch;
 }
 entryfile.close();
 ifstream entryfile1("roy.txt");
 {
  while(!entryfile1.eof())
  {
  // c=c+1;
   entryfile1>>ch;
   if(isalpha(ch))
      c=c+1;
  }
  entryfile1.close();
  cout<<"\n No of characters  are  "<<c-1;
 }
}
