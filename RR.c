#include<stdio.h>
int main()
{
    int i, n, tq;
printf("Enter no. of processes:");
scanf("%d", &n);
int at[n], bt[n], ct[n], tat[n], wt[n], rt[n], time = 0, completed = 0;
float avgtat = 0, avgwt = 0;
for(i=0; i<n; i++)
{
    printf("Enter AT and BT of p %d:", i+1);
    scanf("%d %d", &at[i], &bt[i]);
    rt[i] = bt[i];
}
printf("Enter time Quantum:");
scanf("%d", &tq);
while(completed < n)
{
    int flag = 0;
    for(i=0; i<n; i++)
    {
        if(rt[i] > 0 && at[i] <= time)
        {
            flag = 1;
            if(rt[i] > tq)
            {
                time += tq;
                rt[i] -= tq;
            }
            else
            {
                time += rt[i];
                rt[i] = 0;
                ct[i] = time;
                completed++;
            }
        }
    }
    if(flag == 0)
    time++;
}
for(i=0; i<n; i++)
{
    tat[i] = ct[i] - at[i];
    wt[i] = tat[i] - bt[i];
    avgtat = avgtat + tat[i];
    avgwt = avgwt + wt[i];
}
printf("\nprocess\tAT\tBT\tCT\tTAT\tWT\n");
for(i=0; i<n; i++)
{
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
}
printf("\nAvg Waiting time = %.2f", avgwt/n);
printf("\nAvg TurnAround time = %.2f", avgtat/n);
return 0;
}