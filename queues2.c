#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
void display(queue *,queue *,queue *,queue *);

int main()
{
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
	
	//if(fp1==NULL)
	  //  printf("error");
	
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
	display(q1,q2,q3,q4);
	return 0;
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


void display(queue *q1,queue *q2,queue *q3,queue *q4)
{
node *temp=q1->head;
node *temp1=q2->head;
node *temp2=q3->head;
node *temp3=q4->head;
char s[20];
int n;
for(int i=0;i<15;i++)
{
for(int j=0;j<4;j++)
{
printf("%s \t",temp->data);
temp=temp->link;
}
printf("\nfor 50:50 press 1 else 2 for audience poll 0 for none");
scanf("%d",&n);

if(n==1)
{
 for(int k=0;k<2;k++)
    {
        printf("%s \t",temp2->data);
        temp2=temp2->link;
    }
    printf("\n");
}
else if(n==2)
{
    printf("%s \n",temp3->data);
    temp3=temp3->link;
}
else
{
temp2=temp2->link->link;
temp3=temp3->link;
}
printf("enter your answer  ");
scanf("%s",s);

if(!(strcmp(s,temp1->data)))
    printf("correct\n");
else
    printf("\n");
temp1=temp1->link;
}
}
