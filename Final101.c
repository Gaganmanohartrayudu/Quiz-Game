#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node1{
char q[100];
struct node1 *next;
}node1;
typedef struct list{
node1 *head;
}list;

typedef struct node
{
    char data[50];
    struct node *link;
}node;

typedef struct queue
{
    node *head;
    node *tail;
}queue;

void create1(queue *);
void insert(FILE *,queue *,queue *,queue *,queue *);
void display(list *,queue *,queue *,queue *,queue *);

void create(list *);
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
printf("\n  \t\t Welcome TO KBC \n   RULES:You have 15 Q...each Q has 4 options...\n   You have 2 lifelines namely 50:50 and Audience poll\n     \t\t Good Luck\n");
FILE *fp;
fp=fopen("Questions1.txt","r");
assign(fp,li);

    queue *q1;
	queue *q2;
	queue *q3;
	queue *q4;
	q1=(queue *)malloc(sizeof(queue));
	q2=(queue *)malloc(sizeof(queue));
	q3=(queue *)malloc(sizeof(queue));
	q4=(queue *)malloc(sizeof(queue));
	q1->head=q1->tail=NULL;
	q2->head=q2->tail=NULL;
	q3->head=q3->tail=NULL;
	q4->head=q4->tail=NULL;

	FILE *fp1;


	for(int i=0;i<60;i++)
	{
	create1(q1);
	}
	for(int i=0;i<15;i++)
	{
	create1(q2);
	}
	for(int i=0;i<30;i++)
	{
	create1(q3);
	}
	for(int i=0;i<15;i++)
	{
	create1(q4);
	}

	insert(fp1,q1,q2,q3,q4);
	display(li,q1,q2,q3,q4);


fclose(fp);
return 0;
}
void assign(FILE *fp,list *li)
{
char buf[5000];
node1 *w = li->head;
for(int j=12;j>0;j--)
{
fgets(buf,5000,fp);
strcpy(w->q,buf);
w=w->next;
}
}

void create(list *li)
{
node1 *temp=(node1 *)malloc(sizeof(node1));
temp->next=NULL;
strcpy(temp->q,"hello how are you");
if(li->head==NULL)
{
li->head=temp;
}
else
{
node1 *p=li->head;
while(p->next!=NULL)
{
p=p->next;
}
p->next=temp;
}
}

void create1(queue *qi)
{
node *temp=(node *)malloc(sizeof(node));
strcpy(temp->data,"hello");
temp->link=NULL;
if(qi->head==NULL)
{
qi->head=qi->tail=temp;
}
else
{
qi->tail->link=temp;
qi->tail=temp;
}
}


void insert(FILE *fp1, queue *q1, queue *q2,queue *q3,queue *q4)
{
fp1=fopen("options1.csv","r");
char s[5000];
char *p;
node *temp=q1->head;
node *temp1=q2->head;
node *temp2=q3->head;
node *temp3=q4->head;
while(fgets(s,5000,fp1)!=NULL)
{
    p=strtok(s,",");
    strcpy(temp->data,p);
    temp=temp->link;
    for(int i=0;i<3;i++)
    {
    p=strtok(NULL,",");
    strcpy(temp->data,p);
    temp=temp->link;
    }

    p=strtok(NULL,",");
    strcpy(temp1->data,p);
    temp1=temp1->link;

    p=strtok(NULL,",");
    strcpy(temp2->data,p);
    temp2=temp2->link;

    p=strtok(NULL,",");
    strcpy(temp2->data,p);
    temp2=temp2->link;

    p=strtok(NULL,",");
    strcpy(temp3->data,p);
    temp3=temp3->link;
}
fclose(fp1);
}

void display(list *li,queue *q1,queue *q2,queue *q3,queue *q4)
{
int o1=1;
int o=0;
int i1=0;
int i2=0;

node1 *p=li->head;
node *temp=q1->head;
node *temp1=q2->head;
node *temp2=q3->head;
node *temp3=q4->head;
char s[20];
char n;

for(int i=0;i<15;i++)
{
printf("\n %d .%s \n",o1,p->q);
o1++;
p=p->next;

for(int j=0;j<4;j++)
{
printf("%s \t",temp->data);
temp=temp->link;
}

rec:

if(i1==0 && i2==0)
{
printf("\npress  1: 50:50   2: audience poll   0:None   ");
scanf("%c",&n);
}
else if(i1==0)
{
printf("\npress  1: 50:50    0:None   ");
scanf("%c",&n);
}
else
{
printf("\npress  2: audience poll   0:None   ");
scanf("%c",&n);
}
if(n == '1')
{
 for(int k=0;k<2;k++)
    {
        printf("%s \t",temp2->data);
        temp2=temp2->link;
    }
    printf("\n");
    i1=1;
}
else if(n == '2')
{
    printf("%s \n",temp3->data);
    temp3=temp3->link;
    i2=1;
}
else if(n == '0')
{
temp2=temp2->link->link;
temp3=temp3->link;
}
else
{
printf("\nplease enter the correct choice");
goto rec;
}
printf("enter your answer  ");
scanf("%s",s);

if(!(strcmp(s,temp1->data)))
{
    printf("\n.....correct answer......\n");
    o++;
    }
else{
    printf("\n.....sorry wrong answer......\n");
    printf("The correct answer is  %s \n",temp1->data);
    printf("......Sorry!!! You Lost.........\n");
    break;
    }
temp1=temp1->link;
}
if(o==15)
    printf("\n.....Congratulations!!!! You Won 1 Crore.....\n");
}
