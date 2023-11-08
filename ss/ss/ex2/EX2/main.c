
#include"pass1.h"
int main()
{

    Pass1("add.txt","intermediate.txt","symboltable.txt");
    printf("\n----------------------------------------------------");
    printf("\n\t INTERMEDIATE FILE\n");
    DisplayIntermediatefile("intermediate.txt");
    printf("\n----------------------------------------------------");
    printf("\n\n\t SYMBOL TABLE\n");
    DisplaySymbolTable("symboltable.txt");
    return 0;
}

