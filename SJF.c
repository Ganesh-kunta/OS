#include <stdio.h>
int main() 
{
    int n, i;
printf("Enter number of processes: ");
scanf("%d", &n);
int at[n], bt[n], ct[n], tat[n], wt[n], visited[n];
int time = 0, completed = 0;
float avgWT = 0, avgTAT = 0;
for(i = 0; i < n; i++) 
{
    printf("Enter AT and BT of P %d: ", i+1);
    scanf("%d %d", &at[i], &bt[i]);
    visited[i] = 0;
}
 while(completed < n) 
{
    int minBT = 9999, index = -1;
for(i = 0; i < n; i++)
{
    if(at[i] <= time && visited[i] == 0)
    {
      if(bt[i] < minBT) 
      {
        minBT = bt[i];
        index = i;
      }
    }
}
if(index == -1) 
{
    time++;  
} 
else 
 {
    ct[index] = time + bt[index];
    tat[index] = ct[index] - at[index];
    wt[index] = tat[index] - bt[index];
    time = ct[index];
    visited[index] = 1;
    completed++;
    avgWT += wt[index];
    avgTAT += tat[index];
 }
}
printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
for(i = 0; i < n; i++) 
{
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
}
printf("\nAverage Waiting Time = %.2f", avgWT/n);
printf("\nAverage Turnaround Time = %.2f", avgTAT/n);
return 0;
}