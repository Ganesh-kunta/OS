#include<stdio.h.>
int main()
{
    int base[10], limit[10], i, n;
    int segmentnumber, offset, physicaladdress;
    printf("Enter no.of segments:");
    scanf("%d", &n);
    printf("Enter base and limit for each segment:\n");
    for(i=0; i<n; i++)
    {
        printf("Segment %d base:", i);
        scanf("%d", &base[i]);
        printf("Segment %d limit:", i);
        scanf("%d", &limit[i]);
    }
    printf("\n Enter segment number:");
    scanf("%d", &segmentnumber);
    printf("Enter offset:");
    scanf("%d", &offset);
    if(segmentnumber >= n)
    {
        printf("Invalid segment number!\n");
    }
    else if(offset >= limit[segmentnumber])
    {
        printf("offset exceeds segment limit!\n");
    }
    else
    {
        physicaladdress = base[segmentnumber] + offset;
        printf("\n Base Address: %d", base[segmentnumber]);
        printf("\n Physical Address: %d", physicaladdress);
    }
    return 0;
}