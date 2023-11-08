#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table
{
    char name[10];
    int add;
    char type[10];
    int length;
};

int main()
{
    FILE *fp;
    FILE *fpt;
    int c,flag=0,m,j,i,y;
    struct table s,ts;
    char n[100],t[100];

    while(1)
    {
        printf("\n Enter Choice \n1.Insert \n2.Modify \n3.Delete \n4.Search \n5.Display \n6.Exit \n ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            fp=fopen("a.bin","ab+");

            printf("\nEnter symbol  Name :");
            scanf("%s",s.name);
            printf("\nEnter Address :");
            scanf("%d",&s.add);
            printf("\nEnter Type :");
            scanf("%s",s.type);
            printf("\nEnter Length :");
            scanf("%d",&s.length);
            fwrite(&s, sizeof(struct table), 1, fp);
             rewind(fp);
             fclose(fp);
            fp=fopen("a.bin","rb+");
         
                   m=0;
            while (fread(&s,sizeof(struct table),1,fp) != NULL)
            {
                m++;
            }
            rewind(fp);
            for(i=0; i<m; i++)
            {
                rewind(fp);
                 fseek(fp,i*(sizeof(struct table)), SEEK_CUR);
                fread(&s,sizeof(struct table),1,fp);
                for(j=i+1; j<m; j++)
                {
                    rewind(fp);
                     fseek(fp,j*(sizeof(struct table)), SEEK_CUR);
                    fread(&ts,sizeof(struct table),1,fp);
                    if (strcmp (s.name,ts.name) > 0)
                    {
                        rewind(fp);
                        fseek(fp,(i)*(sizeof(struct table)), SEEK_CUR);
                        fwrite(&ts, sizeof(struct table), 1, fp);
                        rewind(fp);
                        fseek(fp,(j)*(sizeof(struct table)), SEEK_CUR);
                        fwrite(&s, sizeof(struct table), 1, fp);
                    }
                }
            }

            printf("\n Inserted successfully \n");
            fclose(fp);
            break;
        case 2:
            fp=fopen("a.bin","rb+");
            printf("\n Enter the symbol name  ");
            scanf("%s",n);
            int y=0;
            while (fread(&s,sizeof(struct table),1,fp) != NULL)
            {
                if (strcmp (n, s.name) == 0)
                {

                    fseek(fp,(-1)*(sizeof(struct table)), SEEK_CUR);
                    printf("\nEnter new Address ");
                    scanf("%d",&s.add);
                    printf("\nEnter new Type ");
                    scanf("%s",s.type);
                    printf("\nEnter new Length ");
                    scanf("%d",&s.length);
                    fwrite(&s, sizeof(struct table), 1, fp);
                    printf("\n Modified\n");
                    y=1;
                    break;
                }
            }
            if(y==0)
            {
                printf("\n symbol name not found \n\n");
            }
            fclose(fp);
            break;

        case 3:
            fp=fopen("a.bin","ab+");

            fpt=fopen("b.bin","wb+");
     

            printf("\n Enter symbol  Name  ");
            scanf("%s",n);
            rewind(fp);
            while (fread(&s,sizeof(struct table),1,fp) != NULL)
            {
                if (strcmp (n, s.name) == 0)
                {
                    
                    flag=1;
                }
                else
                {
                    fwrite(&s, sizeof(struct table), 1, fpt);
                }
            }
            if(flag==0)
            {
                printf(" \n symbol  not found \n\n");
            }

            fclose(fp);
            fclose(fpt);
            remove("a.bin");
            int x=rename("b.bin","a.bin");
            if(x==-1)
            {
                printf("\n not  deleted\n");
            }
            else
            {
                printf("\nSuccess in  deleting\n");
            }
            break;
        case 4:
            fp=fopen("a.bin","ab+");
             flag=0;

            printf("\n Enter symbol Name ");
            scanf("%s",n);
            rewind(fp);
            while (fread(&s,sizeof(struct table),1,fp) != NULL)
            {
                if (strcmp (n, s.name) == 0)
                {
                    
                    printf("\n symbol Name    :%s",s.name);
                    printf("\n Address : %d",s.add);
                    printf("\n Type    :  %s",s.type);
                    printf("\n Length  : %d",s.length);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("\n symbol name not found \n\n");
            }
            fclose(fp);
            break;
        case 5:
            fp=fopen("a.bin","ab+");
            
            while (fread(&s,sizeof(struct table),1,fp) != NULL)
            {
                if(s.add!=0)
                {

                    printf("\n Name   : %s",s.name);
                    printf("\n Address: %d",s.add);
                    printf("\n Type   :  %s",s.type);
                    printf("\n Length : %d \n \n ",s.length);
                }
            }
            fclose(fp);
            break;
        case 6:
            remove("a.bin");
            return 0;
            break;
        default:
            printf("invalid choise");
            break;
        }
    }
    fclose(fp);
    fclose(fpt);
    
}
