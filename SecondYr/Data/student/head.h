#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void allocatememory(int);
void scandetails(int);
void particularstudent(int,int);
void printall();
void top(int);
void rank(int);
void rankcalc(int);
void print(int);
struct student
{
 int m1,m2,m3,tot,rank,rno;
 float cgpa,avg;
 char name[15];
}*s;
