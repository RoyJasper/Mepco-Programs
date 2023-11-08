#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a=1000;
    char b[4]={'1A'};
    char buffer[20];
    itoa(a,buffer,2);   // here 2 means binary
    printf("Binary value = %s\n", buffer);

    itoa(a,buffer,10);   // here 10 means decimal
    printf("Decimal value = %s\n", buffer);

    itoa(a,buffer,16);   // here 16 means Hexadecimal
    printf("Hexadecimal value = %s\n", buffer);
    printf("%x",b);
    itoa(buffer,b,10);
    printf("\n%s",b);
    return 0;
}
