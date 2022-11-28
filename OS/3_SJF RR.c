// SJF 

#include <stdio.h>
int main()
{
    int AT[10], BT[10], temp[10];
    int i, smallest, count = 0, time, n, exitime;
    double WT = 0, TAT = 0;
    float average_waiting_time, average_TAT;
    
    // taking input
    printf("\nEnter the Total Number of Processes:\t");
    scanf("%d", &n);
    printf("\nEnter Details of %d Processes", n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Arrival Time:\t");
        scanf("%d", &AT[i]);
        printf("Enter Burst Time:\t");
        scanf("%d", &BT[i]);
        temp[i] = BT[i];
    }
    BT[9] = 9999; // infinity value

    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for (time = 0; count != n; time++;)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (AT[i] <= time && BT[i] < BT[smallest] && BT[i] > 0)
            {
                smallest = i;
            }
        }
        BT[smallest]--;
        if (BT[smallest] == 0)
        {   
            count++;
            exitime = time + 1;
            printf("P[%d]\t|\t%d\t|\t%d\n", smallest, exitime - AT[smallest], exitime - AT[smallest] - temp[smallest]);
            WT = WT + exitime - AT[smallest] - temp[smallest];
            TAT = TAT + exitime - AT[smallest];
        }
    }

    average_waiting_time = WT / n;
    average_TAT = TAT / n;
    printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
    printf("Average Turnaround Time:\t%lf\n", average_TAT);
    return 0;
}


// RR

#include <stdio.h>

int main()
{
    int i,n,ct=0,time_quantum,counter;
    int total_wait_time=0,total_turnaround_time=0,arrival_time[10],burst_time[10],rt[10];
    float avg_wait_time,avg_turnaround_time;
    printf("Enter Total No.Of Process : ");
    scanf("%d",&n);
    counter=n;
    for(i=0;i<n;i++)
    {
        printf("\nEnter Deatils of Process[%d]\n",i+1);
        printf("Arrival Time\t");
        scanf("%d",&arrival_time[i]);
        printf("Burst Time:\t");
        scanf("%d",&burst_time[i]);
        rt[i]=burst_time[i];
    }
    printf("\nEnter Time Quantum : ");
    scanf("%d",&time_quantum);
    printf("\nProcess ID\tBurst Time\t Turnaround Time\tWaitimg Time");
    for(ct=0,i=0;counter!=0)
    {
        if(rt[i] <= time_quantum && rt[i] >0)
        {
            ct = ct + rt[i];
            rt[i]=0;
            counter--;
            printf("\nProcess[%d]\t %d\t\t \t%d\t\t\t %d",i+1,burst_time[i],ct-arrival_time[i],ct-arrival_time[i]-burst_time[i]);
            total_wait_time = total_wait_time + ct - arrival_time[i] - burst_time[i];
            total_turnaround_time = total_turnaround_time + ct-arrival_time[i];
        }
        else if(rt[i] > time_quantum)
        {
            rt[i] = rt[i] -  time_quantum;
            ct = ct +time_quantum;
        }
        if(i == n-1)
        {
            i=0;
        }
        else if(arrival_time[i+1] < ct)
        {
            i++;
        }
        else
        {
            i=0;
        }
    }
    avg_wait_time = (float) total_wait_time/n;
    avg_turnaround_time = (float) total_turnaround_time/n;
    printf("\nAverage Waiting Time : %f",avg_wait_time);
    printf("\nAverage Turnaround Time : %f",avg_turnaround_time);

    return 0;
}
