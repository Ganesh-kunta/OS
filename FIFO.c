#include<stdio.h>
int main()
{
    int f, n, i, j, pos = 0, faults = 0;
    int frames[100], pages[100];
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    for(i = 0; i < f; i++)
    {
        frames[i] = -1;
    }
    for(i = 0; i < n; i++)
    {
        int found = 0;
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found= 1;
                break;
            }
        }
        if(found == 0)
        {
            frames[pos] = pages[i];
            pos = (pos + 1) % f;
            faults++;
        }
    }
    printf("Total Page Faults : %d\n", faults);
    return 0;
}