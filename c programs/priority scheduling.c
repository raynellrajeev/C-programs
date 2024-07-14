#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, sum = 0;
    float avg_waiting_time, avg_turnaround_time;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int process[n], burst_time[n], priority[n], arrival_time[n], waiting_time[n], turnaround_time[n];
    for(i = 0; i < n; i++) {
        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter the priority for process %d: ", i + 1);
        scanf("%d", &priority[i]);
        process[i] = i + 1;
    }
    
    // Sort the processes by arrival time and priority using nested loop
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(arrival_time[i] > arrival_time[j]) {
                int temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;

                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time for each process
    int complete_time[n];
    for(i = 0; i < n; i++) {
        if(i == 0) {
            complete_time[i] = arrival_time[i] + burst_time[i];
        }
        else {
            if(arrival_time[i] > complete_time[i - 1]) {
                complete_time[i] = arrival_time[i] + burst_time[i];
            }
            else {
                complete_time[i] = complete_time[i - 1] + burst_time[i];
            }
        }
        turnaround_time[i] = complete_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        sum += waiting_time[i];
    }
    avg_waiting_time = (float)sum / n;
    sum = 0;
    for(i = 0; i < n; i++) {
        sum += turnaround_time[i];
    }
    avg_turnaround_time = (float)sum / n;
    
    // Print the results
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrival_time[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    printf("\nAverage waiting time: %.2f", avg_waiting_time);
    printf("\nAverage turnaround time: %.2f", avg_turnaround_time);
    
    return 0;
}
