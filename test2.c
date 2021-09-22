#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
char q[100];
struct node *next;
}node;
typedef struct list{
node *head;
}list;
void create(list *);
void display(list *);
void assign(FILE *, list *);
void init(list *li)
{
li->head=NULL;
}

int main()
{
list *li;
li=(list *)malloc(sizeof(list));
init(li);
int i=15;
while(i>0){
create(li);
i--;
}
//char buf[200];
printf("RULES:You have 15 Q...each Q has 4 options...\nYou have 2 lifelines namely 50:50 and Audience poll\nanswer each questions\n");
FILE *fp;
fp=fopen("Questions1.txt","r");

assign(fp,li);
display(li);
fclose(fp);
return 0;
}

void assign(FILE *fp,list *li)
{
char buf[5000];
node *w=li->head;
for(int j=15;j>0;j--)
{
fgets(buf,5000,fp);
strcpy(w->q,buf);
w=w->next;
}
}

void create(list *li)
{
node *temp=(node *)malloc(sizeof(node));
temp->next=NULL;
strcpy(temp->q,"hello how are you");
if(li->head==NULL)
{
li->head=temp;
}
else
{
node *p=li->head;
while(p->next!=NULL)
{
p=p->next;
}
p->next=temp;
}
}
void display(list *li)
{
node *p=li->head;
for(int i=0;i<15;i++)
{
printf("%s \n",p->q);
p=p->next;
}
}


