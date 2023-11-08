#include <stdio.h>
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
    FILE *fpt;
    int cho,fou=0,diff=0,modi,taddr,tlen,co=1,n=0,j,i;
    struct symtab sy,syt;
    char name1[10],tname[10],ttyp[10];

    while(1)
    {
        printf("\n Enter Choice 1.Insert 2.Modify 3.Delete 4.Search 5.Display 6.Sort 7.Delete all records 8.Exit  ");
        scanf("%d",&cho);
        switch(cho)
        {
        case 1:
            fp=fopen("sym.bin","ab+");
            if (!fp)
            {
                printf("\nUnable to open file!");
                return -1;
            }

            printf("\nEnter Name ");
            scanf("%s",sy.name);
            printf("\nEnter Address ");
            scanf("%d",&sy.addr);
            printf("\nEnter Type ");
            scanf("%s",sy.typ);
            printf("\nEnter Length ");
            scanf("%d",&sy.len);
            fwrite(&sy, sizeof(struct symtab), 1, fp);
            printf("\n Inserted \n");
            fclose(fp);
            break;
        case 3:
            fp=fopen("sym.bin","ab+");
            if (!fp)
            {
                printf("\nUnable to open file!");
                return -1;
            }

            fpt=fopen("temp.bin","wb+");
            if (!fpt)
            {
                printf("\nUnable to open temp file!");
                return -1;
            }

            printf("\n Enter Name  ");
            scanf("%s",name1);
            rewind(fp);
            while (fread(&sy,sizeof(struct symtab),1,fp) != NULL)
            {
                if (strcmp (name1, sy.name) == 0)
                {
                    printf("\n Record found and deleted \n");
                    fou=1;
                }
                else
                {
                    fwrite(&sy, sizeof(struct symtab), 1, fpt);
                }
            }
            if(fou==0)
            {
                printf(" \n Record not found \n\n");
            }

            fclose(fp);
            fclose(fpt);
            remove("sym.bin");
            int ren=rename("temp.bin","sym.bin");
            if(ren==-1)
            {
                printf("Failure");
            }
            else
            {
                printf("Success");
            }
            break;
        case 2:
            fp=fopen("sym.bin","rb+");
            if (!fp)
            {
                printf("\nUnable to open file!");
                return -1;
            }
            printf("\n Enter Name of node to be modified  ");
            scanf("%s",name1);
            while (fread(&sy,sizeof(struct symtab),1,fp) != NULL)
            {
                if (strcmp (name1, sy.name) == 0)
                {
                    printf("Record found \n\n");
                    printf("\n Name is %s",sy.name);
                    printf("\n Address is is %d",sy.addr);
                    printf("\n Type is  %s",sy.typ);
                    printf("\n Length is %d",sy.len);

                    // fseek(fp,co*(sizeof (struct symtab)),SEEK_CUR);
                    fseek(fp,(-1)*(sizeof(struct symtab)), SEEK_CUR);
                    printf("\n\n\nEnter new Name ");
                    scanf("%s",syt.name);
                    printf("\nEnter new Address ");
                    scanf("%d",&syt.addr);
                    printf("\nEnter new Type ");
                    scanf("%s",syt.typ);
                    printf("\nEnter new Length ");
                    scanf("%d",&syt.len);
                    fwrite(&syt, sizeof(struct symtab), 1, fp);
                    printf("\nRecord Modified\n");
                    fou=1;
                    break;
                }
                else
                {
                    co++;
                }
            }
            if(fou==0)
            {
                printf("\n Record not found \n\n");
            }
            fclose(fp);
            break;
        case 4:
            fp=fopen("sym.bin","ab+");
            if (!fp)
            {
                printf("\nUnable to open file!");
                return -1;
            }

            printf("\n Enter Name ");
            scanf("%s",name1);
            rewind(fp);
            while (fread(&sy,sizeof(struct symtab),1,fp) != NULL)
            {
                if (strcmp (name1, sy.name) == 0)
                {
                    printf(" \nRecord found \n\n");
                    printf("\n Name is %s",sy.name);
                    printf("\n Address is is %d",sy.addr);
                    printf("\n Type is  %s",sy.typ);
                    printf("\n Length is %d",sy.len);
                    fou=1;
                    break;
                }
            }
            if(fou==0)
            {
                printf("\n Record not found \n\n");
            }
            fou=0;
            fclose(fp);
            break;
        case 5:
					jas:
            fp=fopen("sym.bin","ab+");
            if (!fp)
            {
                printf("\nUnable to open file!");
                return -1;
            }

            printf("\n Records are \n");
            while (fread(&sy,sizeof(struct symtab),1,fp) != NULL)
            {
                if(sy.addr!=0)
                {
                    printf("\n Name is %s",sy.name);
                    printf("\n Address is is %d",sy.addr);
                    printf("\n Type is  %s",sy.typ);
                    printf("\n Length is %d \n \n ",sy.len);
                }
            }
            fclose(fp);
            break;
        case 6:
            fp=fopen("sym.bin","rb+");
            if (!fp)
            {
                printf("\nUnable to open file!");
                return -1;
            }
            while (fread(&sy,sizeof(struct symtab),1,fp) != NULL)
            {
                n++;
            }
            rewind(fp);
            for(i=0; i<n; i++)
            {
                rewind(fp);
                 fseek(fp,i*(sizeof(struct symtab)), SEEK_CUR);
                fread(&sy,sizeof(struct symtab),1,fp);
                for(j=i+1; j<n; j++)
                {
                    rewind(fp);
                     fseek(fp,j*(sizeof(struct symtab)), SEEK_CUR);
                    fread(&syt,sizeof(struct symtab),1,fp);
                    if (strcmp (sy.name,syt.name) > 0)
                    {
                        rewind(fp);
                        fseek(fp,(i)*(sizeof(struct symtab)), SEEK_CUR);
                        //fseek(fp,-1*(sizeof(struct symtab)), SEEK_CUR);

                        fwrite(&syt, sizeof(struct symtab), 1, fp);
                        rewind(fp);
                        fseek(fp,(j)*(sizeof(struct symtab)), SEEK_CUR);
                        //fseek(fp,-1*(sizeof(struct symtab)), SEEK_CUR);

                        fwrite(&sy, sizeof(struct symtab), 1, fp);
                    }
                }
            }
            printf("\n Records in binary file are sorted ..\n");
            fclose(fp);
						goto jas;
            break;
        case 8:
            return 0;
            break;
        case 7:
            fpt=fopen("temp.bin","wb+");
            if (!fpt)
            {
                printf("\nUnable to open temp file!");
                return -1;
            }
            fclose(fpt);
            remove("sym.bin");
            int ren1=rename("temp.bin","sym.bin");
            if(ren1==-1)
            {
                printf("Failure");
            }
            else
            {
                printf("\n Delete all record Success \n");
            }
            break;
        default:
            printf("Enter correct option");
            break;
        }
    }
    fclose(fp);
    fclose(fpt);
}
