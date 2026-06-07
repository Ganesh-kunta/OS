#include<stdio.h>
int main()
{
    int n, i;
printf("Enter no. of processes:");
scanf("%d", &n);
int at[n], bt[n], ct[n], tat[n], wt[n], time = 0;
float avgwt = 0, avgtat = 0;
for(i=0; i<n; i++)
{
    printf("Enter Arrival time and Burst time of p %d:", i+1);
    scanf("%d%d", &at[i], &bt[i]);
}
for(i=0; i<n; i++)
{
    if(time < at[i])
    time = at[i];
    ct[i] = time + bt[i];
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    time = ct[i];
    avgwt = avgwt + wt[i];
    avgtat = avgtat + tat[i];
}
printf("\nProcess\tAT\tBt\tCT\tTAT\tWT\n");
for(i=0; i<n; i++)
{
    printf("p%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
}
printf("\n Average Waiting Time = %.2f", avgwt/n);
printf("\n Average Turnaround Time = %.2f", avgtat/n);
return 0;
}