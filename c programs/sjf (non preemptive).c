#include<stdio.h>

int main()
{
    int n, i, j, pos, temp;
    float avg_waiting_time, avg_turnaround_time;
    int total_waiting_time = 0, total_turnaround_time = 0;
    int arrival_time[10], burst_time[10], turnaround_time[10], waiting_time[10];
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    printf("\nEnter Arrival Time and Burst Time for each process:\n");
    for(i=0; i<n; i++)
    {
        printf("\nProcess %d:\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
    }
    
    // Sorting processes based on burst time
    for(i=0; i<n; i++)
    {
        pos = i;
        for(j=i+1; j<n; j++)
        {
            if(burst_time[j] < burst_time[pos])
            {
                pos = j;
            }
        }
        temp = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = temp;
        
        temp = arrival_time[i];
        arrival_time[i] = arrival_time[pos];
        arrival_time[pos] = temp;
    }
    
    // Calculating waiting time and turnaround time for each process
    waiting_time[0] = 0;
    for(i=1; i<n; i++)
    {
        waiting_time[i] = 0;
        for(j=0; j<i; j++)
        {
            waiting_time[i] += burst_time[j];
        }
        total_waiting_time += waiting_time[i];
    }
    
    // Calculating average waiting time and average turnaround time
    avg_waiting_time = (float)total_waiting_time / n;
    avg_turnaround_time = (float)(total_waiting_time + total_turnaround_time) / n;
    
    // Displaying the results
    printf("\nProcess\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for(i=0; i<n; i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("P%d\t\t %d\t\t %d\t\t %d\t\t %d\n", i+1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    
    printf("\nAverage Waiting Time = %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time = %.2f", avg_turnaround_time);
    
    return 0;
}
