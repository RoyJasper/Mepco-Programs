#include<time.h>
#include<stdio.h>
int main()
{
int i;
time_t start,end;
struct tm *cpu;
time(&start);
cpu=localtime(&start);
printf("%.2d",cpu->tm_sec);
return 1;
}
