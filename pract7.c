#include<stdio.h>
 
int main()
{
    //Input no of processed
    int  n;
    printf("Enter Total Number of Processes:");
    scanf("%d", &n);
    int wt = 0, tat = 0, at[n], bt[n], tbt[n];
    int x = n;
 
    //Input details of processes
    for(int i = 0; i < n; i++)
    {
        printf("Enter Details of Process %d \n", i + 1);
        printf("Arrival Time:  ");
        scanf("%d", &at[i]);
        printf("Burst Time:   ");
        scanf("%d", &bt[i]);
        tbt[i] = bt[i];
    }
 
    //Input time slot
    int time_slot;
    printf("Enter Time Slot:");
    scanf("%d", &time_slot);
 
    //Total indicates total time
    //counter indicates which process is executed
    int total = 0,  counter = 0,i;
    printf("Process ID       Burst Time       Turnaround Time      Waiting Time\n");
    for(total=0, i = 0; x!=0; )  
    {  
        // define the conditions
        if(tbt[i] <= time_slot && tbt[i] > 0)    
        {  
            total = total + tbt[i];  
            tbt[i] = 0;  
            counter=1;  
        }     
        else if(tbt[i] > 0)  
        {  
            tbt[i] = tbt[i] - time_slot;  
            total  += time_slot;    
        }  
        if(tbt[i]==0 && counter==1)  
        {  
            x--; //decrement the process no.  
            printf("\nProcess No %d  \t\t %d\t\t %d\t\t\t %d", i+1, bt[i],
                   total-at[i], total-at[i]-bt[i]);  
            wt = wt+total-at[i]-bt[i];  
            tat += total -at[i];  
            counter =0;     
        }  
        if(i==n-1)  
        {  
            i=0;  
        }  
        else if(at[i+1]<=total)  
        {  
            i++;  
        }  
        else  
        {  
            i=0;  
        }  
    }  
    float average_wait_time = wt * 1.0 / n;
    float average_turnaround_time = tat * 1.0 / n;
    printf("\nAverage Waiting Time:%f", average_wait_time);
    printf("\nAvg Turnaround Time:%f", average_turnaround_time);
    return 0;
}