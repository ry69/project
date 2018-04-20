#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>
#include<string.h>

bool student_finish=false;
bool faculty_finish=false;
int burst2 = 0;
int i=0;
int a[100],f=0;
int wait_time_faculty( int burst_faculty[], int rburst_faculty[], int f1, int wait_faculty[], int quant_data, int quantum, int t )
  { 
  int ft=0;int count=0;

  bool done = false;
  
  for (i = 0 ; i < f1; i++)
  count += burst_faculty[i];

  
  while(ft < quantum && faculty_finish == false)
    {
    for (i = 0 ; i < f1; i++)
    {  
      if (rburst_faculty[i] > 0)
      { 
        if (rburst_faculty[i] >= quant_data)
        {
          // adding burst to total time may or mat not exceed the queue burst 
          //check if adding exceeds queue burst
    
          if((ft + quant_data) >= quantum)
     		 {
			  
     		 if((ft + quant_data) > quantum)
			  {
     		 	printf("  F%d  |",(i+1));
     		 	
                           
              
        		int z= quantum - ft;
              rburst_faculty[i] -= z;              
              t += t + z;
              a[f]=t;
              f=f+1;
              ft += z;
              burst2 += z; 
              if(rburst_faculty[i] == 0)
			  {              	
              	wait_faculty[i] = t - burst_faculty[i];
              	
			  }
              if(count==burst2)
			  {
    		faculty_finish == true;
			}
				}
              
            if((ft + quant_data) == quantum)
			{  printf("  F%d  |",(i+1));
			   
              ft += quant_data;
              t += quant_data;
              a[f]=t;
              f=f+1;
              burst2 += quant_data;
              
              if(rburst_faculty[i] == 0){              	
              	wait_faculty[i] = t - burst_faculty[i];
              	
			  }              
              
              rburst_faculty[i]-=quant_data;
              
			if(count==burst2)
			{
   				faculty_finish == true;
			}
            }            
            }
          else{
            rburst_faculty[i] -= quant_data;
            printf("  F%d  |",(i+1));
            
            ft += quant_data;
            t += quant_data; 
            a[f]=t;// for printing simplicity
            f=f+1;
            burst2 += quant_data;
            if(rburst_faculty[i] == 0){              	
              	wait_faculty[i] = t - burst_faculty[i];              	
			  }
  
	  if(count==burst2){
    		faculty_finish == true;
			}   
          }
          
  		}
        else{
        	printf("  F%d  |",(i+1));
        	

          t = t + rburst_faculty[i];
          a[f]=t;
          f=f+1;
          burst2 += rburst_faculty[i];          
          ft += rburst_faculty[i];
          wait_faculty[i] = t - burst_faculty[i];
          if(count==burst2){
				
    		faculty_finish == true;
    		done = true;
			}
          rburst_faculty[i] = 0;
            }
        }
      
    }
    if(ft>=quantum && student_finish == true){
	
    ft = 0;
}
    if(count==burst2){    	
    	faculty_finish == true;
	}
	if(done = true){
	
	break;
}
}return t;

  }
  



void waiting( int s1,int f1, int burst_student[],int burst_faculty[],
                 int quant_data, int wait_student[],int wait_faculty[], int quantum)
{
  printf("\n\n|");
  int rburst_student[s1];
  int rburst_faculty[f1];
  int burst_f[f1];

  int count=0,burst=0;
  for (i = 0 ; i < f1; i++){
  
  count += burst_student[i];
  rburst_student[i] = burst_student[i];
  rburst_faculty[i] = burst_faculty[i];
  burst_f[i] = burst_faculty[i];
  wait_faculty[i] = 0;}


  int t = 0;
  int st=0;
  // round robin 

  while (1 && student_finish == false)
  {   
    bool done = true;

    for (i = 0 ; i < s1; i++)
    {
      if (rburst_student[i] > 0)
      {
        done = false; 

        if (rburst_student[i] >= quant_data)
        {
          // adding burst to total time may or mat not exceed the queue burst 
          //check if adding exceeds queue burst
          if((st + quant_data >= quantum))
           {		
            if((st + quant_data) == quantum)
             {		
              st += quant_data;
              printf("  S%d  |",(i+1));
              
              t += quant_data;
              a[f]=t;
              f=f+1;
              burst += quant_data;
              
              rburst_student[i] -= quant_data;
              if(rburst_student[i] == 0){              	
              	wait_student[i] = t - burst_student[i];
			  }
			  
              t = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
              if(count==burst){
      			student_finish=true;
				  		
              if(faculty_finish==false){
			  
			  t = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
				} 
			}					  
              st = 0;
              
            }
            if((st + quant_data) > quantum)
			{            	
              st += quant_data;
              int z = quantum - st;
              burst += quant_data;            
               printf("  S%d  |",(i+1));   
			   st += z; 
			   burst += z;   
			            
              rburst_student[i] -= z;
              t += z;
              a[f]=t;
            	f=f+1;
              t = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
              if(count==burst)
			  {
      			student_finish=true;	  			
              if(faculty_finish==false){				  		  
			  t = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
				} 
				}
              st = 0;
            }
            
          }
          

          else
		  {
            rburst_student[i] -= quant_data;
            st += quant_data;
            burst += quant_data;
            //calculating waiting time
            printf("  S%d  |",(i+1));
            
            if(rburst_student[i] == 0){              	
              	wait_student[i] = t - burst_student[i];
			  }
            
             t += quant_data;
             a[f]=t;
            f=f+1;
            if(count==burst)
			{
      			student_finish=true;	  			
              
			if(faculty_finish==false)
			{					  
			  t = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
				}
				   }    
          }
      }
          //burst time is smaller than or equal to quan_data
            else{
            	printf("  S%d  |",(i+1));
            	
          		t = t + rburst_student[i];
          		a[f]=t;// for printing simplicity
            	f=f+1;
          		st += rburst_student[i];
          		burst += rburst_student[i];
          		
          		wait_student[i] = t - burst_student[i];
          
          		rburst_student[i] = 0;
          		if(count==burst)
				  {
      			student_finish=true;  
				       
          		if(faculty_finish==false)
				  {		  	  
			  	t = wait_time_faculty(burst_f,rburst_faculty,f1, wait_faculty, quant_data, quantum, t);
				}
			}
            }
        }
        
      }
      if(count==burst){
      	student_finish=true;
	  }
      if (done == true)
      break;
    }
    
    } 

void turn_around(int s1,int f1,int burst_student[],
                        int burst_faculty[],int wait_student[],int wait_faculty[],int turn_student[],int turn_faculty[])
{
 
  for (i = 0; i < s1 ; i++)
    turn_student[i] = burst_student[i] + wait_student[i];

  for (i = 0; i < f1 ; i++)
    turn_faculty[i] = burst_faculty[i] + wait_faculty[i];
}


void average(int s1,int f1, int burst_student[],int burst_faculty[],
                 int quant_data,int quantum)
{
  int wait_student[s1], wait_faculty[f1],turn_student[s1], turn_faculty[f1] ;
  int total_wait_student = 0, total_wait_faculty=0,  total_turn_student = 0, total_turn_faculty=0;
  
  printf("\nThe queries will be executed in the following manner \n");

  waiting(s1,f1, burst_student,burst_faculty,quant_data,wait_student,wait_faculty, quantum);
  turn_around( s1,f1, burst_student,burst_faculty,wait_student,wait_faculty, turn_student, turn_faculty);
  
  printf("\n");
  printf("%02d     ",0);
  
  for(i=0;i<f;i++){
  	printf("%02d     ",a[i]);
  }

  printf("\n\n\nProcessing details for Students\n");
  printf("\n\n\n  Processes \t Burst-time \t Waiting time \t Turn around time\n\n");

  // total waiting time and total turn around time
  
  for (i=0; i<s1; i++)
  {
    total_wait_student = total_wait_student + wait_student[i];
    total_turn_student = total_turn_student + turn_student[i];
    printf("\t%d \t ",i+1); printf("\t%d \t ",burst_student[i]);printf("\t%d \t ",wait_student[i]);printf("\t%d",turn_student[i]);
    printf("\n");
  }
  printf("\n");
  printf("Average waiting time = %f\n", ((float)total_wait_student / (float)s1));
  printf("Average turn around time = %f\n", ((float)total_turn_student / (float)s1));
  printf("\n");
  printf("\n");
  printf("Processing details for Faculties\n");

  printf("\n\n\n  Processes \t Burst-time \t Waiting time \t Turn around time\n\n");

	printf("\n");
  for (i=0; i < f1; i++)
  {
    total_wait_faculty = total_wait_faculty + wait_faculty[i];
    total_turn_faculty = total_turn_faculty + turn_faculty[i];
    printf("\t%d \t ",i+1); printf("\t%d \t ",burst_faculty[i]);	printf("\t%d \t ",wait_faculty[i]); printf("\t%d \t ",turn_faculty[i]);
	printf("\n");      
  }

  printf("\n");
  printf("Average waiting time = %f\n", ((float)total_wait_faculty / (float)f1),"\n");
  printf("Average turn around time = %f\n", ((float)total_turn_faculty / (float)f1), "\n");
  

}

int main()
{
 
  
  printf("Program to handle student and faculty queries\n\n");
  
  	time_t s;
	struct tm* current_time;
	s = time(NULL);
	current_time = localtime(&s);
	
	//check if current system time is between 10am and 12am, then onlt the program runs.
	if(current_time->tm_hour >= 10 && current_time->tm_hour >=00)
	{
		printf("Logged in system\n\n");
		printf("The program is running at %d:%d:%d hours\n\n", current_time->tm_hour,current_time->tm_min,current_time->tm_sec);
  		printf("Enter number of students and faculties \n");
  
  int n1,n2;
  scanf("%d",&n1);
  scanf("%d",&n2);
  
  int burst_student[n1];
  int burst_faculty[n2];
  
  printf("\nEnter burst times in seconds for student queries\n\n");
  
  for(i=0;i<n1;i++)
  scanf("%d",&burst_student[i]);
  
  printf("Enter burst times in seconds for faculty queries\n\n");
  
  for(i=0;i<n2;i++)
  scanf("%d",&burst_faculty[i]);
  
  
  int quant_data=4;

  // Time quantum
  int quantum = 12;
  printf("The time quantum for queue data and for the queue itself has been set to %dsec and %dsec\n",quant_data,quantum);
  printf(" Do you want to change them ? Type yes if you do.\n");
  char string[20];
  scanf("%s",&string);
  if(string=="yes")
  {
  	printf("Enter new values for time quantum for queue data and for the queue");
  	scanf("%d",&quant_data);
  	scanf("%d",&quantum);
  }
  
  int sum=0;
  
  for(i=0;i<n1;i++)
  sum += burst_student[i];
  
  for(i=0;i<n2;i++)
  sum += burst_faculty[i];
  
  average(n1,n2, burst_student,burst_faculty,quant_data, quantum);
  
  return 0;
	}
		else
		printf("Time not between 10 am and 12 am\n");
		printf("You cannot process it now.\n");
  
}
