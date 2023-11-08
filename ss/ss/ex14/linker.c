#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char load[50][50],ads[50][50];
struct mp
{
        char addr[50],first[20],second[20];
};
typedef struct mp *node;
node initialize()
{
	node t;
	t=(node)malloc(sizeof(struct mp));
	return t;
}
int convert(char length[50])
{
	int a,i,b;
	char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	for(i=0;i<16;i++)
		if(length[1]==hex[i])
		{
			a=i;
			break;
		}
	if(length[0]=='1')
	{
		b=length[0]-48;
		b=b*16;
		a=a+b;
	}
	return a;
}
char* binary(char s,char string1[10])
{
	int i,n,a,r,j=0;
	char str[]="0000";
	char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	for(i=0;i<16;i++)
		if(s==hex[i])
		{
			a=i;
			break;
		}
	i=0;
	n=a;
	while(n!=0)
	{
		r=n%2;
		str[i]=r+48;
		i++;
		n=n/2;
	}
	for(i=strlen(str)-1;i>=0;i--)
	{
		string1[j]=str[i];
		j++;
	}
	return string1;
}
char * incre(char addr1[50])
{
	int k,j,a,i;
	char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	k=5;
begin:
	for(i=0;i<16;i++)
		if(addr1[k]==hex[i])
		{
			a=i;
			break;
		}
	a=a+1;
	if(a<16)
	{
		addr1[k]=hex[a];
	}
	else
	{
		addr1[k]='0';
		k=k-1;
		if(k>=0)
			goto begin;
	}
	return addr1;
}
int insert(char name[50],char type[50],char addr[50],FILE *fp)
{
        int n=0,i,j;
        node nn;
        nn=initialize();
        strcpy(nn->addr,name);
        strcpy(nn->first,type);
        strcpy(nn->second,addr);
        fwrite(&nn,sizeof(node),1,fp);
	return 1;
}
void disp(FILE *fp5)
{
        node nn;
        int t=0;
        char c;
        nn=initialize();
	printf("\n Address \t First \t Second");
        while((c = fgetc(fp5)) != EOF)
        {
                fseek(fp5,sizeof(node)*t,SEEK_SET);
                fread(&nn,sizeof(node),1,fp5);
                printf("\n %s\t %s\t %s\t",nn->addr,nn->first,nn->second);
                printf("\n");
                t++;
                fseek(fp5,sizeof(node)*t,SEEK_SET);
        }
        fclose(fp5);
}

char * adder(char a[50],char b[50])
{
	int k,kk,aa,bb,j,i,ka=0;
	char as[6]; 
	k=5;
	kk=3;
        char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        j=aa;
	while(k!=-1)
	{
        	for(i=0;i<16;i++)
                {
                	if(a[k]==hex[i])
                        {
                	        aa=i;
                                break;
                        }
                }			
		for(i=0;i<16;i++)
                {
                	if(b[k]==hex[i])
                        {
                	        bb=i;
                                break;
                        }
                }
		aa=bb+aa;
		if(aa<16)
		{
			b[k]=hex[aa];
			k=k-1;
		}
		else
		{
		njk:	aa=aa-16;
			b[k]=hex[aa];
			k=k-1;
			for(i=0;i<16;i++)
                	{
                		if(b[k]==hex[i])
                     		{
                			aa=i;
                     	         	break;
                       		}
                	}	
			aa++;
			if(aa==16)
			{
				ka=ka+1;
				goto njk;
			}
			b[k]=hex[aa];
			k=k+ka;
		}
	}
	return b;
}
	
void passone()
{
	int i=0,j,k=0,kk,jj,ii=0,ll=0;
	char addr[50],last[50],name[50][50],namee[50],addrr[50][50],d,add[]="000003";
	FILE *fp;
	fp=fopen("input.c","r");
	printf("Loader Address :: ");
	scanf("%s",addr);
	//printf("\nPASS ONE:");
	//printf("\nLOAD MAP:");
	d=fgetc(fp);
	for(jj=0;jj<3;jj++)
	{
	for(i=0;i<50;i++)
	{
		strcpy(addrr[i],"1");
	}
	d=fgetc(fp);
	d=fgetc(fp);
	i=0;
	while(d!='^')
	{
		namee[i]=d;
		i++;
		d=fgetc(fp);
	}
	while(ii!=2)
	{
		if(d=='^')
			ii++;
		d=getc(fp);
	}
	for(i=0;i<6;i++)
	{
		last[i]=d;
		d=fgetc(fp);
	}
	strcpy(last,adder(add,last));
	while(d!='D')
	{
		d=fgetc(fp);
	}
	d=fgetc(fp);
	d=fgetc(fp);
	i=0;
	k=0;
	kk=0;
	j=0;
	while(d!='R'&&d!='\n')
	{
		if(d=='^')
		{
			i++;
			if(kk==2)
			{
				kk=0;
				k++;
			}
			j=0;
		}
		else
		{
			if(i%2==0)
			{
				name[k][j]=d;
				j++;
			}
			else
			{
				addrr[k][j]=d;
				j++;
				kk=2;
			}
		}
		d=fgetc(fp);
	}
	k++;
	for(i=0;i<k;i++)
		strcpy(addrr[i],adder(addr,addrr[i]));
	//printf("\n%s\t%s\t%s\n",namee,addr,last);	
	strcpy(load[ll],namee);
	strcpy(ads[ll],addr);
	ll++;
	for(i=0;i<k;i++)
		printf("%s\t%s\n",name[i],addrr[i]);
	for(i=0;i<k;i++)
	{
		strcpy(load[ll],name[i]);
		strcpy(ads[ll],addrr[i]);
		ll++;
	}
	while(d!='H' && jj!=2)
		d=fgetc(fp);
	ii=0;
	strcpy(addr,adder(last,addr));
	}
}
char aaa[50];
int loader()
{
	int i,len,m,ifg,igg;
	char name[50],name1[50],address[50],length[50],string1[10],string2[10],d;
	char addr1[]="000000";
	FILE *fp,*fp2;
	fp=fopen("input.c","r");
	fp2=fopen("loade.bin","wb+");
	node nn;
	nn=initialize();
	i=0;
	while(i!=50)
	{
		name1[i]='\0';
		length[i]='\0';
		string1[i]='\0';
		string2[i]='\0';
		i++;
	}
	d=fgetc(fp);
	for(igg=0;igg<3;igg++)
	{
		d=fgetc(fp);
		d=fgetc(fp);
		i=0;
		while(d!='^')
		{
			name[i]=d;
			i++;
			d=fgetc(fp);
		}
		for(ifg=0;ifg<9;ifg++)
		{
			if(strcmp(name,load[ifg])==0)
				break;
		}
		i=0;
		while(i!=3)
		{
			d=fgetc(fp);
			if(d=='\n')
				i++;
		}
		d=fgetc(fp);
		while(d=='T')
		{
			d=fgetc(fp);
			d=fgetc(fp);
			i=0;
			while(d!='^')
			{
				addr1[i]=d;
				d=fgetc(fp);
				i++;
			}
			strcpy(addr1,adder(ads[ifg],addr1));
			d=fgetc(fp);
			i=0;
			while(d!='^')
			{
				length[i]=d;
				d=fgetc(fp);
				i++;
			}
			len=convert(length);
			for(i=0;i<len;i++)
			{
				strcpy(address,addr1);
					d=fgetc(fp);
				if(d=='^')
					d=fgetc(fp);
				strcpy(string1,binary(d,string1));
				d=fgetc(fp);
				strcpy(string2,binary(d,string2));
				m=insert(address,string1,string2,fp2);
				strcpy(addr1,incre(addr1));
			}
			d=fgetc(fp);
			d=fgetc(fp);
		}
		while(d!='H'&& igg!=2)
		{
			d=fgetc(fp);
		}
	}
	fclose(fp);
	fclose(fp2);	
	return 0;
}
char * subtract(char a[50],char b[50])
{
	int k,kk,aa,bb,j,i,ka=0;
	char as[6]; 
	k=5;
	kk=3;
        char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        j=aa;
	while(k!=-1)
	{
        	for(i=0;i<16;i++)
                {
                	if(a[k]==hex[i])
                        {
                	        aa=i;
                                break;
                        }
                }			
		for(i=0;i<16;i++)
                {
                	if(b[k]==hex[i])
                        {
                	        bb=i;
                                break;
                        }
                }
		aa=bb-aa;
		if(aa>-1)
		{
			b[k]=hex[aa];
			k=k-1;
		}
		else
		{
		njk:	aa=aa+16;
			b[k]=hex[aa];
			k=k-1;
			for(i=0;i<16;i++)
                	{
                		if(b[k]==hex[i])
                     		{
                			aa=i;
                     	         	break;
                       		}
                	}	
			aa--;
			if(aa==-1)
			{
				ka=ka+1;
				goto njk;
			}
			b[k]=hex[aa];
			k=k+ka;
		}
	}
	return b;
}
int po(int a,int b)
{
	int c=1,i;
	if(b==0)
	{
		return 1;
	}
	else
	{
		for(i=1;i<=b;i++)
		{
			c=c*a;
		}
		return c;
	}
}
char bintohex(char str[50])
{
	int j=0,i,c;
	char a[50],b;
	char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	for(i=strlen(str)-1;i>=0;i--)
	{
		a[j]=str[i];
		j++;
	}
	c=0;
	for(i=0;i<j;i++)
		if(a[i]=='1')
			c=c+po(2,i);
	for(i=0;i<16;i++)
		if(i==c)
			b=hex[i];
	return b;
}
void func(char addr1[50],char addr2[50],int kl,char cc)
{
	FILE *fp,*fp1;
	node nn,nn1;
	int t=0,j,i,k,m;
	char a[]="000000";
	char string1,string2,c,addr3[50],addr4[50],address[50];
	nn=initialize();
	nn1=initialize();
	if(kl%2==0)
	{
		fp=fopen("loade.bin","rb+");
		fp1=fopen("loadee.bin","wb+");
	}
	else
	{
		fp1=fopen("loade.bin","wb+");
		fp=fopen("loadee.bin","rb");
	}
	fseek(fp,sizeof(node)*t,SEEK_SET);
	while((c = fgetc(fp)) != EOF)
        {
                fseek(fp,sizeof(node)*t,SEEK_SET);
                fread(&nn,sizeof(node),1,fp);
		if(strcmp(nn->addr,addr1)==0)
		{	
			strcpy(addr4,nn->addr);
			j=0;
			for(i=0;i<3;i++)
			{
				string1=bintohex(nn->first);
				string2=bintohex(nn->second);
				a[j]=string1;
				j++;
				a[j]=string2;
				j++;
				t++;
				fseek(fp,sizeof(node)*t,SEEK_SET);
                		fread(&nn,sizeof(node),1,fp);
				strcpy(nn1->addr,nn->addr);
				strcpy(nn1->first,nn->first);
				strcpy(nn1->second,nn->second);
			}
			strcpy(addr3,a);
			if(cc=='+')
				strcpy(addr3,adder(addr2,addr3));
			else
				strcpy(addr3,subtract(addr2,addr3));
			for(i=0;i<6;i=i+2)
			{
				strcpy(address,addr4);
				strcpy(nn->first,binary(addr3[i],nn->first));
				strcpy(nn->second,binary(addr3[i+1],nn->second));
				m=insert(address,nn->first,nn->second,fp1);
				strcpy(addr1,incre(addr4));
			}
			fseek(fp,sizeof(node)*t,SEEK_SET);
                		fread(&nn,sizeof(node),1,fp);
			m=insert(nn1->addr,nn1->first,nn1->second,fp1);
			t=t+1;
		}
		else
		{
			m=insert(nn->addr,nn->first,nn->second,fp1);
			t++;
		}
	}
	fclose(fp);
	fclose(fp1);
}
void reloc()
{
	char rl[50],name1[50],c,addr[50],name[50];
	int i,kl=0,ifg,j;
	FILE *fp,*fp1,*fp2;
	fp=fopen("input.c","r");
	c=fgetc(fp);
	for(j=0;j<3;j++)
	{
		c=fgetc(fp);
		c=fgetc(fp);
		i=0;
		while(i!=50)
		{
			name[i]='\0';
			i++;
		}
		i=0;
		while(c!='^')
		{	
			name[i]=c;
			c=fgetc(fp);
			i++;
		}
		for(ifg=0;ifg<9;ifg++)
		{
			if(strcmp(name,load[ifg])==0)
				break;
		}
		strcpy(name,ads[ifg]);
		while(c!='M')
		{
			c=fgetc(fp);
		}
		i=0;
		while(i!=50)
		{
			name1[i]='\0';
			i++;
		}
		while(c=='M')
		{
			i=0;
			c=fgetc(fp);
			c=fgetc(fp);
			while(c!='^')
			{
				name1[i]=c;
				c=fgetc(fp);
				i++;
			}
			c=fgetc(fp);
			strcpy(name1,adder(name,name1));
			while(c!='^')
			{
				c=fgetc(fp);
			}
			c=fgetc(fp);
			i=0;
			while(i!=50)
			{
				rl[i]='\0';
				i++;
			}
			i=0;
			while(c!='\n')
			{
				if(c=='+'||c=='-')
				{
					addr[0]=c;
					c=fgetc(fp);
				}
				else
				{
					rl[i]=c;
					c=fgetc(fp);
					i++;
				}
			}
			for(ifg=0;ifg<9;ifg++)
			{
				if(strcmp(rl,load[ifg])==0)
					break;
			}
			strcpy(rl,ads[ifg]);
			func(name1,rl,kl,addr[0]);
			c=fgetc(fp);
			kl=kl+1;
		}
		while(c!='H'&& j<2)
		{
			c=fgetc(fp);
		}	
	}
	if(kl%2==1)
		fp2=fopen("loadee.bin","rb+");
	else
		fp2=fopen("loade.bin","rb+");
	printf("\n Pass Two : : \n");
	disp(fp2);
}
int main()
{
	int i=0;
	passone();
	loader();
	reloc();
}

