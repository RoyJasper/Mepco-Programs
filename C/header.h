#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void create(int);
void getdetail(int);
void printindi(int,int);
void printall(int);
void printsal(int);
void topper(int);
struct employee
{
int empno,bp;
char empnm[20];
float hra,da,pf,sal;
int a;
}*e;

