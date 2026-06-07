#include<stdio.h>
int main()
{
    int i, n;
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
while(completed!=n)
{
   int min = 9999, shortest = -1;
for(i=0; i<n; i++)
{
    if(at[i]<=time && rt[i]>0 && rt[i]<min)
{
    min = rt[i];
    shortest = i;                                                                                                                
}
}
if(shortest == -1)
{
    time++;
}
else
{
    rt[shortest]--;
    if(rt[shortest] == 0)
    {
        completed++;
        ct[shortest] = time+1;
        tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];
        avgtat = avgtat + tat[shortest];
        avgwt = avgwt + wt[shortest];
    }
    time++;
}
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