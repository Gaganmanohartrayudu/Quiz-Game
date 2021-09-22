#include <stdio.h>
#include<time.h>
#include<stdlib.h>
/*uint32_t GetTickCount(){
    struct timespec ts;
    unsigned theTick= 0U;
    clock_gettime(CLOCK_REALTIME,&ts);
    theTick = ts.tv_nsec /1000000;
    theTick += ts.tv_sec*1000;
    return theTick;
    }

int main()
{
int i;
unsigned int start_time,check_time;
start_time=GetTickCount();
check_time=start_time+2000;
while(!kbhit())
{
printf("P E T I");
while((check_time > GetTickCount()))
{
if(kbhit())
{
i=getch();
printf("Data accepted");return 0;
}
}
printf("time out : 2 sec \n");
printf("timer again set to 0");
start_time=GetTickCount();
check_time=start_time+2000;
}
return 0;
}*/

//int timer();
/*
int main()
{
	int sec = 0;
	clock_t before = clock();
	//int t=0;
	do
	{
	  clock_t difference=clock() - before;
	  sec= difference/CLOCKS_PER_SEC;
	  }while(sec < 10);
	  printf("time taken is %d seconds %d milliseconds",sec, (sec*1000)%1000);
	return 0;
}*/
int main()
{
int sec;
int n;
clock_t start;
printf("enter a number");
start = clock();
scanf("%d",&n);
start = clock()-start;
sec=((int)start)/CLOCKS_PER_SEC;
printf("the time taken is %d",sec);
return 0;
}

