//Operating System Project By Rahul
//Section : K1656
//Registration NO. : 11615145

#include<stdio.h>
#include<stdbool.h>
//average time
void Wait(int process[], int n,int brust[], int wt[], int quan);
void TurnAround(int process[], int n,int brust[], int wt[], int temp[]);
void AvgTime(int process[], int n, int brust[],int quant,char name)
{
    int i,wt[n], temp[n], total_wt = 0, total_time= 0;
    int avg_wait , avg_turnaround ;
    Wait(process, n,brust, wt, quant);
    TurnAround(process, n, brust, wt,temp);
    printf("Processes :  ArivalTime:   BrustTime :  WaitingTime :   TurnAroundTime : \n");
    int count=0;
    for (i=1; i<=n; i++)
    {
        total_wt = total_wt + wt[i];
        total_time = total_time + temp[i];
	count+=brust[i];
	if(count>60)
	{
		break;
	}
        printf("%d \t\t  %d \t\t  %d \t \t %d \t\t\t%d\n",i,process[i],brust[i],wt[i],temp[i]);
    }

    // average query time and average waiting time
    avg_wait=total_wt/(i-1);
    avg_turnaround=total_time/(i-1);
    if(name=='s')
    {
	printf("\n Time he spend on handling of students query is : %d",avg_turnaround);
        printf("\n Average query time is : %d",avg_wait);
    }
    else
    {
	printf("\n Time he spend on handling of faculty query is : %d",avg_turnaround);
        printf("\n Average query time is : %d",avg_wait);
    }
}

//waiting time frome here

void Wait(int process[], int n,int brust[], int wt[], int quan)
{
    int i,t,rem[n];
    t=0;
    for (i = 1 ; i <= n ; i++)
        {
            rem[i] =  brust[i];
        }
    while(1)
    {
        bool flag= true;
        for(i = 1; i <= n; i++)
        {
            if (rem[i]>0)
            {
                flag=false; 
 
                if (rem[i]>quan)
                {
                    t += quan;
                    rem[i] -= quan;
                }
                else
                {
	            wt[i] = t - process[i];
                    t = t + rem[i];
                    //wt[i] = t - brust[i];
                    rem[i] = 0;
                }
            }
        }
        if (flag == true)
          break;
    }
}

//turn around time from here

void TurnAround(int process[], int n,int brust[], int wt[], int temp[])
{
    int i;
    for (i = 1; i <=n ; i++)
        temp[i] = brust[i] + wt[i];
}



int main()
{
 
    int x;
    printf("Enter number of process you want to enter : ");
    scanf("%d",&x);
    int process[x],process1[x];
    int burst_time[x],burst_time1[x]; 
      
    //for students 
    printf("ENTER ARIVAL TIME OF STUDENTS : \n\n");
    int i;
    for(i=1;i<=x;i++)
    {
	printf("Enter arival time of student : %d\t",i);
	scanf("%d",&process[i]);
        printf("\n");
    }
    
    printf("ENTER BRUST TIME OF STUDENTS: \n\n");
    for(i=1;i<=x;i++)
    {
       printf("Enter brust time of student : %d\t",i);
	scanf("%d",&burst_time[i]);
	printf("\n");
    }
    
    //for faculty
    printf("ENTER ARIVAL TIME OF FACULT: \n\n");
    for(i=1;i<=x;i++)
    {
        printf("Enter arival time of faculty : %d\t",i);
	scanf("%d",&process1[i]);
        printf("\n");
    }

    int n = sizeof process / sizeof process[0];

   

    printf("ENTER BRUST TIME FOR FACULTY : \n\n");
    for(i=1;i<=x;i++)
    {
        printf("Enter brust time of student : %d\t",i);
	scanf("%d",&burst_time1[i]);
        printf("\n");
    }
    
    printf("TIME QUANTUM USED process inside queue IS 5 :\n\n");
    int quantum = 5;
    printf("He will spend first 10 am to 11 am for handling students query: \n\n");
    AvgTime(process, n, burst_time, quantum,'s'); 
    n = sizeof process1 / sizeof process1[0];
    printf("\n\n");
   printf("He will spend first 11 am to 12 pm for handling Faculties query: \n\n");
    printf("\n\n\n");
    AvgTime(process1, n ,burst_time1,quantum,'f');
    return 0;
}
