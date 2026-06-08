#include<stdio.h>
int main()
{
    int n, i;
    printf("Enter no. of processes: ");
    scanf("%d",&n);
    int at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], visited[n];
    int time = 0, completed = 0;
    float avgwt = 0, avgtat = 0;
    for(i=0;i<n;i++)
    {
        printf("Enter AT, BT and Priority of P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        visited[i] = 0;
    }
    while(completed != n)
    {
        int highest = 9999;
        int index = -1;
        for(i=0;i<n;i++)
        {
            if(at[i] <= time && visited[i] == 0)
            {
                if(pr[i] < highest)
                {
                    highest = pr[i];
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
            avgwt += wt[index];
            avgtat += tat[index];
        }
    }
    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);
    return 0;
}