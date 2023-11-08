nclude <stdio.h>
#include <stdlib.h>
#include <string.h>

struct symtab
{
    char name[10];
    int addr;
    char typ[10];
    int len;
};

int main()
{
    FILE *fp;
    int cho;
    struct symtab sy;
    char name1[10];
    fp=fopen("sym.bin","wb");
	if (!fp)
    {
		printf("Unable to open binary file!");
		return -1;
	}
	printf("Enter Choice 1.Insert 2.Modify 3.Delete 4.Search 5.Display 6.Exit ");
	scanf("%d",cho);
	switch(cho)
	{
    case 1:
        printf("\nEnter Name");
        scanf("%s",sy.name);
        printf("\nEnter Address");
        scanf("%d",sy.addr);
        printf("\nEnter Type");
        scanf("%s",sy.typ);
        printf("\nEnter Length");
        scanf("%d",sy.len);
        fwrite(&sy, sizeof(struct symtab), 1, fp);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        printf("\nEnter Name");
        scanf("%s",name1);
       while (fread(&sy,sizeof(struct symtab),1,fp) != NULL)
       {
           if (strcmp (name1, sy.name) == 0)
           {
			printf("Record found \n\n");
			printf("\n Name is %s",sy.name);
			printf("\n Address is is %d",sy.addr);
			printf("\n Type is  %s",sy.typ);
			printf("\n Length is %s",sy.len);
           }
       }
       break;
    case 5:
        printf("\n Records are \n");
        while (fread(&sy,sizeof(struct symtab),1,fp) != NULL)
        {
            printf("\n Name is %s",sy.name);
			printf("\n Address is is %d",sy.addr);
			printf("\n Type is  %s",sy.typ);
			printf("\n Length is %s",sy.len);
        }
	}
}

