#include<stdio.h>
main() 
{ 
	FILE *fopen(), *fp; 
	int c ; 
	fp=fopen(“roy.txt”,“r”); 
	c=getc(fp) ; 		
	while(c!=EOF) 
	{
		putchar(c); 		
		c=getc(fp); 	 
	}
	fclose(fp); 
}
