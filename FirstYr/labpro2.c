#include<stdio.h>
#include<stdlib.h>
struct node
{
int element;
struct node * next;
};
typedef struct node *list;
list createNode();
list insert(int,int,list);
list previousNode(int ,list);
list search(int,list);
void display(list);
int isEmpty(list);
int deleteNode(int,list);
int retrieve(int,list);
list makeEmpty(list);
list previousNodeadd(int,list);

list createNode()
{
list n=(list)malloc(sizeof(struct node));
if(n==NULL)
{
printf("Cannot allocate Memory\n");
return NULL;
}
n->next=NULL;
return n;
}
list insert(int pos, int x, list head)
{
list temp ,t;
temp= createNode();
if(temp==NULL)
        return NULL;
temp->element=x;
t=previousNode(pos,head);
if(t!=NULL)
{
        temp-> next=t->next;
        t->next=temp;
return temp;
}
else
return NULL;
}
list previousNode(int pos, list head)
{
list t=head;
int i;
for(i=0;i<pos-1;i++)
{
        if(t->next==NULL)
                return t;
t=t->next;
}
return t;
}
list search(int x, list head)
{
list t=head->next;
while(t!=NULL)
{
if(t->element==x)
        return t;
else
t=t->next;
}
return NULL;
}
void display(list head)
{
list t=head->next;
while(t!=NULL)
{
        printf("%d\n",t->element);
        t=t->next;
}
}
int isEmpty(list head)
{
if(head->next==NULL)
        return 1;
else
        return 0;
}
int deleteNode(int x, list head)
{
list k,t;
if(search(x,head)!=NULL)
{
        t=previousNodeadd(x,head);
        k=t->next;
        t->next=t->next->next;
        free(k);
        return 1;
}
else
        return 0;
}
list previousNodeadd(int x, list head)
{
list t=head;
while(t->next!=NULL)
{
        if(t->next->element=x)
                return t;
        else
                t=t->next;
}
return t;
}

main()
{
int x,pos,ch;
list head = createNode();
do{
printf("\nEnter the choice:");
printf("\n1.Insert \n2.Search\n3.Display\n4.Delete\nChoice?");
scanf("%d",&ch);
switch(ch)
{
        case 1:
                printf("\nEnter the Position and element to insert:");
                scanf("%d%d",&pos,&x);
                if(insert(pos,x,head)!=NULL)
#include<stdio.h>
#include<stdlib.h>
struct node
{
int element;
struct node * next;
};
typedef struct node *list;
list createNode();
list insert(int,int,list);
list previousNode(int ,list);
list search(int,list);
void display(list);
int isEmpty(list);
int deleteNode(int,list);
int retrieve(int,list);
list makeEmpty(list);
list previousNodeadd(int,list);

list createNode()
{
list n=(list)malloc(sizeof(struct node));
if(n==NULL)
{
printf("Cannot allocate Memory\n");
return NULL;
}
n->next=NULL;
return n;
}
list insert(int pos, int x, list head)
{
list temp ,t;
temp= createNode();
if(temp==NULL)
        return NULL;
temp->element=x;
t=previousNode(pos,head);
if(t!=NULL)
{
        temp-> next=t->next;
        t->next=temp;
return temp;
}
else
return NULL;
}
list previousNode(int pos, list head)
{
list t=head;
int i;
for(i=0;i<pos-1;i++)
{
        if(t->next==NULL)
                return t;
t=t->next;
}
return t;
}
list search(int x, list head)
{
list t=head->next;
while(t!=NULL)
{
if(t->element==x)
        return t;
else
t=t->next;
}
return NULL;
}
void display(list head)
{
list t=head->next;
while(t!=NULL)
{
        printf("%d\n",t->element);
        t=t->next;
}
}
int isEmpty(list head)
{
if(head->next==NULL)
        return 1;
else
        return 0;
}
int deleteNode(int x, list head)
{
list k,t;
if(search(x,head)!=NULL)
{
        t=previousNodeadd(x,head);
        k=t->next;
        t->next=t->next->next;
        free(k);
        return 1;
}
else
        return 0;
}
list previousNodeadd(int x, list head)
{
list t=head;
while(t->next!=NULL)
{
        if(t->next->element=x)
                return t;
        else
                t=t->next;
}
return t;
}

main()
{
int x,pos,ch;
list head = createNode();
do{
printf("\nEnter the choice:");
printf("\n1.Insert \n2.Search\n3.Display\n4.Delete\nChoice?");
scanf("%d",&ch);
switch(ch)
{
        case 1:
                printf("\nEnter the Position and element to insert:");
                scanf("%d%d",&pos,&x);
                if(insert(pos,x,head)!=NULL)
                        printf("Insertion Successful\n");
                else
                        printf("Error in Insertion\n");
                break;
        case 2:
                printf("\nEnter the element to search:");
                scanf("%d",&x);
                if(search(x,head)!=NULL)
                        printf("\nElement found\n");
                else
                        printf("\nElement not found\n");
                break;
        case 3:
                printf("\nThe list is \n");
                display(head);
                break;
        case 4:
                printf("\nEnter the element to delete:");
                scanf("%d",&x);
                if(deleteNode(x,head)==1)
                        printf("Element deleted\n");
                else
                        printf("Error in deletion\n");
                break;
}
}while(ch<=4);
}
bash-3.2$ cc linked.c
bash-3.2$ ./a.out

Enter the choice:
1.Insert 
2.Search
3.Display
4.Delete
Choice?1

Enter the Position and element to insert:1
10
Insertion Successful

Enter the choice:
1.Insert 
2.Search
3.Display
4.Delete
Choice?1

Enter the Position and element to insert:2
20
Insertion Successful

Enter the choice:
1.Insert 
2.Search
3.Display
4.Delete
Choice?2

Enter the element to search:10

Element found

Enter the choice:
1.Insert 
2.Search
3.Display
4.Delete
Choice?3

The list is 
10
20

Enter the choice:
1.Insert 
2.Search
3.Display
4.Delete
Choice?4

Enter the element to delete:20
Element deleted

Enter the choice:
1.Insert 
2.Search
3.Display
4.Delete
Choice?5
bash-3.2$ exit
exit

                        printf("Insertion Successful\n");
                else
                        printf("Error in Insertion\n");
                break;
        case 2:
                printf("\nEnter the element to search:");
                scanf("%d",&x);
                if(search(x,head)!=NULL)
                        printf("\nElement found\n");
                else
                        printf("\nElement not found\n");
                break;
        case 3:
                printf("\nThe list is \n");
                display(head);
                break;
        case 4:
                printf("\nEnter the element to delete:");
                scanf("%d",&x);
                if(deleteNode(x,head)==1)
                        printf("Element deleted\n");
                else
                        printf("Error in deletion\n");
                break;
}
}while(ch<=4);
}
bash-3.2$ cc linked.c
bash-3.2$ ./a.out

Enter the choice:
1.Insert 
2.Search
3.Display
4.Delete
Choice?1

Enter the Position and element to insert:1
10
Insertion Successful

Enter the choice:
1.Insert 
2.Search
3.Display
4.Delete
Choice?1

Enter the Position and element to insert:2
20
Insertion Successful

Enter the choice:
1.Insert 
2.Search
3.Display
4.Delete
Choice?2

Enter the element to search:10

Element found

Enter the choice:
1.Insert 
2.Search
3.Display
4.Delete
Choice?3

The list is 
10
20

Enter the choice:
1.Insert 
2.Search
3.Display
4.Delete
Choice?4

Enter the element to delete:20
Element deleted

Enter the choice:
1.Insert 
2.Search
3.Display
4.Delete
Choice?5
bash-3.2$ exit
exit


