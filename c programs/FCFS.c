#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], ct[n], wt[n], tat[n];
    float awt = 0, atat = 0;

    printf("Enter the arrival time for each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter the burst time for each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    ct[0] = bt[0] + at[0];
    for (i = 1; i < n; i++) 
    {
        if(at[i]>ct[i-1])
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            ct[i]=ct[i - 1]+bt[i];
        }
    }

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
        atat += tat[i];
    }
    awt /= n;
    atat /= n;

    printf("\nGantt Chart:\n");
    for (i = 0; i < n; i++) {
        printf(" %d | P%d ", ct[i] - bt[i], i+1);
    }
    printf("%d\n", ct[n-1]);

    printf("\nProcess\t AT\t BT\t CT\t WT\t TAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAWT = %.2f\n", awt);
    printf("ATAT = %.2f\n", atat);

    return 0;
}