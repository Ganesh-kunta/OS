#include<stdio.h>
int main()
{
    int n, f, i, j, k, page[50], frame[10];
    int faults = 0, found, pos, farthest, index;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
    scanf("%d", &page[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < f; j++)
        {
            if(frame[j] == page[i])
            {
                found = 1;
                break;
            }
        }
        if(found == 0)
        {
            pos = -1;
            farthest = i;
            for(j = 0; j < f; j++)
            {
                int flag = 0;
                for(k = i + 1; k < n; k++)
                {
                    if(frame[j] == page[k])
                    {
                        if(k > farthest)
                        {
                            farthest = k;
                            pos = j;
                        }
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    pos = j;
                    break;
                }
            }
            if(pos == -1)
                pos = 0;

            frame[pos] = page[i];
            faults++;
        }
        printf("\nFrames: ");
        for(k = 0; k < f; k++)
        printf("%d ", frame[k]);
    }
    printf("\nTotal Page Faults = %d", faults);
    return 0;
}