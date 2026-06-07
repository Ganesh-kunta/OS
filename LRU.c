#include<stdio.h>
int main()
{
    int n, i, j, f, faults = 0, counter = 0;
    int pages[100], time[100], frames[100];
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }
    for(i = 0; i < n; i++)
    {
        int found = 0;
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }
        if(found == 0)
        {
            int pos = 0;

            for(j = 1; j < f; j++)
            {
                if(time[j] < time[pos])
                {
                    pos = j;
                }
            }
            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }
    }
    printf("Total Page Faults (LRU): %d\n", faults);
    return 0;
}